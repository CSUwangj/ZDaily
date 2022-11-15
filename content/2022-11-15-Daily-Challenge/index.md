+++
updated = 2022-11-15T12:43:05+08:00
title = "2022-11-15 Daily Challenge"
path = "2022-11-15-Daily-Challenge"
date = 2022-11-15T12:43:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/count-complete-tree-nodes/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 15

## Description

**Count Complete Tree Nodes**

<p>Given the <code>root</code> of a <strong>complete</strong> binary tree, return the number of the nodes in the tree.</p>

<p>According to <strong><a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">Wikipedia</a></strong>, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between <code>1</code> and <code>2<sup>h</sup></code> nodes inclusive at the last level <code>h</code>.</p>

<p>Design an algorithm that runs in less than&nbsp;<code data-stringify-type="code">O(n)</code>&nbsp;time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/complete.jpg" style="width: 372px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 5 * 10<sup>4</sup></code></li>
	<li>The tree is guaranteed to be <strong>complete</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
  int height(TreeNode *root) {
    if(!root) return -1;
    int h = 0;
    while(root) {
      h += 1;
      root = root->left;
    }
    return h-1;
  }
public:
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      int h = height(root);
      return h < 0 ? 0 :
                     height(root->right) == h - 1 ? (1 << h) + countNodes(root->right) :
                                                    (1 << (h - 1)) + countNodes(root->left);
    }
};

// Accepted
// 18/18 cases passed (30 ms)
// Your runtime beats 97.25 % of cpp submissions
// Your memory usage beats 93.85 % of cpp submissions (30.7 MB)
```
