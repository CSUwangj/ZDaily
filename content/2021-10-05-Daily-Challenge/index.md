+++
title = "2021-10-05 Daily-Challenge"
path = "2021-10-05-Daily-Challenge"
date = 2021-10-05 13:57:03+08:00
updated = 2021-10-05 14:09:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/climbing-stairs/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 5

## Description

**Climbing Stairs**

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

 

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

 

**Constraints:**

- `1 <= n <= 45`

## Solution

``` cpp
constexpr auto table = []{
  array<int, 46> arr{1, 1};
  for(int i = 2; i < 46; ++i) arr[i] = arr[i - 1] + arr[i - 2];
  return arr;
}();
class Solution {
public:
  int climbStairs(int n) {
    return table[n];
  }
};

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 54.53 % of cpp submissions (6 MB)
```
