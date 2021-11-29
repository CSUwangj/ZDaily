+++
title = "2021-11-26 Daily-Challenge"
path = "2021-11-26-Daily-Challenge"
date = 2021-11-26 18:54:00+08:00
updated = 2021-11-26 18:58:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/search-insert-position/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 26

## Description

**Search Insert Position**

Given a sorted array of distinct integers and a target value, return the index if the  target is found. If not, return the index where it would be if it were  inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:**

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:**

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Example 4:**

```
Input: nums = [1,3,5,6], target = 0
Output: 0
```

**Example 5:**

```
Input: nums = [1], target = 0
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains **distinct** values sorted in **ascending** order.
- `-10^4 <= target <= 10^4`

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
  int searchInsert(vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    nums.push_back(INT_MAX);
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};

// Accepted
// 64/64 cases passed (3 ms)
// Your runtime beats 84.06 % of cpp submissions
// Your memory usage beats 72.14 % of cpp submissions (9.7 MB)
```
