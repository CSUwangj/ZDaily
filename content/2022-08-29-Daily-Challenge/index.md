+++
updated = 2022-08-29 18:14:00+08:00
title = "2022-08-29 Daily-Challenge"
path = "2022-08-29-Daily-Challenge"
date = 2022-08-29 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/number-of-islands/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 29

## Description

**Number of Islands**

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by  connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

**Example 1:**

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

 

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## Solution

``` cpp
class Solution {
  int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
  int height;
  int width;
  vector<vector<bool>> visited;
  void dfs(vector<vector<char>>& grid, int h, int w) {
    grid[h][w] = '0';
    for(int i = 0; i < 4; ++i) {
      int newH = h + move[i][0];
      int newW = w + move[i][1];
      if(newH >= 0 && newH < height && newW >= 0 && newW < width &&
         grid[newH][newW] == '1') {
        dfs(grid, newH, newW);
      }
    }
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    height = grid.size();
    width = grid[0].size();
    int ans = 0;
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        if(grid[i][j] == '1') {
          ans += 1;
          dfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};

// Accepted
// 49/49 cases passed (66 ms)
// Your runtime beats 35.13 % of cpp submissions
// Your memory usage beats 97.03 % of cpp submissions (12.2 MB)
```
