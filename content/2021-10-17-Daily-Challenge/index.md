+++
title = "2021-10-17 Daily-Challenge"
path = "2021-10-17-Daily-Challenge"
date = 2021-10-17 10:33:45+08:00
updated = 2021-10-17 10:55:33+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/path-sum-iii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 17

## Description

**Path Sum III**

Given the `root` of a binary tree and an integer `targetSum`, return *the number of paths where the sum of the values along the path equals* `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
```

**Example 2:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 1000]`.
- `-10^9 <= Node.val <= 10^9`
- `-1000 <= targetSum <= 1000`

## Solution

``` cpp
class Solution {
  int sum;
  int ans;
  void dfs(TreeNode* root, int cur, bool inPath) {
    if(!root) return;
    if(cur == root->val) ans += 1;
    if(!inPath) {
      dfs(root->left, cur, false);
      dfs(root->right, cur, false);
    }
    dfs(root->left, cur-root->val, true);
    dfs(root->right, cur-root->val, true);
  }
public:
  int pathSum(TreeNode* root, int sum) {
    if(!root) return 0;
    this->sum = sum;
    dfs(root, sum, false);
    return ans;
  }
};

// Accepted
// 126/126 cases passed (20 ms)
// Your runtime beats 66.65 % of cpp submissions
// Your memory usage beats 77.5 % of cpp submissions (15.7 MB)
```
