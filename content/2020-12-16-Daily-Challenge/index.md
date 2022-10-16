+++
title = "2020-12-16 Daily-Challenge"
path = "2020-12-16-Daily-Challenge"
date = 2020-12-16 12:00:42+08:00
updated = 2020-12-16 19:57:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find Peak Element](https://leetcode.com/problems/find-peak-element/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3568/) with `cpp`.

<!-- more -->

# Find Peak Element

## Description

A peak element is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

**Example 2:**

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-231 <= nums[i] <= 231 - 1`
- `nums[i] != nums[i + 1]` for all valid `i`.

**Follow up:** Could you implement a solution with logarithmic complexity?

## Solution

logarithmic complexity solution, just use binary search

``` cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int len = nums.size();
        if(nums[0] > nums[1]) return 0;
        if(nums[len-1] > nums[len-2]) return len-1;
        int begin = 0, end = len-1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            if(nums[mid] < nums[mid-1]) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        return -1;
    }
};
```

# December LeetCoding Challenge 16

## Description

**Validate Binary Search Tree**

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```
Input: root = [2,1,3]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `-231 <= Node.val <= 231 - 1`

## Solution

inorder traversal

``` cpp
class Solution {
    int prev;
    bool hasPrev = false;
    
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(!hasPrev) {
            prev = root->val;
            hasPrev = true;
        } else {
            if(root->val <= prev) return false;
            prev = root->val;
        }
        return isValidBST(root->right);
    }
};
```