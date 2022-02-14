+++
title = "2022-02-14 Daily-Challenge"
path = "2022-02-14-Daily-Challenge"
date = 2022-02-14 11:13:00+08:00
updated = 2022-02-14 11:14:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/maximum-depth-of-binary-tree/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 14

## Description

**Maximum Depth of Binary Tree**

Given the `root` of a binary tree, return *its maximum depth*.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Example 2:**

```
Input: root = [1,null,2]
Output: 2
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-100 <= Node.val <= 100`

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
  int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

// Accepted
// 39/39 cases passed (7 ms)
// Your runtime beats 83.32 % of cpp submissions
// Your memory usage beats 56.35 % of cpp submissions (18.9 MB)
```
