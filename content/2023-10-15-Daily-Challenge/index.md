+++
updated = 2023-10-15T20:58:35+08:00
title = "2023-10-15 Daily Challenge"
path = "2023-10-15-Daily-Challenge"
date = 2023-10-15T20:58:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 15

## Description

**Number of Ways to Stay in the Same Place After Some Steps**

<p>You have a pointer at index <code>0</code> in an array of size <code>arrLen</code>. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).</p>

<p>Given two integers <code>steps</code> and <code>arrLen</code>, return the number of ways such that your pointer is still at index <code>0</code> after <strong>exactly</strong> <code>steps</code> steps. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> steps = 3, arrLen = 2
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> steps = 2, arrLen = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> steps = 4, arrLen = 2
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= steps &lt;= 500</code></li>
	<li><code>1 &lt;= arrLen &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
int ways[2][500];
class Solution {
public:
  int numWays(int steps, int arrLen) {
    if(arrLen == 1) return 1;
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    int boundary = min(arrLen, 500);
    for(int i = 1; i <= steps; ++i) {
      int parity = i & 1;
      ways[parity][0] = (ways[!parity][0] + ways[!parity][1]) % MOD;
      ways[parity][boundary - 1] = (ways[!parity][boundary - 1] + ways[!parity][boundary - 2]) % MOD;
      for(int j = 1; j < boundary - 1; ++j) {
        ways[parity][j] = ways[!parity][j - 1];
        ways[parity][j] += ways[!parity][j];
        ways[parity][j] %= MOD;
        ways[parity][j] += ways[!parity][j + 1];
        ways[parity][j] %= MOD;
      }
    }
    return ways[steps & 1][0];
  }
};

// Accepted
// 33/33 cases passed (7 ms)
// Your runtime beats 94.59 % of cpp submissions
// Your memory usage beats 98.27 % of cpp submissions (6.3 MB)
```
