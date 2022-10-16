+++
updated = 2022-05-27 18:14:00+08:00
title = "2022-05-27 Daily-Challenge"
path = "2022-05-27-Daily-Challenge"
date = 2022-05-27 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 27

## Description

**Number of Steps to Reduce a Number to Zero**

Given an integer `num`, return *the number of steps to reduce it to zero*.

In one step, if the current number is even, you have to divide it by `2`, otherwise, you have to subtract `1` from it.

 

**Example 1:**

```
Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
```

**Example 2:**

```
Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
```

**Example 3:**

```
Input: num = 123
Output: 12
```

 

**Constraints:**

- `0 <= num <= 10^6`

## Solution

``` cpp
class Solution {
public:
  int numberOfSteps (int num) {
    int answer = 0;
    while(num) {
      if(num % 2) num -= 1;
      else num >>= 1;
      ++answer;
    }
    return answer;
  }
};

// Accepted
// 204/204 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 74.11 % of cpp submissions (5.8 MB)
```
