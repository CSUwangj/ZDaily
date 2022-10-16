+++
title = "2021-12-31 Daily-Challenge"
path = "2021-12-31-Daily-Challenge"
date = 2021-12-31 12:23:00+08:00
updated = 2021-12-31 12:25:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 31

## Description

**Maximum Difference Between Node and Ancestor**

Given the `root` of a binary tree, find the maximum value `v` for which there exist **different** nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b` or any child of `a` is an ancestor of `b`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg)

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg)

```
Input: root = [1,null,2,null,0,3]
Output: 3
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5000]`.
- `0 <= Node.val <= 10^5`

## Solution

``` cpp
class Solution {
public:
  int maxAncestorDiff(TreeNode* root, int mmin = INT_MAX, int mmax = INT_MIN) {
    // root node will not be nullptr by constraints
    if(!root) return mmax - mmin;
    mmin = min(mmin, root->val);
    mmax = max(mmax, root->val);
    return max(maxAncestorDiff(root->left, mmin, mmax), maxAncestorDiff(root->right, mmin, mmax));
  }
};

// Accepted
// 27/27 cases passed (4 ms)
// Your runtime beats 81.69 % of cpp submissions
// Your memory usage beats 74.27 % of cpp submissions (9.7 MB)
```
