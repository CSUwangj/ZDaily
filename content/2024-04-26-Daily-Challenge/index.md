+++
updated = 2024-04-26T19:12:44+08:00
title = "2024-04-26 Daily Challenge"
path = "2024-04-26-Daily-Challenge"
date = 2024-04-26T19:12:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/minimum-falling-path-sum-ii/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 26

## Description

**Minimum Falling Path Sum II**

<p>Given an <code>n x n</code> integer matrix <code>grid</code>, return <em>the minimum sum of a <strong>falling path with non-zero shifts</strong></em>.</p>

<p>A <strong>falling path with non-zero shifts</strong> is a choice of exactly one element from each row of <code>grid</code> such that no two elements chosen in adjacent rows are in the same column.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is&nbsp;[1,5,7], so the answer is&nbsp;13.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[7]]
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-99 &lt;= grid[i][j] &lt;= 99</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    vector<int> minimum = {0, 0};
    int minIndex = -1;
    int cols = grid.front().size();
    for(const auto &row : grid) {
      // cout << minimum[0] << ' ' << minimum[1] << ' ' << minIndex << endl;
      int newIndex = -1;
      vector<int> newMinimum = {INT_MAX, INT_MAX};
      for(int j = 0; j < cols; ++j) {
        int mmin = row[j] + minimum[j == minIndex];
        if(mmin < newMinimum[0]) {
          newMinimum[1] = newMinimum[0];
          newMinimum[0] = mmin;
          newIndex = j;
        } else if(mmin < newMinimum[1]) {
          newMinimum[1] = mmin;
        }
      }
      swap(minimum, newMinimum);
      minIndex = newIndex;
    }
    return minimum[0];
  }
};
```
