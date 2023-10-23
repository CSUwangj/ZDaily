+++
updated = 2023-10-23T14:17:54+08:00
title = "2023-10-23 Daily Challenge"
path = "2023-10-23-Daily-Challenge"
date = 2023-10-23T14:17:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/power-of-four/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 23

## Description

**Power of Four**

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of four. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of four, if there exists an integer <code>x</code> such that <code>n == 4<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 16
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> false
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> true
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it without loops/recursion?

## Solution

``` cpp
class Solution {
public:
  bool isPowerOfFour(int n) {
    return n && __builtin_popcount(n) == 1 && !(__builtin_ctz(n) & 1);
  }
};

// Accepted
// 1061/1061 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 71.3 % of cpp submissions (5.8 MB)
```
