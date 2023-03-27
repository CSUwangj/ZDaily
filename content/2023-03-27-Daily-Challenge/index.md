+++
updated = 2023-03-27T13:07:14+08:00
title = "2023-03-27 Daily Challenge"
path = "2023-03-27-Daily-Challenge"
date = 2023-03-27T13:07:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-path-sum/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 27

## Description

**Minimum Path Sum**

<p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
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
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int dp[2][cols];
    for(int i = 0; i < cols; ++i) {
      dp[0][i] = grid[0][i];
      if(i) dp[0][i] += dp[0][i - 1];
    }
    for(int i = 1; i < rows; ++i) {
      int parity = (i & 1);
      dp[parity][0] = dp[!parity][0] + grid[i][0];
      for(int j = 1; j < cols; ++j) {
        dp[parity][j] = min(dp[!parity][j], dp[parity][j - 1]) + grid[i][j];
      }
    }
    return dp[!(rows & 1)][cols - 1];
  }
};

// Accepted
// 61/61 cases passed (3 ms)
// Your runtime beats 99.49 % of cpp submissions
// Your memory usage beats 82.48 % of cpp submissions (9.7 MB)
```
