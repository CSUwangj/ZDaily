+++
updated = 2022-06-17 18:14:00+08:00
title = "2022-06-17 Daily-Challenge"
path = "2022-06-17-Daily-Challenge"
date = 2022-06-17 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/binary-tree-cameras/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 17

## Description

**Binary Tree Cameras**

You are given the `root` of a binary tree. We install cameras on the tree nodes where each  camera at a node can monitor its parent, itself, and its immediate  children.

Return *the minimum number of cameras needed to monitor all nodes of the tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png)

```
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png)

```
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `Node.val == 0`

## Solution

``` cpp
class Solution {
  unordered_map<TreeNode*, int> put;
  unordered_map<TreeNode*, int> covered;
  unordered_map<TreeNode*, int> blank;
  void solve(TreeNode *root) {
    if(!root) return;
    solve(root->left);
    solve(root->right);
    put[root] = 1 + min({
                    covered[root->left],
                    put[root->left],
                    blank[root->left]
                  }) + min({
                    covered[root->right],
                    put[root->right],
                    blank[root->right]
                  });
    covered[root] = min({put[root->left] + covered[root->right],
                         put[root->right] + covered[root->left],
                         put[root->left] + put[root->right]});
    blank[root] = covered[root->left] + covered[root->right];
  }
public:
  int minCameraCover(TreeNode* root) {
    put[nullptr] = 10000;
    solve(root);
    return min(put[root], covered[root]);
  }
};

// Accepted
// 171/171 cases passed (36 ms)
// Your runtime beats 9.71 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (28.2 MB)
```
