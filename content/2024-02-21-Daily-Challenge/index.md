+++
updated = 2024-02-21T21:05:08+08:00
title = "2024-02-21 Daily Challenge"
path = "2024-02-21-Daily-Challenge"
date = 2024-02-21T21:05:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/bitwise-and-of-numbers-range/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 21

## Description

**Bitwise AND of Numbers Range**

<p>Given two integers <code>left</code> and <code>right</code> that represent the range <code>[left, right]</code>, return <em>the bitwise AND of all numbers in this range, inclusive</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> left = 5, right = 7
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> left = 0, right = 0
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> left = 1, right = 2147483647
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= left &lt;= right &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
constexpr int highbit(int x) {
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;
  x ^= x >> 1;
  return x;
}
class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    if(left == right) return left;
    int result = left & right;
    int answer = 0;
    int bit = highbit(right);
    while(bit) {
      if(bit & result) {
        answer |= bit;
      } else if((bit & left) || (bit & right)) {
        break;
      }
      bit >>= 1;
    }
    return answer;
  }
};

// Accepted
// 8268/8268 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 77.49 % of cpp submissions (5.9 MB)
```
