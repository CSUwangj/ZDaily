+++
updated = 2024-03-26T12:27:58+08:00
title = "2024-03-26 Daily Challenge"
path = "2024-03-26-Daily-Challenge"
date = 2024-03-26T12:27:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/first-missing-positive/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 26

## Description

**First Missing Positive**

<p>Given an unsorted integer array <code>nums</code>. Return the <em>smallest positive integer</em> that is <em>not present</em> in <code>nums</code>.</p>

<p>You must implement an algorithm that runs in <code>O(n)</code> time and uses <code>O(1)</code> auxiliary space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The numbers in the range [1,2] are all in the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,-1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 1 is in the array but 2 is missing.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [7,8,9,11,12]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The smallest positive integer 1 is missing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    for(auto &n : nums) {
      if(n < 1) n = INT_MAX;
    }
    for(auto n : nums) {
      n = abs(n);
      if(n > len) continue;
      if(nums[n - 1] > 0) nums[n - 1] = -nums[n - 1];
    }
    for(int i = 0; i < len; ++i) {
      if(nums[i] > 0) return i + 1;
    }
    return len + 1;
  }
};

// Accepted
// 173/173 cases passed (148 ms)
// Your runtime beats 76.92 % of cpp submissions
// Your memory usage beats 40.04 % of cpp submissions (83.1 MB)
```
