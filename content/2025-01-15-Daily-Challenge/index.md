+++
updated = 2025-01-15T17:02:08+08:00
title = "2025-01-15 Daily Challenge"
path = "2025-01-15-Daily-Challenge"
date = 2025-01-15T17:02:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimize-xor/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 15

## Description

**Minimize XOR**

<p>Given two positive integers <code>num1</code> and <code>num2</code>, find the positive integer <code>x</code> such that:</p>

<ul>
	<li><code>x</code> has the same number of set bits as <code>num2</code>, and</li>
	<li>The value <code>x XOR num1</code> is <strong>minimal</strong>.</li>
</ul>

<p>Note that <code>XOR</code> is the bitwise XOR operation.</p>

<p>Return <em>the integer </em><code>x</code>. The test cases are generated such that <code>x</code> is <strong>uniquely determined</strong>.</p>

<p>The number of <strong>set bits</strong> of an integer is the number of <code>1</code>&#39;s in its binary representation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num1 = 3, num2 = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 3 = 0</code> is minimal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num1 = 1, num2 = 12
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 1 = 2</code> is minimal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1, num2 &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int c = __builtin_popcount(num2);
    int result = 0;
    for(int i = 30; i >= 0 && c; --i) {
      if((1 << i) & num1) {
        result = result | (1 << i);
        c -= 1;
      }
    }
    for(int i = 0; i < 30 && c; ++i) {
      if(!((1 << i) & num1)) {
        result = result | (1 << i);
        c -= 1;
      }
    }
    return result;
  }
};

// Accepted
// 277/277 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40.19 % of cpp submissions (8.1 MB)
```
