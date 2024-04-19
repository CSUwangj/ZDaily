+++
updated = 2024-04-19T13:32:09+08:00
title = "2024-04-19 Daily Challenge"
path = "2024-04-19-Daily-Challenge"
date = 2024-04-19T13:32:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/number-of-islands/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 19

## Description

**Number of Islands**

<p>Given an <code>m x n</code> 2D binary grid <code>grid</code> which represents a map of <code>&#39;1&#39;</code>s (land) and <code>&#39;0&#39;</code>s (water), return <em>the number of islands</em>.</p>

<p>An <strong>island</strong> is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> grid = [
  [&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;0&quot;],
  [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;],
  [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
  [&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;]
]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [
  [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
  [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
  [&quot;0&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;],
  [&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;1&quot;,&quot;1&quot;]
]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>grid[i][j]</code> is <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


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
