+++
title = "2021-09-24 Daily-Challenge"
path = "2021-09-24-Daily-Challenge"
date = 2021-09-24 20:03:11+08:00
updated = 2021-09-24 20:14:56+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3986/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 24

## Description

**N-th Tribonacci Number**

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given `n`, return the value of Tn.

 

**Example 1:**

```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**Example 2:**

```
Input: n = 25
Output: 1389537
```

 

**Constraints:**

- `0 <= n <= 37`
- The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.

## Solution

``` cpp
struct Table{
  constexpr Table() : values() {
    values[0] = 0;
    values[1] = 1;
    values[2] = 1;
    for(int i = 3; i < 38; ++i) {
      values[i] = values[i - 1] + values[i - 2] + values[i - 3];
    }
  }
  int values[38] = {};
};
constexpr auto table = Table();
class Solution {
public:
  int tribonacci(int n) {
    return table.values[n];
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 47.39 % of cpp submissions (5.9 MB)
```
