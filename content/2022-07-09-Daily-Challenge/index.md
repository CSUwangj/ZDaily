+++
updated = 2022-07-09 18:14:00+08:00
title = "2022-07-09 Daily-Challenge"
path = "2022-07-09-Daily-Challenge"
date = 2022-07-09 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/jump-game-vi/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 9

## Description

**Jump Game VI**

You are given a **0-indexed** integer array `nums` and an integer `k`.

You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.

You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.

Return *the **maximum score** you can get*.

 

**Example 1:**

```
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
```

**Example 2:**

```
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
```

**Example 3:**

```
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
```

 

**Constraints:**

- `1 <= nums.length, k <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    list<int> monoQueue{nums[0]};
    int len = nums.size();
    for(int i = 1; i < min(k, len); ++i) {
      nums[i] += monoQueue.front();
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      monoQueue.push_back(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      nums[i] += monoQueue.front();
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      if(monoQueue.size() && monoQueue.front() == nums[i - k]) monoQueue.pop_front();
      monoQueue.push_back(nums[i]);
    }
    return nums.back();
  }
};

// Accepted
// 65/65 cases passed (256 ms)
// Your runtime beats 23.86 % of cpp submissions
// Your memory usage beats 18.31 % of cpp submissions (119.8 MB)
```
