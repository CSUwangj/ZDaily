+++
title = "2021-12-12 Daily-Challenge"
path = "2021-12-12-Daily-Challenge"
date = 2021-12-12 23:41:00+08:00
updated = 2021-12-12 23:56:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/partition-equal-subset-sum/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 12

## Description

**Partition Equal Subset Sum**

Given a **non-empty** array `nums` containing **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

**Example 1:**

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

 

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

## Solution

``` cpp
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if((sum & 1) || nums.empty()) return false;

    int target = sum >> 1;
    bitset<10001> dp;
    dp[0] = 1;
    for(auto i : nums) {
      dp |= (dp << i);
    }
    return dp[target];
  }
};

// Accepted
// 117/117 cases passed (4 ms)
// Your runtime beats 99.79 % of cpp submissions
// Your memory usage beats 97.1 % of cpp submissions (9.1 MB)
```
