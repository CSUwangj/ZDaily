+++
title = "2022-01-11 Daily-Challenge"
path = "2022-01-11-Daily-Challenge"
date = 2022-01-11 18:30:00+08:00
updated = 2022-01-11 18:32:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 11

## Description

**Sum of Root To Leaf Binary Numbers**

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

- For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return *the sum of these numbers*.

The test cases are generated so that the answer fits in a **32-bits** integer.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)

```
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

**Example 2:**

```
Input: root = [0]
Output: 0
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `Node.val` is `0` or `1`.

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
  int sumRootToLeaf(TreeNode* root, int cur = 0) {
    if(!root) return 0;
    cur = ((cur << 1) | root->val);
    if(!root->left && !root->right) return cur;
    return sumRootToLeaf(root->left, cur) + sumRootToLeaf(root->right, cur);
  }
};

// Accepted
// 63/63 cases passed (4 ms)
// Your runtime beats 87.29 % of cpp submissions
// Your memory usage beats 29.55 % of cpp submissions (16.8 MB)
```
