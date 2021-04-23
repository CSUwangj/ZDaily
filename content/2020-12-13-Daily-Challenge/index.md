+++
title = "2020-12-13 Daily-Challenge"
path = "2020-12-13-Daily-Challenge"
date = 2020-12-13 17:12:33+08:00
updated = 2020-12-13 19:20:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3564/) with `cpp`.

<!-- more -->

# LeetCode Review

## Smallest Subtree with all the Deepest Nodes

more elegant solution

``` cpp
class Solution {
    pair<TreeNode*, int> helper(TreeNode* root, int level) {
        if(!root) return make_pair(root, 0);
        auto left = helper(root->left, level+1);
        auto right = helper(root->right, level+1);
        if(left.second == right.second) return make_pair(root, left.second ? left.second : level);
        if(left.second < right.second) return right;
        return left;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root, 0).first;
    }
};
```

# December LeetCoding Challenge13

## Description

**Burst Balloons**

## Description

Given `n` balloons, indexed from `0` to `n-1`. Each balloon is painted with a number on it represented by array `nums`. You are asked to burst all the balloons. If the you burst balloon `i` you will get `nums[left] * nums[i] * nums[right]` coins. Here `left` and `right` are adjacent indices of `i`. After the burst, the `left` and `right` then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

**Note:**

- You may imagine `nums[-1] = nums[n] = 1`. They are not real therefore you can not burst them.
- 0 ≤ `n` ≤ 500, 0 ≤ `nums[i]` ≤ 100

**Example:**

```
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

## Solution

interval DP... why is this at 13th?

``` cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> newArr{1};
        for(auto i : nums) if(i) newArr.push_back(i);
        newArr.push_back(1);
        len = newArr.size()-2;
        vector<vector<int>> dp(len+2, vector<int>(len+2));
        for(int k = 0; k < len; ++k) {
            for(int i = 1; i+k <= len; ++i) {
                int left = i;
                int right = i+k;
                for(int j = left; j <= right; ++j) {
                    int coins = dp[j+1][right]+dp[left][j-1]+newArr[j]*newArr[left-1]*newArr[right+1];
                    dp[left][right] = max(dp[left][right], coins);
                }
                // cout << "dp[" << left << "][" << right << "]: " << dp[left][right] << endl;
            }
        }
        return dp[1][len];
    }
};
```
