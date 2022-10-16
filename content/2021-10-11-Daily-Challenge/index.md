+++
title = "2021-10-11 Daily-Challenge"
path = "2021-10-11-Daily-Challenge"
date = 2021-10-11 18:55:04+08:00
updated = 2021-10-11 19:03:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/diameter-of-binary-tree/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 11

## Description

**Diameter of Binary Tree**

Given the `root` of a binary tree, return *the length of the **diameter** of the tree*.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

**Example 2:**

```
Input: root = [1,2]
Output: 1
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-100 <= Node.val <= 100`

## Solution

``` cpp
class Solution {
  int answer;
  int pathLength(TreeNode * root) {
    if(!root) return 0;
    int left = pathLength(root->left);
    int right = pathLength(root->right);
    answer = max(answer, left + right);
    return 1 + max(left, right);
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    pathLength(root);
    return answer;
  }
};

// Accepted
// 104/104 cases passed (14 ms)
// Your runtime beats 37.05 % of cpp submissions
// Your memory usage beats 64.86 % of cpp submissions (20.3 MB)
```
