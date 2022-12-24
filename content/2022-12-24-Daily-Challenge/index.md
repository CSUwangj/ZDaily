+++
updated = 2022-12-24T21:52:30+08:00
title = "2022-12-24 Daily Challenge"
path = "2022-12-24-Daily-Challenge"
date = 2022-12-24T21:52:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/domino-and-tromino-tiling/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 24

## Description

**Domino and Tromino Tiling**

<p>You have two types of tiles: a <code>2 x 1</code> domino shape and a tromino shape. You may rotate these shapes.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg" style="width: 362px; height: 195px;" />
<p>Given an integer n, return <em>the number of ways to tile an</em> <code>2 x n</code> <em>board</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg" style="width: 500px; height: 226px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The five different ways are show above.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
auto table = [](){
  array<int, 1001> table{1, 1, 2};
  for(int i = 3; i < 1001; ++i) {
    table[i] = table[i - 1] + table[i - 2] % MOD;
    table[i] %= MOD;
    table[i] += table[i - 3] * 2 % MOD;
    table[i] %= MOD;
    for(int j = 4; j <= i; ++j) {
      table[i] += 2 * table[i - j] % MOD;
      table[i] %= MOD;
    }
  }
  return table;
}();
class Solution {
public:
  int numTilings(int n) {
    return table[n];
  }
};
// Accepted
// 39/39 cases passed (4 ms)
// Your runtime beats 32.61 % of cpp submissions
// Your memory usage beats 60.67 % of cpp submissions (6 MB)
```
