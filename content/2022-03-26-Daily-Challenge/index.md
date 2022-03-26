+++
updated = 2022-03-26 19:24:00+08:00
title = "2022-03-26 Daily-Challenge"
path = "2022-03-26-Daily-Challenge"
date = 2022-03-26 18:23:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/binary-search/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 26

## Description

**Binary Search**

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.

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
  int search(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] >= target) {
        end = mid;
      } else {
        begin = mid+1;
      }
    }
    return nums[begin]==target?begin:-1;
  }
};

// Accepted
// 47/47 cases passed (28 ms)
// Your runtime beats 98.7 % of cpp submissions
// Your memory usage beats 13.43 % of cpp submissions (27.7 MB)
```
