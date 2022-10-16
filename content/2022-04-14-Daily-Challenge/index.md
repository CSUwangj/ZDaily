+++
updated = 2022-04-14 19:09:00+08:00
title = "2022-04-14 Daily-Challenge"
path = "2022-04-14-Daily-Challenge"
date = 2022-04-14 19:04:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/search-in-a-binary-search-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 14

## Description

**Search in a Binary Search Tree**

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```
Input: root = [4,2,7,1,3], val = 5
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `1 <= Node.val <= 10^7`
- `root` is a binary search tree.
- `1 <= val <= 10^7`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    if(root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
};

// Accepted
// 36/36 cases passed (36 ms)
// Your runtime beats 95.42 % of cpp submissions
// Your memory usage beats 93.48 % of cpp submissions (34.7 MB)
```
