+++
title = "2021-04-11 Daily-Challenge"
path = "2021-04-11-Daily-Challenge"
date = 2021-04-11 15:02:24+08:00
updated = 2021-04-11 20:05:03+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3704/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge11

**Deepest Leaves Sum**

## Description

Given the `root` of a binary tree, return *the sum of values of its deepest leaves*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

**Example 2:**

```
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `1 <= Node.val <= 100`

## Solution

``` cpp
class Solution {
  int sum = 0;
  int height = 0;
  void solve(TreeNode *root, int level) {
    if(!root) return;
    if(level > height) {
      sum = 0;
      height = level;
    }
    sum += (level == height) * root->val;
    solve(root->left, level + 1);
    solve(root->right, level + 1);
  }
public:
  int deepestLeavesSum(TreeNode* root) {
    solve(root, 0);
    return sum;
  }
};
```
