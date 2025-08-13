+++
updated = 2025-08-13T21:45:28+08:00
title = "2025-08-13 Daily Challenge"
path = "2025-08-13-Daily-Challenge"
date = 2025-08-13T21:45:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/power-of-three/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 13

## Description

**Power of Three**

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of three. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of three, if there exists an integer <code>x</code> such that <code>n == 3<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 27
<strong>Output:</strong> true
<strong>Explanation:</strong> 27 = 3<sup>3</sup>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 0
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no x where 3<sup>x</sup> = 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = -1
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no x where 3<sup>x</sup> = (-1).
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
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};

// Accepted
// 21040/21040 cases passed (8 ms)
// Your runtime beats 16.56 % of cpp submissions
// Your memory usage beats 76.82 % of cpp submissions (8.8 MB)
```
