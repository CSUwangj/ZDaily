+++
updated = 2022-09-06 18:14:00+08:00
title = "2022-09-06 Daily-Challenge"
path = "2022-09-06-Daily-Challenge"
date = 2022-09-06 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/binary-tree-pruning/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 6

## Description

**Binary Tree Pruning**

Given the `root` of a binary tree, return *the same tree where every subtree (of the given tree) not containing a* `1` *has been removed*.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 200]`.
- `Node.val` is either `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    if(!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(!root->val && !root->left && !root->right) return nullptr;
    return root;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 21.01 % of cpp submissions (8.8 MB)
```
