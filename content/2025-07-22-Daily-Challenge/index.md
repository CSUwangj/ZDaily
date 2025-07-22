+++
updated = 2025-07-22T18:01:00+08:00
title = "2025-07-22 Daily Challenge"
path = "2025-07-22-Daily-Challenge"
date = 2025-07-22T18:01:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/maximum-erasure-value/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 22

## Description

**Maximum Erasure Value**

<p>You are given an array of positive integers <code>nums</code> and want to erase a subarray containing&nbsp;<strong>unique elements</strong>. The <strong>score</strong> you get by erasing the subarray is equal to the <strong>sum</strong> of its elements.</p>

<p>Return <em>the <strong>maximum score</strong> you can get by erasing <strong>exactly one</strong> subarray.</em></p>

<p>An array <code>b</code> is called to be a <span class="tex-font-style-it">subarray</span> of <code>a</code> if it forms a contiguous subsequence of <code>a</code>, that is, if it is equal to <code>a[l],a[l+1],...,a[r]</code> for some <code>(l,r)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,4,5,6]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The optimal subarray here is [2,4,5,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,1,2,5,2,1,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The optimal subarray here is [5,2,1] or [1,2,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>



## Solution

``` cpp
class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    bool vis[10001] = {};
    int sum = 0;
    int start = 0;
    int len = nums.size();
    int answer = 0;
    for(int end = 0; end < len; ++end) {
      while(vis[nums[end]]) {
        vis[nums[start]] = false;
        sum -= nums[start];
        start += 1;
      }
      vis[nums[end]] = true;
      sum += nums[end];
      answer = max(sum, answer);
    }
    return answer;
  }
};

// Accepted
// 62/62 cases passed (338 ms)
// Your runtime beats 77.77 % of cpp submissions
// Your memory usage beats 99.27 % of cpp submissions (89.1 MB)
```
