+++
updated = 2022-06-01 18:14:00+08:00
title = "2022-06-01 Daily-Challenge"
path = "2022-06-01-Daily-Challenge"
date = 2022-06-01 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/running-sum-of-1d-array/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 1

## Description

**Running Sum of 1d Array**

​Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10^6 <= nums[i] <= 10^6`

## Solution

``` cpp
class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    int len = nums.size();
    for(int i = 1; i < len; ++i) nums[i] += nums[i - 1];
    return nums;
  }
};

// Accepted
// 53/53 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 38.06 % of cpp submissions (8.6 MB)
```
