+++
updated = 2022-03-29 18:45:00+08:00
title = "2022-03-29 Daily-Challenge"
path = "2022-03-29-Daily-Challenge"
date = 2022-03-29 18:43:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/find-the-duplicate-number/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 29

## Description

**Find the Duplicate Number**

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return *this repeated number*.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

 

**Example 1:**

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:**

```
Input: nums = [3,1,3,4,2]
Output: 3
```

 

**Constraints:**

- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in `nums` appear only **once** except for **precisely one integer** which appears **two or more** times.

 

**Follow up:**

- How can we prove that at least one duplicate number must exist in `nums`?
- Can you solve the problem in linear runtime complexity?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    for(auto i : nums) {
      i = i > 0 ? i : -i;
      if(nums[i] < 0) return i;
      nums[i] = -nums[i];
    }
    return -1;
  }
};

// Accepted
// 58/58 cases passed (90 ms)
// Your runtime beats 98.15 % of cpp submissions
// Your memory usage beats 99.24 % of cpp submissions (61 MB)
```
