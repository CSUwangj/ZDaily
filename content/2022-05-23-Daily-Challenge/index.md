+++
updated = 2022-05-23 18:14:00+08:00
title = "2022-05-23 Daily-Challenge"
path = "2022-05-23-Daily-Challenge"
date = 2022-05-23 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/ones-and-zeroes/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 23

## Description

**Ones and Zeroes**

You are given an array of binary strings `strs` and two integers `m` and `n`.

Return *the size of the largest subset of `strs` such that there are **at most*** `m` `0`*'s and* `n` `1`*'s in the subset*.

A set `x` is a **subset** of a set `y` if all elements of `x` are also elements of `y`.

 

**Example 1:**

```
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
```

**Example 2:**

```
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
```

 

**Constraints:**

- `1 <= strs.length <= 600`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists only of digits `'0'` and `'1'`.
- `1 <= m, n <= 100`

## Solution

``` cpp
class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int count[len][2];
    for(int i = 0; i < len; ++i) {
      count[i][0] = 0;
      count[i][1] = 0;
      for(auto c : strs[i]) count[i][c == '1'] += 1;
    }
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; ++i) {
      for(int j = 0; j <= n; ++j) dp[i][j] = -1;
    }
    int answer = 0;
    dp[0][0] = 0;
    for(int i = 0; i < len; ++i) {
      for(int zero = m; zero >= count[i][0]; --zero) {
        for(int one = n; one >= count[i][1]; --one) {
          if(dp[zero - count[i][0]][one - count[i][1]] == -1) continue;
          dp[zero][one] = max(dp[zero - count[i][0]][one - count[i][1]] + 1, dp[zero][one]);
          answer = max(answer, dp[zero][one]);
        }
      }
    }
    
    return answer;
  }
};

// Accepted
// 71/71 cases passed (73 ms)
// Your runtime beats 98.35 % of cpp submissions
// Your memory usage beats 96.22 % of cpp submissions (8.7 MB)
```
