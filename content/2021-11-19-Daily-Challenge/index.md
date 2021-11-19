+++
title = "2021-11-19 Daily-Challenge"
path = "2021-11-19-Daily-Challenge"
date = 2021-11-19 18:49:38+08:00
updated = 2021-11-19 18:53:17+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/hamming-distance/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 19

## Description

**Hamming Distance**

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, return *the **Hamming distance** between them*.

 

**Example 1:**

```
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
```

**Example 2:**

```
Input: x = 3, y = 1
Output: 1
```

 

**Constraints:**

<ul>
	<li><code>0 &lt;=&nbsp;x, y &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
const int M1  = 0x55555555; // 01010101
const int M2  = 0x33333333; // 00110011
const int M4  = 0x0F0F0F0F; // 00001111
const int M8  = 0x00FF00FF; 
const int M16 = 0x0000FFFF;
constexpr int pop_count(int x) {
  x = (x & M1) + ((x >> 1) & M1);
  x = (x & M2) + ((x >> 2) & M2);
  x = (x & M4) + ((x >> 4) & M4);
  x = (x & M8) + ((x >> 8) & M8);
  x = (x & M16) + ((x >> 16) & M16);
  return x;
}
class Solution {
public:
  int hammingDistance(int x, int y) {
    return pop_count(x ^ y);
  }
};

// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.54 % of cpp submissions (5.9 MB)
```
