+++
updated = 2022-10-30T14:22:44+08:00
title = "2022-10-30 Daily Challenge"
path = "2022-10-30-Daily-Challenge"
date = 2022-10-30T14:22:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 30

## Description

**Shortest Path in a Grid with Obstacles Elimination**

<p>You are given an <code>m x n</code> integer matrix <code>grid</code> where each cell is either <code>0</code> (empty) or <code>1</code> (obstacle). You can move up, down, left, or right from and to an empty cell in <strong>one step</strong>.</p>

<p>Return <em>the minimum number of <strong>steps</strong> to walk from the upper left corner </em><code>(0, 0)</code><em> to the lower right corner </em><code>(m - 1, n - 1)</code><em> given that you can eliminate <strong>at most</strong> </em><code>k</code><em> obstacles</em>. If it is not possible to find such walk return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg" style="width: 244px; height: 405px;" />
<pre>
<strong>Input:</strong> grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1,2) -&gt; (2,2) -&gt; <strong>(3,2)</strong> -&gt; (4,2).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> We need to eliminate at least two obstacles to find such a walk.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> <strong>or</strong> <code>1</code>.</li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 0</code></li>
</ul>


## Solution

``` cpp
const int8_t moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[80][40][40];
struct State {
  int16_t step;
  int8_t rest;
  int8_t row;
  int8_t column;
  State(int16_t step = 0, int8_t rest = 0, int8_t row = 0, int8_t column = 0) : 
    step(step), rest(rest), row(row), column(column) { }
  bool operator<(const State& other) const {
    return step > other.step || (step == other.step && rest < other.rest);
  }
};
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int8_t rows = grid.size();
    int8_t cols = grid.front().size();
    if(k >= rows + cols - 3) return rows + cols - 2;
    memset(vis, 0, sizeof(vis[0]) * (k + 1));
    priority_queue<State> pq;
    pq.push(State(0, k, 0, 0));
    vis[k][0][0] = true;
    while(pq.size()) {
      auto [step, rest, row, col] = pq.top();
      // cout << step << " " << rest << " " << row << " " << col <<endl;
      pq.pop();
      if(row == rows - 1 && col == cols - 1) return step;
      for(int i = 0; i < 4; ++i) {
        int8_t newRow = row + moves[i][0];
        int8_t newCol = col + moves[i][1];
        int8_t newRest = rest;
        if(newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0) continue;
        newRest -= grid[newRow][newCol];
        // cout << newRest << ' ' << newRow << ' ' << newCol <<endl;
        if(newRest < 0 || vis[newRest][newRow][newCol]) {
          continue;
        }
        pq.push(State(step + 1, newRest, newRow, newCol));
        vis[newRest][newRow][newCol] = true;
      }
    }
    return -1;
  }
};

// Accepted
// 52/52 cases passed (10 ms)
// Your runtime beats 98.78 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.9 MB)
```
