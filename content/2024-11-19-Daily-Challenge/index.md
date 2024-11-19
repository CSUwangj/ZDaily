+++
updated = 2024-11-19T09:22:38+08:00
title = "2024-11-19 Daily Challenge"
path = "2024-11-19-Daily-Challenge"
date = 2024-11-19T09:22:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 19

## Description

**Maximum Sum of Distinct Subarrays With Length K**

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Find the maximum subarray sum of all the subarrays of <code>nums</code> that meet the following conditions:</p>

<ul>
	<li>The length of the subarray is <code>k</code>, and</li>
	<li>All the elements of the subarray are <strong>distinct</strong>.</li>
</ul>

<p>Return <em>the maximum subarray sum of all the subarrays that meet the conditions</em><em>.</em> If no subarray meets the conditions, return <code>0</code>.</p>

<p><em>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,4,2,9,9,9], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,4,4], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    long long answer = 0;
    long long current = 0;
    map<int, int> count;
    for(int i = 0; i < k; ++i) {
      current += nums[i];
      count[nums[i]] += 1;
    }
    if(count.size() == k) answer = current;
    for(int i = k; i < nums.size(); ++i) {
      count[nums[i]] += 1;
      count[nums[i - k]] -= 1;
      current += nums[i];
      current -= nums[i - k];
      if(!count[nums[i - k]]) count.erase(nums[i - k]);
      if(count.size() == k) answer = max(answer, current);
    }
    return answer;
  }
};
```
