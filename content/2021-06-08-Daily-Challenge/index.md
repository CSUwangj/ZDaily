+++
title = "2021-06-08 Daily-Challenge"
path = "2021-06-08-Daily-Challenge"
date = 2021-06-08 15:06:53+08:00
updated = 2021-06-08 19:57:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3771/) with `cpp`.

<!-- more -->

# Subarray Sums Divisible by K

## Description

Given an array `nums` of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by `k`.

 

**Example 1:**

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

 

**Note:**

1. `1 <= nums.length <= 30000`
2. `-10000 <= nums[i] <= 10000`
3. `2 <= k <= 10000`

## Solution

``` cpp
class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    int sum = 0;
    int answer = 0;
    cnt[0] = 1;
    for(auto i : nums) {
      sum = ((sum + i) % k + k) % k;
      answer += cnt[sum];
      cnt[sum] += 1;
    }
    return answer;
  }
};
```

# June LeetCoding Challenge 8

## Description

**Construct Binary Tree from Preorder and Inorder Traversal**

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

 

**Constraints:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is **guaranteed** to be the preorder traversal of the tree.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.

## Solution

``` cpp
class Solution {
  TreeNode *build(
    vector<int>& preorder,
    int preBegin,
    int preEnd,
    vector<int>& inorder,
    int inBegin,
    int inEnd
  ) {
    if(preBegin > preEnd) return nullptr;
    int rootIdx = -1;
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == preorder[preBegin]) {
        rootIdx = i;
        break;
      }
    }
    int offset = rootIdx - inBegin;
    TreeNode *root = new TreeNode(preorder[preBegin]);
    root->left = build(preorder, preBegin + 1, preBegin + offset, inorder, inBegin, inBegin + offset - 1);
    root->right = build(preorder, preBegin + offset + 1, preEnd, inorder, inBegin + offset + 1, inEnd);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    return build(preorder, 0, len - 1, inorder, 0, len - 1);
  }
};
```
