+++
updated = 2024-08-25T14:22:26+08:00
title = "2024-08-25 Daily Challenge"
path = "2024-08-25-Daily-Challenge"
date = 2024-08-25T14:22:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/binary-tree-postorder-traversal/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 25

## Description

**Binary Tree Postorder Traversal**

<p>Given the <code>root</code> of a&nbsp;binary tree, return <em>the postorder traversal of its nodes&#39; values</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg" style="width: 127px; height: 200px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,3]
<strong>Output:</strong> [3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?

## Solution

``` cpp
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->right)) {
        answer.push_back(cur->val);
        cur = cur->left;
      } else {
        TreeNode *right = cur->right;
        while(right->left && right->left != cur) {
          right = right->left;
        }
        if(right->left == cur) {
          right->left = nullptr;
          cur = cur->left;
        } else {
          answer.push_back(cur->val);
          right->left = cur;
          cur = cur->right;
        }
      }
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
```
