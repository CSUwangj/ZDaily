+++
updated = 2024-06-09T19:25:04+08:00
title = "2024-06-09 Daily Challenge"
path = "2024-06-09-Daily-Challenge"
date = 2024-06-09T19:25:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/subarray-sums-divisible-by-k/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 9

## Description

**Subarray Sums Divisible by K**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of non-empty <strong>subarrays</strong> that have a sum divisible by </em><code>k</code>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,5,0,-2,-3,1], k = 5
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5], k = 9
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    int sum = 0;
    int answer = 0;
    cnt[0] = 1;
    for(auto i : nums) {
      sum = ((sum + i) % k + k) % k;
      answer += cnt[sum];
      cnt[sum] += 1;
    }
    return answer;
  }
};
```
