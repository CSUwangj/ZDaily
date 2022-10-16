+++
updated = 2022-07-06 18:14:00+08:00
title = "2022-07-06 Daily-Challenge"
path = "2022-07-06-Daily-Challenge"
date = 2022-07-06 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/fibonacci-number/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 6

## Description

**Fibonacci Number**

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

 

**Example 1:**

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

 

**Constraints:**

- `0 <= n <= 30`

## Solution

``` cpp
struct mat {
  int val[2][2] = {};
};

const mat base = {
  .val = {{1, 1}, {1, 0}}
};

//  a b  |  1 1 
//  0 0  |  1 0

//  a+b b
//   0  0

constexpr mat multiply(mat a, mat b) {
  mat result;
  result.val[0][0] = a.val[0][0] * b.val[0][0] + a.val[0][1] * b.val[1][0];
  result.val[0][1] = a.val[0][0] * b.val[0][1] + a.val[0][1] * b.val[1][1];
  result.val[1][0] = a.val[1][0] * b.val[0][0] + a.val[1][1] * b.val[1][0];
  result.val[1][1] = a.val[1][0] * b.val[0][1] + a.val[1][1] * b.val[1][1];
  return result;
}

constexpr mat exp(mat b, int e) {
  mat result = {
    .val = {{1, 0}, {0, 1}}
  };
  while(e) {
    if(e & 1) {
      result = multiply(result, b);
    }
    b = multiply(b, b);
    e >>= 1;
  }
  return result;
}

class Solution {
public:
  int fib(int n) {
    mat result = { .val = {{1, 0}, {0, 0}} };
    result = multiply(result, exp(base, n));
    return result.val[0][1];
  }
};

// Accepted
// 31/31 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.05 % of cpp submissions (5.9 MB)
```
