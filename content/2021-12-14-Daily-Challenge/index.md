+++
title = "2021-12-14 Daily-Challenge"
path = "2021-12-14-Daily-Challenge"
date = 2021-12-14 18:40:00+08:00
updated = 2021-12-14 18:49:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/range-sum-of-bst/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 14

## Description

**Range Sum of BST**

Given the `root` node of a binary search tree and two integers `low` and `high`, return *the sum of values of all nodes with a value in the **inclusive** range* `[low, high]`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg)

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg)

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2 * 10^4]`.
- `1 <= Node.val <= 10^5`
- `1 <= low <= high <= 10^5`
- All `Node.val` are **unique**.

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
  int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root) return 0;
    if(root->val > high) return rangeSumBST(root->left, low, high);
    if(root->val < low) return rangeSumBST(root->right, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
};

// Accepted
// 41/41 cases passed (92 ms)
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 60.14 % of cpp submissions (64.6 MB)
```
