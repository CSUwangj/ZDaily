+++
updated = 2024-08-11T13:22:18+08:00
title = "2024-08-11 Daily Challenge"
path = "2024-08-11-Daily-Challenge"
date = 2024-08-11T13:22:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 11

## Description

**Minimum Number of Days to Disconnect Island**

<p>You are given an <code>m x n</code> binary grid <code>grid</code> where <code>1</code> represents land and <code>0</code> represents water. An <strong>island</strong> is a maximal <strong>4-directionally</strong> (horizontal or vertical) connected group of <code>1</code>&#39;s.</p>

<p>The grid is said to be <strong>connected</strong> if we have <strong>exactly one island</strong>, otherwise is said <strong>disconnected</strong>.</p>

<p>In one day, we are allowed to change <strong>any </strong>single land cell <code>(1)</code> into a water cell <code>(0)</code>.</p>

<p>Return <em>the minimum number of days to disconnect the grid</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/land1.jpg" style="width: 500px; height: 169px;" />
<pre>
<strong>Input:</strong> grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

<strong>Output:</strong> 2
<strong>Explanation:</strong> We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/land2.jpg" style="width: 404px; height: 85px;" />
<pre>
<strong>Input:</strong> grid = [[1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Grid of full water is also disconnected ([[1,1]] -&gt; [[0,0]]), 0 islands.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const vector<pair<int, int>> MOVES = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
  };
  void dfs(vector<vector<bool>> &seen, const vector<vector<int>> &grid, int rows, int cols, int row, int col) {
    seen[row][col] = true;

    for(auto [dRow, dCol] : MOVES) {
      int newRow = row + dRow;
      int newCol = col + dCol;
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(!grid[newRow][newCol]) continue;
      if(seen[newRow][newCol]) continue;
      dfs(seen, grid, rows, cols, newRow, newCol);
    }
  }
  int countIsland(const vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    vector<vector<bool>> seen(rows, vector<bool>(cols));
    int islands = 0;

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(seen[i][j] || !grid[i][j]) continue;
        islands += 1;
        dfs(seen, grid, rows, cols, i, j);
      }
    }
    return islands;
  }
public:
  int minDays(vector<vector<int>>& grid) {
    if(countIsland(grid) != 1) return 0;
    for(auto &row : grid) {
      for(auto &cell : row) {
        if(!cell) continue;
        cell = 0;
        if(countIsland(grid) != 1) return 1;
        cell = 1;
      }
    }
    return 2;
  }
};
```
