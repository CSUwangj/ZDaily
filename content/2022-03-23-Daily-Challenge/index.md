+++
updated = 2022-03-23 18:43:00+08:00
title = "2022-03-23 Daily-Challenge"
path = "2022-03-23-Daily-Challenge"
date = 2022-03-23 18:42:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/broken-calculator/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 23

## Description

**Broken Calculator**

There is a broken calculator that has the integer `startValue` on its display initially. In one operation, you can:

- multiply the number on display by `2`, or
- subtract `1` from the number on display.

Given two integers `startValue` and `target`, return *the minimum number of operations needed to display* `target` *on the calculator*.

 

**Example 1:**

```
Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
```

**Example 2:**

```
Input: startValue = 5, target = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
```

**Example 3:**

```
Input: startValue = 3, target = 10
Output: 3
Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.
```

 

**Constraints:**

- `1 <= x, y <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int brokenCalc(int X, int Y) {
    int answer = 0;
    while(Y > X) {
        if(Y & 1) Y += 1;
        else Y /= 2;
        answer += 1;
    }
    return answer + X - Y;
  }
};

// Accepted
// 84/84 cases passed (3 ms)
// Your runtime beats 32.55 % of cpp submissions
// Your memory usage beats 73.18 % of cpp submissions (5.8 MB)
```
