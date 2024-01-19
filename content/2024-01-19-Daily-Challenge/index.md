+++
updated = 2024-01-19T16:46:07+08:00
title = "2024-01-19 Daily Challenge"
path = "2024-01-19-Daily-Challenge"
date = 2024-01-19T16:46:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimum-falling-path-sum/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 19

## Description

**Minimum Falling Path Sum**

<p>Given an <code>n x n</code> array of integers <code>matrix</code>, return <em>the <strong>minimum sum</strong> of any <strong>falling path</strong> through</em> <code>matrix</code>.</p>

<p>A <strong>falling path</strong> starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position <code>(row, col)</code> will be <code>(row + 1, col - 1)</code>, <code>(row + 1, col)</code>, or <code>(row + 1, col + 1)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg" style="width: 499px; height: 500px;" />
<pre>
<strong>Input:</strong> matrix = [[2,1,3],[6,5,4],[7,8,9]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> There are two falling paths with a minimum sum as shown.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg" style="width: 164px; height: 365px;" />
<pre>
<strong>Input:</strong> matrix = [[-19,57],[-40,-5]]
<strong>Output:</strong> -59
<strong>Explanation:</strong> The falling path with a minimum sum is shown.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int lastSum = INT_MAX;
        for(int k = max(0, j - 1); k < min(cols, j + 2); ++k) {
          lastSum = min(lastSum, matrix[i - 1][k]);
        }
        matrix[i][j] += lastSum;
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};

// Accepted
// 50/50 cases passed (14 ms)
// Your runtime beats 45.08 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (12.4 MB)
```
