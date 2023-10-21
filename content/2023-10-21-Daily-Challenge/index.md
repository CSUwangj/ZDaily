+++
updated = 2023-10-22T12:16:59+08:00
title = "2023-10-21 Daily Challenge"
path = "2023-10-21-Daily-Challenge"
date = 2023-10-22T12:16:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/constrained-subsequence-sum/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 21

## Description

**Constrained Subsequence Sum**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the maximum sum of a <strong>non-empty</strong> subsequence of that array such that for every two <strong>consecutive</strong> integers in the subsequence, <code>nums[i]</code> and <code>nums[j]</code>, where <code>i &lt; j</code>, the condition <code>j - i &lt;= k</code> is satisfied.</p>

<p>A <em>subsequence</em> of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,2,-10,5,20], k = 2
<strong>Output:</strong> 37
<b>Explanation:</b> The subsequence is [10, 2, 5, 20].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,-3], k = 1
<strong>Output:</strong> -1
<b>Explanation:</b> The subsequence must be non-empty, so we choose the largest number.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,-2,-10,-5,20], k = 2
<strong>Output:</strong> 23
<b>Explanation:</b> The subsequence is [10, -2, -5, 20].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    deque<int> dq;
    for(int i = 0; i < nums.size(); ++i) {
      nums[i] += dq.size() ? nums[dq.front()] : 0;

      while(dq.size() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
        if(nums[i] >= nums[dq.back()]) {
          dq.pop_back();
        } else {
          dq.pop_front();
        }
      }

      if(nums[i] > 0) {
        dq.push_back(i);
      }
    }

    return *max_element(nums.begin(), nums.end());
  }
};

// Accepted
// 36/36 cases passed (240 ms)
// Your runtime beats 59.59 % of cpp submissions
// Your memory usage beats 98.57 % of cpp submissions (115 MB)
```
