+++
updated = 2022-07-11 18:14:00+08:00
title = "2022-07-11 Daily-Challenge"
path = "2022-07-11-Daily-Challenge"
date = 2022-07-11 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/binary-tree-right-side-view/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 11

## Description

**Binary Tree Right Side View**

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

**Example 2:**

```
Input: root = [1,null,3]
Output: [1,3]
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
  vector<int> answer;
  void traversal(TreeNode* root, int level) {
    if(!root) return;
    if(level > answer.size()) answer.push_back(root->val);
    traversal(root->right, level + 1);
    traversal(root->left, level + 1);
  }
public:
  vector<int> rightSideView(TreeNode* root) {
    traversal(root, 1);
    return move(answer);
  }
};

// Accepted
// 215/215 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88.71 % of cpp submissions (11.9 MB)
```
