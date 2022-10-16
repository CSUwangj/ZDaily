+++
title = "2021-10-03 Daily-Challenge"
path = "2021-10-03-Daily-Challenge"
date = 2021-10-03 23:23:23+08:00
updated = 2021-10-03 23:34:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/jump-game/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 3

## Description

**Jump Game**

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.

 

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
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
  bool canJump(vector<int>& nums) {
    int cur = 0;
    int len = nums.size();
    for(int i = 0; i < len && i <= cur; ++i) {
      cur = max(cur, i + nums[i]);
      if(cur >= len - 1) return true;
    }
    return false;
  }
};

// Accepted
// 166/166 cases passed (32 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 49.19 % of cpp submissions (48.3 MB)
```
