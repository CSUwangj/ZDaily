+++
updated = 2025-08-28T20:14:07+02:00
title = "2025-08-28 Daily Challenge"
path = "2025-08-28-Daily-Challenge"
date = 2025-08-28T20:14:07+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/sort-matrix-by-diagonals/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 28

## Description

**Sort Matrix by Diagonals**

<p>You are given an <code>n x n</code> square matrix of integers <code>grid</code>. Return the matrix such that:</p>

<ul>
	<li>The diagonals in the <strong>bottom-left triangle</strong> (including the middle diagonal) are sorted in <strong>non-increasing order</strong>.</li>
	<li>The diagonals in the <strong>top-right triangle</strong> are sorted in <strong>non-decreasing order</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,7,3],[9,8,2],[4,5,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[8,2,3],[9,6,7],[4,5,1]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example1drawio.png" style="width: 461px; height: 181px;" /></p>

<p>The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:</p>

<ul>
	<li><code>[1, 8, 6]</code> becomes <code>[8, 6, 1]</code>.</li>
	<li><code>[9, 5]</code> and <code>[4]</code> remain unchanged.</li>
</ul>

<p>The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:</p>

<ul>
	<li><code>[7, 2]</code> becomes <code>[2, 7]</code>.</li>
	<li><code>[3]</code> remains unchanged.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,1],[1,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[2,1],[1,0]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example2adrawio.png" style="width: 383px; height: 141px;" /></p>

<p>The diagonals with a black arrow must be non-increasing, so <code>[0, 2]</code> is changed to <code>[2, 0]</code>. The other diagonals are already in the correct order.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[1]]</span></p>

<p><strong>Explanation:</strong></p>

<p>Diagonals with exactly one element are already in order, so no changes are needed.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>grid.length == grid[i].length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>-10<sup>5</sup> &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    vector<int> countainer;
    int n = grid.size();
    for(int i = 0; i < n - 1; ++i) {
      int row = 0;
      int col = n - 1 - i;
      for(int j = 0; col + j < n; ++j) {
        countainer.push_back(grid[row + j][col + j]);
      }
      sort(countainer.begin(), countainer.end());
      for(int j = 0; col + j < n; ++j) {
        grid[row + j][col + j] = countainer[j];
      }
      countainer.clear();
    }
    for(int i = 0; i < n; ++i) {
      int row = i;
      int col = 0;
      for(int j = 0; row + j < n; ++j) {
        countainer.push_back(grid[row + j][col + j]);
      }
      sort(countainer.begin(), countainer.end(), greater<int>());
      for(int j = 0; row + j < n; ++j) {
        grid[row + j][col + j] = countainer[j];
      }
      countainer.clear();
    }
    return grid;
  }
};

// Accepted
// 1306/1306 cases passed (8 ms)
// Your runtime beats 66.46 % of cpp submissions
// Your memory usage beats 93.21 % of cpp submissions (41.9 MB)
```
