+++
updated = 2022-06-27 18:14:00+08:00
title = "2022-06-27 Daily-Challenge"
path = "2022-06-27-Daily-Challenge"
date = 2022-06-27 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 27

## Description

**Partitioning Into Minimum Number Of Deci-Binary Numbers**

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are **deci-binary**, while `112` and `3001` are not.

Given a string `n` that represents a positive decimal integer, return *the **minimum** number of positive **deci-binary** numbers needed so that they sum up to* `n`*.*

 

**Example 1:**

```
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
```

**Example 2:**

```
Input: n = "82734"
Output: 8
```

**Example 3:**

```
Input: n = "27346209830709182346"
Output: 9
```

 

**Constraints:**

- `1 <= n.length <= 10^5`
- `n` consists of only digits.
- `n` does not contain any leading zeros and represents a positive integer.

## Solution

``` cpp
class Solution {
public:
  int minPartitions(string n) {
    return *max_element(n.begin(), n.end()) - '0';
  }
};

// Accepted
// 97/97 cases passed (64 ms)
// Your runtime beats 14.51 % of cpp submissions
// Your memory usage beats 92.75 % of cpp submissions (13.4 MB)
```
