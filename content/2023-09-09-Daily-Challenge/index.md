+++
updated = 2023-09-09T21:30:40+08:00
title = "2023-09-09 Daily Challenge"
path = "2023-09-09-Daily-Challenge"
date = 2023-09-09T21:30:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/combination-sum-iv/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 9

## Description

**Combination Sum IV**

<p>Given an array of <strong>distinct</strong> integers <code>nums</code> and a target integer <code>target</code>, return <em>the number of possible combinations that add up to</em>&nbsp;<code>target</code>.</p>

<p>The test cases are generated so that the answer can fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], target = 4
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9], target = 3
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>All the elements of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?</p>


## Solution

``` cpp
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i) {
      for(auto num : nums) {
        if(num <= i && INT_MAX - dp[i] > dp[i - num]) dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};

// Accepted
// 15/15 cases passed (3 ms)
// Your runtime beats 50.37 % of cpp submissions
// Your memory usage beats 46.24 % of cpp submissions (6.7 MB)
```
