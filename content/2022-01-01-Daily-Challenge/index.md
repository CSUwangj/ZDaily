+++
title = "2022-01-01 Daily-Challenge"
path = "2022-01-01-Daily-Challenge"
date = 2022-01-01 13:03:00+08:00
updated = 2022-01-01 13:32:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/burst-balloons/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 1

## Description

**Burst Balloons**

<p>You are given <code>n</code> balloons, indexed from <code>0</code> to <code>n - 1</code>. Each balloon is painted with a number on it represented by an array <code>nums</code>. You are asked to burst all the balloons.</p>

<p>If you burst the <code>i<sup>th</sup></code> balloon, you will get <code>nums[i - 1] * nums[i] * nums[i + 1]</code> coins. If <code>i - 1</code> or <code>i + 1</code> goes out of bounds of the array, then treat it as if there is a balloon with a <code>1</code> painted on it.</p>

<p>Return <em>the maximum coins you can collect by bursting the balloons wisely</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,5,8]
<strong>Output:</strong> 167
<strong>Explanation:</strong>
nums = [3,1,5,8] --&gt; [3,5,8] --&gt; [3,8] --&gt; [8] --&gt; []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5]
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<p>You are given <code>n</code> balloons, indexed from <code>0</code> to <code>n - 1</code>. Each balloon is painted with a number on it represented by an array <code>nums</code>. You are asked to burst all the balloons.</p>

<p>If you burst the <code>i<sup>th</sup></code> balloon, you will get <code>nums[i - 1] * nums[i] * nums[i + 1]</code> coins. If <code>i - 1</code> or <code>i + 1</code> goes out of bounds of the array, then treat it as if there is a balloon with a <code>1</code> painted on it.</p>

<p>Return <em>the maximum coins you can collect by bursting the balloons wisely</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,5,8]
<strong>Output:</strong> 167
<strong>Explanation:</strong>
nums = [3,1,5,8] --&gt; [3,5,8] --&gt; [3,8] --&gt; [8] --&gt; []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5]
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

## Solution

``` cpp
int a[502];
int dp[502][502];
class Solution {
public:
  int maxCoins(vector<int>& nums) {
    memset(dp, 0, sizeof(dp));
    int n = nums.size();
    
    a[0] = 1;
    a[n+1] = 1;
    for(int i = 0; i < n; i++) {
      a[i+1] = nums[i];
    }
    
    for(int l = 3; l <= n+2; l++) {
      for(int i = 0; i + l - 1 <= n + 1; i++){
        for(int j = 1; j <= l - 2; j++){
          dp[i][i+l-1] = max(dp[i][i + j] + dp[i + j][i+l-1] + a[i] * a[i+j] * a[i + l - 1], dp[i][i+l-1]);
        }
      }
    }
    return dp[0][n+1];
  }
};

// Accepted
// 70/70 cases passed (128 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 95.76 % of cpp submissions (8.9 MB)
```
