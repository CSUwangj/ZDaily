+++
updated = 2025-04-29T20:35:09+08:00
title = "2025-04-29 Daily Challenge"
path = "2025-04-29-Daily-Challenge"
date = 2025-04-29T20:35:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 29

## Description

**Count Subarrays Where Max Element Appears at Least K Times**

<p>You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.</p>

<p>Return <em>the number of subarrays where the <strong>maximum</strong> element of </em><code>nums</code><em> appears <strong>at least</strong> </em><code>k</code><em> times in that subarray.</em></p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,3,3], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,2,1], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> No subarray contains the element 4 at least 3 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    long long answer = 0;
    int mmax = *max_element(nums.begin(), nums.end());

    int begin = 0;
    int end = 0;
    while(end < nums.size()) {
      if(nums[end] == mmax) {
        k -= 1;
      }
      end += 1;
      while(!k && begin < nums.size() && nums[begin++] != mmax) {}
      k += !k;
      answer += begin;
    }
    return answer;
  }
};

// Accepted
// 633/633 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 48.26 % of cpp submissions (121.7 MB)
```
