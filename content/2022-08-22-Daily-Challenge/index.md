+++
updated = 2022-08-22 18:14:00+08:00
title = "2022-08-22 Daily-Challenge"
path = "2022-08-22-Daily-Challenge"
date = 2022-08-22 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/stamping-the-sequence/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 22

## Description

**Power of Four**

Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

 

**Example 1:**

```
Input: n = 16
Output: true
```

**Example 2:**

```
Input: n = 5
Output: false
```

**Example 3:**

```
Input: n = 1
Output: true
```

 

**Constraints:**

- `-2^31 <= n <= 2^31 - 1`

 

**Follow up:** Could you solve it without loops/recursion?

## Solution

``` cpp
class Solution {
public:
  bool isPowerOfFour(int n) {
    return n && __builtin_popcount(n) == 1 && !(__builtin_ctz(n) & 1);
  }
};

// Accepted
// 1061/1061 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 71.3 % of cpp submissions (5.8 MB)
```
