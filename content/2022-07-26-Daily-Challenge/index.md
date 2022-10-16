+++
updated = 2022-07-26 18:14:00+08:00
title = "2022-07-26 Daily-Challenge"
path = "2022-07-26-Daily-Challenge"
date = 2022-07-26 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 26

## Description

**Lowest Common Ancestor of a Binary Tree**

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the tree.

## Solution

``` cpp
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    if(!root) return nullptr;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    if(!left && !right) return nullptr;
    if(!left) return right;
    return left;
  }
};

// Accepted
// 31/31 cases passed (30 ms)
// Your runtime beats 32.18 % of cpp submissions
// Your memory usage beats 25.3 % of cpp submissions (14.3 MB)
```
