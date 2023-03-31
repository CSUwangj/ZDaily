+++
updated = 2023-03-31T13:07:06+08:00
title = "2023-03-31 Daily Challenge"
path = "2023-03-31-Daily-Challenge"
date = 2023-03-31T13:07:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 31

## Description

**Number of Ways of Cutting a Pizza**

<p>Given a rectangular pizza represented as a <code>rows x cols</code>&nbsp;matrix containing the following characters: <code>&#39;A&#39;</code> (an apple) and <code>&#39;.&#39;</code> (empty cell) and given the integer <code>k</code>. You have to cut the pizza into <code>k</code> pieces using <code>k-1</code> cuts.&nbsp;</p>

<p>For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.</p>

<p><em>Return the number of ways of cutting the pizza such that each piece contains <strong>at least</strong> one apple.&nbsp;</em>Since the answer can be a huge number, return this modulo 10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/ways_to_cut_apple_1.png" style="width: 500px; height: 378px;" /></strong></p>

<pre>
<strong>Input:</strong> pizza = [&quot;A..&quot;,&quot;AAA&quot;,&quot;...&quot;], k = 3
<strong>Output:</strong> 3 
<strong>Explanation:</strong> The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pizza = [&quot;A..&quot;,&quot;AA.&quot;,&quot;...&quot;], k = 3
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> pizza = [&quot;A..&quot;,&quot;A..&quot;,&quot;...&quot;], k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 50</code></li>
	<li><code>rows ==&nbsp;pizza.length</code></li>
	<li><code>cols ==&nbsp;pizza[i].length</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>pizza</code> consists of characters <code>&#39;A&#39;</code>&nbsp;and <code>&#39;.&#39;</code> only.</li>
</ul>

## Solution

``` cpp
class Solution {
  int dp[10][50][50];
  int prefixSum[51][51] = {};
  int rows;
  int cols;
  const int MOD = 1e9 + 7;
public:
  int ways(vector<string>& pizza, int k) {
    rows = pizza.size();
    cols = pizza.front().size();
    memset(dp, -1, k * sizeof(dp[0]));
    for(int row = rows - 1; row >= 0; --row) {
      for(int col = cols - 1; col >= 0; --col) {
        prefixSum[row][col] = prefixSum[row][col + 1] + prefixSum[row + 1][col] - prefixSum[row + 1][col + 1] + (pizza[row][col] == 'A');
      }
    }

    return solve(k - 1, 0, 0);
  }

  int solve(int k, int row, int col) {
    if(!prefixSum[row][col]) return 0;
    if(k == 0) return 1;
    if(dp[k][row][col] != -1) return dp[k][row][col];
    int result = 0;
    for(int newRow = row + 1; newRow < rows; ++newRow) {
      if(prefixSum[row][col] - prefixSum[newRow][col] > 0){
        result += solve(k - 1, newRow, col);
        result %= MOD;
      }
    }
    for(int newCol = col + 1; newCol < cols; ++newCol) {
      if(prefixSum[row][col] - prefixSum[row][newCol] > 0) {
        result += solve(k - 1, row, newCol);
        result %= MOD;
      }
    }
    dp[k][row][col] = result;
    return result;
  }
};

// Accepted
// 53/53 cases passed (7 ms)
// Your runtime beats 98.95 % of cpp submissions
// Your memory usage beats 94.5 % of cpp submissions (7.6 MB)
```
