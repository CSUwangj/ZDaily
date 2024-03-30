+++
updated = 2024-03-30T09:40:34+08:00
title = "2024-03-30 Daily Challenge"
path = "2024-03-30-Daily-Challenge"
date = 2024-03-30T09:40:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/subarrays-with-k-different-integers/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 30

## Description

**Subarrays with K Different Integers**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>good subarrays</strong> of </em><code>nums</code>.</p>

<p>A <strong>good array</strong> is an array where the number of different integers in that array is exactly <code>k</code>.</p>

<ul>
	<li>For example, <code>[1,2,3,1,2]</code> has <code>3</code> different integers: <code>1</code>, <code>2</code>, and <code>3</code>.</li>
</ul>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,3], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,4], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int subarraysWithAtMostKDistinct(const vector<int>& nums, int k) {
    if(!k) return 0;
    int len = nums.size();
    map<int, int> count;
    int result = 0;
    int begin = 0;
    for(int end = 0; end < len; ++end) {
      count[nums[end]] += 1;
      while(begin <= end && count.size() > k) {
        count[nums[begin]] -= 1;
        if(!count[nums[begin]]) count.erase(nums[begin]);
        begin += 1;
      }
      result += (end - begin + 1);
    }
    return result;
  }
public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
  }
};
```
