+++
updated = 2022-06-25 18:14:00+08:00
title = "2022-06-25 Daily-Challenge"
path = "2022-06-25-Daily-Challenge"
date = 2022-06-25 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/non-decreasing-array/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 25

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
- `1 <= n <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

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

// Accepted
// 335/335 cases passed (42 ms)
// Your runtime beats 46.84 % of cpp submissions
// Your memory usage beats 7.46 % of cpp submissions (27.9 MB)
```
