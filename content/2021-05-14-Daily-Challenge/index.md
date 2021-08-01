+++
title = "2021-05-14 Daily-Challenge"
path = "2021-05-14-Daily-Challenge"
date = 2021-05-14 19:30:17+08:00
updated = 2021-05-14 20:00:07+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3742/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 14

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
```

``` cpp
class Solution {
public:
  void flatten(TreeNode* root) {
    if(!root) return;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    while(cur) {
      if(!cur->left) {
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *right = cur->left;
        while(right->right != nullptr && right->right != cur) {
          right = right->right;
        }
        if(right->right == cur) {
          right->right = cur->right;
          cur->right = cur->left;
          cur->left = nullptr;
          cur = right->right;
        } else {
          right->right = cur;
          cur = cur->left;
        }
      }
    }
  }
};
```
