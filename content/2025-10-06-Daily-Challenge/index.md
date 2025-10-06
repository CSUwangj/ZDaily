+++
updated = 2025-10-06T20:39:20+02:00
title = "2025-10-06 Daily Challenge"
path = "2025-10-06-Daily-Challenge"
date = 2025-10-06T20:39:20+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/swim-in-rising-water/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 6

## Description

**Swim in Rising Water**

<p>You are given an <code>n x n</code> integer matrix <code>grid</code> where each value <code>grid[i][j]</code> represents the elevation at that point <code>(i, j)</code>.</p>

<p>It starts raining, and water gradually rises over time. At time <code>t</code>, the water level is <code>t</code>, meaning <strong>any</strong> cell with elevation less than equal to <code>t</code> is submerged or reachable.</p>

<p>You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most <code>t</code>. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.</p>

<p>Return <em>the minimum time until you can reach the bottom right square </em><code>(n - 1, n - 1)</code><em> if you start at the top left square </em><code>(0, 0)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[0,2],[1,3]]
<strong>Output:</strong> 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg" style="width: 404px; height: 405px;" />
<pre>
<strong>Input:</strong> grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;&nbsp;n<sup>2</sup></code></li>
	<li>Each value <code>grid[i][j]</code> is <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
using ti = tuple<int, int, int>;
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int size = grid.size();
    int maxTime = size * size - 1;
    if(grid.front().front() == maxTime || grid.back().back() == maxTime) return maxTime;
    vector<vector<bool>> vis(size, vector<bool>(size));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = true;
    while(pq.size()) {
      auto [time, row, col] = pq.top();
      pq.pop();
      if(row == size - 1 && col == size - 1) return time;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) continue;
        if(vis[newRow][newCol]) continue;
        vis[newRow][newCol] = true;
        pq.push({max(time, grid[newRow][newCol]), newRow, newCol});
      }
    }
    return -1;
  }
};

// Accepted
// 43/43 cases passed (6 ms)
// Your runtime beats 66.95 % of cpp submissions
// Your memory usage beats 57.21 % of cpp submissions (13.8 MB)
```
