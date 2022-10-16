+++
updated = 2022-04-17 18:55:00+08:00
title = "2022-04-17 Daily-Challenge"
path = "2022-04-17-Daily-Challenge"
date = 2022-04-17 18:53:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/increasing-order-search-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 17

## Description

**Increasing Order Search Tree**

Given the `root` of a binary search tree, rearrange the tree in **in-order** so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg)

```
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg)

```
Input: root = [5,1,7]
Output: [1,null,5,null,7]
```

 

**Constraints:**

- The number of nodes in the given tree will be in the range `[1, 100]`.
- `0 <= Node.val <= 1000`

## Solution

``` cpp
class Solution {
  void traversal(TreeNode *&newCur, TreeNode *cur) {
    if(!cur) return;
    traversal(newCur, cur->left);
    newCur->right = new TreeNode(cur->val);
    newCur = newCur->right;
    traversal(newCur, cur->right);
  }
public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode *newRoot = new TreeNode();
    TreeNode *tmp = newRoot;
    traversal(tmp, root);
    return newRoot->right;
  }
};

// Accepted
// 37/37 cases passed (3 ms)
// Your runtime beats 65.44 % of cpp submissions
// Your memory usage beats 19.7 % of cpp submissions (8 MB)
```
