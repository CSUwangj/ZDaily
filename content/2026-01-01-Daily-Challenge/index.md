+++
updated = 2026-01-01T06:36:33+01:00
title = "2026-01-01 Daily Challenge"
path = "2026-01-01-Daily-Challenge"
date = 2026-01-01T06:36:33+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/plus-one/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 1

## Description

**Plus One**

<p>You are given a <strong>large integer</strong> represented as an integer array <code>digits</code>, where each <code>digits[i]</code> is the <code>i<sup>th</sup></code> digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading <code>0</code>&#39;s.</p>

<p>Increment the large integer by one and return <em>the resulting array of digits</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> digits = [1,2,3]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> digits = [4,3,2,1]
<strong>Output:</strong> [4,3,2,2]
<strong>Explanation:</strong> The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> digits = [9]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li><code>digits</code> does not contain any leading <code>0</code>&#39;s.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for(auto it = digits.rbegin(); carry && it != digits.rend(); ++it) {
      int curVal = *it + carry;
      carry = curVal / 10;
      *it = curVal % 10;
    }
    if(carry == 1) {
      digits.insert(digits.begin(), 1, 1);
    }
    return digits;
  }
};

// Accepted
// 112/112 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50.17 % of cpp submissions (11.6 MB)
```
