+++
updated = 2025-11-25T10:12:41+01:00
title = "2025-11-25 Daily Challenge"
path = "2025-11-25-Daily-Challenge"
date = 2025-11-25T10:12:41+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/smallest-integer-divisible-by-k/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 25

## Description

**Smallest Integer Divisible by K**

<p>Given a positive integer <code>k</code>, you need to find the <strong>length</strong> of the <strong>smallest</strong> positive integer <code>n</code> such that <code>n</code> is divisible by <code>k</code>, and <code>n</code> only contains the digit <code>1</code>.</p>

<p>Return <em>the <strong>length</strong> of </em><code>n</code>. If there is no such <code>n</code>, return -1.</p>

<p><strong>Note:</strong> <code>n</code> may not fit in a 64-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The smallest answer is n = 1, which has length 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no such positive integer n divisible by 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The smallest answer is n = 111, which has length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if(k % 2 == 0 || k % 5 == 0) return -1;
    int cur = 0;
    for(int i = 1; i <= k; ++i) {
      cur = (cur * 10 + 1) % k;
      if(cur == 0) return i;
    }
    // actually won't go to here
    return INT_MAX;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.22 % of cpp submissions (6 MB)
```
