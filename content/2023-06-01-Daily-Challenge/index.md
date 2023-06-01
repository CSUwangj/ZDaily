+++
updated = 2023-06-01T11:09:19+08:00
title = "2023-06-01 Daily Challenge"
path = "2023-06-01-Daily-Challenge"
date = 2023-06-01T11:09:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/shortest-path-in-binary-matrix/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 1

## Description

**Shortest Path in Binary Matrix**

<p>Given an <code>n x n</code> binary matrix <code>grid</code>, return <em>the length of the shortest <strong>clear path</strong> in the matrix</em>. If there is no clear path, return <code>-1</code>.</p>

<p>A <strong>clear path</strong> in a binary matrix is a path from the <strong>top-left</strong> cell (i.e., <code>(0, 0)</code>) to the <strong>bottom-right</strong> cell (i.e., <code>(n - 1, n - 1)</code>) such that:</p>

<ul>
	<li>All the visited cells of the path are <code>0</code>.</li>
	<li>All the adjacent cells of the path are <strong>8-directionally</strong> connected (i.e., they are different and they share an edge or a corner).</li>
</ul>

<p>The <strong>length of a clear path</strong> is the number of visited cells of this path.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example1_1.png" style="width: 500px; height: 234px;" />
<pre>
<strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example2_1.png" style="height: 216px; width: 500px;" />
<pre>
<strong>Input:</strong> grid = [[0,0,0],[1,1,0],[1,1,0]]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,0,0],[1,1,0],[1,1,0]]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j] is 0 or 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid.front().front() || grid.back().back()) return -1;
    int n = grid.size();
    vector<vector<int>> dis(n, vector<int>(n));
    dis[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for(int i = 0; i < 8; ++i) {
        int newRow = row + move[i][0];
        int newCol = col + move[i][1];
        if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol]) continue;
        if(dis[newRow][newCol]) continue;
        dis[newRow][newCol] = dis[row][col] + 1;
        q.push(make_pair(newRow, newCol));
      }
    }
    return dis.back().back() ? dis.back().back() : -1;
  }
};

// Accepted
// 89/89 cases passed (69 ms)
// Your runtime beats 79.27 % of cpp submissions
// Your memory usage beats 61.94 % of cpp submissions (20.9 MB)
```
