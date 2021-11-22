+++
title = "2021-11-22 Daily-Challenge"
path = "2021-11-22-Daily-Challenge"
date = 2021-11-22 18:32:00+08:00
updated = 2021-11-22 19:04:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/delete-node-in-a-bst/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 22

## Description

**Delete Node in a BST**

Given a root  node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)

```
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
```

**Example 3:**

```
Input: root = [], key = 0
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `-105 <= Node.val <= 105`
- Each node has a **unique** value.
- `root` is a valid binary search tree.
- `-105 <= key <= 105`

 

**Follow up:** Could you solve it with time complexity `O(height of tree)`?

## Solution

``` cpp
static auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void rebuildFromLeft(TreeNode *root) {
    if(!root->left->right) {
      root->val = root->left->val;
      if(root->left->left) {
        rebuildFromLeft(root->left);
      } else {
        root->left = nullptr;
      }
      return;
    }
    TreeNode *cur = root->left;
    TreeNode *parent;
    while(cur->right) {
      parent = cur;
      cur = cur->right;
    }
    root->val = cur->val;
    if(cur->left) {
      rebuildFromLeft(cur);
    } else {
      parent->right = nullptr;
    }
  }
  
  void rebuildFromRight(TreeNode *root) {
    if(!root->right->left) {
      root->val = root->right->val;
      if(root->right->right) {
        rebuildFromRight(root->right);
      } else {
        root->right = nullptr;
      }
      return;
    }
    TreeNode *cur = root->right;
    TreeNode *parent;
    while(cur->left) {
      parent = cur;
      cur = cur->left;
    }
    root->val = cur->val;
    if(cur->right) {
      rebuildFromRight(cur);
    } else {
      parent->left = nullptr;
    }
  }
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode *cur = root;
    TreeNode *parent = nullptr;
    while(cur && cur->val != key) {
      parent = cur;
      if(key > cur->val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }
    if(!cur) return root;
    if(!cur->left && !cur->right) {
      if(!parent) return nullptr;
      if(parent->left == cur) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
      return root;
    }
    if(cur->left) {
      rebuildFromLeft(cur);
    } else {
      rebuildFromRight(cur);
    }
    return root;
  }
};

// Accepted
// 91/91 cases passed (36 ms)
// Your runtime beats 48.74 % of cpp submissions
// Your memory usage beats 30.07 % of cpp submissions (32.9 MB)
```
