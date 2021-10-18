+++
title = "2021-10-18 Daily-Challenge"
path = "2021-10-18-Daily-Challenge"
date = 2021-10-18 13:53:12+08:00
updated = 2021-10-18 14:00:37+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/cousins-in-binary-tree) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 18

## Description

**Cousins in Binary Tree**

Given the `root` of a binary tree with unique values and the values of two different nodes of the tree `x` and `y`, return `true` *if the nodes corresponding to the values* `x` *and* `y` *in the tree are **cousins**, or* `false` *otherwise.*

Two nodes of a binary tree are **cousins** if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth `0`, and children of each depth `k` node are at the depth `k + 1`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)

```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png)

```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png)

```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 100]`.
- `1 <= Node.val <= 100`
- Each node has a **unique** value.
- `x != y`
- `x` and `y` are exist in the tree.

## Solution

``` cpp
class Solution {
  TreeNode *parents[2];
  int depths[2];
  int nodes[2];
  void find(TreeNode *parent, TreeNode *cur, int depth = 0) {
    if(!cur) return;
    for(int i = 0; i < 2; ++i) {
      if(cur->val == nodes[i]) {
        parents[i] = parent;
        depths[i] = depth;
      }
    }
    find(cur, cur->left, depth + 1);
    find(cur, cur->right, depth + 1);
  }
public:
  bool isCousins(TreeNode* root, int x, int y) {
    nodes[0] = x;
    nodes[1] = y;
    find(nullptr, root);
    return depths[0] == depths[1] && parents[0] != parents[1];
  }
};

// Accepted
// 105/105 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.59 % of cpp submissions (11 MB)
```
