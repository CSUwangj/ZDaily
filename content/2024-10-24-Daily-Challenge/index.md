+++
updated = 2024-10-24T10:15:07+08:00
title = "2024-10-24 Daily Challenge"
path = "2024-10-24-Daily-Challenge"
date = 2024-10-24T10:15:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/flip-equivalent-binary-trees/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 24

## Description

**Flip Equivalent Binary Trees**

<p>For a binary tree <strong>T</strong>, we can define a <strong>flip operation</strong> as follows: choose any node, and swap the left and right child subtrees.</p>

<p>A binary tree <strong>X</strong>&nbsp;is <em>flip equivalent</em> to a binary tree <strong>Y</strong> if and only if we can make <strong>X</strong> equal to <strong>Y</strong> after some number of flip operations.</p>

<p>Given the roots of two binary trees <code>root1</code> and <code>root2</code>, return <code>true</code> if the two trees are flip equivalent or <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Flipped Trees Diagram" src="https://assets.leetcode.com/uploads/2018/11/29/tree_ex.png" style="width: 500px; height: 220px;" />
<pre>
<strong>Input:</strong> root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
<strong>Output:</strong> true
<strong>Explanation: </strong>We flipped at nodes with values 1, 3, and 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root1 = [], root2 = []
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root1 = [], root2 = [1]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree is in the range <code>[0, 100]</code>.</li>
	<li>Each tree will have <strong>unique node values</strong> in the range <code>[0, 99]</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if(!root1 || !root2) {
        if(root1 != root2) return false;
        return true;
    }
    if(root1->val != root2->val) return false;
    if(root1->left || root1->right || root2->left || root2->right) return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) || (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
    return true;
  }
};
```
