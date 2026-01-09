+++
updated = 2026-01-09T21:45:17+01:00
title = "2026-01-09 Daily Challenge"
path = "2026-01-09-Daily-Challenge"
date = 2026-01-09T21:45:17+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 9

## Description

**Smallest Subtree with all the Deepest Nodes**

<p>Given the <code>root</code> of a binary tree, the depth of each node is <strong>the shortest distance to the root</strong>.</p>

<p>Return <em>the smallest subtree</em> such that it contains <strong>all the deepest nodes</strong> in the original tree.</p>

<p>A node is called <strong>the deepest</strong> if it has the largest depth possible among any node in the entire tree.</p>

<p>The <strong>subtree</strong> of a node is a tree consisting of that node, plus the set of all descendants of that node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" style="width: 600px; height: 510px;" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>Output:</strong> [2,7,4]
<strong>Explanation:</strong> We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The root is the deepest node in the tree.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0,1,3,null,2]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[1, 500]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>The values of the nodes in the tree are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 1123: <a href="https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/" target="_blank">https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/</a></p>


## Solution

``` cpp
class Solution {
  pair<TreeNode*, int> helper(TreeNode* root, int level) {
    if(!root) return make_pair(root, 0);
    auto left = helper(root->left, level+1);
    auto right = helper(root->right, level+1);
    if(left.second == right.second) return make_pair(root, left.second ? left.second : level);
    if(left.second < right.second) return right;
    return left;
  }
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return helper(root, 0).first;
  }
};

// Accepted
// 58/58 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 27.2 % of cpp submissions (16.3 MB)
```
