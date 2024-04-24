+++
updated = 2024-04-24T19:44:53+08:00
title = "2024-04-24 Daily Challenge"
path = "2024-04-24-Daily-Challenge"
date = 2024-04-24T19:44:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/n-th-tribonacci-number/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 24

## Description

**N-th Tribonacci Number**

<p>The Tribonacci sequence T<sub>n</sub> is defined as follows:&nbsp;</p>

<p>T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, and T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub> for n &gt;= 0.</p>

<p>Given <code>n</code>, return the value of T<sub>n</sub>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 25
<strong>Output:</strong> 1389537
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 37</code></li>
	<li>The answer is guaranteed to fit within a 32-bit integer, ie. <code>answer &lt;= 2^31 - 1</code>.</li>
</ul>

## Solution

``` cpp
struct Table{
  constexpr Table() : values() {
    values[0] = 0;
    values[1] = 1;
    values[2] = 1;
    for(int i = 3; i < 38; ++i) {
      values[i] = values[i - 1] + values[i - 2] + values[i - 3];
    }
  }
  int values[38] = {};
};
constexpr auto table = Table();
class Solution {
public:
  int tribonacci(int n) {
    return table.values[n];
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 47.39 % of cpp submissions (5.9 MB)
```
