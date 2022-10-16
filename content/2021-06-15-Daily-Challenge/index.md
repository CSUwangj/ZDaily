+++
title = "2021-06-15 Daily-Challenge"
path = "2021-06-15-Daily-Challenge"
date = 2021-06-15 15:33:44+08:00
updated = 2021-06-15 21:23:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3780/) with `cpp`.

<!-- more -->

# Search in a Binary Search Tree

## Description

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```
Input: root = [4,2,7,1,3], val = 5
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `1 <= Node.val <= 10^7`
- `root` is a binary search tree.
- `1 <= val <= 10^7`

## Solution

``` cpp
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    if(root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
};
```

# June LeetCoding Challenge 15

## Description

**Matchsticks to Square**

You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.

Return `true` if you can make this square and `false` otherwise.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg)

```
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
```

**Example 2:**

```
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
```

 

**Constraints:**

- `1 <= matchsticks.length <= 15`
- `0 <= matchsticks[i] <= 10^9`

## Solution

``` cpp
class Solution {
  vector<bool> used;
  int len;
  long long target;
  bool solve(vector<int> &m, int a, int b, int c, int d, int l) {
    if(l == len && a == target && b == target && c == target && d == target) {
      return true;
    }
    if(a > target || b > target || c > target || d > target) {
      return false;
    }
    if(solve(m, a + m[l], b, c, d, l + 1)) return true;
    if(solve(m, a, b + m[l], c, d, l + 1)) return true;
    if(solve(m, a, b, c + m[l], d, l + 1)) return true;
    return solve(m, a, b, c, d + m[l], l + 1);
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    long long sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    return solve(matchsticks, 0, 0, 0, 0, 0); 
  }
};  
```
