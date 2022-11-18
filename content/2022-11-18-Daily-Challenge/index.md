+++
updated = 2022-11-18T12:47:19+08:00
title = "2022-11-18 Daily Challenge"
path = "2022-11-18-Daily-Challenge"
date = 2022-11-18T12:47:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/ugly-number/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 18

## Description

**Ugly Number**

<p>An <strong>ugly number</strong> is a positive integer whose prime factors are limited to <code>2</code>, <code>3</code>, and <code>5</code>.</p>

<p>Given an integer <code>n</code>, return <code>true</code> <em>if</em> <code>n</code> <em>is an <strong>ugly number</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> 6 = 2 &times; 3</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 8
<strong>Output:</strong> true
<strong>Explanation:</strong> 8 = 2 &times; 2 &times; 2
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 14
<strong>Output:</strong> false
<strong>Explanation:</strong> 14 is not ugly since it includes the prime factor 7.
</pre>

<p><strong>Example 4:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool isUgly(int n) {
    if(n < 1) return false;
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    return n == 1;
  }
};

// Accepted
// 1013/1013 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.16 % of cpp submissions (6 MB)
```
