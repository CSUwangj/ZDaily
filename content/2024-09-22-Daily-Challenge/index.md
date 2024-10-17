+++
updated = 2024-09-22T19:51:37+08:00
title = "2024-09-22 Daily Challenge"
path = "2024-09-22-Daily-Challenge"
date = 2024-09-22T19:51:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 22

## Description

**K-th Smallest in Lexicographical Order**

<p>Given two integers <code>n</code> and <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>lexicographically smallest integer in the range</em> <code>[1, n]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 13, k = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  int getReqNum(long long a, long long b, int &n) {
    int gap = 0;
    while(a <= n) {
      gap += min<long long>(n + 1, b) - a;
      a *= 10;
      b *= 10;
    }
    return gap;
  }
public:
  int findKthNumber(int n, int k) {
    long long num = 1;
    for(int i = 1; i < k; ) {
      int req = getReqNum(num, num + 1, n);
      if(i + req <= k) {
        i += req;
        num += 1;
      } else {
        i += 1;
        num *= 10;
      }
    }
    return num;
  }
};
```
