+++
title = "2021-11-21 Daily-Challenge"
path = "2021-11-21-Daily-Challenge"
date = 2021-11-21 22:21:00+08:00
updated = 2021-11-21 22:30:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 21

## Description

**Construct Binary Tree from Inorder and Postorder Traversal**

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

 

**Constraints:**

- `1 <= inorder.length <= 3000`
- `postorder.length == inorder.length`
- `-3000 <= inorder[i], postorder[i] <= 3000`
- `inorder` and `postorder` consist of **unique** values.
- Each value of `postorder` also appears in `inorder`.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.
- `postorder` is **guaranteed** to be the postorder traversal of the tree.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  TreeNode* buildTree(
    vector<int> &inorder, 
    int inBegin,
    int inEnd,
    vector<int> &postorder,
    int postBegin,
    int postEnd
  ) {
    if(inBegin > inEnd) return nullptr;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == postorder[postEnd]) {
        int offset = i - inBegin;
        root->left = buildTree(inorder, inBegin, inBegin + offset - 1, postorder, postBegin, postBegin + offset - 1);
        root->right = buildTree(inorder, inBegin + offset + 1, inEnd, postorder, postBegin + offset, postEnd - 1);
        break;
      }
    }
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int len = inorder.size();
    return buildTree(inorder, 0, len - 1, postorder, 0, len - 1);
  }
};

// Accepted
// 202/202 cases passed (32 ms)
// Your runtime beats 32.56 % of cpp submissions
// Your memory usage beats 62.12 % of cpp submissions (26.2 MB)
```
