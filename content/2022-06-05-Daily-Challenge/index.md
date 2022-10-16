+++
updated = 2022-06-05 18:14:00+08:00
title = "2022-06-05 Daily-Challenge"
path = "2022-06-05-Daily-Challenge"
date = 2022-06-05 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/n-queens-ii/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 5

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

// Accepted
// 9/9 cases passed (6 ms)
// Your runtime beats 64.32 % of cpp submissions
// Your memory usage beats 97.4 % of cpp submissions (5.8 MB)
```
