+++
updated = 2023-10-30T14:19:10+08:00
title = "2023-10-30 Daily Challenge"
path = "2023-10-30-Daily-Challenge"
date = 2023-10-30T14:19:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 30

## Description

**Sort Integers by The Number of 1 Bits**

<p>You are given an integer array <code>arr</code>. Sort the integers in the array&nbsp;in ascending order by the number of <code>1</code>&#39;s&nbsp;in their binary representation and in case of two or more integers have the same number of <code>1</code>&#39;s you have to sort them in ascending order.</p>

<p>Return <em>the array after sorting it</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [0,1,2,3,4,5,6,7,8]
<strong>Output:</strong> [0,1,2,4,8,3,5,6,7]
<strong>Explantion:</strong> [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1024,512,256,128,64,32,16,8,4,2,1]
<strong>Output:</strong> [1,2,4,8,16,32,64,128,256,512,1024]
<strong>Explantion:</strong> All integers have 1 bit in the binary representation, you should just sort them in ascending order.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
const int M1  = 0X55555555; // 01010101010101010101010101010101
const int M2  = 0X33333333; // 00110011001100110011001100110011
const int M4  = 0X0F0F0F0F; // 00001111000011110000111100001111
const int M8  = 0X00FF00FF; // 00000000111111110000000011111111
const int M16 = 0X0000FFFF; // 00000000000000001111111111111111
constexpr int popcount(int x) { 
  x = (x & M1) + ((x >> 1) & M1);
  x = (x & M2) + ((x >> 2) & M2);
  x = (x & M4) + ((x >> 4) & M4);
  x = (x & M8) + ((x >> 8) & M8);
  x = (x & M16) + ((x >> 16) & M16);
  return x;
}
class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int ba = popcount(a);
      int bb = popcount(b);
      return ba < bb || (ba == bb && a < b); 
    });
    return arr;
  }
};

// Accepted
// 77/77 cases passed (6 ms)
// Your runtime beats 76.61 % of cpp submissions
// Your memory usage beats 66.29 % of cpp submissions (10.5 MB)
```
