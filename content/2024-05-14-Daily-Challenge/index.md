+++
updated = 2024-05-14T12:11:33+08:00
title = "2024-05-14 Daily Challenge"
path = "2024-05-14-Daily-Challenge"
date = 2024-05-14T12:11:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/path-with-maximum-gold/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 14

## Description

**Path with Maximum Gold**

<p>In a gold mine <code>grid</code> of size <code>m x n</code>, each cell in this mine has an integer representing the amount of gold in that cell, <code>0</code> if it is empty.</p>

<p>Return the maximum amount of gold you can collect under the conditions:</p>

<ul>
	<li>Every time you are located in a cell you will collect all the gold in that cell.</li>
	<li>From your position, you can walk one step to the left, right, up, or down.</li>
	<li>You can&#39;t visit the same cell more than once.</li>
	<li>Never visit a cell with <code>0</code> gold.</li>
	<li>You can start and stop collecting gold from <strong>any </strong>position in the grid that has some gold.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,6,0],[5,8,7],[0,9,0]]
<strong>Output:</strong> 24
<strong>Explanation:</strong>
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -&gt; 8 -&gt; 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
<strong>Output:</strong> 28
<strong>Explanation:</strong>
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6 -&gt; 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 15</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li>There are at most <strong>25 </strong>cells containing gold.</li>
</ul>


## Solution

``` cpp
class Solution {
  int rows;
  int cols;
  int dfs(vector<vector<int>>& grid, int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols || !grid[row][col]) return 0;
    int gold = grid[row][col];
    grid[row][col] = 0;

    int result = max({
      dfs(grid, row, col + 1),
      dfs(grid, row, col - 1),
      dfs(grid, row + 1, col),
      dfs(grid, row - 1, col)
    });
    result += gold;
    grid[row][col] = gold;
    return result;
  }
  int allOrNone(vector<vector<int>>& grid) {
    int result = 0;
    for(const auto &row : grid) {
      for(auto n : row) {
        if(!n) return 0;
        result += n;
      }
    }
    return result;
  }
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int all = allOrNone(grid);
    if(all) return all;

    rows = grid.size();
    cols = grid.front().size();

    int answer = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        answer = max(answer, dfs(grid, i, j));
      }
    }

    return answer;
  }
};
```
