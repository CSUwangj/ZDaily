+++
title = "2021-02-02 Daily-Challenge"
path = "2021-02-02-Daily-Challenge"
date = 2021-02-02 18:00:59+08:00
updated = 2021-02-02 18:54:06+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done  and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3622/) with `cpp`.

<!-- more -->


# February LeetCoding Challenge2

**Trim a Binary Search Tree**

## Description

Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should **not** change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a **unique answer**.

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

**Example 3:**

```
Input: root = [1], low = 1, high = 2
Output: [1]
```

**Example 4:**

```
Input: root = [1,null,2], low = 1, high = 3
Output: [1,null,2]
```

**Example 5:**

```
Input: root = [1,null,2], low = 2, high = 4
Output: [2]
```

 

**Constraints:**

- The number of nodes in the tree in the range `[1, 104]`.
- $0 \le Node.val \le 10^4$`
- The value of each node in the tree is **unique**.
- `root` is guaranteed to be a valid binary search tree.
- $0 \le low \le high\le 10^4$

## Solution

``` cpp
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
```