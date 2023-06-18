+++
updated = 2023-06-18T20:45:34+08:00
title = "2023-06-18 Daily Challenge"
path = "2023-06-18-Daily-Challenge"
date = 2023-06-18T20:45:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 18

## Description

**Number of Increasing Paths in a Grid**

<p>You are given an <code>m x n</code> integer matrix <code>grid</code>, where you can move from a cell to any adjacent cell in all <code>4</code> directions.</p>

<p>Return <em>the number of <strong>strictly</strong> <strong>increasing</strong> paths in the grid such that you can start from <strong>any</strong> cell and end at <strong>any</strong> cell. </em>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Two paths are considered different if they do not have exactly the same sequence of visited cells.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/10/griddrawio-4.png" style="width: 181px; height: 121px;" />
<pre>
<strong>Input:</strong> grid = [[1,1],[3,4]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -&gt; 3], [1 -&gt; 4], [3 -&gt; 4].
- Paths with length 3: [1 -&gt; 3 -&gt; 4].
The total number of paths is 4 + 3 + 1 = 8.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1],[2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -&gt; 2].
The total number of paths is 2 + 1 = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int rows;
  int cols;
  int solve(
    int row,
    int col,
    int parent,
    const vector<vector<int>>& grid,
    vector<vector<int>> &dp
  ) {
    if(row < 0 || row >= rows) return 0;
    if(col < 0 || col >= cols) return 0;
    if(grid[row][col] <= parent) return 0;
    if(dp[row][col] != -1) return dp[row][col];

    int result = 1;
    for(int m = 0; m < 4; ++m) {
      int newRow = row + MOVES[m][0];
      int newCol = col + MOVES[m][1];
      result += solve(newRow, newCol, grid[row][col], grid, dp);
      result %= MOD;
    }
    dp[row][col] = result;
    return result;
  }
public:
  int countPaths(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid.front().size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(dp[r][c] == -1) solve(r, c, -1, grid, dp);
      }
    }

    int answer = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        answer += dp[r][c];
        answer %= MOD;
      }
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (292 ms)
// Your runtime beats 75.49 % of cpp submissions
// Your memory usage beats 80.56 % of cpp submissions (43.4 MB)
```
