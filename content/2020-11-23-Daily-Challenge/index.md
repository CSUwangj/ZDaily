+++
title = "2020-11-23 Daily-Challenge"
path = "2020-11-23-Daily-Challenge"
date = 2020-11-23 18:02:13+08:00
updated = 2020-11-23 18:53:57+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Monotonic Array* on [leetcode](https://leetcode.com/problems/monotonic-array/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3541/) with `cpp`.

<!-- more -->

# Monotonic Array

## Description

An array is *monotonic* if it is either monotone increasing or monotone decreasing.

An array `A` is monotone increasing if for all `i <= j`, `A[i] <= A[j]`. An array `A` is monotone decreasing if for all `i <= j`, `A[i] >= A[j]`.

Return `true` if and only if the given array `A` is monotonic.

**Example 1:**

```
Input: [1,2,2,3]
Output: true
```

**Example 2:**

```
Input: [6,5,4,4]
Output: true
```

**Example 3:**

```
Input: [1,3,2]
Output: false
```

**Example 4:**

```
Input: [1,2,4,5]
Output: true
```

**Example 5:**

```
Input: [1,1,1]
Output: true
```

**Note:**

1. `1 <= A.length <= 50000`
2. `-100000 <= A[i] <= 100000`

## Solution

nothing to say

``` cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        int pos = 1;
        while(pos < len && A[pos] == A[pos-1]) ++pos;
        if(pos == len) return true;
        if(A[pos] > A[pos-1]) {
            while(pos < len && A[pos] >= A[pos-1]) ++pos;
            return pos==len;
        } else {
            while(pos < len && A[pos] <= A[pos-1]) ++pos;
            return pos==len;
        }
        
    }
};
```

# November LeetCoding Challenge23

**House Robber III**

## Description

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

**Example 1:**

```
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

**Example 2:**

```
Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

## Solution

basic tree DP

same as first problem on [OI-WIKI](https://oi-wiki.org/dp/tree/)

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
    unordered_map<TreeNode*, pair<int, int>> m{{nullptr, {0, 0}}};
    void calc(TreeNode* root) {
        if(!root) return;
        calc(root->left);
        calc(root->right);
        int notPick = max(m[root->left].first, m[root->left].second) + max(m[root->right].first, m[root->right].second);
        int pick = root->val + m[root->left].first + m[root->right].first;
        m[root] = make_pair(notPick, pick);
    }
public:
    int rob(TreeNode* root) {
        calc(root);
        return max(m[root].first, m[root].second);
    }
};
```
