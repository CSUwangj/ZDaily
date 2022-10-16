+++
updated = 2022-07-27 18:14:00+08:00
title = "2022-07-27 Daily-Challenge"
path = "2022-07-27-Daily-Challenge"
date = 2022-07-27 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 27

## Description

**Flatten Binary Tree to Linked List**

Given the `root` of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
- The "linked list" should be in the same order as a [**pre-order** **traversal**](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) of the binary tree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

```
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [0]
Output: [0]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`

 

**Follow up:** Can you flatten the tree in-place (with `O(1)` extra space)?

## Solution

``` cpp
class Solution {
  TreeNode* rightMost = nullptr;
public:
  void flatten(TreeNode* root) {
    if(!root) return;
    rightMost = root;
    if(root->left) {
      flatten(root->left);
      rightMost->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
    flatten(rightMost->right);
  }
};

// Accepted
// 225/225 cases passed (13 ms)
// Your runtime beats 33.77 % of cpp submissions
// Your memory usage beats 38.74 % of cpp submissions (12.8 MB)
```
