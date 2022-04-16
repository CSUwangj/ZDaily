+++
updated = 2022-04-16 18:46:00+08:00
title = "2022-04-16 Daily-Challenge"
path = "2022-04-16-Daily-Challenge"
date = 2022-04-16 18:44:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/convert-bst-to-greater-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 16

## Description

**Convert BST to Greater Tree**

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that  every key of the original BST is changed to the original key plus the  sum of all keys greater than the original key in BST.

As a reminder, a *binary search tree* is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/05/02/tree.png)

```
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**Example 2:**

```
Input: root = [0,null,1]
Output: [1,null,1]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- All the values in the tree are **unique**.
- `root` is guaranteed to be a valid binary search tree.

 

**Note:** This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void traversal(TreeNode *root, int &sum) {
    if(!root) return;
    traversal(root->right, sum);
    root->val += sum;
    sum = root->val;
    traversal(root->left, sum);
  }
public:
  TreeNode* convertBST(TreeNode* root) {
    int tmp = 0;
    traversal(root, tmp);
    return root;
  }
};

// Accepted
// 215/215 cases passed (38 ms)
// Your runtime beats 83.38 % of cpp submissions
// Your memory usage beats 12.35 % of cpp submissions (33.6 MB)
```
