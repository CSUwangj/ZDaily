+++
title = "2021-10-13 Daily-Challenge"
path = "2021-10-13-Daily-Challenge"
date = 2021-10-13 20:55:44+08:00
updated = 2021-10-13 21:05:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 13

## Description

**Construct Binary Search Tree from Preorder Traversal**

Given an array of integers preorder, which represents the **preorder traversal** of a BST (i.e., **binary search tree**), construct the tree and return *its root*.

It is **guaranteed** that there is always possible to find a binary search tree with the given requirements for the given test cases.

A **binary search tree** is a binary tree where for every node, any descendant of `Node.left` has a value **strictly less than** `Node.val`, and any descendant of `Node.right` has a value **strictly greater than** `Node.val`.

A **preorder traversal** of a binary tree displays the value of the node first, then traverses `Node.left`, then traverses `Node.right`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/03/06/1266.png)

```
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

**Example 2:**

```
Input: preorder = [1,3]
Output: [1,null,3]
```

 

**Constraints:**

- `1 <= preorder.length <= 100`
- `1 <= preorder[i] <= 10^8`
- All the values of `preorder` are **unique**.

## Solution

``` cpp
class Solution {
  int len;
  TreeNode* solve(vector<int> &arr, int &index, int min = INT_MIN, int max = INT_MAX) {
    if(index == len) return nullptr;
    if(arr[index] < min || arr[index] > max) return nullptr;
    int val = arr[index];
    auto node = new TreeNode(val);
    index += 1;
    node->left = solve(arr, index, min, val);
    node->right = solve(arr, index, val, max);
    return node;
  }
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    len = preorder.size();
    int index = 0;
    return solve(preorder, index);
  }
};

// Accepted
// 110/110 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 43.07 % of cpp submissions (13.8 MB)
```
