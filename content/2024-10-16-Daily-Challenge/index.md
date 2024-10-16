+++
updated = 2024-10-16T08:03:24+08:00
title = "2024-10-16 Daily Challenge"
path = "2024-10-16-Daily-Challenge"
date = 2024-10-16T08:03:24+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/longest-happy-string/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 16

## Description

**Longest Happy String**

<p>A string <code>s</code> is called <strong>happy</strong> if it satisfies the following conditions:</p>

<ul>
	<li><code>s</code> only contains the letters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</li>
	<li><code>s</code> does not contain any of <code>&quot;aaa&quot;</code>, <code>&quot;bbb&quot;</code>, or <code>&quot;ccc&quot;</code> as a substring.</li>
	<li><code>s</code> contains <strong>at most</strong> <code>a</code> occurrences of the letter <code>&#39;a&#39;</code>.</li>
	<li><code>s</code> contains <strong>at most</strong> <code>b</code> occurrences of the letter <code>&#39;b&#39;</code>.</li>
	<li><code>s</code> contains <strong>at most</strong> <code>c</code> occurrences of the letter <code>&#39;c&#39;</code>.</li>
</ul>

<p>Given three integers <code>a</code>, <code>b</code>, and <code>c</code>, return <em>the <strong>longest possible happy </strong>string</em>. If there are multiple longest happy strings, return <em>any of them</em>. If there is no such string, return <em>the empty string </em><code>&quot;&quot;</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> a = 1, b = 1, c = 7
<strong>Output:</strong> &quot;ccaccbcc&quot;
<strong>Explanation:</strong> &quot;ccbccacc&quot; would also be a correct answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> a = 7, b = 1, c = 0
<strong>Output:</strong> &quot;aabaa&quot;
<strong>Explanation:</strong> It is the only correct answer in this case.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= a, b, c &lt;= 100</code></li>
	<li><code>a + b + c &gt; 0</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string longestDiverseString(int a, int b, int c, char charA = 'a', char charB = 'b', char charC = 'c') {
    if(a < b) return longestDiverseString(b, a, c, charB, charA, charC);
    if(b < c) return longestDiverseString(a, c, b, charA, charC, charB);
    if(!b) return string(min(2, a), charA);
    int countA = min(2, a);
    int countB = a - countA >= b ? 1 : 0;
    return string(countA, charA) + string(countB, charB) + longestDiverseString(a - countA, b - countB, c, charA, charB, charC);
  }
};
```
