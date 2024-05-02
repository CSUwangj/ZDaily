+++
updated = 2024-05-02T10:58:38+08:00
title = "2024-05-02 Daily Challenge"
path = "2024-05-02-Daily-Challenge"
date = 2024-05-02T10:58:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 2

## Description

**Largest Positive Integer That Exists With Its Negative**

<p>Given an integer array <code>nums</code> that <strong>does not contain</strong> any zeros, find <strong>the largest positive</strong> integer <code>k</code> such that <code>-k</code> also exists in the array.</p>

<p>Return <em>the positive integer </em><code>k</code>. If there is no such integer, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,2,-3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the only valid k we can find in the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,10,6,7,-7,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-10,8,6,7,-2,-3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no a single valid k, we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findMaxK(vector<int>& nums) {
    int count[2001] = {};
    for(auto n : nums) {
      count[n + 1000] += 1;
    }
    for(int i = 2000; i > 1000; --i) {
      if(count[2000 - i] && count[i]) return i - 1000;
    }
    return -1;
  }
};
```
