+++
title = "2020-10-26 Daily-Challenge"
path = "2020-10-26-Daily-Challenge"
date = 2020-10-26 00:13:22+08:00
updated = 2020-10-26 20:18:48+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Odd Even Jump* on [leetcode](https://leetcode.com/problems/odd-even-jump/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3508/) with `cpp`.

<!-- more -->

# Odd Even Jump

## Description

You are given an integer array A. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.

You may jump forward from index i to index j (with i < j) in the following way:

During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
It may be the case that for some index i, there are no legal jumps.
A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once).

Return the number of good starting indices.

## Solution

reverse travel through A and add number into map, iwhere later will be used to determine does that position is a suitable odd/even jump.

``` cpp
class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    int len = A.size(), ans = 1;
    if(len < 2) return len;
    vector<bool> odd(len, false);
    vector<bool> even(len, false);
    map<int, int> pos;
    pos[A[len-1]] = len-1;
    odd[len-1] = true;
    even[len-1] = true;
    for(int i = len-2; i >= 0; --i) {
      int v = A[i];
      if(pos.count(v)) {
        odd[i] = even[pos[v]];
        even[i] = odd[pos[v]];
      } else {
        auto it = pos.lower_bound(v);
        if(it != pos.end()) {
          odd[i] = even[it->second];
        }
        it = pos.upper_bound(v);
        if(it != pos.begin()) {
          --it;
          even[i] = odd[it->second];
        }
      }
      ans += odd[i];
      pos[A[i]] = i;
    }
    for(auto b: odd) {
      cout << b << ' ';
    }
    cout << endl;
    return ans;
  }
};
```

# October LeetCoding Challenge26

**Champagne Tower**

## Description

We stack glasses in a pyramid, where the **first** row has `1` glass, the **second** row has `2` glasses, and so on until the 100th row. Each glass holds one cup (`250`ml) of champagne.

Then, some champagne is poured in the first glass at the top. When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it. When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on. (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full. After two cups of champagne are poured, the two glasses on the second row are half full. After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now. After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/09/tower.png)

Now after pouring some non-negative integer cups of champagne, return how full the `jth` glass in the `ith` row is (both `i` and `j` are 0-indexed.)

 

**Example 1:**

```
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
```

**Example 2:**

```
Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
```

**Example 3:**

```
Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
```

**Constraints:**

- `0 <= poured <= 109`
- `0 <= query_glass <= query_row < 100`

## Solution

simple simulation.

``` cpp
class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> rows(query_row+1);
    rows[0] = poured;
    for(int i = 0; i < query_row; ++i) {
      for(int j = i; j >= 0; --j) {
        rows[j] = rows[j] > 1.0 ? rows[j]-1.0 : 0;
        rows[j+1] += rows[j] / 2;
        rows[j] /= 2;
      }
    }
    return min(1.0, rows[query_glass]);
  }
};
```
