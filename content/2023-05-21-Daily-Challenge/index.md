+++
updated = 2023-05-21T12:28:38+08:00
title = "2023-05-21 Daily Challenge"
path = "2023-05-21-Daily-Challenge"
date = 2023-05-21T12:28:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/shortest-bridge/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 21

## Description

**Shortest Bridge**

<p>You are given an <code>n x n</code> binary matrix <code>grid</code> where <code>1</code> represents land and <code>0</code> represents water.</p>

<p>An <strong>island</strong> is a 4-directionally connected group of <code>1</code>&#39;s not connected to any other <code>1</code>&#39;s. There are <strong>exactly two islands</strong> in <code>grid</code>.</p>

<p>You may change <code>0</code>&#39;s to <code>1</code>&#39;s to connect the two islands to form <strong>one island</strong>.</p>

<p>Return <em>the smallest number of </em><code>0</code><em>&#39;s you must flip to connect the two islands</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,1,0],[0,0,0],[0,0,1]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There are exactly two islands in <code>grid</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  using pi = pair<int, int>;
public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pi> q;
    for(int i = 0; i < n && q.empty(); ++i) {
      for(int j = 0; j < n && q.empty(); ++j) {
        if(grid[i][j]) {
          q.push({i, j});
          grid[i][j] = 2;
        }
      }
    }
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      grid[row][col] = 2;
      for(int m = 0; m < 4; ++m) {
        int newRow = row + moves[m][0];
        int newCol = col + moves[m][1];
        if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
        if(grid[newRow][newCol] != 1) continue;
        q.push({newRow, newCol});
        grid[newRow][newCol] = 2;
      }
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    int answer = 0;
    while(q.size()) {
      int s = q.size();
      for(int _ = 0; _ < s; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int m = 0; m < 4; ++m) {
          int newRow = row + moves[m][0];
          int newCol = col + moves[m][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(grid[newRow][newCol] == 2) continue;
          if(grid[newRow][newCol] == 1) return answer;
          q.push({newRow, newCol});
          grid[newRow][newCol] = 2;
        }
      }
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 97/97 cases passed (48 ms)
// Your runtime beats 80.51 % of cpp submissions
// Your memory usage beats 91.3 % of cpp submissions (18.6 MB)
```
