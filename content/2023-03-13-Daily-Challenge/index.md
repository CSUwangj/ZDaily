+++
updated = 2023-03-13T11:21:53+08:00
title = "2023-03-13 Daily Challenge"
path = "2023-03-13-Daily-Challenge"
date = 2023-03-13T11:21:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/symmetric-tree/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 13

## Description

**Symmetric Tree**

<p>Given the <code>root</code> of a binary tree, <em>check whether it is a mirror of itself</em> (i.e., symmetric around its center).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 354px; height: 291px;" />
<pre>
<strong>Input:</strong> root = [1,2,2,3,4,4,3]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;" />
<pre>
<strong>Input:</strong> root = [1,2,2,null,3,null,3]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it both recursively and iteratively?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool helper(TreeNode *left, TreeNode *right) {
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    return helper(left->left, right->right) && helper(left->right, right->left);
  }
public:
  bool isSymmetric(TreeNode* root) {
    return helper(root, root);
  }
};

// Accepted
// 197/197 cases passed (8 ms)
// Your runtime beats 50.17 % of cpp submissions
// Your memory usage beats 17.95 % of cpp submissions (16.5 MB)
```
