+++
updated = 2024-01-09T13:28:23+08:00
title = "2024-01-09 Daily Challenge"
path = "2024-01-09-Daily-Challenge"
date = 2024-01-09T13:28:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/leaf-similar-trees/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 9

## Description

**Leaf-Similar Trees**

<p>Consider all the leaves of a binary tree, from&nbsp;left to right order, the values of those&nbsp;leaves form a <strong>leaf value sequence</strong><em>.</em></p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 400px; height: 336px;" /></p>

<p>For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.</p>

<p>Two binary trees are considered <em>leaf-similar</em>&nbsp;if their leaf value sequence is the same.</p>

<p>Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg" style="width: 600px; height: 237px;" />
<pre>
<strong>Input:</strong> root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg" style="width: 300px; height: 110px;" />
<pre>
<strong>Input:</strong> root1 = [1,2,3], root2 = [1,3,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree will be in the range <code>[1, 200]</code>.</li>
	<li>Both of the given trees will have values in the range <code>[0, 200]</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  void add(TreeNode* node, vector<int> &sequence) {
    if(!node->left && !node->right) {
      sequence.push_back(node->val);
    } else {
      if(node->left) add(node->left, sequence);
      if(node->right) add(node->right, sequence);
    }
  }
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1, seq2;
    add(root1, seq1);
    add(root2, seq2);
    return seq1 == seq2;
  }
};

// Accepted
// 43/43 cases passed (3 ms)
// Your runtime beats 66.12 % of cpp submissions
// Your memory usage beats 13.67 % of cpp submissions (13.6 MB)
```
