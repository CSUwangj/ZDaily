+++
updated = 2023-07-21T12:43:14+08:00
title = "2023-07-21 Daily Challenge"
path = "2023-07-21-Daily-Challenge"
date = 2023-07-21T12:43:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 21

## Description

**Number of Longest Increasing Subsequence**

<p>Given an integer array&nbsp;<code>nums</code>, return <em>the number of longest increasing subsequences.</em></p>

<p><strong>Notice</strong> that the sequence has to be <strong>strictly</strong> increasing.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,4,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,2,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> LIS(nums.size(), 1);
    vector<int> ways(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[j] < nums[i] && LIS[j]+1 > LIS[i]) {
          ways[i] = ways[j];
          LIS[i] = LIS[j] + 1;
        } else if(nums[j] < nums[i] && LIS[j]+1 == LIS[i]) {
          ways[i] += ways[j];  
        } 
      }
    }
    int LISLength = *max_element(LIS.begin(), LIS.end());
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(LIS[i] == LISLength) ans += ways[i];
    }
    return ans;
  }
};

// Accepted
// 223/223 cases passed (217 ms)
// Your runtime beats 43.24 % of cpp submissions
// Your memory usage beats 66.65 % of cpp submissions (13.2 MB)
```
