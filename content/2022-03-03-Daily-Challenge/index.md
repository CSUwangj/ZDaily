+++
title = "2022-03-03 Daily-Challenge"
path = "2022-03-03-Daily-Challenge"
date = 2022-03-03 18:30:00+08:00
updated = 2022-03-03 18:32:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/arithmetic-slices/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 3

## Description

**Arithmetic Slices**

An integer array is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

- For example, `[1,3,5,7,9]`, `[7,7,7,7]`, and `[3,-1,-5,-9]` are arithmetic sequences.

Given an integer array `nums`, return *the number of arithmetic **subarrays** of* `nums`.

A **subarray** is a contiguous subsequence of the array.

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
```

**Example 2:**

```
Input: nums = [1]
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 5000`
- `-1000 <= nums[i] <= 1000`

## Solution

``` cpp
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int last = nums.front();
    int count = 0;
    int diff = 0;
    int answer = 0;
    for(auto n : nums) {
      if(n - last == diff) {
        count += 1;
      } else {
        answer += max(0, count - 2) * (count - 1) / 2;
        count = 2;
        diff = n - last;
      }
      last = n;
    }
    answer += max(0, count - 2) * (count - 1) / 2;
    return answer;
  }
};

// Accepted
// 15/15 cases passed (3 ms)
// Your runtime beats 66.63 % of cpp submissions
// Your memory usage beats 88.02 % of cpp submissions (7.3 MB)
```
