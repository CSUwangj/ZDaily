+++
updated = 2024-06-12T14:16:57+08:00
title = "2024-06-12 Daily Challenge"
path = "2024-06-12-Daily-Challenge"
date = 2024-06-12T14:16:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/sort-colors/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 12

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
    for(int mid = 0; mid <= end;) {
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
        mid += 1;
      } else if(nums[mid] == 2) {
        swap(nums[mid], nums[end]);
        end -= 1;
      } else {
        mid += 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
```
