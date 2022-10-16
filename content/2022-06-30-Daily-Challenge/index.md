+++
updated = 2022-06-30 18:14:00+08:00
title = "2022-06-30 Daily-Challenge"
path = "2022-06-30-Daily-Challenge"
date = 2022-06-30 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 30

## Description

**Minimum Moves to Equal Array Elements II**

Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.

In one move, you can increment or decrement an element of the array by `1`.

Test cases are designed so that the answer will fit in a **32-bit** integer.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

**Example 2:**

```
Input: nums = [1,10,2,9]
Output: 16
```

 

**Constraints:**

- `n == nums.length`
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`


## Solution

``` cpp
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for(auto i : nums) sum += i;
    long long cur = 0;
    long long answer = INT_MAX;
    for(long long i = 0; i < len; ++i) {
      answer = min(answer, (nums[i] * i - cur) + (sum - cur - (len - i) * nums[i]));
      cur += nums[i];
    }
    return answer;
  }
};

// Accepted
// 30/30 cases passed (16 ms)
// Your runtime beats 55.47 % of cpp submissions
// Your memory usage beats 15.75 % of cpp submissions (10.9 MB)
```
