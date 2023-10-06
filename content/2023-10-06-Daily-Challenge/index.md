+++
updated = 2023-10-06T13:26:33+08:00
title = "2023-10-06 Daily Challenge"
path = "2023-10-06-Daily-Challenge"
date = 2023-10-06T13:26:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/integer-break/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 6

## Description

**Integer Break**

<p>Given an integer <code>n</code>, break it into the sum of <code>k</code> <strong>positive integers</strong>, where <code>k &gt;= 2</code>, and maximize the product of those integers.</p>

<p>Return <em>the maximum product you can get</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> 2 = 1 + 1, 1 &times; 1 = 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 36
<strong>Explanation:</strong> 10 = 3 + 3 + 4, 3 &times; 3 &times; 4 = 36.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 58</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int integerBreak(int n) {
    int answer = 0;
    int k = 1;
    do {
      k += 1;
      int result = 1;
      int base = n / k;
      int reminder = n % k;
      for(int i = 0; i < n % k; ++i) {
        result *= base + 1;
      }
      for(int i = 0; i < k - n % k; ++i) {
        result *= base;
      }
      answer = max(result, answer);
    }while(k < n);
    return answer;
  }
};

// Accepted
// 50/50 cases passed (2 ms)
// Your runtime beats 49.96 % of cpp submissions
// Your memory usage beats 36.38 % of cpp submissions (6.3 MB)
```
