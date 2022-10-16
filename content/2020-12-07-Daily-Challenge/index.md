+++
title = "2020-12-07 Daily-Challenge"
path = "2020-12-07-Daily-Challenge"
date = 2020-12-07 18:21:30+08:00
updated = 2020-12-07 20:12:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reduce Array Size to The Half](https://leetcode.com/problems/reduce-array-size-to-the-half/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3556/) with `cpp`.

<!-- more -->

# Reduce Array Size to The Half

## Description

Given an array `arr`. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return *the minimum size of the set* so that **at least** half of the integers of the array are removed.

**Example 1:**

```
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
```

**Example 2:**

```
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
```

**Example 3:**

```
Input: arr = [1,9]
Output: 1
```

**Example 4:**

```
Input: arr = [1000,1000,3,7]
Output: 1
```

**Example 5:**

```
Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `arr.length` is even.
- `1 <= arr[i] <= 10^5`

## Solution

nothing to say

``` cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto i : arr) {
            m[i] += 1;
        }
        if(m.size() < 3) return 1;
        int len = arr.size();
        vector<int> cnt;
        for(auto [i, c] : m) {
            cnt.push_back(c);
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        if(cnt[0] >= len/2) return 1;
        for(int i = 1; i < cnt.size(); ++i) {
            cnt[i] += cnt[i-1];
            if(cnt[i] >= len/2) return i+1;
        }
        return len;
    }
};
```

# December LeetCoding Challenge 7

## Description

**Spiral Matrix II**

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n2` in spiral order.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

**Example 2:**

```
Input: n = 1
Output: [[1]]
```

**Constraints:**

- `1 <= n <= 20`

## Solution

in fact I used `pick one` and have already done it on this morning, so I just do another random problem.

``` cpp
class Solution {
    int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int sat(vector<vector<int>> &result, int newH, int newW, int n) {
        return newH >= 0 && newW >= 0 && newH < n && newW < n && !result[newH][newW];
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        auto result = vector<vector<int>>(n, vector<int>(n, 0));
        result[0][0] = 1;
        if(n == 1) return result;
        int h = 0;
        int w = 1;
        int direction = 0;
        while(true) {
            result[h][w] = result[h-move[direction][0]][w-move[direction][1]] + 1;
            int turn = 0;
            while(turn < 4 && !sat(result, h + move[direction][0], w + move[direction][1], n)) {
                direction = (direction + 1) % 4;
                turn += 1;
            }
            if(turn == 4) break;
            h += move[direction][0];
            w += move[direction][1];
        }
        return result;
    }
};
```