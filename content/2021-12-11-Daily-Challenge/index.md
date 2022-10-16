+++
title = "2021-12-11 Daily-Challenge"
path = "2021-12-11-Daily-Challenge"
date = 2021-12-11 09:41:00+08:00
updated = 2021-12-11 09:56:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/nth-magical-number/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 10

## Description

**Nth Magical Number**

A positive integer is *magical* if it is divisible by either `a` or `b`.

Given the three integers `n`, `a`, and `b`, return the `nth` magical number. Since the answer may be very large, **return it modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 1, a = 2, b = 3
Output: 2
```

**Example 2:**

```
Input: n = 4, a = 2, b = 3
Output: 6
```

**Example 3:**

```
Input: n = 5, a = 2, b = 4
Output: 10
```

**Example 4:**

```
Input: n = 3, a = 6, b = 4
Output: 8
```

 

**Constraints:**

- `1 <= n <= 10^9`
- `2 <= a, b <= 4 * 10^4`

## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr int lcm(int a, int b) {
  int originA = a;
  int originB = b;
  int c = a % b;
  while(c) {
    a = b;
    b = c;
    c = a % b;
  }
  return originA / b * originB;
}
constexpr int findOffset(int a, int b, int g, int rest) {
  unsigned int low = 0;
  unsigned int high = g;
  while(low < high) {
    unsigned int mid = (low + high) >> 1;
    if(mid / a + mid / b < rest) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low % MOD;
}
class Solution {
public:
  int nthMagicalNumber(int n, int a, int b) {
    if(a < b) swap(a, b);
    if(!(a % b)) return 1LL * n * b % MOD;
    int g = lcm(a, b);
    int count = g / a + g / b - 1;
    int whole = 1LL * g * (n / count) % MOD;
    return (whole + findOffset(a, b, g, n % count)) % MOD;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 94.83 % of cpp submissions (5.7 MB)
```
