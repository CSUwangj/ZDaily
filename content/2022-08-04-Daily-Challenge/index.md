+++
updated = 2022-08-04 18:14:00+08:00
title = "2022-08-04 Daily-Challenge"
path = "2022-08-04-Daily-Challenge"
date = 2022-08-04 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/mirror-reflection/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 4

## Description

**Mirror Reflection**

There is a  special square room with mirrors on each of the four walls. Except for  the southwest corner, there are receptors on each of the remaining  corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p` and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0th` receptor.

Given the two integers `p` and `q`, return *the number of the receptor that the ray meets first*.

The test cases are guaranteed so that the ray will meet a receptor eventually.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png)

```
Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
```

**Example 2:**

```
Input: p = 3, q = 1
Output: 1
```

 

**Constraints:**

- `1 <= q <= p <= 1000`

## Solution

``` cpp
class Solution {
  int gcd(int a, int b) {
    while(b) {
      int c = a;
      a = b;
      b = c % a;
    }
    return a;
  }
public:
  int mirrorReflection(int p, int q) {
    int metY = p*q/gcd(p, q);
    int metX = metY / q * p;
    int roundX = metX / p;
    int roundY = metY / p;
    
    if((roundY & roundX & 1) == 1) return 1;
    if((roundY & 1 == 1)) return 2;
    return 0;
  }
};

// Accepted
// 69/69 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 62.81 % of cpp submissions (5.9 MB)
```
