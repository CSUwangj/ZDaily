+++
updated = 2025-05-22T01:43:54+08:00
title = "2025-05-21 Daily Challenge"
path = "2025-05-21-Daily-Challenge"
date = 2025-05-22T01:43:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/set-matrix-zeroes/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 21

## Description

**Set Matrix Zeroes**

<p>Given an <code>m x n</code> integer matrix <code>matrix</code>, if an element is <code>0</code>, set its entire row and column to <code>0</code>&#39;s.</p>

<p>You must do it <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg" style="width: 450px; height: 169px;" />
<pre>
<strong>Input:</strong> matrix = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> [[1,0,1],[0,0,0],[1,0,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg" style="width: 450px; height: 137px;" />
<pre>
<strong>Input:</strong> matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
<strong>Output:</strong> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-2<sup>31</sup> &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>A straightforward solution using <code>O(mn)</code> space is probably a bad idea.</li>
	<li>A simple improvement uses <code>O(m + n)</code> space, but still not the best solution.</li>
	<li>Could you devise a constant space solution?</li>
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
  void setZeroes(vector<vector<int>>& matrix) {
    bool firstRow = false;
    bool firstCol = false;
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 0; i < rows; ++i) {
      if(!matrix[i][0]) firstCol = true;
    }
    for(int i = 0; i < cols; ++i) {
      if(!matrix[0][i]) firstRow = true;
    }
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for(int i = 1; i < rows; ++i) {
      if(!matrix[i][0]) {
        for(int j = 1; j < cols; ++j) {
          matrix[i][j] = 0;
        }
      }
    }
    for(int i = 1; i < cols; ++i) {
      if(!matrix[0][i]) {
        for(int j = 1; j < rows; ++j) {
          matrix[j][i] = 0;
        }
      }
    }
    if(firstCol) {
      for(int j = 0; j < rows; ++j) {
        matrix[j][0] = 0;
      }
    }
    if(firstRow) {
      for(int j = 0; j < cols; ++j) {
        matrix[0][j] = 0;
      }
    }
  }
};

// Accepted
// 202/202 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.14 % of cpp submissions (18.6 MB)
```
