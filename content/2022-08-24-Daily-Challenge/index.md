+++
updated = 2022-08-24 18:14:00+08:00
title = "2022-08-24 Daily-Challenge"
path = "2022-08-24-Daily-Challenge"
date = 2022-08-24 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/power-of-three/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 24

## Description

**Power of Three**

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

 

**Example 1:**

```
Input: n = 27
Output: true
```

**Example 2:**

```
Input: n = 0
Output: false
```

**Example 3:**

```
Input: n = 9
Output: true
```

 

**Constraints:**

- `-231 <= n <= 231 - 1`

 

**Follow up:** Could you solve it without loops/recursion?

## Solution

``` cpp
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};

// Accepted
// 21038/21038 cases passed (18 ms)
// Your runtime beats 92.54 % of cpp submissions
// Your memory usage beats 88.51 % of cpp submissions (5.8 MB)
```
