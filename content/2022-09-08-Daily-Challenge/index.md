+++
updated = 2022-09-08 18:14:00+08:00
title = "2022-09-08 Daily-Challenge"
path = "2022-09-08-Daily-Challenge"
date = 2022-09-08 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/binary-tree-inorder-traversal/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 8

## Description

**Binary Tree Inorder Traversal**

Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

 

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

``` cpp
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->left)) {
        answer.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          answer.push_back(cur->val);
          left->right = nullptr;
          cur = cur->right;
        } else {
          left->right = cur;
          cur = cur->left;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 70/70 cases passed (6 ms)
// Your runtime beats 21.04 % of cpp submissions
// Your memory usage beats 39.59 % of cpp submissions (8.5 MB)
```
