+++
updated = 2024-01-21T19:22:34+08:00
title = "2024-01-21 Daily Challenge"
path = "2024-01-21-Daily-Challenge"
date = 2024-01-21T19:22:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/house-robber/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 21

## Description

**House Robber**

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int rob(vector<int>& nums) {
    int dp[2] = {};
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      int parity = (i & 1);
      dp[parity] = max(dp[!parity], dp[parity] + nums[i]);
    }
    return max(dp[0], dp[1]);
  }
};

// Accepted
// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.98 % of cpp submissions (7.7 MB)
```
