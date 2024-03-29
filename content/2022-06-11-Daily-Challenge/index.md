+++
updated = 2022-06-11 18:14:00+08:00
title = "2022-06-11 Daily-Challenge"
path = "2022-06-11-Daily-Challenge"
date = 2022-06-11 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 11

## Description

**Minimum Operations to Reduce X to Zero**

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it is possible**, otherwise, return* `-1`.

 

**Example 1:**

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

**Example 2:**

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

**Example 3:**

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `1 <= x <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> sumLeft, sumRight;
    int len = nums.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      sumLeft[sum] = i+1;
    }
    sumLeft[0] = 0;
    sum = 0;
    for(int i = 1; i <= len; ++i) {
      sum += nums[len-i];
      sumRight[sum] = i;
    }
    sumRight[0] = 0;
    
    int answer = INT_MAX;
    for(auto [sum, cnt] : sumLeft) {
      if(sumRight.count(x-sum) && cnt+sumRight[x-sum] <= len) answer = min(answer, cnt+sumRight[x-sum]);
    }
    return answer == INT_MAX ? -1 : answer;
  }
};

// Accepted
// 93/93 cases passed (1576 ms)
// Your runtime beats 5.09 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (237.8 MB)
```
