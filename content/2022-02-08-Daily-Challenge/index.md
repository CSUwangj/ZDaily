+++
title = "2022-02-08 Daily-Challenge"
path = "2022-02-08-Daily-Challenge"
date = 2022-02-08 19:20:00+08:00
updated = 2022-02-08 19:29:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/add-digits/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 8

## Description

**Add Digits**

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

 

**Example 1:**

```
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
```

**Example 2:**

```
Input: num = 0
Output: 0
```

 

**Constraints:**

- <code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code>

**Follow up:** Could you do it without any loop/recursion in `O(1)` runtime?

## Solution

``` cpp
class Solution {
public:
  int addDigits(int num) {
    if(!num) return num;
    if(!(num % 9)) return 9;
    return num % 9;
  }
};

// Accepted
// 1101/1101 cases passed (5 ms)
// Your runtime beats 17.94 % of cpp submissions
// Your memory usage beats 75.31 % of cpp submissions (5.9 MB)
```
