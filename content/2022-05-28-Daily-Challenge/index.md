+++
updated = 2022-05-28 18:14:00+08:00
title = "2022-05-28 Daily-Challenge"
path = "2022-05-28-Daily-Challenge"
date = 2022-05-28 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/missing-number/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 28

## Description

**Missing Number**

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

 

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

 

**Constraints:**

- `n == nums.length`
- `1 <= n <= 104`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

 

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

## Solution

``` cpp
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int sum = (len + 1) * len / 2;
    for(auto i : nums) sum -= i;
    return sum;
  }
};

// Accepted
// 122/122 cases passed (11 ms)
// Your runtime beats 99.14 % of cpp submissions
// Your memory usage beats 93.84 % of cpp submissions (17.9 MB)
```
