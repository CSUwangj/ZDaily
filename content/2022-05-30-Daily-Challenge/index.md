+++
updated = 2022-05-30 18:14:00+08:00
title = "2022-05-30 Daily-Challenge"
path = "2022-05-30-Daily-Challenge"
date = 2022-05-30 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/divide-two-integers/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 30

## Description

**Divide Two Integers**

​<p>Given two integers <code>dividend</code> and <code>divisor</code>, divide two integers <strong>without</strong> using multiplication, division, and mod operator.</p>

<p>The integer division should truncate toward zero, which means losing its fractional part. For example, <code>8.345</code> would be truncated to <code>8</code>, and <code>-2.7335</code> would be truncated to <code>-2</code>.</p>

<p>Return <em>the <strong>quotient</strong> after dividing </em><code>dividend</code><em> by </em><code>divisor</code>.</p>

<p><strong>Note: </strong>Assume we are dealing with an environment that could only store integers within the <strong>32-bit</strong> signed integer range: <code>[&minus;2<sup>31</sup>, 2<sup>31</sup> &minus; 1]</code>. For this problem, if the quotient is <strong>strictly greater than</strong> <code>2<sup>31</sup> - 1</code>, then return <code>2<sup>31</sup> - 1</code>, and if the quotient is <strong>strictly less than</strong> <code>-2<sup>31</sup></code>, then return <code>-2<sup>31</sup></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> dividend = 10, divisor = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 10/3 = 3.33333.. which is truncated to 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> dividend = 7, divisor = -3
<strong>Output:</strong> -2
<strong>Explanation:</strong> 7/-3 = -2.33333.. which is truncated to -2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= dividend, divisor &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>divisor != 0</code></li>
</ul>

## Solution

``` cpp
class Solution {
  int answer = 0;
  int minus(int current, int base, int resultBase) {
    if(current > base) {
      return current;
    }
    if(base >= INT_MIN / 2) current = minus(current, base + base, resultBase + resultBase);
    if(current > base) {
      return current;
    }
    current -= base;
    answer += resultBase;
    return current;
  }
public:
  int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    int sign = 1;
    if(dividend > 0) {
      sign = -1;
      dividend = 0 - dividend;
    }
    if(divisor > 0) {
      sign = sign == 1 ? -1 : 1;
      divisor = 0 - divisor;
    }
    minus(dividend, divisor, -1);
    answer = sign == 1 ? 0 - answer : answer;
    return answer;
  }
};

// Accepted
// 992/992 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.09 % of cpp submissions (5.9 MB)
```
