+++
updated = 2024-01-26T15:49:28+08:00
title = "2024-01-26 Daily Challenge"
path = "2024-01-26-Daily-Challenge"
date = 2024-01-26T15:49:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/out-of-boundary-paths/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 26

## Description

**Out of Boundary Paths**

<p>There is an <code>m x n</code> grid with a ball. The ball is initially at the position <code>[startRow, startColumn]</code>. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply <strong>at most</strong> <code>maxMove</code> moves to the ball.</p>

<p>Given the five integers <code>m</code>, <code>n</code>, <code>maxMove</code>, <code>startRow</code>, <code>startColumn</code>, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png" style="width: 500px; height: 296px;" />
<pre>
<strong>Input:</strong> m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png" style="width: 500px; height: 293px;" />
<pre>
<strong>Input:</strong> m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>


## Solution

``` cpp
const int SZ = 50;
const int MOD = 1e9 + 7;
int path[2][SZ][SZ];
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(path[0], 0, sizeof(path[0]));
    path[0][startRow][startColumn] = 1;
    int result = 0;
    for(int cnt = 0; cnt < maxMove; cnt++) {
      int parity = cnt & 1;
      memset(path[!parity], 0, sizeof(path[0]));
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          // cout << path[parity][i][j] << ' ' ;
          for(int c = 0; c < 4; ++c) {
            int newRow = i + moves[c][0];
            int newCol = j + moves[c][1];
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
            path[!parity][newRow][newCol] += path[parity][i][j];
            path[!parity][newRow][newCol] %= MOD;
          }
        }
        // cout << endl;
      }
      // cout << endl;
      for(int i = 0; i < m; ++i) {
        result += path[parity][i][0];
        result %= MOD;
        result += path[parity][i][n - 1];
        result %= MOD;
      }
      for(int i = 0; i < n; ++i) {
        result += path[parity][0][i];
        result %= MOD;
        result += path[parity][m - 1][i];
        result %= MOD;
      }
    }
    return result;
  }
};

// Accepted
// 94/94 cases passed (8 ms)
// Your runtime beats 84.71 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (5.8 MB)
```
