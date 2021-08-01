+++
title = "2021-06-07 Daily-Challenge"
path = "2021-06-07-Daily-Challenge"
date = 2021-06-07 17:12:33+08:00
updated = 2021-06-07 19:13:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Array Nesting](https://leetcode.com/problems/array-nesting/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/) with `cpp`.

<!-- more -->

# Array Nesting

## Description

You are given an integer array `nums` of length `n` where `nums` is a permutation of the numbers in the range `[0, n - 1]`.

You should build a set `s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... }` subjected to the following rule:

- The first element in `s[k]` starts with the selection of the element `nums[k]` of `index = k`.
- The next element in `s[k]` should be `nums[nums[k]]`, and then `nums[nums[nums[k]]]`, and so on.
- We stop adding right before a duplicate element occurs in `s[k]`.

Return *the longest length of a set* `s[k]`.

 

**Example 1:**

```
Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
```

**Example 2:**

```
Input: nums = [0,1,2]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] < nums.length`
- All the values of `nums` are **unique**.

## Solution

simple simulation

``` cpp
auto speedup = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int answer = 0;
    int len = nums.size();
    vector<bool> vis(len);
    for(int i = 0; i < len; ++i) {
      if(vis[i]) continue;
      int cur = i;
      int chain = 0;
      while(!vis[cur]) {
        chain += 1;
        vis[cur] = true;
        cur = nums[cur];
      }
      answer = max(answer, chain);
    }
    return answer;
  }
};
```

# June LeetCoding Challenge 7

## Description

**Min Cost Climbing Stairs**

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.

 

**Example 1:**

```
Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
```

**Example 2:**

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
```

 

**Constraints:**

- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`

## Solution

``` cpp
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp[3];
    int len = cost.size();
    for(int i = 2; i <= len; ++i) {
      dp[i % 3] = min(dp[(i + 1) % 3] + cost[i - 2], dp[(i + 2) % 3] + cost[i - 1]);
    }
    return dp[len % 3];
  }
};
```
