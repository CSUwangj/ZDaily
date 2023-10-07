+++
updated = 2023-10-07T21:12:17+08:00
title = "2023-10-07 Daily Challenge"
path = "2023-10-07-Daily-Challenge"
date = 2023-10-07T21:12:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 7

## Description

**Build Array Where You Can Find The Maximum Exactly K Comparisons**

<p>You are given three integers <code>n</code>, <code>m</code> and <code>k</code>. Consider the following algorithm to find the maximum element of an array of positive integers:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/02/e.png" style="width: 424px; height: 372px;" />
<p>You should build the array arr which has the following properties:</p>

<ul>
	<li><code>arr</code> has exactly <code>n</code> integers.</li>
	<li><code>1 &lt;= arr[i] &lt;= m</code> where <code>(0 &lt;= i &lt; n)</code>.</li>
	<li>After applying the mentioned algorithm to <code>arr</code>, the value <code>search_cost</code> is equal to <code>k</code>.</li>
</ul>

<p>Return <em>the number of ways</em> to build the array <code>arr</code> under the mentioned conditions. As the answer may grow large, the answer <strong>must be</strong> computed modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2, m = 3, k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5, m = 2, k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no possible arrays that satisify the mentioned conditions.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 9, m = 1, k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;
    int dp[51][101][51] = {};
    int pre[51][101][51] = {};
    for(int i = 0; i <= m; ++i) {
      dp[1][i][1] = 1;
      pre[1][i][1] = i;
    }

    for(int len = 2; len <= n; ++len) {
      for(int mmax = 1; mmax <= m; ++mmax) {
        for(int cost = 1; cost <= k; ++cost) {
          dp[len][mmax][cost] = (1LL * mmax * dp[len - 1][mmax][cost]) % MOD;
          
          dp[len][mmax][cost] += pre[len - 1][mmax - 1][cost - 1];
          dp[len][mmax][cost] %= MOD;

          pre[len][mmax][cost] = pre[len][mmax - 1][cost] + dp[len][mmax][cost];
          pre[len][mmax][cost] %= MOD;
        }
      }
    }

    return pre[n][m][k];
  }
};

// Accepted
// 28/28 cases passed (3 ms)
// Your runtime beats 98.62 % of cpp submissions
// Your memory usage beats 43.32 % of cpp submissions (8.5 MB)
```
