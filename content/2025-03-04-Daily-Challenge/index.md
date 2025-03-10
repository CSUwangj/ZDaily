+++
updated = 2025-03-04T10:09:23+08:00
title = "2025-03-04 Daily Challenge"
path = "2025-03-04-Daily-Challenge"
date = 2025-03-04T10:09:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 4

## Description

**Check if Number is a Sum of Powers of Three**

<p>Given an integer <code>n</code>, return <code>true</code> <em>if it is possible to represent </em><code>n</code><em> as the sum of distinct powers of three.</em> Otherwise, return <code>false</code>.</p>

<p>An integer <code>y</code> is a power of three if there exists an integer <code>x</code> such that <code>y == 3<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 12
<strong>Output:</strong> true
<strong>Explanation:</strong> 12 = 3<sup>1</sup> + 3<sup>2</sup>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 91
<strong>Output:</strong> true
<strong>Explanation:</strong> 91 = 3<sup>0</sup> + 3<sup>2</sup> + 3<sup>4</sup>
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 21
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>7</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  vector<int> powers{4782969, 1594323, 531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1};
public:
  bool checkPowersOfThree(int n) {
    for(auto power : powers) {
      if(n >= power) n -= power;
    }
    return n == 0;
  }
};

// Accepted
// 129/129 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 41.55 % of cpp submissions (7.9 MB)
```
