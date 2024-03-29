+++
updated = 2023-12-26T12:10:59+08:00
title = "2023-12-26 Daily Challenge"
path = "2023-12-26-Daily-Challenge"
date = 2023-12-26T12:10:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 26

## Description

**Number of Dice Rolls With Target Sum**

<p>You have <code>n</code> dice, and each die has <code>k</code> faces numbered from <code>1</code> to <code>k</code>.</p>

<p>Given three integers <code>n</code>, <code>k</code>, and <code>target</code>, return <em>the number of possible ways (out of the </em><code>k<sup>n</sup></code><em> total ways) </em><em>to roll the dice, so the sum of the face-up numbers equals </em><code>target</code>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 6, target = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> You throw one die with 6 faces.
There is only one way to get a sum of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 6, target = 7
<strong>Output:</strong> 6
<strong>Explanation:</strong> You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 30, k = 30, target = 500
<strong>Output:</strong> 222616187
<strong>Explanation:</strong> The answer must be returned modulo 10<sup>9</sup> + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
int dp[2][1001];
const int MOD = 1e9 + 7;
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    if(d * f < target || d > target) return 0;
    if(d == target) return 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= d; ++i) {
      int parity = i & 1;
      for(int j = 0; j < i; ++j) {
        dp[parity][j] = 0;
      }
      for(int j = i; j <= i * f; ++j) {
        dp[parity][j] = 0;
        for(int k = 1; k <= f; ++k) {
          if(j - k < 0) continue;
          dp[parity][j] += dp[!parity][j - k];
          dp[parity][j] %= MOD;
        }
      }
      // for(int j = 0; j <= i * f; ++j) {
      //   cout << dp[parity][j] << ' ';
      // }
      // cout << endl;
    }
    return dp[d & 1][target];
  }
};

// Accepted
// 65/65 cases passed (0 ms)
// Your runtime beats 100.00 % of cpp submissions
// Your memory usage beats 99.60 % of cpp submissions (5.9 MB)
```
