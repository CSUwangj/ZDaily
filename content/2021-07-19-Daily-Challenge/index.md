+++
title = "2021-07-19 Daily-Challenge"
path = "2021-07-19-Daily-Challenge"
date = 2021-07-19 20:33:34+08:00
updated = 2021-07-19 20:54:33+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3819/) with `cpp`.

<!-- more -->

# Rank Transform of an Array

## Description

Given an array of integers `arr`, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

- Rank is an integer starting from 1.
- The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
- Rank should be as small as possible.

 

**Example 1:**

```
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
```

**Example 2:**

```
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
```

**Example 3:**

```
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
```

 

**Constraints:**

- `0 <= arr.length <= 10^5`
- `-10^9 <= arr[i] <= 10^9`

## Solution

bad data, counting sort can be 44ms and beat 100%, but it's a fake solution.

``` cpp
class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> order(arr);
    sort(order.begin(), order.end());
    order.resize(unique(order.begin(), order.end()) - order.begin());
    unordered_map<int, int> rk;
    int count = 0;
    for(auto i : order) rk[i] = ++count;
    for(auto &i : arr) i = rk[i];
    return arr;
  }
};

// Accepted
// 37/37 cases passed (84 ms)
// Your runtime beats 89.57 % of cpp submissions
// Your memory usage beats 72.51 % of cpp submissions (39.1 MB)
```

# July LeetCoding Challenge 19

## Description

**Lowest Common Ancestor of a Binary Search Tree**

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [2,1], p = 2, q = 1
Output: 2
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

## Solution

``` cpp
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    if(left) return left;
    if(right) return right;
    return nullptr;
  }
};

// Accepted
// 27/27 cases passed (28 ms)
// Your runtime beats 79.85 % of cpp submissions
// Your memory usage beats 9.47 % of cpp submissions (23.3 MB)
```

ah ha, it's a BST

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    return root;
  }
};

// Accepted
// 27/27 cases passed (20 ms)
// Your runtime beats 99.02 % of cpp submissions
// Your memory usage beats 57.6 % of cpp submissions (23.3 MB)
```
