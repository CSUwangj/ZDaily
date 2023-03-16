+++
updated = 2023-03-16T10:36:50+08:00
title = "2023-03-16 Daily Challenge"
path = "2023-03-16-Daily-Challenge"
date = 2023-03-16T10:36:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 16

## Description

**Construct Binary Tree from Inorder and Postorder Traversal**

<p>Given two integer arrays <code>inorder</code> and <code>postorder</code> where <code>inorder</code> is the inorder traversal of a binary tree and <code>postorder</code> is the postorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>Input:</strong> inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
<strong>Output:</strong> [3,9,20,null,null,15,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> inorder = [-1], postorder = [-1]
<strong>Output:</strong> [-1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= inorder.length &lt;= 3000</code></li>
	<li><code>postorder.length == inorder.length</code></li>
	<li><code>-3000 &lt;= inorder[i], postorder[i] &lt;= 3000</code></li>
	<li><code>inorder</code> and <code>postorder</code> consist of <strong>unique</strong> values.</li>
	<li>Each value of <code>postorder</code> also appears in <code>inorder</code>.</li>
	<li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
	<li><code>postorder</code> is <strong>guaranteed</strong> to be the postorder traversal of the tree.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  TreeNode* buildTree(
    vector<int> &inorder, 
    int inBegin,
    int inEnd,
    vector<int> &postorder,
    int postBegin,
    int postEnd
  ) {
    if(inBegin > inEnd) return nullptr;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == postorder[postEnd]) {
        int offset = i - inBegin;
        root->left = buildTree(inorder, inBegin, inBegin + offset - 1, postorder, postBegin, postBegin + offset - 1);
        root->right = buildTree(inorder, inBegin + offset + 1, inEnd, postorder, postBegin + offset, postEnd - 1);
        break;
      }
    }
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int len = inorder.size();
    return buildTree(inorder, 0, len - 1, postorder, 0, len - 1);
  }
};

// Accepted
// 202/202 cases passed (32 ms)
// Your runtime beats 32.56 % of cpp submissions
// Your memory usage beats 62.12 % of cpp submissions (26.2 MB)
```
