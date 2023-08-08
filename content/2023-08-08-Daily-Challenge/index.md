+++
updated = 2023-08-08T03:01:26+08:00
title = "2023-08-08 Daily Challenge"
path = "2023-08-08-Daily-Challenge"
date = 2023-08-08T03:01:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/search-in-rotated-sorted-array/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 8

## Description

**Search in Rotated Sorted Array**

<p>There is an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values).</p>

<p>Prior to being passed to your function, <code>nums</code> is <strong>possibly rotated</strong> at an unknown pivot index <code>k</code> (<code>1 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,5,6,7]</code> might be rotated at pivot index <code>3</code> and become <code>[4,5,6,7,0,1,2]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the possible rotation and an integer <code>target</code>, return <em>the index of </em><code>target</code><em> if it is in </em><code>nums</code><em>, or </em><code>-1</code><em> if it is not in </em><code>nums</code>.</p>

<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
<strong>Output:</strong> -1
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1], target = 0
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is an ascending array that is possibly rotated.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int len = nums.size();
    int begin = 0;
    int end = len - 1;
    int mid;
    while (nums[begin] > nums[end]) {
      mid = (begin + end) / 2;
      if (nums[mid] >= nums[begin]) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    int pivot = begin;
    begin = 0;
    end = len;
    while (begin < end) {
      mid = (begin + end) / 2;
      if (nums[(mid + pivot) % len] < target) begin = mid + 1;
      else end = mid;
    }
    return nums[(begin + pivot) % len] == target ? (begin + pivot) % len : -1;
  }
};

// Accepted
// 195/195 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 13.7 % of cpp submissions (11.1 MB)
```
