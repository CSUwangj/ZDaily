+++
updated = 2023-02-13T13:28:12+08:00
title = "2023-02-13 Daily Challenge"
path = "2023-02-13-Daily-Challenge"
date = 2023-02-13T13:28:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 13

## Description

**Count Odd Numbers in an Interval Range**

<p>Given two non-negative integers <code>low</code> and <code><font face="monospace">high</font></code>. Return the <em>count of odd numbers between </em><code>low</code><em> and </em><code><font face="monospace">high</font></code><em>&nbsp;(inclusive)</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> low = 3, high = 7
<strong>Output:</strong> 3
<b>Explanation: </b>The odd numbers between 3 and 7 are [3,5,7].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 8, high = 10
<strong>Output:</strong> 1
<b>Explanation: </b>The odd numbers between 8 and 10 are [9].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int countOdds(int low, int high) {
    return (high - low) / 2 + ((low | high) & 1);
  }
};

// Accepted
// 84/84 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.66 % of cpp submissions (6 MB)
```
