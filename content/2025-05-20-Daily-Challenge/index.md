+++
updated = 2025-05-20T14:57:47+08:00
title = "2025-05-20 Daily Challenge"
path = "2025-05-20-Daily-Challenge"
date = 2025-05-20T14:57:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/zero-array-transformation-i/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 20

## Description

**Zero Array Transformation I**

<p>You are given an integer array <code>nums</code> of length <code>n</code> and a 2D array <code>queries</code>, where <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>.</p>

<p>For each <code>queries[i]</code>:</p>

<ul>
	<li>Select a <span data-keyword="subset">subset</span> of indices within the range <code>[l<sub>i</sub>, r<sub>i</sub>]</code> in <code>nums</code>.</li>
	<li>Decrement the values at the selected indices by 1.</li>
</ul>

<p>A <strong>Zero Array</strong> is an array where all elements are equal to 0.</p>

<p>Return <code>true</code> if it is <em>possible</em> to transform <code>nums</code> into a <strong>Zero Array </strong>after processing all the queries sequentially, otherwise return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,0,1], queries = [[0,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>For i = 0:</strong>

	<ul>
		<li>Select the subset of indices as <code>[0, 2]</code> and decrement the values at these indices by 1.</li>
		<li>The array will become <code>[0, 0, 0]</code>, which is a Zero Array.</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,2,1], queries = [[1,3],[0,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>For i = 0:</strong>

	<ul>
		<li>Select the subset of indices as <code>[1, 2, 3]</code> and decrement the values at these indices by 1.</li>
		<li>The array will become <code>[4, 2, 1, 0]</code>.</li>
	</ul>
	</li>
	<li><strong>For i = 1:</strong>
	<ul>
		<li>Select the subset of indices as <code>[0, 1, 2]</code> and decrement the values at these indices by 1.</li>
		<li>The array will become <code>[3, 1, 0, 0]</code>, which is not a Zero Array.</li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int decrement = 0;
    int k = 0;
    vector<int> decrements(nums.size() + 1);
    for(auto &q : queries) {
      decrements[q[0]] += 1;
      decrements[q[1] + 1] -= 1;
    }
    for(int i = 0; i < nums.size(); ++i) {
      decrement += decrements[i];
      if(nums[i] > decrement) return false; 
    }
    return true;
  }
};

// Accepted
// 668/668 cases passed (6 ms)
// Your runtime beats 73.34 % of cpp submissions
// Your memory usage beats 56.99 % of cpp submissions (293 MB)
```
