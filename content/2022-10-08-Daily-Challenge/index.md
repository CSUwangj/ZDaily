+++
updated = 2022-10-08 18:14:00+08:00
title = "2022-10-08 Daily-Challenge"
path = "2022-10-08-Daily-Challenge"
date = 2022-10-08 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/3sum-closest/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 8

## Description

**3Sum Closest**

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return *the sum of the three integers*.

You may assume that each input would have exactly one solution.

 

**Example 1:**

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

**Example 2:**

```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```

 

**Constraints:**

- `3 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if(target <= nums.front() * 3 || len == 3) {
      return nums[0] + nums[1] + nums[2];
    }
    if(target >= nums.back() * 3) {
      return nums[len - 1] + nums[len - 2] + nums[len - 3];
    }
    int diff = INT_MAX;
    int answer = INT_MIN;
    for(int i = 0; i < len - 2; ++i) {
      if(nums[i] + nums[i + 1] + nums[i + 2] - target > diff) {
        break;
      }
      int start = i + 1;
      int end = len - 1;
      while(start < end) {
        int result = nums[i] + nums[start] + nums[end];
        int d = result - target;
        if(!d) {
          return result;
        } else if(d < 0) {
          if(diff > -d) {
            diff = -d;
            answer = result;
          }
          do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
        } else {
          if(diff > d) {
            diff = d;
            answer = result;
          }
          do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 162/162 cases passed (45 ms)
// Your runtime beats 99.64 % of cpp submissions
// Your memory usage beats 0.01 % of cpp submissions (16.6 MB)
```
