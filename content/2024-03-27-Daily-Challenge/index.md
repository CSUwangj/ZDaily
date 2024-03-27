+++
updated = 2024-03-27T12:47:51+08:00
title = "2024-03-27 Daily Challenge"
path = "2024-03-27-Daily-Challenge"
date = 2024-03-27T12:47:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/subarray-product-less-than-k/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 27

## Description

**Subarray Product Less Than K**

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than </em><code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,5,2,6], k = 100
<strong>Output:</strong> 8
<strong>Explanation:</strong> The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], k = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1) return 0;
    int begin = 0; 
    int product = 1;
    int answer = 0;
    int len = nums.size();
    for(int end = 0; end < len; ++end) {
      product *= nums[end];
      while(product >= k) product /= nums[begin++];
      answer += end - begin + 1;
    }
    return answer;
  }
};
```
