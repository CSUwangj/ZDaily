+++
updated = 2022-03-28 15:37:00+08:00
title = "2022-03-28 Daily-Challenge"
path = "2022-03-28-Daily-Challenge"
date = 2022-03-28 18:35:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 28

## Description

**Search in Rotated Sorted Array II**

There is an integer array `nums` sorted in non-decreasing order (not necessarily with **distinct** values).

Before being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and become `[4,5,6,6,7,0,1,2,4,4]`.

Given the array `nums` **after** the rotation and an integer `target`, return `true` *if* `target` *is in* `nums`*, or* `false` *if it is not in* `nums`*.*

You must decrease the overall operation steps as much as possible.

 

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

 

**Constraints:**

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is guaranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`

 

**Follow up:** This problem is similar to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), but `nums` may contain **duplicates**. Would this affect the runtime complexity? How and why?

## Solution

``` cpp
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if(nums.empty()) return false;
    int offset = 0;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      if(nums[i] < nums[i-1]) {
        offset = i;
        break;
      }
    }
    int start = 0, end = nums.size() - 1;
    while(start < end) {
      int mid = (start + end) / 2;
      int pos = (mid + offset) % len;
      if(nums[pos] < target) start = mid + 1;
      else end = mid;
    }
    return nums[(start+offset)%len] == target;
  }
};

// Accepted
// 279/279 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.12 % of cpp submissions (13.9 MB)
```
