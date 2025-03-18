+++
updated = 2025-03-18T13:21:31+08:00
title = "2025-03-18 Daily Challenge"
path = "2025-03-18-Daily-Challenge"
date = 2025-03-18T13:21:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/longest-nice-subarray/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 18

## Description

**Longest Nice Subarray**

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>We call a subarray of <code>nums</code> <strong>nice</strong> if the bitwise <strong>AND</strong> of every pair of elements that are in <strong>different</strong> positions in the subarray is equal to <code>0</code>.</p>

<p>Return <em>the length of the <strong>longest</strong> nice subarray</em>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p><strong>Note</strong> that subarrays of length <code>1</code> are always considered nice.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,8,48,10]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,5,11,13]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int answer = 0;
    int begin = 0;
    int mask = 0;
    int len = nums.size();
    for(int end = 0; end < len; ++end) {
      while(mask & nums[end]) {
        mask ^= nums[begin];
        begin += 1;
      }
      mask ^= nums[end];
      answer = max(answer, end - begin + 1);
    }
    return answer;
  }
};

// Accepted
// 65/65 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 28.44 % of cpp submissions (61 MB)
```
