+++
updated = 2025-05-06T21:28:19+08:00
title = "2025-05-06 Daily Challenge"
path = "2025-05-06-Daily-Challenge"
date = 2025-05-06T21:28:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/build-array-from-permutation/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 6

## Description

**Build Array from Permutation**

<p>Given a <strong>zero-based permutation</strong> <code>nums</code> (<strong>0-indexed</strong>), build an array <code>ans</code> of the <strong>same length</strong> where <code>ans[i] = nums[nums[i]]</code> for each <code>0 &lt;= i &lt; nums.length</code> and return it.</p>

<p>A <strong>zero-based permutation</strong> <code>nums</code> is an array of <strong>distinct</strong> integers from <code>0</code> to <code>nums.length - 1</code> (<strong>inclusive</strong>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,2,1,5,3,4]
<strong>Output:</strong> [0,1,2,4,5,3]<strong>
Explanation:</strong> The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,0,1,2,3,4]
<strong>Output:</strong> [4,5,0,1,2,3]
<strong>Explanation:</strong> The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li>The elements in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you solve it without using an extra space (i.e., <code>O(1)</code> memory)?</p>


## Solution

``` cpp
class Solution {
public:
  vector<int> buildArray(vector<int>& nums) {
    vector<int> answer(nums.size());
    for(int i = 0; i < nums.size(); ++i) {
      answer[i] = nums[nums[i]];
    }
    return answer;
  }
};

// Accepted
// 140/140 cases passed (4 ms)
// Your runtime beats 5.44 % of cpp submissions
// Your memory usage beats 39.42 % of cpp submissions (20.5 MB)
```
