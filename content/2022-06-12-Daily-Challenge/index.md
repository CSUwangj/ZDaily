+++
updated = 2022-06-12 14:14:00+08:00
title = "2022-06-12 Daily-Challenge"
path = "2022-06-12-Daily-Challenge"
date = 2022-06-12 14:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-erasure-value/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 12

## Description

**Maximum Erasure Value**

You are given an array of positive integers `nums` and want to erase a subarray containing **unique elements**. The **score** you get by erasing the subarray is equal to the **sum** of its elements.

Return *the **maximum score** you can get by erasing **exactly one** subarray.*

An array `b` is called to be a subarray of `a` if it forms a contiguous subsequence of `a`, that is, if it is equal to `a[l],a[l+1],...,a[r]` for some `(l,r)`.

 

**Example 1:**

```
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
```

**Example 2:**

```
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    bool vis[10001] = {};
    int sum = 0;
    int start = 0;
    int len = nums.size();
    int answer = 0;
    for(int end = 0; end < len; ++end) {
      while(vis[nums[end]]) {
        vis[nums[start]] = false;
        sum -= nums[start];
        start += 1;
      }
      vis[nums[end]] = true;
      sum += nums[end];
      answer = max(sum, answer);
    }
    return answer;
  }
};

// Accepted
// 62/62 cases passed (338 ms)
// Your runtime beats 77.77 % of cpp submissions
// Your memory usage beats 99.27 % of cpp submissions (89.1 MB)
```
