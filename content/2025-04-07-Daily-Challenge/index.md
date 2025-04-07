+++
updated = 2025-04-07T23:59:15+08:00
title = "2025-04-07 Daily Challenge"
path = "2025-04-07-Daily-Challenge"
date = 2025-04-07T23:59:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/partition-equal-subset-sum/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 7

## Description

**Partition Equal Subset Sum**

<p>Given an integer array <code>nums</code>, return <code>true</code> <em>if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,11,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned as [1, 5, 5] and [11].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> The array cannot be partitioned into equal sum subsets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if((sum & 1) || nums.empty()) return false;

    int target = sum >> 1;
    vector<bool> dp(target + 1);
    dp[0] = true;
    for(auto i : nums) {
      for(int j = target; j >= i; --j) {
        if(dp[j - i]) dp[j] = true;
      }
      if(dp[target]) return true;
    }
    return false;
  }
};

// Accepted
// 117/117 cases passed (16 ms)
// Your runtime beats 97.09 % of cpp submissions
// Your memory usage beats 92.1 % of cpp submissions (9.1 MB)
```
