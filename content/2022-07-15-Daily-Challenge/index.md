+++
updated = 2022-07-15 18:14:00+08:00
title = "2022-07-15 Daily-Challenge"
path = "2022-07-15-Daily-Challenge"
date = 2022-07-15 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/max-area-of-island/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 15

## Description

**Max Area of Island**

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg)

```
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
```

**Example 2:**

```
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

 

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`.

## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int current;
  int rows;
  int cols;
  void dfs(vector<vector<int>>& grid, int row, int col) {
    grid[row][col] = 0;
    current += 1;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(grid[newRow][newCol]) {
        dfs(grid, newRow, newCol);
      }
    }
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid.front().size();
    int answer = 0;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        if(grid[i][j]) {
          current = 0;
          dfs(grid, i, j);
          answer = max(answer, current);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 728/728 cases passed (22 ms)
// Your runtime beats 82.07 % of cpp submissions
// Your memory usage beats 98.43 % of cpp submissions (23 MB)
```
