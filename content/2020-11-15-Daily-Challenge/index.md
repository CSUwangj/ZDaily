+++
title = "2020-11-15 Daily-Challenge"
path = "2020-11-15-Daily-Challenge"
date = 2020-11-15 16:42:21+08:00
updated = 2020-11-15 21:31:47+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3532/) with `cpp`.

<!-- more -->

# LeetCode Review

## Populating Next Right Pointers in Each Node

use `next` pointer we built to achieve the goal

``` cpp
class Solution {
public:
    Node* connect(Node* root) {
        Node* curLevel = root;
        while(curLevel) {
            Node* nextLevel = curLevel->left;
            Node* curNode = curLevel;
            while(curNode) {
                if(curNode->left) curNode->left->next = curNode->right;
                if(curNode->right) {
                    if(curNode->next) curNode->right->next = curNode->next->left;
                    else curNode->right->next = nullptr;
                }
                curNode = curNode->next;
            }
            curLevel = nextLevel;
        }
        return root;
    }
};
```

## Permutations II

handwritting next_permutation

but without optimization

``` cpp
class Solution {
    bool next_permutation(vector<int>& nums) {
        if(nums.size() < 2) return false;
        int len = nums.size();
        int a = len - 2;
        
        while(a >= 0 && nums[a] >= nums[a+1]) a -= 1;
        if(a == -1) return false;
        
        int minGreater = INT_MAX, b = -1;
        int i = a+1;
        while(i < len) {
            if(nums[i] > nums[a] && nums[i] < minGreater) {
                b = i;
                minGreater = nums[i];
            }
            i += 1;
        }
        
        swap(nums[a], nums[b]);
        sort(nums.begin()+a+1, nums.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{nums};
        while(next_permutation(nums)) {
            ans.push_back(nums);
        }
        return ans;
    }
};
```

rest one hard problem is great question which need no review(actually my laptop is running out of battery ;P)

# November LeetCoding Challenge15

## Description

**Range Sum of BST**

Given the `root` node of a binary search tree, return *the sum of values of all nodes with a value in the range `[low, high]`*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg)

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg)

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2 * 104]`.
- `1 <= Node.val <= 105`
- `1 <= low <= high <= 105`
- All `Node.val` are **unique**.

## Solution

nothing to say

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
    int result = 0;
    int high;
    int low;
    void helper(TreeNode* root) {
        if(!root) return;
        if(root->val >= low && root->val <= high) result += root->val;
        if(root->val > low) helper(root->left);
        if(root->val < high) helper(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        helper(root);
        return result;
    }
};
```
