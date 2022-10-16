+++
updated = 2022-08-10 18:14:00+08:00
title = "2022-08-10 Daily-Challenge"
path = "2022-08-10-Daily-Challenge"
date = 2022-08-10 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 10

## Description

**Convert Sorted Array to Binary Search Tree**

Given an integer array `nums` where the elements are sorted in **ascending order**, convert *it to a **height-balanced** binary search tree*.

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

```
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in a **strictly increasing** order.

## Solution

``` cpp
class Solution {
  TreeNode *construct(vector<int> &nums, int begin, int end) {
    if(begin > end) return nullptr;
    int mid = (begin + end) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = construct(nums, begin, mid - 1);
    root->right = construct(nums, mid + 1, end);
    return root;
  }
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    return construct(nums, 0, len - 1);
  }
};

// Accepted
// 31/31 cases passed (8 ms)
// Your runtime beats 95.55 % of cpp submissions
// Your memory usage beats 75.67 % of cpp submissions (21.4 MB)
```
