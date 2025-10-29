+++
updated = 2025-10-29T12:52:30+01:00
title = "2025-10-29 Daily Challenge"
path = "2025-10-29-Daily-Challenge"
date = 2025-10-29T12:52:30+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/smallest-number-with-all-set-bits/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 29

## Description

**Smallest Number With All Set Bits**

<p>You are given a <em>positive</em> number <code>n</code>.</p>

<p>Return the <strong>smallest</strong> number <code>x</code> <strong>greater than</strong> or <strong>equal to</strong> <code>n</code>, such that the binary representation of <code>x</code> contains only <span data-keyword="set-bit">set bits</span></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p>The binary representation of 7 is <code>&quot;111&quot;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 10</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<p>The binary representation of 15 is <code>&quot;1111&quot;</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The binary representation of 3 is <code>&quot;11&quot;</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int smallestNumber(int n) {
    int base = 1;
    while((1 << base) - 1 < n) {
      base += 1;
    }
    return (1 << base) - 1;
  }
};

// Accepted
// 608/608 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.74 % of cpp submissions (8 MB)
```
