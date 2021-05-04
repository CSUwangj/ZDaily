+++
title = "2021-05-04 Daily-Challenge"
path = "2021-05-04-Daily-Challenge"
date = 2021-05-04 15:00:00+08:00
updated = 2021-05-04 17:21:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/) with `cpp`.

<!-- more -->

# Find N Unique Integers Sum up to Zero

## Description

Given an integer `n`, return **any** array containing `n` **unique** integers such that they add up to `0`.

 

**Example 1:**

```
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
```

**Example 2:**

```
Input: n = 3
Output: [-1,0,1]
```

**Example 3:**

```
Input: n = 1
Output: [0]
```

 

**Constraints:**

- `1 <= n <= 1000`

## Solution

``` cpp
class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> answer(n);
    for(int i = 0; i * 2 + 1 < n; ++i) {
      answer[i * 2] = i + 1;
      answer[i * 2 + 1] = -i - 1;
    }
    return move(answer);
  }
};
```

# May LeetCoding Challenge4

## Description

**Non-decreasing Array**

Given an array `nums` with `n` integers, your task is to check if it could become non-decreasing by modifying **at most one element**.

We define an array is non-decreasing if `nums[i] <= nums[i + 1]` holds for every `i` (**0-based**) such that (`0 <= i <= n - 2`).

 

**Example 1:**

```
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
```

**Example 2:**

```
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
```

 

**Constraints:**

- `n == nums.length`
- <code>1 <= n <= 10<sup>4</sup></code>
- <code>-10 <= nums[i] <= 10<sup>5</sup></code>

## Solution

``` cpp
class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int len = nums.size();
    int addCount = 0;
    int minusCount = 0;
    vector<int> copies = nums;
    for(int i = 0; i < len - 1; ++i) {
      if(nums[i] > nums[i + 1]) {
        nums[i + 1] = nums[i];
        addCount += 1;
      }
    }
    for(int i = len - 1; i > 0; --i) {
      if(copies[i] < copies[i - 1]) {
        copies[i - 1] = copies[i];
        minusCount += 1;
      }
    }
    return addCount < 2 || minusCount < 2;
  }
};
```
