+++
title = "2021-05-16 Daily-Challenge"
path = "2021-05-16-Daily-Challenge"
date = 2021-05-16 15:05:33+08:00
updated = 2021-05-16 15:40:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3745/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 16

## Description

**Binary Tree Cameras**

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor **its parent, itself, and its immediate children**.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png)

```
Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png)

```
Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
```


**Note:**

1. The number of nodes in the given tree will be in the range `[1, 1000]`.
2. **Every** node has value 0.

## Solution

another 1A, haha!

it's a tree DP?

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
  unordered_map<TreeNode*, int> put;
  unordered_map<TreeNode*, int> covered;
  unordered_map<TreeNode*, int> blank;
  void solve(TreeNode *root) {
    if(!root) return;
    solve(root->left);
    solve(root->right);
    put[root] = 1 + min({
                    covered[root->left],
                    put[root->left],
                    blank[root->left]
                  }) + min({
                    covered[root->right],
                    put[root->right],
                    blank[root->right]
                  });
    covered[root] = min({put[root->left] + covered[root->right],
                         put[root->right] + covered[root->left],
                         put[root->left] + put[root->right]});
    blank[root] = covered[root->left] + covered[root->right];
  }
public:
  int minCameraCover(TreeNode* root) {
    put[nullptr] = 10000;
    solve(root);
    return min(put[root], covered[root]);
  }
};
```

check [solution](https://leetcode.com/problems/binary-tree-cameras/solution/) and learned greedy solution

``` cpp
class Solution {
  unordered_set<TreeNode*> covered{nullptr};
  int answer = 0;
  void solve(TreeNode *cur, TreeNode *par = nullptr) {
    if(!cur) return;
    solve(cur->left, cur);
    solve(cur->right, cur);
    if((par == nullptr && !covered.count(cur)) || !covered.count(cur->left) || !covered.count(cur->right)) {
      answer += 1;
      covered.insert(cur);
      covered.insert(par);
      covered.insert(cur->left);
      covered.insert(cur->right);
    }
  }
public:
  int minCameraCover(TreeNode* root) {
    solve(root);
    return answer;
  }
};
```
