+++
updated = 2022-08-05 18:14:00+08:00
title = "2022-08-05 Daily-Challenge"
path = "2022-08-05-Daily-Challenge"
date = 2022-08-05 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/combination-sum-iv/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 5

## Description

**Combination Sum IV**

Given an array of **distinct** integers `nums` and a target integer `target`, return *the number of possible combinations that add up to* `target`.

The test cases are generated so that the answer can fit in a **32-bit** integer.

 

**Example 1:**

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

**Example 2:**

```
Input: nums = [9], target = 3
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 1000`
- All the elements of `nums` are **unique**.
- `1 <= target <= 1000`

 

**Follow up:** What if negative numbers are allowed in  the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Solution

``` cpp
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i) {
      for(auto num : nums) {
        if(num <= i && INT_MAX - dp[i] > dp[i - num]) dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};

// Accepted
// 15/15 cases passed (4 ms)
// Your runtime beats 46.34 % of cpp submissions
// Your memory usage beats 65.95 % of cpp submissions (6.6 MB)
```
