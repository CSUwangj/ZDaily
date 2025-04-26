+++
updated = 2025-04-26T21:47:35+08:00
title = "2025-04-26 Daily Challenge"
path = "2025-04-26-Daily-Challenge"
date = 2025-04-26T21:47:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 26

## Description

**Count Subarrays With Fixed Bounds**

<p>You are given an integer array <code>nums</code> and two integers <code>minK</code> and <code>maxK</code>.</p>

<p>A <strong>fixed-bound subarray</strong> of <code>nums</code> is a subarray that satisfies the following conditions:</p>

<ul>
	<li>The <strong>minimum</strong> value in the subarray is equal to <code>minK</code>.</li>
	<li>The <strong>maximum</strong> value in the subarray is equal to <code>maxK</code>.</li>
</ul>

<p>Return <em>the <strong>number</strong> of fixed-bound subarrays</em>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,2,7,5], minK = 1, maxK = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1], minK = 1, maxK = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], minK, maxK &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long answer = 0;
    int lastInvalid = -1;
    int prevMinKIndex = -1;
    int prevMaxKIndex = -1;

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] < minK || nums[i] > maxK) {
        lastInvalid = i;
      }
      if (nums[i] == minK) {
        prevMinKIndex = i;
      }
      if (nums[i] == maxK) {
        prevMaxKIndex = i;
      }

      answer += max(0, min(prevMinKIndex, prevMaxKIndex) - lastInvalid);
    }

    return answer;
  }
};

// Accepted
// 53/53 cases passed (4 ms)
// Your runtime beats 38.42 % of cpp submissions
// Your memory usage beats 31.29 % of cpp submissions (94 MB)
```
