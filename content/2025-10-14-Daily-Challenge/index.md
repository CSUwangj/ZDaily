+++
updated = 2025-10-14T23:38:59+02:00
title = "2025-10-14 Daily Challenge"
path = "2025-10-14-Daily-Challenge"
date = 2025-10-14T23:38:59+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 14

## Description

**Adjacent Increasing Subarrays Detection I**

<p>Given an array <code>nums</code> of <code>n</code> integers and an integer <code>k</code>, determine whether there exist <strong>two</strong> <strong>adjacent</strong> <span data-keyword="subarray-nonempty">subarrays</span> of length <code>k</code> such that both subarrays are <strong>strictly</strong> <strong>increasing</strong>. Specifically, check if there are <strong>two</strong> subarrays starting at indices <code>a</code> and <code>b</code> (<code>a &lt; b</code>), where:</p>

<ul>
	<li>Both subarrays <code>nums[a..a + k - 1]</code> and <code>nums[b..b + k - 1]</code> are <strong>strictly increasing</strong>.</li>
	<li>The subarrays must be <strong>adjacent</strong>, meaning <code>b = a + k</code>.</li>
</ul>

<p>Return <code>true</code> if it is <em>possible</em> to find <strong>two </strong>such subarrays, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,5,7,8,9,2,3,4,3,1], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The subarray starting at index <code>2</code> is <code>[7, 8, 9]</code>, which is strictly increasing.</li>
	<li>The subarray starting at index <code>5</code> is <code>[2, 3, 4]</code>, which is also strictly increasing.</li>
	<li>These two subarrays are adjacent, so the result is <code>true</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,4,4,4,5,6,7], k = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt; 2 * k &lt;= nums.length</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    if(k == 1) return true;
    int prev = 0;
    int increase = 1;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      if(nums[i] > nums[i - 1]) {
        increase += 1;
        if(increase == k && prev >= k) return true;
        if(increase >= 2 * k) return true;
        continue;
      }
      prev = increase;
      increase = 1;
    }
    return false;
  }
};

// Accepted
// 1422/1422 cases passed (11 ms)
// Your runtime beats 76.82 % of cpp submissions
// Your memory usage beats 54.55 % of cpp submissions (40.5 MB)
```
