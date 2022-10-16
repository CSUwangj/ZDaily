+++
updated = 2022-09-07 18:14:00+08:00
title = "2022-09-07 Daily-Challenge"
path = "2022-09-07-Daily-Challenge"
date = 2022-09-07 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/construct-string-from-binary-tree/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 7

## Description

**Construct String from Binary Tree**

Given the `root` of a binary tree, construct a string consisting of parenthesis and  integers from a binary tree with the preorder traversal way, and return  it.

Omit all the empty parenthesis pairs that do not affect the  one-to-one mapping relationship between the string and the original  binary tree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg)

```
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/03/cons2-tree.jpg)

```
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`

## Solution

``` cpp
class Solution {
public:
  string tree2str(TreeNode* root) {
    if(!root) return "";
    auto current = to_string(root->val);
    if(root->left || root->right) current += "(" + tree2str(root->left) + ")";
    if(root->right) current += "(" + tree2str(root->right) + ")";
    return current;
  }
};

// Accepted
// 160/160 cases passed (53 ms)
// Your runtime beats 25.89 % of cpp submissions
// Your memory usage beats 23.79 % of cpp submissions (53.9 MB)
```
