+++
updated = 2023-07-04T16:16:17+08:00
title = "2023-07-04 Daily Challenge"
path = "2023-07-04-Daily-Challenge"
date = 2023-07-04T16:16:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/single-number-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 4

## Description

**Single Number II**

<p>Given an integer array <code>nums</code> where&nbsp;every element appears <strong>three times</strong> except for one, which appears <strong>exactly once</strong>. <em>Find the single element and return it</em>.</p>

<p>You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,3,2]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,1,0,1,99]
<strong>Output:</strong> 99
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Each element in <code>nums</code> appears exactly <strong>three times</strong> except for one element which appears <strong>once</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int a = 0;
    int b = 0;
    for(auto n : nums) {
      int tmp = (a&(~b)&(~n)) | ((~b)&(~a)&n);
      b = (b&(~a)&(~n)) | (a&n&(~b));
      a = tmp;
    }
    return a;
  }
};

// Accepted
// 14/14 cases passed (3 ms)
// Your runtime beats 98.52 % of cpp submissions
// Your memory usage beats 72.62 % of cpp submissions (9.4 MB)
```
