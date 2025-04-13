+++
updated = 2025-04-13T10:31:41+08:00
title = "2025-04-13 Daily Challenge"
path = "2025-04-13-Daily-Challenge"
date = 2025-04-13T10:31:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-good-numbers/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 13

## Description

**Count Good Numbers**

<p>A digit string is <strong>good</strong> if the digits <strong>(0-indexed)</strong> at <strong>even</strong> indices are <strong>even</strong> and the digits at <strong>odd</strong> indices are <strong>prime</strong> (<code>2</code>, <code>3</code>, <code>5</code>, or <code>7</code>).</p>

<ul>
	<li>For example, <code>&quot;2582&quot;</code> is good because the digits (<code>2</code> and <code>8</code>) at even positions are even and the digits (<code>5</code> and <code>2</code>) at odd positions are prime. However, <code>&quot;3245&quot;</code> is <strong>not</strong> good because <code>3</code> is at an even index but is not even.</li>
</ul>

<p>Given an integer <code>n</code>, return <em>the <strong>total</strong> number of good digit strings of length </em><code>n</code>. Since the answer may be large, <strong>return it modulo </strong><code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>digit string</strong> is a string consisting of digits <code>0</code> through <code>9</code> that may contain leading zeros.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good numbers of length 1 are &quot;0&quot;, &quot;2&quot;, &quot;4&quot;, &quot;6&quot;, &quot;8&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> 400
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 50
<strong>Output:</strong> 564908303
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>15</sup></code></li>
</ul>


## Solution

``` cpp
inline long long qpow(long long base, long long exp, long long mod) {
  long long result = 1;
  while(exp) {
    if(exp & 1) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    exp >>= 1;
  }
  return result;
}
class Solution {
  const int MOD = 1e9 + 7;
public:
  int countGoodNumbers(long long n) {
    return qpow(5, (1 + n) / 2, MOD) * qpow(4, n / 2, MOD) % MOD;
  }
};

// Accepted
// 166/166 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.99 % of cpp submissions (7.9 MB)
```
