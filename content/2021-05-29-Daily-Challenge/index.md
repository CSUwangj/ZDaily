+++
title = "2021-05-29 Daily-Challenge"
path = "2021-05-29-Daily-Challenge"
date = 2021-05-29 14:45:00+08:00
updated = 2021-05-29 15:18:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/) with `cpp`.

<!-- more -->

# LeetCode Review

## To Lower Case

too easy to review

## Evaluate Reverse Polish Notation

too easy to review

## Partitioning Into Minimum Number Of Deci-Binary Numbers

too easy to review

## Maximum Product of Word Lengths

too easy to review

## Maximum Erasure Value

too easy to review

## Count Negative Numbers in a Sorted Matrix

too easy to review

## Length of Longest Fibonacci Subsequence

too easy to review

## Dice Roll Simulation

come up with DP formula by myself, no need to review

## Create Maximum Number

still remember way of merge, no need to review

## Minimum Difficulty of a Job Schedule

``` cpp
class Solution {
public:
  int minDifficulty(vector<int>& jd, int d) {
    int len = jd.size();
    if(d > len) return -1;
    if(len == d) return accumulate(jd.begin(), jd.end(), 0);
    if(d == 1) return *max_element(jd.begin(), jd.end());
    int dp[2][len];
    dp[0][0] = jd[0];
    for(int i = 1; i < len; ++i) dp[0][i] = max(jd[i], dp[0][i - 1]);
    vector<int> ms;
    for(int i = 1; i < d; ++i) {
      int parity = i & 1;
      ms.clear();
      for(int j = i; j < len; ++j) {
        dp[parity][j] = dp[!parity][j - 1] + jd[j];
        while(ms.size() && jd[ms.back()] < jd[j]) {
          int k = ms.back();
          ms.pop_back();
          dp[parity][j] = min(dp[parity][j], dp[parity][k] - jd[k] + jd[j]);
        }
        if(ms.size()) {
          dp[parity][j] = min(dp[parity][j], dp[parity][ms.back()]);
        }
        ms.push_back(j);
      }
    }
    return dp[!(d & 1)][len - 1];
  }
};
```

# May LeetCoding Challenge 29

## Description

**N-Queens II**

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *the number of distinct solutions to the **n-queens puzzle***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

 

**Constraints:**

- `1 <= n <= 9`

## Solution

``` cpp
int rows[9];
bool check(int row, int col) {
  for(int i = 0; i < row; ++i) {
    if(abs(i - row) == abs(rows[i] - col) || col == rows[i]) return false;
  }
  return true;
}
class Solution {
  int answer = 0;

  void solve(int cur, int n) {
    if(cur == n) {
      answer += 1;
      return;
    }
    for(int i = 0; i < n; ++i) {
      if(check(cur, i)) {
        rows[cur] = i;
        solve(cur + 1, n);
      }
    }
  }
public:
  int totalNQueens(int n) {
    solve(0, n);
    return answer;
  }
};
```
