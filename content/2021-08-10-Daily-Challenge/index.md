+++
title = "2021-08-10 Daily-Challenge"
path = "2021-08-10-Daily-Challenge"
date = 2021-08-10 18:39:04+08:00
updated = 2021-08-10 22:43:18+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3876/) with `cpp`.

<!-- more -->

# Minimum Falling Path Sum II

## Description

Given a square grid of integers `arr`, a *falling path with non-zero shifts* is a choice of exactly one element from each row of `arr`, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

 

**Example 1:**

```
Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
```

 

**Constraints:**

- `1 <= arr.length == arr[i].length <= 200`
- `-99 <= arr[i][j] <= 99`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& arr) {
    pair<int, int> smallest{0, -1}, secondSmallest{0, -1};
    pair<int, int> tmp1{INT_MAX, -1}, tmp2{INT_MAX, -1};
    int n = arr.size();
    for(auto &row : arr) {
      for(int i = 0; i < n; ++i) {
        int result;
        if(i == smallest.second) {
          result = row[i] + secondSmallest.first;
        } else {
          result = row[i] + smallest.first;
        }
        if(result < tmp1.first) {
          tmp2 = tmp1;
          tmp1 = {result, i};
        } else if (result < tmp2.first) {
          tmp2 = {result, i};
        }
      }
      swap(tmp1, smallest);
      swap(tmp2, secondSmallest);
      tmp1 = {INT_MAX, -1};
      tmp2 = {INT_MAX, -1};
    }
    return smallest.first;
  }
};

// Accepted
// 13/13 cases passed (12 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 68.84 % of cpp submissions (13.1 MB)
```

# August LeetCoding Challenge 10

## Description

**Flip String to Monotone Increasing**

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none), followed by some number of `1`'s (also possibly none).

You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to `0`.

Return *the minimum number of flips to make* `s` *monotone increasing*.

 

**Example 1:**

```
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```

**Example 2:**

```
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
```

**Example 3:**

```
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int ones = 0;
    int len = s.length();
    for(auto c : s) {
      ones += (c & 1);
    }
    int zeros = len - ones;
    int currentOnes = 0;
    int currentZeros = 0;
    int answer = zeros;
    for(auto c : s) {
      currentZeros += !(c & 1);
      currentOnes += (c & 1);
      answer = min(answer, currentOnes + zeros - currentZeros);
    }
    return answer;
  }
};

// Accepted
// 93/93 cases passed (12 ms)
// Your runtime beats 29.13 % of cpp submissions
// Your memory usage beats 21.38 % of cpp submissions (11.1 MB)
```
