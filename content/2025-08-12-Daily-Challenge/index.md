+++
updated = 2025-08-13T05:04:20+08:00
title = "2025-08-12 Daily Challenge"
path = "2025-08-12-Daily-Challenge"
date = 2025-08-13T05:04:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 12

## Description

**Ways to Express an Integer as Sum of Powers**

<p>Given two <strong>positive</strong> integers <code>n</code> and <code>x</code>.</p>

<p>Return <em>the number of ways </em><code>n</code><em> can be expressed as the sum of the </em><code>x<sup>th</sup></code><em> power of <strong>unique</strong> positive integers, in other words, the number of sets of unique integers </em><code>[n<sub>1</sub>, n<sub>2</sub>, ..., n<sub>k</sub>]</code><em> where </em><code>n = n<sub>1</sub><sup>x</sup> + n<sub>2</sub><sup>x</sup> + ... + n<sub>k</sub><sup>x</sup></code><em>.</em></p>

<p>Since the result can be very large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>For example, if <code>n = 160</code> and <code>x = 3</code>, one way to express <code>n</code> is <code>n = 2<sup>3</sup> + 3<sup>3</sup> + 5<sup>3</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10, x = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can express n as the following: n = 3<sup>2</sup> + 1<sup>2</sup> = 10.
It can be shown that it is the only way to express 10 as the sum of the 2<sup>nd</sup> power of unique integers.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4, x = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can express n in the following ways:
- n = 4<sup>1</sup> = 4.
- n = 3<sup>1</sup> + 1<sup>1</sup> = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>1 &lt;= x &lt;= 5</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
  int solve(int pos, int rest, vector<vector<int>> &dp, const vector<int> &powers) {
    if(!rest) return 1;
    if(pos < 0) return 0;
    if(dp[pos][rest] != -1) return dp[pos][rest];
    dp[pos][rest] = 0;
    for(int i = pos; i >= 0; --i) {
      if(powers[i] > rest) continue;
      dp[pos][rest] += solve(i - 1, rest - powers[i], dp, powers);
      dp[pos][rest] %= MOD;
    }
    return dp[pos][rest];
  }
public:
  int numberOfWays(int n, int x) {
    vector<int> powers;
    for(int i = 1; pow(i, x) < n + 1; ++i) {
      powers.push_back(pow(i, x));
    }
    int len = powers.size();
    vector<vector<int>> dp(len, vector<int>(n + 1, -1));
    return solve(len - 1, n, dp, powers);
  }
};

// Accepted
// 1502/1502 cases passed (646 ms)
// Your runtime beats 14.16 % of cpp submissions
// Your memory usage beats 59.48 % of cpp submissions (72.1 MB)
```
