+++
updated = 2023-07-24T11:33:43+08:00
title = "2023-07-24 Daily Challenge"
path = "2023-07-24-Daily-Challenge"
date = 2023-07-24T11:33:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/powx-n/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 24

## Description

**Pow(x, n)**

<p>Implement <a href="http://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(x, n)</a>, which calculates <code>x</code> raised to the power <code>n</code> (i.e., <code>x<sup>n</sup></code>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 2.00000, n = 10
<strong>Output:</strong> 1024.00000
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = 2.10000, n = 3
<strong>Output:</strong> 9.26100
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> x = 2.00000, n = -2
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-100.0 &lt; x &lt; 100.0</code></li>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup>-1</code></li>
	<li><code>n</code> is an integer.</li>
	<li>Either <code>x</code> is not zero or <code>n &gt; 0</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= x<sup>n</sup> &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
class Solution {
public:
  double myPow(double x, int n) {
    int sign = sgn(n);
    n = abs(n);
    double result = 1;
    double base = x;
    while(n) {
      if(n & 1) result *= base;
      base *= base;
      n /= 2;
    }
    return sign == -1 ? 1 / result : 1 * result;
  }
};

// Accepted
// 306/306 cases passed (4 ms)
// Your runtime beats 40.18 % of cpp submissions
// Your memory usage beats 62.65 % of cpp submissions (5.9 MB)
```
