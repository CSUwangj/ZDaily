+++
title = "2022-01-04 Daily-Challenge"
path = "2022-01-04-Daily-Challenge"
date = 2022-01-04 18:17:00+08:00
updated = 2022-01-04 18:18:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/complement-of-base-10-integer/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 4

## Description

**Complement of Base 10 Integer**

The **complement** of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

- For example, The integer `5` is `"101"` in binary and its **complement** is `"010"` which is the integer `2`.

Given an integer `n`, return *its complement*.

 

**Example 1:**

```
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

**Example 2:**

```
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

**Example 3:**

```
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

 

**Constraints:**

- `0 <= n < 10^9`

 

**Note:** This question is the same as 476: https://leetcode.com/problems/number-complement/

## Solution

``` cpp
class Solution {
public:
  int bitwiseComplement(int n) {
    if(n > INT_MAX / 2) return INT_MAX ^ n;
    int bit = 1;
    while(bit <= n) {
      bit <<= 1;
    }
    return (bit - 1 | 1) ^ n;
  }
};

// Accepted
// 128/128 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.27 % of cpp submissions (5.9 MB)
```
