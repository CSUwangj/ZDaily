+++
updated = 2022-10-04 18:14:00+08:00
title = "2022-10-04 Daily-Challenge"
path = "2022-10-04-Daily-Challenge"
date = 2022-10-04 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/path-sum/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 4

## Description

**Path Sum**

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Example 3:**

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution

``` cpp
class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(root->left || root->right) return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    return sum == root->val;
  }
};

// Accepted
// 117/117 cases passed (10 ms)
// Your runtime beats 90.94 % of cpp submissions
// Your memory usage beats 38.76 % of cpp submissions (21.4 MB)
```
