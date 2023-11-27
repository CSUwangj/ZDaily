+++
updated = 2023-11-27T13:39:41+08:00
title = "2023-11-27 Daily Challenge"
path = "2023-11-27-Daily-Challenge"
date = 2023-11-27T13:39:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/knight-dialer/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 27

## Description

**Knight Dialer**

<p>The chess knight has a <strong>unique movement</strong>,&nbsp;it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an <strong>L</strong>). The possible movements of chess knight are shown in this diagaram:</p>

<p>A chess knight can move as indicated in the chess diagram below:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/18/chess.jpg" style="width: 402px; height: 402px;" />
<p>We have a chess knight and a phone pad as shown below, the knight <strong>can only stand on a numeric cell</strong>&nbsp;(i.e. blue cell).</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/18/phone.jpg" style="width: 242px; height: 322px;" />
<p>Given an integer <code>n</code>, return how many distinct phone numbers of length <code>n</code> we can dial.</p>

<p>You are allowed to place the knight <strong>on any numeric cell</strong> initially and then you should perform <code>n - 1</code> jumps to dial a number of length <code>n</code>. All jumps should be <strong>valid</strong> knight jumps.</p>

<p>As the answer may be very large, <strong>return the answer modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 20
<strong>Explanation:</strong> All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3131
<strong>Output:</strong> 136006598
<strong>Explanation:</strong> Please take care of the mod.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>


## Solution

the problem is similar to the Fibonacci number, maybe we can rewrite it with matrix method, then we can calculate the answer when n is very large like 1e20.

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int knightDialer(int n) {
   int ways[2][10];
    for(int i = 0; i < 10; ++i) {
      ways[1][i] = 1;
    }
    for(int i = 2; i <= n; ++i) {
      int parity = (i & 1);
      ways[parity][0] = (ways[!parity][4] + ways[!parity][6]) % MOD;
      ways[parity][1] = (ways[!parity][6] + ways[!parity][8]) % MOD;
      ways[parity][2] = (ways[!parity][7] + ways[!parity][9]) % MOD;
      ways[parity][3] = (ways[!parity][4] + ways[!parity][8]) % MOD;
      ways[parity][4] = (ways[!parity][3] + ways[!parity][9]) % MOD;
      ways[parity][4] = (ways[parity][4] + ways[!parity][0]) % MOD;
      ways[parity][6] = (ways[!parity][1] + ways[!parity][7]) % MOD;
      ways[parity][6] = (ways[parity][6] + ways[!parity][0]) % MOD;
      ways[parity][7] = (ways[!parity][2] + ways[!parity][6]) % MOD;
      ways[parity][8] = (ways[!parity][1] + ways[!parity][3]) % MOD;
      ways[parity][9] = (ways[!parity][4] + ways[!parity][2]) % MOD;
      ways[parity][5] = 0;
    }
    int answer = 0;
    for(int i = 0; i < 10; ++i) {
      answer += ways[n & 1][i];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 121/121 cases passed (4 ms)
// Your runtime beats 97.08 % of cpp submissions
// Your memory usage beats 98.68 % of cpp submissions (6.2 MB)
```
