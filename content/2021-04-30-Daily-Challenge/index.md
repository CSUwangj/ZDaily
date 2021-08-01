+++
title = "2021-04-30 Daily-Challenge"
path = "2021-04-30-Daily-Challenge"
date = 2021-04-30 18:50:22+08:00
updated = 2021-04-30 19:15:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Power of Four](https://leetcode.com/problems/power-of-four/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3723/) with `cpp`.

<!-- more -->

# Power of Four

## Description

Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

 

**Example 1:**

```
Input: n = 16
Output: true
```

**Example 2:**

```
Input: n = 5
Output: false
```

**Example 3:**

```
Input: n = 1
Output: true
```

 

**Constraints:**

- <code>-2<sup>31</sup> <= n <= 2<sup>31</sup> - 1</code>

## Solution

``` cpp
class Solution {
public:
  bool isPowerOfFour(int n) {
    if(n < 1) return false;
    double p = log(n) / log(4);
    double diff = abs(p - floor(p));
    return diff < numeric_limits<double>::epsilon();  
  }
};
```

# April LeetCoding challenge 30

## Description

**Find First and Last Position of Element in Sorted Array**
Given three integers `x`, `y`, and `bound`, return *a list of all the **powerful integers** that have a value less than or equal to* `bound`.

An integer is **powerful** if it can be represented as `xi + yj` for some integers `i >= 0` and `j >= 0`.

You may return the answer in **any order**. In your answer, each value should occur **at most once**.

 

**Example 1:**

```
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
```

**Example 2:**

```
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
```

 

**Constraints:**

- `1 <= x, y <= 100`
- <code>0 <= bound <= 10<sup>6</sup></code>

## Solution

``` cpp
class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    if(x == 1 && y == 1) {
      if(bound >= 2) return {2};
      return {};
    }
    if(x == 1 || y == 1) {
      int rest = x == 1 ? y : x;
      int cur = 1;
      vector<int> answer;
      while(cur + 1 <= bound) {
        answer.push_back(cur + 1);
        cur *= rest;
      }
      return answer;
    }
    unordered_set<int> answer;
    for(int i = 1; i + 1 <= bound; i *= x) {
      for(int j = 1; j + i <= bound; j *= y) {
        answer.insert(i + j);
      }
    }
    return vector<int>(answer.begin(), answer.end()); 
  }
};

// 102 / 102 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 6.6 MB
```
