+++
updated = 2024-04-18T13:12:26+08:00
title = "2024-04-18 Daily Challenge"
path = "2024-04-18-Daily-Challenge"
date = 2024-04-18T13:12:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/island-perimeter/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 18

## Description

**Island Perimeter**

<p>You are given <code>row x col</code> <code>grid</code> representing a map where <code>grid[i][j] = 1</code> represents&nbsp;land and <code>grid[i][j] = 0</code> represents water.</p>

<p>Grid cells are connected <strong>horizontally/vertically</strong> (not diagonally). The <code>grid</code> is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).</p>

<p>The island doesn&#39;t have &quot;lakes&quot;, meaning the water inside isn&#39;t connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don&#39;t exceed 100. Determine the perimeter of the island.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/island.png" style="width: 221px; height: 213px;" />
<pre>
<strong>Input:</strong> grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The perimeter is the 16 yellow stripes in the image above.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1]]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,0]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 &lt;= row, col &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li>There is exactly one island in <code>grid</code>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    int answer = 0;

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(j != cols - 1 && grid[i][j] != grid[i][j + 1]) {
          answer += 1;
        }
        if(i != rows - 1 && grid[i][j] != grid[i + 1][j]) {
          answer += 1;
        }
      }
    }
    for(int i = 0; i < rows; ++i) {
      answer += grid[i][0];
      answer += grid[i][cols - 1];
    }
    for(int i = 0; i < cols; ++i) {
      answer += grid[0][i];
      answer += grid[rows - 1][i];
    }

    return answer;
  }
};

// Accepted
// 5833/5833 cases passed (119 ms)
// Your runtime beats 38.48 % of cpp submissions
// Your memory usage beats 58.06 % of cpp submissions (96.2 MB)
```
