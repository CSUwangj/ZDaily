+++
title = "2020-10-22 Daily-Challenge"
path = "2020-10-22-Daily-Challenge"
date = 2020-10-22 00:33:22+08:00
updated = 2020-10-22 20:18:48+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Add One Row to Tree* on [leetcode](https://leetcode.com/problems/add-one-row-to-tree/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3504/) with `cpp`.

<!-- more -->

# Add One Row to Tree

## Description

Given the root of a binary tree, then value `v` and depth `d`, you need to add a row of nodes with value `v` at the given depth `d`. The root node is at depth 1.

The adding rule is: given a positive integer depth `d`, for each NOT null tree nodes `N` in depth `d-1`, create two tree nodes with value `v` as `N's` left subtree root and right subtree root. And `N's` **original left subtree** should be the left subtree of the new left subtree root, its **original right subtree** should be the right subtree of the new right subtree root. If depth `d` is 1 that means there is no depth d-1 at all, then create a tree node with value **v** as the new root of the whole original tree, and the original tree is the new root's left subtree.

**Example 1:**

```
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   
```



**Example 2:**

```
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
```

**Note:**

1. The given d is in range [1, maximum depth of the given tree + 1].
2. The given binary tree has at least one tree node.

## Solution

recursive solution

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* addOneRow(TreeNode* root, int v, int d, TreeNode* left, TreeNode* right) {
        if(d == 1) {
            return new TreeNode(v, left, right);
        }
        if(!root) return nullptr;
        root->left = addOneRow(root->left, v, d-1, root->left, nullptr);
        root->right = addOneRow(root->right, v, d-1, nullptr, root->right);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return addOneRow(root, v, d, root, nullptr);
    }
};
```

# October LeetCoding Challenge 22

## Description

**Minimum Depth of Binary Tree**

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

**Example 2:**

```
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 105]`.
- `-1000 <= Node.val <= 1000`

## Solution

nothing to say.

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!(root->left) && !(root->right)) return 1;
        if(root->left && root->right) return 1+min(minDepth(root->left), minDepth(root->right));
        if(root->left) return 1+minDepth(root->left);
        return 1+minDepth(root->right);
    }
};
```
