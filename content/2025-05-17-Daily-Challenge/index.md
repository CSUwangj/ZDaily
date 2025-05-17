+++
updated = 2025-05-18T02:05:18+08:00
title = "2025-05-17 Daily Challenge"
path = "2025-05-17-Daily-Challenge"
date = 2025-05-18T02:05:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/sort-colors/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 17

## Description

**Sort Colors**

<p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library&#39;s sort function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,0,1]
<strong>Output:</strong> [0,1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>nums[i]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>


## Solution

``` cpp
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    while(begin < end && (nums[begin] == 0 || nums[begin] == 2 || nums[end] == 0 || nums[end] == 2)) {
      while(begin < end && nums[begin] == 0) {
        begin += 1;
      }
      while(begin < end && nums[end] == 2) {
        end -= 1;
      }
      if(begin >= end) break;
      if((nums[begin] == 2 || nums[end] == 0)) {
        swap(nums[begin], nums[end]);
        if(nums[end] == 0) begin += 1;
        if(nums[begin] == 2) end -= 1;
      }
    }
    int mid = begin + 1;
    while(mid <= end) {
      while(mid <= end && nums[mid] == 1) mid += 1;
      if(mid > end) break;
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
      } else {
        swap(nums[mid], nums[end]);
        end -= 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
```
