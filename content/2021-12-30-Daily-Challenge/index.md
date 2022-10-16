+++
title = "2021-12-30 Daily-Challenge"
path = "2021-12-30-Daily-Challenge"
date = 2021-12-30 19:35:00+08:00
updated = 2021-12-30 19:37:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/smallest-integer-divisible-by-k/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 30

## Description

**Smallest Integer Divisible by K**

Given a positive integer `k`, you need to find the **length** of the **smallest** positive integer `n` such that `n` is divisible by `k`, and `n` only contains the digit `1`.

Return *the **length** of* `n`. If there is no such `n`, return -1.

**Note:** `n` may not fit in a 64-bit signed integer.

 

**Example 1:**

```
Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.
```

**Example 2:**

```
Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.
```

**Example 3:**

```
Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
```

 

**Constraints:**

- `1 <= k <= 10^5`

## Solution

``` cpp
class Solution {
public:
  int smallestRepunitDivByK(int k) {
      if(k % 2 == 0 || k % 5 == 0) return -1;
      int cur = 0;
      for(int i = 1; i <= k; ++i) {
          cur = (cur * 10 + 1) % k;
          if(cur == 0) return i;
      }
      // actually won't go to here
      return INT_MAX;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.22 % of cpp submissions (6 MB)
```
