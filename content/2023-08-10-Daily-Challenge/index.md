+++
updated = 2023-08-10T16:52:08+08:00
title = "2023-08-10 Daily Challenge"
path = "2023-08-10-Daily-Challenge"
date = 2023-08-10T16:52:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 10

## Description

**Search in Rotated Sorted Array II**

<p>There is an integer array <code>nums</code> sorted in non-decreasing order (not necessarily with <strong>distinct</strong> values).</p>

<p>Before being passed to your function, <code>nums</code> is <strong>rotated</strong> at an unknown pivot index <code>k</code> (<code>0 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,4,4,5,6,6,7]</code> might be rotated at pivot index <code>5</code> and become <code>[4,5,6,6,7,0,1,2,4,4]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the rotation and an integer <code>target</code>, return <code>true</code><em> if </em><code>target</code><em> is in </em><code>nums</code><em>, or </em><code>false</code><em> if it is not in </em><code>nums</code><em>.</em></p>

<p>You must decrease the overall operation steps as much as possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 0
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 3
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is guaranteed to be rotated at some pivot.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> This problem is similar to&nbsp;<a href="/problems/search-in-rotated-sorted-array/description/" target="_blank">Search in Rotated Sorted Array</a>, but&nbsp;<code>nums</code> may contain <strong>duplicates</strong>. Would this affect the runtime complexity? How and why?</p>


## Solution

``` cpp
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if(nums.empty()) return false;
    int offset = 0;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      if(nums[i] < nums[i-1]) {
        offset = i;
        break;
      }
    }
    int start = 0, end = nums.size() - 1;
    while(start < end) {
      int mid = (start + end) / 2;
      int pos = (mid + offset) % len;
      if(nums[pos] < target) start = mid + 1;
      else end = mid;
    }
    return nums[(start+offset)%len] == target;
  }
};

// Accepted
// 280/280 cases passed (5 ms)
// Your runtime beats 63.37 % of cpp submissions
// Your memory usage beats 50.05 % of cpp submissions (14 MB)
```
