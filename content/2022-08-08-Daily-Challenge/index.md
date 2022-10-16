+++
updated = 2022-08-08 18:14:00+08:00
title = "2022-08-08 Daily-Challenge"
path = "2022-08-08-Daily-Challenge"
date = 2022-08-08 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/longest-increasing-subsequence/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 8

## Description

**Longest Increasing Subsequence**

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of  the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.

 

**Example 1:**

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

**Example 3:**

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 2500`
- `-10^4 <= nums[i] <= 10^4`

 

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

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
  int lengthOfLIS(vector<int>& nums) {
    vector<int> LIS{nums[0]};
    for(auto i : nums) {
      auto it = lower_bound(LIS.begin(), LIS.end(), i);
      if(it != LIS.end()) {
        *it = i;
      } else {
        LIS.push_back(i);
      }
    }
    return LIS.size();
  }
};

// Accepted
// 54/54 cases passed (7 ms)
// Your runtime beats 97.92 % of cpp submissions
// Your memory usage beats 69.86 % of cpp submissions (10.5 MB)
```
