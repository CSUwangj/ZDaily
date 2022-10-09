+++
updated = 2022-10-09 18:14:00+08:00
title = "2022-10-09 Daily-Challenge"
path = "2022-10-09-Daily-Challenge"
date = 2022-10-09 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 9

## Description

**Two Sum IV - Input is a BST**

Given the `root` of a Binary Search Tree and a target number `k`, return *`true` if there exist two elements in the BST such that their sum is equal to the given target*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- `root` is guaranteed to be a **valid** binary search tree.
- `-10^5 <= k <= 10^5`

## Solution

``` cpp
class Solution {
  TreeNode *leftTravel(TreeNode *root, int min) {
    if(!root) return root;
    TreeNode *left = root->left;
    while(left && left->val > min) {
      while(left->right && left->right != root) {
        left = left->right;
      }
      if(left->right == root) {
        left->right = nullptr;
        return root;
      } 
      left->right = root;
      root = root->left;
      left = root->left;
    }
    return root;
  }

  TreeNode *rightTravel(TreeNode *root, int max) {
    if(!root) return root;
    TreeNode *right = root->right;
    while(right && right->val < max) {
      while(right->left && right->left != root) {
        right = right->left;
      }
      if(right->left == root) {
        right->left = nullptr;
        return root;
      } 
      right->left = root;
      root = root->right;
      right = root->right;
    }
    return root;
  }
  TreeNode *copy(TreeNode *root) {
    if(!root) return root;
    TreeNode *newRoot = new TreeNode(root->val);
    newRoot->left = copy(root->left);
    newRoot->right = copy(root->right);
    return newRoot;
  }
public:
  bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    // comment line below, dump leetcode will RE
    root = copy(root);
    TreeNode *leftCur = leftTravel(root, INT_MIN);
    TreeNode *rightCur = rightTravel(root, INT_MAX);
    while(leftCur && rightCur && leftCur != rightCur) {
    int leftMin = leftCur->val;
    int rightMost = rightCur->val;
      int sum = leftCur->val + rightCur->val;
      if(sum == k) {
        return true;
      } else if (sum < k) {
        leftCur = leftTravel(leftCur->right, leftMin);
      } else {
        rightCur = rightTravel(rightCur->left, rightMost);
      }
    }
    return false;
  }
};

// Accepted
// 422/422 cases passed (52 ms)
// Your runtime beats 22.62 % of cpp submissions
// Your memory usage beats 12.33 % of cpp submissions (40.9 MB)
```
