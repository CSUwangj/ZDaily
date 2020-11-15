+++
title = "2020-11-15 Daily-Challenge"
path = "2020-11-15-Daily-Challenge"
date = 2020-11-15 16:42:21+08:00
updated = 2020-11-15 16:52:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge]() with `cpp`.

<!-- more -->

# LeetCode Review

# November LeetCoding Challenge15

**Range Sum of BST**

## Description

Given the `root` node of a binary search tree, return *the sum of values of all nodes with a value in the range `[low, high]`*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg)

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg)

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2 * 104]`.
- `1 <= Node.val <= 105`
- `1 <= low <= high <= 105`
- All `Node.val` are **unique**.

## Solution

nothing to say

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int result = 0;
    int high;
    int low;
    void helper(TreeNode* root) {
        if(!root) return;
        if(root->val >= low && root->val <= high) result += root->val;
        if(root->val > low) helper(root->left);
        if(root->val < high) helper(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        helper(root);
        return result;
    }
};
```
