+++
updated = 2025-07-16T22:35:32+08:00
title = "2025-07-16 Daily Challenge"
path = "2025-07-16-Daily-Challenge"
date = 2025-07-16T22:35:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 16

## Description

**Find the Maximum Length of Valid Subsequence I**

You are given an integer array <code>nums</code>.
<p>A <span data-keyword="subsequence-array">subsequence</span> <code>sub</code> of <code>nums</code> with length <code>x</code> is called <strong>valid</strong> if it satisfies:</p>

<ul>
	<li><code>(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.</code></li>
</ul>

<p>Return the length of the <strong>longest</strong> <strong>valid</strong> subsequence of <code>nums</code>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest valid subsequence is <code>[1, 2, 3, 4]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,1,2,1,2]</span></p>

<p><strong>Output:</strong> 6</p>

<p><strong>Explanation:</strong></p>

<p>The longest valid subsequence is <code>[1, 2, 1, 2, 1, 2]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest valid subsequence is <code>[1, 3]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumLength(vector<int>& nums) {
    // dp[sum][parity]
    vector<vector<int>> length(2, vector<int>(2));
    for(auto n : nums) {
      int parity = n & 1;
      length[0][parity] = length[0][parity] + 1;
      length[1][parity] = length[1][!parity] + 1;
    }
    return max({length[0][0], length[0][1], length[1][0], length[1][1]});
  }
};

// Accepted
// 951/951 cases passed (8 ms)
// Your runtime beats 42.06 % of cpp submissions
// Your memory usage beats 30 % of cpp submissions (96.4 MB)
```
