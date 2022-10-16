+++
updated = 2022-07-25 18:14:00+08:00
title = "2022-07-25 Daily-Challenge"
path = "2022-07-25-Daily-Challenge"
date = 2022-07-25 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 25

## Description

**Find First and Last Position of Element in Sorted Array**

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```
Input: nums = [], target = 0
Output: [-1,-1]
```

 

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is a non-decreasing array.
- `-10^9 <= target <= 10^9`

## Solution

``` cpp
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if(!len) return{-1, -1};
    int begin = 0;
    int end = len - 1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(nums[begin] != target) return {-1, -1};
    int left = begin;
    begin = 0;
    end = len - 1;
    while(begin < end) {
      int mid = (begin + end + 1) >> 1;
      if(nums[mid] > target) {
        end = mid - 1;
      } else {
        begin = mid;
      }
    }
    return {left, begin};
  }
};

// Accepted
// 88/88 cases passed (13 ms)
// Your runtime beats 48.91 % of cpp submissions
// Your memory usage beats 83.66 % of cpp submissions (13.6 MB)
```
