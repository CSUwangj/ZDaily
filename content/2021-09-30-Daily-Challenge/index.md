+++
title = "2021-09-30 Daily-Challenge"
path = "2021-09-30-Daily-Challenge"
date = 2021-09-30 21:15:53+08:00
updated = 2021-09-30 21:25:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3993/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 30

## Description

**Partition to K Equal Sum Subsets**

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

 

**Example 1:**

```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

**Example 2:**

```
Input: nums = [1,2,3,4], k = 3
Output: false
```

 

**Constraints:**

- `1 <= k <= nums.length <= 16`
- `1 <= nums[i] <= 104`
- The frequency of each element is in the range `[1, 4]`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<bool> used;
  int left;
  int part;
  int len;
  bool dfs(vector<int>& nums, int rest, int start) {
    if(!left) return true;
    if(rest == 0) return dfs(nums, part, 0);
    for(int i = start; i < len; ++i) {
      if(!used[i] && nums[i] <= rest) {
        used[i] = true;
        left -= 1;
        if(dfs(nums, rest - nums[i], i + 1)) return true;
        used[i] = false;
        left += 1;
      }
    }
    return false;
  }
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    part = accumulate(nums.begin(), nums.end(), 0);
    len = nums.size();
    if(part % k || len < k) return false;
    used.resize(len);
    left = len;
    part /= k;
    for(auto n : nums) {
      if(n > part) return false;
    }
    return dfs(nums, part, 0);
  }
};

// Accepted
// 142/142 cases passed (4 ms)
// Your runtime beats 84.15 % of cpp submissions
// Your memory usage beats 85.03 % of cpp submissions (9 MB)
```
