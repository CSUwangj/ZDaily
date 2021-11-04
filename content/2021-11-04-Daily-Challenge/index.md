+++
title = "2021-11-04 Daily-Challenge"
path = "2021-11-04-Daily-Challenge"
date = 2021-11-04 18:03:59+08:00
updated = 2021-11-04 18:13:19+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/sum-of-left-leaves/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 4

## Description

**Sum of Left Leaves**

Given the `root` of a binary tree, return the sum of all left leaves.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```
Input: root = [1]
Output: 0
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `-1000 <= Node.val <= 1000`

## Solution

``` cpp
class Solution {
public:
  int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    int val = 0;
    if(root->left && !root->left->left && !root->left->right) {
      return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

// Accepted
// 100/100 cases passed (4 ms)
// Your runtime beats 71.52 % of cpp submissions
// Your memory usage beats 44.54 % of cpp submissions (13.5 MB)
```
