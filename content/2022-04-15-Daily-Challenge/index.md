+++
updated = 2022-04-15 19:09:00+08:00
title = "2022-04-15 Daily-Challenge"
path = "2022-04-15-Daily-Challenge"
date = 2022-04-15 19:04:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/search-in-a-binary-search-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 15

## Description

**Trim a Binary Search Tree**

Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should **not** change the relative structure of the elements that will remain in the  tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a **unique answer**.

Return *the root of the trimmed binary search tree*. Note that the root may change depending on the given bounds.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg)

```
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg)

```
Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
```

 

**Constraints:**

- The number of nodes in the tree in the range `[1, 10^4]`.
- `0 <= Node.val <= 10^4`
- The value of each node in the tree is **unique**.
- `root` is guaranteed to be a valid binary search tree.
- `0 <= low <= high <= 10^4`

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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(!root) return root;
    if(root->val < low) return trimBST(root->right, low, high);
    if(root->val > high) return trimBST(root->left, low, high);
    while(root->left && root->left->val < low) root->left = root->left->right;
    root->left = trimBST(root->left, low, high);
    while(root->right && root->right->val > high) root->right = root->right->left;
    root->right = trimBST(root->right, low, high);
    return root;
  }
};

// Accepted
// 78/78 cases passed (7 ms)
// Your runtime beats 99.34 % of cpp submissions
// Your memory usage beats 7.34 % of cpp submissions (24.1 MB)
```
