+++
title = "2021-01-02 Daily-Challenge"
path = "2021-01-02-Daily-Challenge"
date = 2021-01-02 02:57:46+08:00
updated = 2021-01-02 19:38:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3590/) with `cpp`.

<!-- more -->

# LeetCode Review

## Merge Two Sorted Lists

too easy to review

## Sort Array By Parity II

too easy to review

## Construct Quad Tree

too easy to review

## Check Array Formation Through Concatenation

too easy to review

## Task Scheduler

no need to review

## Reach a Number

no need to review

## Pseudo-Palindromic Paths in a Binary Tree

no need to review

## Largest Rectangle in Histogram

use a stack just need one iteration

``` cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st{-1};
        heights.push_back(0);
        int len = heights.size();
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            while(st.size() && st.back() != -1 && heights[i] < heights[st.back()]) {
                int index = st.back();
                st.pop_back();
                int h = heights[index];
                int w = i - st.back() - 1;
                answer = max(answer, h*w);
            }
            st.push_back(i);
        }
        return answer;
    }
};
```

## Game of Life

another way to enumerate

``` cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int count = 0;
                for(int row = max(0, i-1); row <= min(rows-1, i+1); ++row) {
                    for(int col = max(0, j-1); col <= min(cols-1, j+1); ++col) {
                        count += (board[row][col]&1);
                    }
                }
                count -= board[i][j];
                if(count == 3 || (count == 2 && board[i][j] == 1)) {
                    board[i][j] |= 2;
                }
            }
        }
        for(auto &row : board) {
            for(auto &cell : row) {
                cell >>= 1;
            }
        }
    }
};
```

## Lowest Common Ancestor of a Binary Tree

using parent pointers

``` cpp
class Solution {
    unordered_map<TreeNode*, int> level;
    unordered_map<TreeNode*, TreeNode*> parent;
    void build(TreeNode *root) {
        if(!root) return;
        if(root->left) {
            level[root->left] = level[root] + 1;
            parent[root->left] = root;
            build(root->left);
        }
        if(root->right) {
            level[root->right] = level[root] + 1;
            parent[root->right] = root;
            build(root->right);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        build(root);
        while(level[p] > level[q]) p = parent[p];
        while(level[q] > level[p]) q = parent[q];
        while(q != p) {
            p = parent[p];
            q = parent[q];
        }
        return q;
    }
};
```

# January LeetCoding Challenge2

## Description

**Find a Corresponding Node of a Binary Tree in a Clone of That Tree**

Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.

The `cloned` tree is a **copy of** the `original` tree.

Return *a reference to the same node* in the `cloned` tree.

**Note** that you are **not allowed** to change any of the two trees or the `target` node and the answer **must be** a reference to a node in the `cloned` tree.

**Follow up:** Solve the problem if repeated values on the tree are allowed.

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

**Example 4:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e4.png)

```
Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5
```

**Example 5:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e5.png)

```
Input: tree = [1,2,null,3], target = 2
Output: 2
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 10^4]`.
- The values of the nodes of the `tree` are unique.
- `target` node is a node from the `original` tree and is not `null`.

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
```
