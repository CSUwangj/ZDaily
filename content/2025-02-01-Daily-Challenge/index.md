+++
updated = 2025-02-01T21:39:46+08:00
title = "2025-02-01 Daily Challenge"
path = "2025-02-01-Daily-Challenge"
date = 2025-02-01T21:39:46+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/special-array-i/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 1

## Description

**Special Array I**

<p>An array is considered <strong>special</strong> if every pair of its adjacent elements contains two numbers with different parity.<!-- notionvc: e6bed0fa-c67d-43a7-81b4-99fb85b99e98 --></p>

<p>You are given an array of integers <code>nums</code>. Return <code>true</code> if <code>nums</code> is a <strong>special</strong> array, otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>There is only one element. So the answer is <code>true</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>There is only two pairs: <code>(2,1)</code> and <code>(1,4)</code>, and both of them contain numbers with different parity. So the answer is <code>true</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,1,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p><code>nums[1]</code> and <code>nums[2]</code> are both odd. So the answer is <code>false</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
    for(int i = 1; i < nums.size(); ++i) {
      if(!((nums[i] % 2) ^ (nums[i - 1] % 2))) return false;
    }
    return true;
  }
};

// Accepted
// 852/852 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 13.08 % of cpp submissions (27.5 MB)
```
