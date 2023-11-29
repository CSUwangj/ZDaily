+++
updated = 2023-11-29T12:33:30+08:00
title = "2023-11-29 Daily Challenge"
path = "2023-11-29-Daily-Challenge"
date = 2023-11-29T12:33:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/number-of-1-bits/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 29

## Description

**Number of 1 Bits**

<p>Write a function that takes&nbsp;the binary representation of an unsigned integer and returns the number of &#39;1&#39; bits it has (also known as the <a href="http://en.wikipedia.org/wiki/Hamming_weight" target="_blank">Hamming weight</a>).</p>

<p><strong>Note:</strong></p>

<ul>
	<li>Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer&#39;s internal binary representation is the same, whether it is signed or unsigned.</li>
	<li>In Java, the compiler represents the signed integers using <a href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2&#39;s complement notation</a>. Therefore, in <strong class="example">Example 3</strong>, the input represents the signed integer. <code>-3</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 00000000000000000000000000001011
<strong>Output:</strong> 3
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000000001011</strong> has a total of three &#39;1&#39; bits.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 00000000000000000000000010000000
<strong>Output:</strong> 1
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000010000000</strong> has a total of one &#39;1&#39; bit.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 11111111111111111111111111111101
<strong>Output:</strong> 31
<strong>Explanation:</strong> The input binary string <strong>11111111111111111111111111111101</strong> has a total of thirty one &#39;1&#39; bits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The input must be a <strong>binary string</strong> of length <code>32</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If this function is called many times, how would you optimize it?

## Solution

``` cpp
const uint32_t m1 = 0x55555555;
const uint32_t m2 = 0x33333333;
const uint32_t m4 = 0x0F0F0F0F;
const uint32_t m8 = 0x00FF00FF;
const uint32_t m16 = 0x0000FFFF;
class Solution { 
public:
  int hammingWeight(uint32_t n) {
    n = (n & m1) + ((n >> 1) & m1);
    n = (n & m2) + ((n >> 2) & m2);
    n = (n & m4) + ((n >> 4) & m4);
    n = (n & m8) + ((n >> 8) & m8);
    n = (n & m16) + ((n >> 16) & m16);
    return n;
  }
};

// Accepted
// 601/601 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 57.22 % of cpp submissions (6.4 MB)
```
