+++
updated = 2022-05-03 18:58:00+08:00
title = "2022-05-03 Daily-Challenge"
path = "2022-05-03-Daily-Challenge"
date = 2022-05-03 18:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/sort-array-by-parity/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 3

## Description

**Shortest Unsorted Continuous Subarray**

Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return *the shortest such subarray and output its length*.

 

**Example 1:**

```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
```

**Example 3:**

```
Input: nums = [1]
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

 

**Follow up:** Can you solve it in `O(n)` time complexity?

## Solution

``` cpp
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int len = nums.size();
    int wrongLess = -1;
    for(int i = 1; i < len; ++i) {
      if(nums[i] < nums[i - 1]) {
        wrongLess = i - 1;
        break;
      }
    }
    if(wrongLess == -1) return 0;
    int wrongGreater = -1;
    for(int i = len - 2; i >= 0; --i) {
      if(nums[i] > nums[i + 1]) {
        wrongGreater = i + 1;
        break;
      }
    }
    int minPos = wrongLess;
    int maxPos = wrongGreater;
    for(int i = min(wrongLess, wrongGreater); i <= max(wrongLess, wrongGreater); ++i) {
      if(nums[i] < nums[minPos]) minPos = i;
      if(nums[i] > nums[maxPos]) maxPos = i;
    }
    int begin = 0;
    while(nums[begin] <= nums[minPos]) begin += 1;
    int end = len - 1;
    while(nums[end] >= nums[maxPos]) end -= 1;
    return end - begin + 1;
  }
};

// Accepted
// 307/307 cases passed (26 ms)
// Your runtime beats 94.24 % of cpp submissions
// Your memory usage beats 68.9 % of cpp submissions (26.6 MB)
```
