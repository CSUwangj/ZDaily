+++
updated = 2023-06-07T13:46:09+08:00
title = "2023-06-07 Daily Challenge"
path = "2023-06-07-Daily-Challenge"
date = 2023-06-07T13:46:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 7

## Description

**Minimum Flips to Make a OR b Equal to c**

<p>Given 3 positives numbers <code>a</code>, <code>b</code> and <code>c</code>. Return the minimum flips required in some bits of <code>a</code> and <code>b</code> to make (&nbsp;<code>a</code> OR <code>b</code> == <code>c</code>&nbsp;). (bitwise OR operation).<br />
Flip operation&nbsp;consists of change&nbsp;<strong>any</strong>&nbsp;single bit 1 to 0 or change the bit 0 to 1&nbsp;in their binary representation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/06/sample_3_1676.png" style="width: 260px; height: 87px;" /></p>

<pre>
<strong>Input:</strong> a = 2, b = 6, c = 5
<strong>Output:</strong> 3
<strong>Explanation: </strong>After flips a = 1 , b = 4 , c = 5 such that (<code>a</code> OR <code>b</code> == <code>c</code>)</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> a = 4, b = 2, c = 7
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> a = 1, b = 2, c = 3
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a &lt;= 10^9</code></li>
	<li><code>1 &lt;= b&nbsp;&lt;= 10^9</code></li>
	<li><code>1 &lt;= c&nbsp;&lt;= 10^9</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int answer = 0;
    while(a || b || c) {
      if(c & 1) {
        answer += !((a|b)&1);
      } else {
        answer += (a&1) + (b&1);
      }
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    return answer;
  }
};

// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.33 % of cpp submissions (5.9 MB)
```
