+++
updated = 2025-10-06T00:18:17+02:00
title = "2025-10-05 Daily Challenge"
path = "2025-10-05-Daily-Challenge"
date = 2025-10-06T00:18:17+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/pacific-atlantic-water-flow/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 5

## Description

**Pacific Atlantic Water Flow**

<p>There is an <code>m x n</code> rectangular island that borders both the <strong>Pacific Ocean</strong> and <strong>Atlantic Ocean</strong>. The <strong>Pacific Ocean</strong> touches the island&#39;s left and top edges, and the <strong>Atlantic Ocean</strong> touches the island&#39;s right and bottom edges.</p>

<p>The island is partitioned into a grid of square cells. You are given an <code>m x n</code> integer matrix <code>heights</code> where <code>heights[r][c]</code> represents the <strong>height above sea level</strong> of the cell at coordinate <code>(r, c)</code>.</p>

<p>The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell&#39;s height is <strong>less than or equal to</strong> the current cell&#39;s height. Water can flow from any cell adjacent to an ocean into the ocean.</p>

<p>Return <em>a <strong>2D list</strong> of grid coordinates </em><code>result</code><em> where </em><code>result[i] = [r<sub>i</sub>, c<sub>i</sub>]</code><em> denotes that rain water can flow from cell </em><code>(r<sub>i</sub>, c<sub>i</sub>)</code><em> to <strong>both</strong> the Pacific and Atlantic oceans</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg" style="width: 400px; height: 400px;" />
<pre>
<strong>Input:</strong> heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
<strong>Output:</strong> [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
<strong>Explanation:</strong> The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -&gt; Pacific Ocean 
&nbsp;      [0,4] -&gt; Atlantic Ocean
[1,3]: [1,3] -&gt; [0,3] -&gt; Pacific Ocean 
&nbsp;      [1,3] -&gt; [1,4] -&gt; Atlantic Ocean
[1,4]: [1,4] -&gt; [1,3] -&gt; [0,3] -&gt; Pacific Ocean 
&nbsp;      [1,4] -&gt; Atlantic Ocean
[2,2]: [2,2] -&gt; [1,2] -&gt; [0,2] -&gt; Pacific Ocean 
&nbsp;      [2,2] -&gt; [2,3] -&gt; [2,4] -&gt; Atlantic Ocean
[3,0]: [3,0] -&gt; Pacific Ocean 
&nbsp;      [3,0] -&gt; [4,0] -&gt; Atlantic Ocean
[3,1]: [3,1] -&gt; [3,0] -&gt; Pacific Ocean 
&nbsp;      [3,1] -&gt; [4,1] -&gt; Atlantic Ocean
[4,0]: [4,0] -&gt; Pacific Ocean 
       [4,0] -&gt; Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> heights = [[1]]
<strong>Output:</strong> [[0,0]]
<strong>Explanation:</strong> The water can flow from the only cell to the Pacific and Atlantic oceans.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == heights.length</code></li>
	<li><code>n == heights[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heights[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
  int rows;
  int cols;
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col) {
    if(vis[row][col]) return;
    vis[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(heights[row][col] > heights[newRow][newCol]) continue;
      dfs(heights, vis, newRow, newCol);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> answer;
    if(heights.empty() || heights.front().empty()) return answer;
    rows = heights.size();
    cols = heights.front().size();
    vector<vector<bool>> visPac(rows, vector<bool>(cols));
    vector<vector<bool>> visAtl(rows, vector<bool>(cols));
    
    for(int i = 0; i < cols; ++i) {
      dfs(heights, visPac, 0, i);
      dfs(heights, visAtl, rows - 1, i);
    }
    for(int i = 0; i < rows; ++i) {
      dfs(heights, visPac, i, 0);
      dfs(heights, visAtl, i, cols - 1);
    }
    
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(visPac[i][j] && visAtl[i][j]) answer.push_back({i, j});
      }
    }
    
    return answer;
  }
};

// Accepted
// 114/114 cases passed (3 ms)
// Your runtime beats 88.44 % of cpp submissions
// Your memory usage beats 82.45 % of cpp submissions (22.2 MB)
```
