+++
updated = 2024-08-04T15:18:06+08:00
title = "2024-08-04 Daily Challenge"
path = "2024-08-04-Daily-Challenge"
date = 2024-08-04T15:18:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 4

## Description

**Range Sum of Sorted Subarray Sums**

<p>You are given the array <code>nums</code> consisting of <code>n</code> positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of <code>n * (n + 1) / 2</code> numbers.</p>

<p><em>Return the sum of the numbers from index </em><code>left</code><em> to index </em><code>right</code> (<strong>indexed from 1</strong>)<em>, inclusive, in the new array. </em>Since the answer can be a huge number return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 1, right = 5
<strong>Output:</strong> 13 
<strong>Explanation:</strong> All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 3, right = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong> The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 1, right = 10
<strong>Output:</strong> 50
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= left &lt;= right &lt;= n * (n + 1) / 2</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    int arr[n * (n + 1) / 2];
    int pos = 0;
    for(int i = 0; i < n; ++i) {
      int s = 0;
      for(int j = i ; j < n; ++j) {
        s += nums[j];
        arr[pos] = s;
        pos += 1;
      }
    }
    sort(arr, arr + n * (n + 1) / 2);
    int answer = 0;
    for(int i = left - 1; i < right; ++i) {
      answer += arr[i];
      answer %= MOD;
    } 
    return answer;
  }
};
```
