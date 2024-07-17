+++
updated = 2024-07-17T14:56:48+08:00
title = "2024-07-17 Daily Challenge"
path = "2024-07-17-Daily-Challenge"
date = 2024-07-17T14:56:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/delete-nodes-and-return-forest/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 17

## Description

**Delete Nodes And Return Forest**

<p>Given the <code>root</code> of a binary tree, each node in the tree has a distinct value.</p>

<p>After deleting all nodes with a value in <code>to_delete</code>, we are left with a forest (a disjoint union of trees).</p>

<p>Return the roots of the trees in the remaining forest. You may return the result in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png" style="width: 237px; height: 150px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6,7], to_delete = [3,5]
<strong>Output:</strong> [[1,2,null,4],[6],[7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2,4,null,3], to_delete = [3]
<strong>Output:</strong> [[1,2,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is at most <code>1000</code>.</li>
	<li>Each node has a distinct value between <code>1</code> and <code>1000</code>.</li>
	<li><code>to_delete.length &lt;= 1000</code></li>
	<li><code>to_delete</code> contains distinct values between <code>1</code> and <code>1000</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  TreeNode *solve(TreeNode* root, const set<int>& to_delete, vector<TreeNode*> &answer, bool newRoot = false) {
    if(!root) return nullptr;
    bool del = to_delete.count(root->val);
    if(newRoot && !del) answer.push_back(root);
    root->right = solve(root->right, to_delete, answer, del);
    root->left = solve(root->left, to_delete, answer, del);
    return del ? nullptr : root;
  }
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    if(!root) return {};
    set<int> del_set(to_delete.begin(), to_delete.end());
    vector<TreeNode*> answer;
    solve(root, del_set, answer, true);
    return answer;
  }
};
```
