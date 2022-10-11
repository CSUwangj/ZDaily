+++
updated = 2022-10-11 18:14:00+08:00
title = "2022-10-11 Daily-Challenge"
path = "2022-10-11-Daily-Challenge"
date = 2022-10-11 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/increasing-triplet-subsequence/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 11

## Description

**Increasing Triplet Subsequence**

Given an integer array `nums`, return `true` *if there exists a triple of indices* `(i, j, k)` *such that* `i < j < k` *and* `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.

 

**Example 1:**

```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```

**Example 2:**

```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```

**Example 3:**

```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

 

**Constraints:**

- `1 <= nums.length <= 5 * 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

 

**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space complexity?

## Solution

``` cpp
class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int min = INT_MAX, middle = INT_MAX;
    for(auto i : nums) {
      if(i < min) {
        min = i;
      } else if (i > min && i < middle) {
        middle = i;
      } else if (i > middle) {
        return true;
      }
    }
    return false;
  }
};

// Accepted
// 76/76 cases passed (79 ms)
// Your runtime beats 88.38 % of cpp submissions
// Your memory usage beats 67.34 % of cpp submissions (61.6 MB)
```
