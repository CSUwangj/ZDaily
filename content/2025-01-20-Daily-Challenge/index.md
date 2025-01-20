+++
updated = 2025-01-20T16:14:32+08:00
title = "2025-01-20 Daily Challenge"
path = "2025-01-20-Daily-Challenge"
date = 2025-01-20T16:14:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/first-completely-painted-row-or-column/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 20

## Description

**First Completely Painted Row or Column**

<p>You are given a <strong>0-indexed</strong> integer array <code>arr</code>, and an <code>m x n</code> integer <strong>matrix</strong> <code>mat</code>. <code>arr</code> and <code>mat</code> both contain <strong>all</strong> the integers in the range <code>[1, m * n]</code>.</p>

<p>Go through each index <code>i</code> in <code>arr</code> starting from index <code>0</code> and paint the cell in <code>mat</code> containing the integer <code>arr[i]</code>.</p>

<p>Return <em>the smallest index</em> <code>i</code> <em>at which either a row or a column will be completely painted in</em> <code>mat</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="image explanation for example 1" /><img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;" />
<pre>
<strong>Input:</strong> arr = [1,3,4,2], mat = [[1,4],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;" />
<pre>
<strong>Input:</strong> arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The second column becomes fully painted at arr[3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n = mat[i].length</code></li>
	<li><code>arr.length == m * n</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], mat[r][c] &lt;= m * n</code></li>
	<li>All the integers of <code>arr</code> are <strong>unique</strong>.</li>
	<li>All the integers of <code>mat</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<int> rowCount(rows), colCount(cols);
    vector<pair<int, int>> pos(rows * cols + 1);
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        pos[mat[r][c]].first = r;
        pos[mat[r][c]].second = c;
      }
    }
    for(int i = 0; i < arr.size(); ++i) {
      auto [r, c] = pos[arr[i]];
      rowCount[r] += 1;
      colCount[c] += 1;
      if(rowCount[r] == cols || colCount[c] == rows) return i;
    }
    return -1;
  }
};

// Accepted
// 1058/1058 cases passed (8 ms)
// Your runtime beats 87.2 % of cpp submissions
// Your memory usage beats 91.77 % of cpp submissions (133.9 MB)
```
