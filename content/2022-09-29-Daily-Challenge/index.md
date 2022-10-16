+++
updated = 2022-09-29 18:14:00+08:00
title = "2022-09-29 Daily-Challenge"
path = "2022-09-29-Daily-Challenge"
date = 2022-09-29 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/find-k-closest-elements/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 29

## Description

**Find K Closest Elements**

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`

 

**Example 1:**

```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

**Example 2:**

```
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

 

**Constraints:**

- `1 <= k <= arr.length`
- `1 <= arr.length <= 10^4`
- `arr` is sorted in **ascending** order.
- `-104 <= arr[i], x <= 10^4`

## Solution

``` cpp
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int len = arr.size();
    if(k == len) return arr;
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(pos == 0) return vector<int>(arr.begin(), arr.begin() + k);
    if(pos == len) return vector<int>(arr.end() - k, arr.end());
    int start = pos;
    int sz = (arr[pos] == x);
    while(sz < k) {
      if(start == 0) break;
      if(start + sz == len) {
        start = len - k;
        break;
      }
      if(x - arr[start - 1] <= arr[start + sz] - x) {
        start -= 1;
      }
      sz += 1;
    }
    return vector<int>(arr.begin() + start, arr.begin() + start + k);
  }
};

// Accepted
// 66/66 cases passed (48 ms)
// Your runtime beats 91.78 % of cpp submissions
// Your memory usage beats 78 % of cpp submissions (31.2 MB)
```
