+++
updated = 2024-06-22T23:08:28+08:00
title = "2024-06-22 Daily Challenge"
path = "2024-06-22-Daily-Challenge"
date = 2024-06-22T23:08:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/count-number-of-nice-subarrays/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 22

## Description

**Count Number of Nice Subarrays**

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>. A continuous subarray is called <strong>nice</strong> if there are <code>k</code> odd numbers on it.</p>

<p>Return <em>the number of <strong>nice</strong> sub-arrays</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,2,1,1], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,4,6], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no odd numbers in the array.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,1,2,2,1,2,2,2], k = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    for(auto &n : nums) {
      n %= 2;
    }

    vector<int> prefix(nums.size() + 1);
    prefix[0] = 1;
    int s = 0;
    int answer = 0;
    for(int i = 0; i < nums.size(); ++i) {
      s += nums[i];
      answer += (s >= k) ? prefix[s - k] : 0;
      prefix[s] += 1;
    }

    return answer;
  }
};
```
