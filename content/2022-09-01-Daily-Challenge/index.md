+++
updated = 2022-09-01 18:14:00+08:00
title = "2022-09-01 Daily-Challenge"
path = "2022-09-01-Daily-Challenge"
date = 2022-09-01 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 1

## Description

**Count Good Nodes in Binary Tree**

Given a binary tree `root`, a node *X* in the tree is named **good** if in the path from root to *X* there are no nodes with a value *greater than* X.

Return the number of **good** nodes in the binary tree.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)**

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png)**

```
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

 

**Constraints:**

- The number of nodes in the binary tree is in the range `[1, 10^5]`.
- Each node's value is between `[-10^4, 10^4]`.

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
  int goodNodes(TreeNode* root, int X = INT_MIN) {
    if(!root) return 0;
    if(root->val >= X) {
      return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
    } else {
      return goodNodes(root->left, X) + goodNodes(root->right, X);
    }
  }
};

// Accepted
// 63/63 cases passed (96 ms)
// Your runtime beats 99.23 % of cpp submissions
// Your memory usage beats 6.64 % of cpp submissions (86.6 MB)
```
