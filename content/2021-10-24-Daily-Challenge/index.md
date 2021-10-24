+++
title = "2021-10-24 Daily-Challenge"
path = "2021-10-24-Daily-Challenge"
date = 2021-10-24 18:09:33+08:00
updated = 2021-10-24 18:15:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/count-complete-tree-nodes/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 24

## Description

**Count Complete Tree Nodes**

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Example 2:**

```
Input: root = []
Output: 0
```

**Example 3:**

```
Input: root = [1]
Output: 1
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5 * 10^4]`.
- `0 <= Node.val <= 5 * 10^4`
- The tree is guaranteed to be **complete**.

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
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      TreeNode* left = root;
      TreeNode* right = root;
      int count = 0;
      while(left && right) {
        left = left->left;
        right = right->right;
        count += 1;
      }
      if(!left && !right) return (1 << count) - 1;
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Accepted
// 18/18 cases passed (62 ms)
// Your runtime beats 13.83 % of cpp submissions
// Your memory usage beats 21.46 % of cpp submissions (30.9 MB)
```
