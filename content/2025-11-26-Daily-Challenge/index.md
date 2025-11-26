+++
updated = 2025-11-26T23:49:49+01:00
title = "2025-11-26 Daily Challenge"
path = "2025-11-26-Daily-Challenge"
date = 2025-11-26T23:49:49+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 26

## Description

**Paths in Matrix Whose Sum Is Divisible by K**

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>grid</code> and an integer <code>k</code>. You are currently at position <code>(0, 0)</code> and you want to reach position <code>(m - 1, n - 1)</code> moving only <strong>down</strong> or <strong>right</strong>.</p>

<p>Return<em> the number of paths where the sum of the elements on the path is divisible by </em><code>k</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/13/image-20220813183124-1.png" style="width: 437px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/17/image-20220817112930-3.png" style="height: 85px; width: 132px;" />
<pre>
<strong>Input:</strong> grid = [[0,0]], k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/08/12/image-20220812224605-3.png" style="width: 257px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k)));
    dp[0][0][grid[0][0] % k] = 1;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int val = grid[i][j];
        if(i) {
          for(int s = 0; s < k; ++s) {
            dp[i][j][(s + val) % k] += dp[i - 1][j][s];
            dp[i][j][(s + val) % k] %= MOD;
          }
        }
        if(j) {
          for(int s = 0; s < k; ++s) {
            dp[i][j][(s + val) % k] += dp[i][j - 1][s];
            dp[i][j][(s + val) % k] %= MOD;
          }
        }
      }
    }
    return dp.back().back()[0];
  }
};

// Accepted
// 88/88 cases passed (211 ms)
// Your runtime beats 81.18 % of cpp submissions
// Your memory usage beats 79.06 % of cpp submissions (132.1 MB)
```
