+++
title = "2022-02-15 Daily-Challenge"
path = "2022-02-15-Daily-Challenge"
date = 2022-02-15 18:13:00+08:00
updated = 2022-02-15 18:14:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/single-number/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 15

## Description

**Single Number**

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

**Example 1:**

```
Input: nums = [2,2,1]
Output: 1
```

**Example 2:**

```
Input: nums = [4,1,2,1,2]
Output: 4
```

**Example 3:**

```
Input: nums = [1]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 104 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

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
  int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
      return a ^ b;
    });
  }
};

// Accepted
// 61/61 cases passed (27 ms)
// Your runtime beats 53.51 % of cpp submissions
// Your memory usage beats 50.83 % of cpp submissions (17 MB)
```
