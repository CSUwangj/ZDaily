+++
updated = 2022-04-12 20:05:00+08:00
title = "2022-04-12 Daily-Challenge"
path = "2022-04-12-Daily-Challenge"
date = 2022-04-12 21:04:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/game-of-life/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 12

## Description

**Game of Life**

According to [Wikipedia's article](https://en.wikipedia.org/wiki/Conway's_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state: **live** (represented by a `1`) or **dead** (represented by a `0`). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules  simultaneously to every cell in the current state, where births and  deaths occur simultaneously. Given the current state of the `m x n` grid `board`, return *the next state*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg)

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg)

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

 

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 25`
- `board[i][j]` is `0` or `1`.

 

**Follow up:**

- Could you solve it in-place? Remember that the board needs to be  updated simultaneously: You cannot update some cells first and then use  their updated values to update other cells.
- In this question, we represent the board using a 2D array. In  principle, the board is infinite, which would cause problems when the  active area encroaches upon the border of the array (i.e., live cells  reach the border). How would you address these problems?

## Solution

``` cpp
class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        for(int row = max(0, i-1); row <= min(rows-1, i+1); ++row) {
          for(int col = max(0, j-1); col <= min(cols-1, j+1); ++col) {
            board[i][j] += ((board[row][col] & 1) << 1);
          }
        }
        board[i][j] -= ((board[i][j] & 1) << 1);
      }
    }
    for(auto &row : board) {
      for(auto &cell : row) {
        if(cell > 4 && cell < 8) cell = 1;
        else cell = 0;
      }
    }
  }
};

// Accepted
// 22/22 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.27 % of cpp submissions (7 MB)
```
