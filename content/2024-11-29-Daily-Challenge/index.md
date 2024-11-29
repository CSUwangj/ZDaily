+++
updated = 2024-11-29T13:26:07+08:00
title = "2024-11-29 Daily Challenge"
path = "2024-11-29-Daily-Challenge"
date = 2024-11-29T13:26:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 29

## Description

**Minimum Time to Visit a Cell In a Grid**

<p>You are given a <code>m x n</code> matrix <code>grid</code> consisting of <b>non-negative</b> integers where <code>grid[row][col]</code> represents the <strong>minimum</strong> time required to be able to visit the cell <code>(row, col)</code>, which means you can visit the cell <code>(row, col)</code> only when the time you visit it is greater than or equal to <code>grid[row][col]</code>.</p>

<p>You are standing in the <strong>top-left</strong> cell of the matrix in the <code>0<sup>th</sup></code> second, and you must move to <strong>any</strong> adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.</p>

<p>Return <em>the <strong>minimum</strong> time required in which you can visit the bottom-right cell of the matrix</em>. If you cannot visit the bottom-right cell, then return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/02/14/yetgriddrawio-8.png" /></p>

<pre>
<strong>Input:</strong> grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] &lt;= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] &lt;= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] &lt;= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] &lt;= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] &lt;= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] &lt;= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] &lt;= 7.
The final time is 7. It can be shown that it is the minimum time possible.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/02/14/yetgriddrawio-9.png" style="width: 151px; height: 151px;" /></p>

<pre>
<strong>Input:</strong> grid = [[0,2,4],[3,2,1],[1,0,4]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no path from the top left to the bottom-right cell.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[0][0] == 0</code></li>
</ul>

<p>&nbsp;</p>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
  static constexpr int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
public:
  int minimumTime(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
    map<int, int> times;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(pq.size()) {
      auto [time, pos] = pq.top();
      pq.pop();
      if(times.count(pos)) continue;
      times[pos] = time;
      int row = pos / cols;
      int col = pos % cols;
      for(int i = 0; i < 4; ++i) {
        int newCol = col + MOVES[i][0];
        int newRow = row + MOVES[i][1];
        if(newCol < 0 || newRow < 0 || newRow >= rows || newCol >= cols) continue;
        int newPos = newRow * cols + newCol;
        if(times.count(newPos)) continue;
        int newTime = grid[newRow][newCol] > time + 1 ? 1 - (grid[newRow][newCol] - time) % 2 + grid[newRow][newCol]: time + 1;
        pq.push({newTime, newPos});
      }
    }

    return times[rows * cols - 1];
  }
};
```
