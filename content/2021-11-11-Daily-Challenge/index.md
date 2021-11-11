+++
title = "2021-11-11 Daily-Challenge"
path = "2021-11-11-Daily-Challenge"
date = 2021-11-11 20:34:54+08:00
updated = 2021-11-11 20:39:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 11

## Description

**Minimum Value to Get Positive Step by Step Sum**

Given an array of integers `nums`, you start with an initial **positive** value *startValue**.*

In each iteration, you calculate the step by step sum of *startValue* plus elements in `nums` (from left to right).

Return the minimum **positive** value of *startValue* such that the step by step sum is never less than 1.

 

**Example 1:**

```
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
```

**Example 2:**

```
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 
```

**Example 3:**

```
Input: nums = [1,-2,-3]
Output: 5
```

 

**Constraints:**

- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

## Solution

``` cpp
class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int answer = 1;
    int sumRev = 1;
    for(auto i : nums) {
      sumRev -= i;
      if(answer < sumRev) answer = sumRev;
    }
    return answer;
  }
};

// Accepted
// 53/53 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 14.12 % of cpp submissions (7.4 MB)
```
