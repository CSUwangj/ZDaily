+++
updated = 2022-10-05 18:14:00+08:00
title = "2022-10-05 Daily-Challenge"
path = "2022-10-05-Daily-Challenge"
date = 2022-10-05 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/add-one-row-to-tree/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 5

## Description

**Add One Row to Tree**

Given the `root` of a binary tree and two integers `val` and `depth`, add a row of nodes with value `val` at the given depth `depth`.

Note that the `root` node is at depth `1`.

The adding rule is:

- Given the integer `depth`, for each not null tree node `cur` at the depth `depth - 1`, create two tree nodes with value `val` as `cur`'s left subtree root and right subtree root.
- `cur`'s original left subtree should be the left subtree of the new left subtree root.
- `cur`'s original right subtree should be the right subtree of the new right subtree root.
- If `depth == 1` that means there is no depth `depth - 1` at all, then create a tree node with value `val` as the new root of the whole original tree, and the original tree is the new root's left subtree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/15/addrow-tree.jpg)

```
Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/11/add2-tree.jpg)

```
Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- The depth of the tree is in the range `[1, 10^4]`.
- `-100 <= Node.val <= 100`
- `-105 <= val <= 10^5`
- `1 <= depth <= the depth of tree + 1`

## Solution

``` cpp
class Solution {
public:
  TreeNode* addOneRow(TreeNode* root, int v, int d, bool left = true) {
    if(d == 1) {
      TreeNode *newRoot = new TreeNode(v);
      if(left) newRoot->left = root;
      else newRoot->right = root;
      return newRoot;
    }
    if(!root) return nullptr;
    root->left = addOneRow(root->left, v, d-1, true);
    root->right = addOneRow(root->right, v, d-1, false);
    return root;
  }
};

// Accepted
// 109/109 cases passed (23 ms)
// Your runtime beats 85.7 % of cpp submissions
// Your memory usage beats 62.88 % of cpp submissions (25 MB)
```
