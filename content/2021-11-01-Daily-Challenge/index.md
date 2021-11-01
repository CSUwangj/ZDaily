+++
title = "2021-11-01 Daily-Challenge"
path = "2021-11-01-Daily-Challenge"
date = 2021-11-01 17:43:23+08:00
updated = 2021-11-01 17:50:32+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/surrounded-regions/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 1

## Description

**Surrounded Regions**

Given an `m x n` matrix `board` containing `'X'` and `'O'`, *capture all regions that are 4-directionally surrounded by* `'X'`.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

```
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
```

**Example 2:**

```
Input: board = [["X"]]
Output: [["X"]]
```

 

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.

## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  vector<vector<bool>> vis;
  void dfs(int row, int col, vector<vector<char>>& board) {
    vis[row][col] = true;
    board[row][col] = 'A';
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
      if(vis[newRow][newCol] || board[newRow][newCol] == 'X') continue;
      dfs(newRow, newCol, board);
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(int i = 0; i < cols; ++i) {
      if(!vis[0][i] && board[0][i] == 'O') dfs(0, i, board);
      if(!vis[rows - 1][i] && board[rows - 1][i] == 'O') dfs(rows - 1, i, board); 
    }
    for(int i = 0; i < rows; ++i) {
      if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, board);
      if(!vis[i][cols - 1] && board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
    }
    for(auto &row : board) {
      for(auto &c : row) {
        c = (c == 'A' ? 'O' : 'X');
      }
    }
  }
};

// Accepted
// 58/58 cases passed (12 ms)
// Your runtime beats 84.68 % of cpp submissions
// Your memory usage beats 44.1 % of cpp submissions (10.2 MB)
```
