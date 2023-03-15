+++
updated = 2023-03-15T14:41:22+08:00
title = "2023-03-15 Daily Challenge"
path = "2023-03-15-Daily-Challenge"
date = 2023-03-15T14:41:22+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 15

## Description

**Check Completeness of a Binary Tree**

<p>Given the <code>root</code> of a binary tree, determine if it is a <em>complete binary tree</em>.</p>

<p>In a <strong><a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">complete binary tree</a></strong>, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between <code>1</code> and <code>2<sup>h</sup></code> nodes inclusive at the last level <code>h</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png" style="width: 180px; height: 145px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png" style="width: 200px; height: 145px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,null,7]
<strong>Output:</strong> false
<strong>Explanation:</strong> The node with value 7 isn&#39;t as far left as possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 100]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
  enum state{ fail, complete, full };
  const pair<state, int> FAIL{fail, -1};
  // pair(state, height)
  pair<state, int> helper(TreeNode *root) {
    if(!root) return make_pair(full, 0);
    auto [leftState, leftHeight] = helper(root->left);
    auto [rightState, rightHeight] = helper(root->right);
    
    // fail if any of left/right subtree is not a complete tree
    if(leftState == fail || rightState == fail) return FAIL;
    
    // fail if height of left subtree is less than or is two or more greater than right subtree's
    // it's fail
    if(leftHeight < rightHeight || leftHeight > rightHeight + 1) return FAIL;
    
    if(leftHeight == rightHeight) {
      // left subtree is complete but not full, and have right subtree, it's fail
      if(leftState == complete) return FAIL;
      // if left subtree is full, then state of tree is depend on right subtree
      return {rightState, leftHeight + 1};
    }
    
    // height of left subtree is one greater than right subtree's
    // if right subtree is not full, it's fail
    if(rightState != full) return FAIL;
    // otherwise, it's a complete binary tree
    return {complete, leftHeight + 1};
  }
public:
  bool isCompleteTree(TreeNode* root) {
    auto [state, height] = helper(root);
    return state != fail;
  }
};

// Accepted
// 120/120 cases passed (7 ms)
// Your runtime beats 43.82 % of cpp submissions
// Your memory usage beats 78.75 % of cpp submissions (10.4 MB)
```
