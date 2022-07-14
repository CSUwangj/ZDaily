+++
updated = 2022-07-14 18:14:00+08:00
title = "2022-07-14 Daily-Challenge"
path = "2022-07-14-Daily-Challenge"
date = 2022-07-14 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 14

## Description

**Construct Binary Tree from Preorder and Inorder Traversal**

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

 

**Constraints:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is **guaranteed** to be the preorder traversal of the tree.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.

## Solution

``` cpp
class Solution {
  TreeNode *build(
    vector<int>& preorder,
    int preBegin,
    int preEnd,
    vector<int>& inorder,
    int inBegin,
    int inEnd
  ) {
    if(preBegin > preEnd) return nullptr;
    int rootIdx = -1;
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == preorder[preBegin]) {
        rootIdx = i;
        break;
      }
    }
    int offset = rootIdx - inBegin;
    TreeNode *root = new TreeNode(preorder[preBegin]);
    root->left = build(preorder, preBegin + 1, preBegin + offset, inorder, inBegin, inBegin + offset - 1);
    root->right = build(preorder, preBegin + offset + 1, preEnd, inorder, inBegin + offset + 1, inEnd);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    return build(preorder, 0, len - 1, inorder, 0, len - 1);
  }
};

// Accepted
// 203/203 cases passed (44 ms)
// Your runtime beats 40.32 % of cpp submissions
// Your memory usage beats 79.05 % of cpp submissions (25.9 MB)
```
