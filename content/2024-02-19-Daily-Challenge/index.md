+++
updated = 2024-02-19T16:46:08+08:00
title = "2024-02-19 Daily Challenge"
path = "2024-02-19-Daily-Challenge"
date = 2024-02-19T16:46:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/power-of-two/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 19

## Description

**Power of Two**

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of two. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of two, if there exists an integer <code>x</code> such that <code>n == 2<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation: </strong>2<sup>0</sup> = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 16
<strong>Output:</strong> true
<strong>Explanation: </strong>2<sup>4</sup> = 16
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> false
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
  bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n - 1));
  }
};

// Accepted
// 1109/1109 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 39.77 % of cpp submissions (7.1 MB)
```
