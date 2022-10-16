+++
title = "2021-10-27 Daily-Challenge"
path = "2021-10-27-Daily-Challenge"
date = 2021-10-27 19:35:43+08:00
updated = 2021-10-27 20:08:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/sort-colors/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 27

## Description

**Sort Colors**

Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

**Example 1:**

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**

```
Input: nums = [2,0,1]
Output: [0,1,2]
```

**Example 3:**

```
Input: nums = [0]
Output: [0]
```

**Example 4:**

```
Input: nums = [1]
Output: [1]
```

 

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is `0`, `1`, or `2`.

 

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

## Solution

``` cpp
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    while(begin < end && (nums[begin] == 0 || nums[begin] == 2 || nums[end] == 0 || nums[end] == 2)) {
      while(begin < end && nums[begin] == 0) {
        begin += 1;
      }
      while(begin < end && nums[end] == 2) {
        end -= 1;
      }
      if(begin >= end) break;
      if((nums[begin] == 2 || nums[end] == 0)) {
        swap(nums[begin], nums[end]);
        if(nums[end] == 0) begin += 1;
        if(nums[begin] == 2) end -= 1;
      }
    }
    int mid = begin + 1;
    while(mid <= end) {
      while(mid <= end && nums[mid] == 1) mid += 1;
      if(mid > end) break;
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
      } else {
        swap(nums[mid], nums[end]);
        end -= 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
```

Dutch national flag problem, seems elegant

``` cpp
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    for(int mid = 0; mid <= end;) {
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
        mid += 1;
      } else if(nums[mid] == 2) {
        swap(nums[mid], nums[end]);
        end -= 1;
      } else {
        mid += 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
```
