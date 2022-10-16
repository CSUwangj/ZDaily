+++
title = "2021-11-20 Daily-Challenge"
path = "2021-11-20-Daily-Challenge"
date = 2021-11-20 14:50:00+08:00
updated = 2021-11-20 14:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/single-element-in-a-sorted-array/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 20

## Description

**Single Element in a Sorted Array**

You are given a sorted array consisting of only integers where every element appears  exactly twice, except for one element which appears exactly once.

Return *the single element that appears only once*.

Your solution must run in `O(log n)` time and `O(1)` space.

 

**Example 1:**

```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

**Example 2:**

```
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

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
  int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while(low < high - 1) {
      int mid = (low + high) >> 1;
      mid ^= (mid & 1);
      if(nums[mid] == nums[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[high];
  }
};

// Accepted
// 14/14 cases passed (4 ms)
// Your runtime beats 98.01 % of cpp submissions
// Your memory usage beats 81.48 % of cpp submissions (11 MB)
```
