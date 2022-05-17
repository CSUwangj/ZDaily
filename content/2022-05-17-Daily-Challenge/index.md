+++
updated = 2022-05-17 18:24:00+08:00
title = "2022-05-17 Daily-Challenge"
path = "2022-05-17-Daily-Challenge"
date = 2022-05-17 18:21:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 17

## Description

**Find a Corresponding Node of a Binary Tree in a Clone of That Tree**

Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.

The `cloned` tree is a **copy of** the `original` tree.

Return *a reference to the same node* in the `cloned` tree.

**Note** that you are **not allowed** to change any of the two trees or the `target` node and the answer **must be** a reference to a node in the `cloned` tree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e1.png)

```
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e2.png)

```
Input: tree = [7], target =  7
Output: 7
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e3.png)

```
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
```

 

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 10^4]`.
- The values of the nodes of the `tree` are unique.
- `target` node is a node from the `original` tree and is not `null`.

 

**Follow up:** Could you solve the problem if repeated values on the tree are allowed?

## Solution

``` cpp
class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(!original) return nullptr;
    if(original == target) return cloned;
    TreeNode *left = getTargetCopy(original->left, cloned->left, target);
    if(left) return left;
    TreeNode *right = getTargetCopy(original->right, cloned->right, target);
    if(right) return right;
    return nullptr;
  }
};

// Accepted
// 56/56 cases passed (599 ms)
// Your runtime beats 70.48 % of cpp submissions
// Your memory usage beats 81.24 % of cpp submissions (163.8 MB)
```
