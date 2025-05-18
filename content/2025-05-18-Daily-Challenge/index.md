+++
updated = 2025-05-19T01:31:02+08:00
title = "2025-05-18 Daily Challenge"
path = "2025-05-18-Daily-Challenge"
date = 2025-05-19T01:31:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 18

## Description

**Painting a Grid With Three Different Colors**

<p>You are given two integers <code>m</code> and <code>n</code>. Consider an <code>m x n</code> grid where each cell is initially white. You can paint each cell <strong>red</strong>, <strong>green</strong>, or <strong>blue</strong>. All cells <strong>must</strong> be painted.</p>

<p>Return<em> the number of ways to color the grid with <strong>no two adjacent cells having the same color</strong></em>. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/colorthegrid.png" style="width: 200px; height: 50px;" />
<pre>
<strong>Input:</strong> m = 1, n = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The three possible colorings are shown in the image above.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/copy-of-colorthegrid.png" style="width: 321px; height: 121px;" />
<pre>
<strong>Input:</strong> m = 1, n = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The six possible colorings are shown in the image above.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> m = 5, n = 5
<strong>Output:</strong> 580986
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 5</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int colorTheGrid(int m, int n) {
    int target = pow(3, m);
    vector<vector<int>> pattern(target, vector<int>(m));
    for(int i = 0; i < target; ++i) {
      int current = i;
      for(int col = 0; col < m; ++col) {
        pattern[i][col] = current % 3;
        current /= 3;
      }
    }
    vector<int> validCol;
    for(int i = 0; i < target; ++i) {
      bool ok = true;
      for(int col = 1; col < m && ok; ++col) {
        ok = (pattern[i][col] != pattern[i][col - 1]);
      }
      if(ok) validCol.push_back(i);
    }
    vector<vector<bool>> validAdjacent(target, vector<bool>(target));
    for(auto i : validCol) {
      for(auto j : validCol) {
        bool ok = true;
        for(int col = 0; col < m && ok; ++col) {
          ok = (pattern[i][col] != pattern[j][col]);
        }
        if(ok) validAdjacent[i][j] = true;
      }
    }

    vector<vector<int>> dp(2, vector<int>(target, 1));
    for(int col = 2; col <= n; ++col) {
      int parity = col & 1;
      for(auto i : validCol) {
        dp[parity][i] = 0;
        for(auto j : validCol) {
          if(!validAdjacent[i][j]) continue; 
          dp[parity][i] += dp[!parity][j];
          dp[parity][i] %= MOD;
        }
      }
    }
    int answer = 0;
    for(auto i : validCol) {
      answer += dp[n & 1][i];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 84/84 cases passed (72 ms)
// Your runtime beats 48.9 % of cpp submissions
// Your memory usage beats 85.16 % of cpp submissions (10.1 MB)
```
