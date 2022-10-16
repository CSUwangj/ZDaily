+++
updated = 2022-10-12 18:14:00+08:00
title = "2022-10-12 Daily-Challenge"
path = "2022-10-12-Daily-Challenge"
date = 2022-10-12 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/largest-perimeter-triangle/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 12

## Description

**Largest Perimeter Triangle**

Given an integer array `nums`, return *the largest perimeter of a triangle with a non-zero area, formed from three of these lengths*. If it is impossible to form any triangle of a non-zero area, return `0`.

 

**Example 1:**

```
Input: nums = [2,1,2]
Output: 5
```

**Example 2:**

```
Input: nums = [1,2,1]
Output: 0
```

 

**Constraints:**

- `3 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^6`

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
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i = 0; i < nums.size() - 2; ++i) {
      if(nums[i] - nums[i + 1] < nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};

// Accepted
// 84/84 cases passed (28 ms)
// Your runtime beats 99.7 % of cpp submissions
// Your memory usage beats 96.06 % of cpp submissions (21.7 MB)
```
