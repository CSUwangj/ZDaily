+++
title = "2021-10-26 Daily-Challenge"
path = "2021-10-26-Daily-Challenge"
date = 2021-10-26 18:20:15+08:00
updated = 2021-10-26 18:35:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/invert-binary-tree/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 26

## Description

**Invert Binary Tree**

Given the `root` of a binary tree, invert the tree, and return *its root*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

```
Input: root = [2,1,3]
Output: [2,3,1]
```

**Example 3:**

```
Input: root = []
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Solution

``` cpp
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};

// Accepted
// 77/77 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 79.47 % of cpp submissions (9.7 MB)
```
