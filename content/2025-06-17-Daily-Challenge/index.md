+++
updated = 2025-06-18T02:50:39+08:00
title = "2025-06-17 Daily Challenge"
path = "2025-06-17-Daily-Challenge"
date = 2025-06-18T02:50:39+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 17

## Description

**Count the Number of Arrays with K Matching Adjacent Elements**

<p>You are given three integers <code>n</code>, <code>m</code>, <code>k</code>. A <strong>good array</strong> <code>arr</code> of size <code>n</code> is defined as follows:</p>

<ul>
	<li>Each element in <code>arr</code> is in the <strong>inclusive</strong> range <code>[1, m]</code>.</li>
	<li><em>Exactly</em> <code>k</code> indices <code>i</code> (where <code>1 &lt;= i &lt; n</code>) satisfy the condition <code>arr[i - 1] == arr[i]</code>.</li>
</ul>

<p>Return the number of <strong>good arrays</strong> that can be formed.</p>

<p>Since the answer may be very large, return it <strong>modulo </strong><code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, m = 2, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>There are 4 good arrays. They are <code>[1, 1, 2]</code>, <code>[1, 2, 2]</code>, <code>[2, 1, 1]</code> and <code>[2, 2, 1]</code>.</li>
	<li>Hence, the answer is 4.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, m = 2, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The good arrays are <code>[1, 1, 1, 2]</code>, <code>[1, 1, 2, 2]</code>, <code>[1, 2, 2, 2]</code>, <code>[2, 1, 1, 1]</code>, <code>[2, 2, 1, 1]</code> and <code>[2, 2, 2, 1]</code>.</li>
	<li>Hence, the answer is 6.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, m = 2, k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The good arrays are <code>[1, 2, 1, 2, 1]</code> and <code>[2, 1, 2, 1, 2]</code>. Hence, the answer is 2.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
const int MMAX = 1e5 + 1;

long long fact[MMAX] = {};
long long invFact[MMAX] = {};
long long qpow(long long base, int exp) {
  long long result = 1;
  while (exp) {
    if (exp & 1) {
      result *= base;
      result %= MOD;
    }
    base *= base;
    base %= MOD;
    exp >>= 1;
  }
  return result;
}

long long combination(int n, int m) {
  return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
}
auto _ = [](){
  fact[0] = 1;
  for (int i = 1; i < MMAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }

  invFact[MMAX - 1] = qpow(fact[MMAX - 1], MOD - 2);
  for (int i = MMAX - 1; i; i--) {
    invFact[i - 1] = invFact[i] * i % MOD;
  }
  return 2;
}();
class Solution {
public:
  int countGoodArrays(int n, int m, int k) {
    return combination(n - 1, k) * m % MOD * qpow(m - 1, n - 1 - k) % MOD;
  }
};

// Accepted
// 809/809 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 79.55 % of cpp submissions (9.9 MB)
```
