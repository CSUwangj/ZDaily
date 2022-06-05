+++
updated = 2022-06-04 18:14:00+08:00
title = "2022-06-04 Daily-Challenge"
path = "2022-06-04-Daily-Challenge"
date = 2022-06-04 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/n-queens/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 4

## Description

**N-Queens**

​The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```

**Example 2:**

```
Input: n = 1
Output: [["Q"]]
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
  vector<vector<string>> answer;

  void addResult(int n) {
    vector<string> result;
    for(int i = 0; i < n; ++i) {
      string row(n, '.');
      row[rows[i]] = 'Q';
      result.emplace_back(row);
    }
    answer.emplace_back(result);
  }

  void solve(int cur, int n) {
    if(cur == n) {
      addResult(n);
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
  vector<vector<string>> solveNQueens(int n) {
    solve(0, n);
    return move(answer);
  }
};

// Accepted
// 9/9 cases passed (5 ms)
// Your runtime beats 81.60 % of cpp submissions
// Your memory usage beats 36.63 % of cpp submissions (8 MB)
```
