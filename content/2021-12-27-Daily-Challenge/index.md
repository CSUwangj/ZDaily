+++
title = "2021-12-27 Daily-Challenge"
path = "2021-12-27-Daily-Challenge"
date = 2021-12-27 18:51:00+08:00
updated = 2021-12-27 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/number-complement/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 27

## Description

**Number Complement**

The **complement** of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

- For example, The integer `5` is `"101"` in binary and its **complement** is `"010"` which is the integer `2`.

Given an integer `num`, return *its complement*.

 

**Example 1:**

```
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

**Example 2:**

```
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

 

**Constraints:**

- <code>1 &lt;= num &lt; 2<sup>31</sup></code>

 

**Note:** This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

## Solution

``` cpp
class Solution {
public:
  int findComplement(int n) {
    if(n > INT_MAX / 2) return INT_MAX ^ n;
    int bit = 1;
    while(bit <= n) {
      bit <<= 1;
    }
    return (bit - 1 | 1) ^ n;
  }
};

// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40.00 % of cpp submissions (6 MB)
```
