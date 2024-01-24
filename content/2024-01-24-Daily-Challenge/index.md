+++
updated = 2024-01-24T19:40:43+08:00
title = "2024-01-24 Daily Challenge"
path = "2024-01-24-Daily-Challenge"
date = 2024-01-24T19:40:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 24

## Description

**Pseudo-Palindromic Paths in a Binary Tree**

<p>Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be <strong>pseudo-palindromic</strong> if at least one permutation of the node values in the path is a palindrome.</p>

<p><em>Return the number of <strong>pseudo-palindromic</strong> paths going from the root node to leaf nodes.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;" /></p>

<pre>
<strong>Input:</strong> root = [2,3,1,3,1,null,1]
<strong>Output:</strong> 2 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;" /></strong></p>

<pre>
<strong>Input:</strong> root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>Output:</strong> 1 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [9]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 9</code></li>
</ul>


## Solution

``` cpp
class Solution {
  bool parity[10] = {0};
  int answer = 0;
  int odd = 0;
  void helper(TreeNode *root) {
    parity[root->val] ^= 1;
    if(parity[root->val]) odd += 1;
    else odd -= 1;
    if(!(root->left) && !(root->right)) answer += (odd < 2);
    if(root->left) helper(root->left);
    if(root->right) helper(root->right);
    if(parity[root->val]) odd -= 1;
    else odd += 1;
    parity[root->val] ^= 1;
  }
public:
  int pseudoPalindromicPaths (TreeNode* root) {
    helper(root);
    return answer;
  }
};

// Accepted
// 56/56 cases passed (246 ms)
// Your runtime beats 89.81 % of cpp submissions
// Your memory usage beats 99.2 % of cpp submissions (177.6 MB)
```
