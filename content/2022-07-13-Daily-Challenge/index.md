+++
updated = 2022-07-13 18:14:00+08:00
title = "2022-07-13 Daily-Challenge"
path = "2022-07-13-Daily-Challenge"
date = 2022-07-13 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/binary-tree-level-order-traversal/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 13

## Description

**Binary Tree Level Order Traversal**

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> curLevel;
      for(int i = 0; i < sz; ++i) {
        auto node = q.front();
        q.pop();
        curLevel.push_back(node->val);
        if(node->left) {
          q.push(node->left);
        }
        if(node->right) {
          q.push(node->right);
        }
      }
      answer.push_back(curLevel);
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (8 ms)
// Your runtime beats 42.5 % of cpp submissions
// Your memory usage beats 61.71 % of cpp submissions (12.5 MB)
```
