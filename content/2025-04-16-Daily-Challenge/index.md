+++
updated = 2025-04-16T12:36:35+08:00
title = "2025-04-16 Daily Challenge"
path = "2025-04-16-Daily-Challenge"
date = 2025-04-16T12:36:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-good-subarrays/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 16

## Description

**Count the Number of Good Subarrays**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>good</strong> subarrays of</em> <code>nums</code>.</p>

<p>A subarray <code>arr</code> is <strong>good</strong> if there are <strong>at least </strong><code>k</code> pairs of indices <code>(i, j)</code> such that <code>i &lt; j</code> and <code>arr[i] == arr[j]</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1], k = 10
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only good subarray is the array nums itself.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,4,3,2,2,4], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int begin = 0;
    long long answer = 0;
    for(int end = 0; end < nums.size(); ++end) {
      k -= count[nums[end]];
      count[nums[end]] += 1;
      while(k <= 0) {
        count[nums[begin]] -= 1;
        k += count[nums[begin]];
        begin += 1;
      }
      answer += begin;
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (80 ms)
// Your runtime beats 61.7 % of cpp submissions
// Your memory usage beats 54.61 % of cpp submissions (79.1 MB)
```
