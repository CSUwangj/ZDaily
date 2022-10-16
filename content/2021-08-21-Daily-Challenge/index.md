+++
title = "2021-08-21 Daily-Challenge"
path = "2021-08-21-Daily-Challenge"
date = 2021-08-21 18:00:03+08:00
updated = 2021-08-21 18:40:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3905/) with `cpp`.

<!-- more -->

# LeetCode Review

## Valid Sudoku

too easy to review

## Maximum Product of Splitted Binary Tree

too easy to review

## Decode Ways

too easy to review

## Count Good Nodes in Binary Tree

too easy to review

## Range Sum Query - Immutable

too easy to review

## Implement Queue using Stacks

too easy to review

## Min Stack

too easy to review

## Count Pairs With XOR in a Range

too easy to review

## Check if Binary String Has at Most One Segment of Ones

too easy to review

# August LeetCoding Challenge 21

## Description

**Sudoku Solver**

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

The `'.'` character indicates empty cells.

 

**Example 1:**

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

```
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
```

 

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit or `'.'`.
- It is **guaranteed** that the input board has only one solution.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> rows = vector<int>(9);
  vector<int> cols = vector<int>(9);
  vector<int> squares = vector<int>(9);
  void init(vector<vector<char>>& board) {
    for(int i = 0; i < 81; ++i){
      int row = i % 9;
      int col = i / 9;
      int square = i % 9 / 3 * 3 + i / 9 / 3;
      if(board[row][col] == '.') continue;
      rows[row] |= (1 << (board[row][col] - '0'));
      cols[col] |= (1 << (board[row][col] - '0'));
      squares[square] |= (1 << (board[row][col] - '0'));
    }
  }
  bool dfs(vector<vector<char>>& board, int pos) {
    if(pos == 81) return true;
    int row = pos % 9;
    int col = pos / 9;
    int square = pos % 9 / 3 * 3 + pos / 9 / 3;
    if(board[row][col] != '.') return dfs(board, pos+1);
    for(int i = 1; i < 10; ++i) {
      if(rows[row] & (1 << i) ||
        cols[col] & (1 << i) ||
        squares[square] & (1 << i)) continue;
      rows[row] |= (1 << i);
      cols[col] |= (1 << i);
      squares[square] |= (1 << i);
      if(dfs(board, pos+1)) {
        board[row][col] = i+'0';
        return true;
      }
      rows[row] ^= (1 << i);
      cols[col] ^= (1 << i);
      squares[square] ^= (1 << i);
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    init(board);
    dfs(board, 0);
  }
};

// Accepted
// 6/6 cases passed (4 ms)
// Your runtime beats 98.8 % of cpp submissions
// Your memory usage beats 83.27 % of cpp submissions (6.4 MB)
```