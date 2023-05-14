+++
updated = 2023-05-14T14:54:45+08:00
title = "2023-05-14 Daily Challenge"
path = "2023-05-14-Daily-Challenge"
date = 2023-05-14T14:54:45+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/maximize-score-after-n-operations/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 14

## Description

**Maximize Score After N Operations**

<p>You are given <code>nums</code>, an array of positive integers of size <code>2 * n</code>. You must perform <code>n</code> operations on this array.</p>

<p>In the <code>i<sup>th</sup></code> operation <strong>(1-indexed)</strong>, you will:</p>

<ul>
	<li>Choose two elements, <code>x</code> and <code>y</code>.</li>
	<li>Receive a score of <code>i * gcd(x, y)</code>.</li>
	<li>Remove <code>x</code> and <code>y</code> from <code>nums</code>.</li>
</ul>

<p>Return <em>the maximum score you can receive after performing </em><code>n</code><em> operations.</em></p>

<p>The function <code>gcd(x, y)</code> is the greatest common divisor of <code>x</code> and <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,6,8]
<strong>Output:</strong> 11
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6]
<strong>Output:</strong> 14
<strong>Explanation:</strong>&nbsp;The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 7</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  int len;
  int n;
  int solve(
    vector<int>& dp,
    vector<vector<int>>& gcd,
    int mask,
    int ops
  ) {
    if(ops > n) return 0;
    if(dp[mask]) return dp[mask];

    int result = 0;
    for(int i = 0; i < len; ++i) {
      if(mask & (1 << i)) continue;
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        if(mask & (1 << j)) continue;
        int newMask = mask | (1 << i) | (1 << j);
        result = max(result, ops * gcd[i][j] + solve(dp, gcd, newMask, ops + 1));
      }
    }

    return dp[mask] = result;
  }
public:
  int maxScore(vector<int>& nums) {
    len = nums.size();
    n = len / 2;
    vector<int> dp(1 << len);
    vector<vector<int>> gcd(len, vector<int>(len));

    for(int i = 0; i < len; ++i) {
      for(int j = i + 1; j < len; ++j) {
        gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);
      }
    }
    return solve(dp, gcd, 0, 1);
  }
};

// Accepted
// 76/76 cases passed (156 ms)
// Your runtime beats 72.32 % of cpp submissions
// Your memory usage beats 49.83 % of cpp submissions (9 MB)
```
