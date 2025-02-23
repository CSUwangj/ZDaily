+++
updated = 2025-02-23T11:48:40+08:00
title = "2025-02-23 Daily Challenge"
path = "2025-02-23-Daily-Challenge"
date = 2025-02-23T11:48:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 23

## Description

**Construct Binary Tree from Preorder and Postorder Traversal**

<p>Given two integer arrays, <code>preorder</code> and <code>postorder</code> where <code>preorder</code> is the preorder traversal of a binary tree of <strong>distinct</strong> values and <code>postorder</code> is the postorder traversal of the same tree, reconstruct and return <em>the binary tree</em>.</p>

<p>If there exist multiple answers, you can <strong>return any</strong> of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/24/lc-prepost.jpg" style="width: 304px; height: 265px;" />
<pre>
<strong>Input:</strong> preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
<strong>Output:</strong> [1,2,3,4,5,6,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> preorder = [1], postorder = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 30</code></li>
	<li><code>1 &lt;= preorder[i] &lt;= preorder.length</code></li>
	<li>All the values of <code>preorder</code> are <strong>unique</strong>.</li>
	<li><code>postorder.length == preorder.length</code></li>
	<li><code>1 &lt;= postorder[i] &lt;= postorder.length</code></li>
	<li>All the values of <code>postorder</code> are <strong>unique</strong>.</li>
	<li>It is guaranteed that <code>preorder</code> and <code>postorder</code> are the preorder traversal and postorder traversal of the same binary tree.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  TreeNode* constructFromPrePost(
    vector<int>& preorder,
    vector<int>& postorder,
    int prebegin = -1,
    int preend = -1,
    int postbegin = -1,
    int postend = -1
  ) {
    if(prebegin == -1) {
      prebegin = 0;
      preend = preorder.size() - 1;
      postbegin = 0;
      postend = preorder.size() - 1;
    }
    if(prebegin > preend) return nullptr;
    TreeNode *root = new TreeNode(preorder[prebegin]);
    if(prebegin == preend) return root;
    int pivot = -1;
    for(int i = postbegin; i <= postend && pivot == -1; ++i) {
      if(postorder[i] == preorder[prebegin + 1]) {
        int offset = i - postbegin;
        root->left = constructFromPrePost(preorder, postorder, prebegin + 1, prebegin + 1 + offset, postbegin, postbegin + offset);
        pivot = offset;
      }
    }
    if(prebegin + 1 + pivot == preend) return root;
    root->right = constructFromPrePost(preorder, postorder, prebegin + 1 + pivot + 1, preend, postbegin + pivot + 1, postend - 1);
    return root;
  }
};

// Accepted
// 306/306 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 56.32 % of cpp submissions (28.2 MB)
```
