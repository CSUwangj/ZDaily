+++
updated = 2024-06-23T20:17:54+08:00
title = "2024-06-23 Daily Challenge"
path = "2024-06-23-Daily-Challenge"
date = 2024-06-23T20:17:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 23

## Description

**Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit**

<p>Given an array of integers <code>nums</code> and an integer <code>limit</code>, return the size of the longest <strong>non-empty</strong> subarray such that the absolute difference between any two elements of this subarray is less than or equal to <code>limit</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,2,4,7], limit = 4
<strong>Output:</strong> 2 
<strong>Explanation:</strong> All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 &lt;= 4.
[8,2] with maximum absolute diff |8-2| = 6 &gt; 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 &gt; 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 &gt; 4.
[2] with maximum absolute diff |2-2| = 0 &lt;= 4.
[2,4] with maximum absolute diff |2-4| = 2 &lt;= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 &gt; 4.
[4] with maximum absolute diff |4-4| = 0 &lt;= 4.
[4,7] with maximum absolute diff |4-7| = 3 &lt;= 4.
[7] with maximum absolute diff |7-7| = 0 &lt;= 4. 
Therefore, the size of the longest subarray is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,1,2,4,7,2], limit = 5
<strong>Output:</strong> 4 
<strong>Explanation:</strong> The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 &lt;= 5.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= limit &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> maxMonoQueue, minMonoQueue;
    int begin = 0;
    int answer = 0;
    for(int end = 0; end < nums.size(); ++end) {
      while(maxMonoQueue.size() && maxMonoQueue.back() < nums[end]) maxMonoQueue.pop_back();
      while(minMonoQueue.size() && minMonoQueue.back() > nums[end]) minMonoQueue.pop_back();
      maxMonoQueue.push_back(nums[end]);
      minMonoQueue.push_back(nums[end]);
      while(maxMonoQueue.size() && minMonoQueue.size() && maxMonoQueue.front() - minMonoQueue.front() > limit) {
        if(maxMonoQueue.front() == nums[begin]) maxMonoQueue.pop_front();
        if(minMonoQueue.front() == nums[begin]) minMonoQueue.pop_front();
        begin += 1;
      }

      answer = max(answer, end - begin + 1);
    }

    return answer;
  }
};
```
