+++
title = "2020-10-14 Daily-Challenge"
path = "2020-10-14-Daily-Challenge"
date = 2020-10-14 00:37:31+08:00
updated = 2020-10-14 20:18:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Path Sum III* on [leetcode](https://leetcode.com/problems/path-sum-iii/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3494/) with `cpp`.

<!-- more -->

# Path Sum III

## Description

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

**Example:**

```
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
```

## Solution

simple recursion

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int pathSum(TreeNode* root, int sum, bool inPath = false) {
    if (!root) return 0;
    int ans = (root->val == sum);
    if (!inPath) ans += pathSum(root->left, sum) + pathSum(root->right, sum);
    ans += pathSum(root->left, sum - root->val, true) + pathSum(root->right, sum - root->val, true);
    return ans;
  }
};
```

# October LeetCoding Challenge 14

## Description

**House Robber II**

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

**Example 1:**

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

**Example 2:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```
Input: nums = [0]
Output: 0
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## Solution

using dp find maximum of `[0,n-1)` and `[1,n)`.

``` cpp
class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size()-1);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size()-1; ++i) {
      dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    int ans = dp[dp.size()-1];
    dp[0] = nums[1], dp[1] = max(nums[1], nums[2]);
    for(int i = 3; i < nums.size(); ++i) {
      dp[i-1] = max(dp[i-2], dp[i-3]+nums[i]);
    }
    ans = max(ans, dp[dp.size()-1]);
    return ans;
  }
};
```