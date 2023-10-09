+++
updated = 2023-10-09T12:19:43+08:00
title = "2023-10-09 Daily Challenge"
path = "2023-10-09-Daily-Challenge"
date = 2023-10-09T12:19:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 9

## Description

**Find First and Last Position of Element in Sorted Array**

<p>Given an array of integers <code>nums</code> sorted in non-decreasing order, find the starting and ending position of a given <code>target</code> value.</p>

<p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>

<p>You must&nbsp;write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
<strong>Output:</strong> [3,4]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
<strong>Output:</strong> [-1,-1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> [-1,-1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> is a non-decreasing array.</li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if(!len) return{-1, -1};
    int begin = 0;
    int end = len - 1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(nums[begin] != target) return {-1, -1};
    int left = begin;
    begin = 0;
    end = len - 1;
    while(begin < end) {
      int mid = (begin + end + 1) >> 1;
      if(nums[mid] > target) {
        end = mid - 1;
      } else {
        begin = mid;
      }
    }
    return {left, begin};
  }
};

// Accepted
// 88/88 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 25.3 % of cpp submissions (14 MB)
```
