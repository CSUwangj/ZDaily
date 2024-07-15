+++
updated = 2024-07-15T15:05:58+08:00
title = "2024-07-15 Daily Challenge"
path = "2024-07-15-Daily-Challenge"
date = 2024-07-15T15:05:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/create-binary-tree-from-descriptions/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 15

## Description

**Create Binary Tree From Descriptions**

<p>You are given a 2D integer array <code>descriptions</code> where <code>descriptions[i] = [parent<sub>i</sub>, child<sub>i</sub>, isLeft<sub>i</sub>]</code> indicates that <code>parent<sub>i</sub></code> is the <strong>parent</strong> of <code>child<sub>i</sub></code> in a <strong>binary</strong> tree of <strong>unique</strong> values. Furthermore,</p>

<ul>
	<li>If <code>isLeft<sub>i</sub> == 1</code>, then <code>child<sub>i</sub></code> is the left child of <code>parent<sub>i</sub></code>.</li>
	<li>If <code>isLeft<sub>i</sub> == 0</code>, then <code>child<sub>i</sub></code> is the right child of <code>parent<sub>i</sub></code>.</li>
</ul>

<p>Construct the binary tree described by <code>descriptions</code> and return <em>its <strong>root</strong></em>.</p>

<p>The test cases will be generated such that the binary tree is <strong>valid</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/09/example1drawio.png" style="width: 300px; height: 236px;" />
<pre>
<strong>Input:</strong> descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
<strong>Output:</strong> [50,20,80,15,17,19]
<strong>Explanation:</strong> The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/09/example2drawio.png" style="width: 131px; height: 300px;" />
<pre>
<strong>Input:</strong> descriptions = [[1,2,1],[2,3,0],[3,4,1]]
<strong>Output:</strong> [1,2,null,null,3,4]
<strong>Explanation:</strong> The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= descriptions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>descriptions[i].length == 3</code></li>
	<li><code>1 &lt;= parent<sub>i</sub>, child<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= isLeft<sub>i</sub> &lt;= 1</code></li>
	<li>The binary tree described by <code>descriptions</code> is valid.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    map<int, pair<int, int>> child;
    map<int, bool> notRoot;
    for(const auto &description : descriptions) {
      if(description[2]) {
        child[description[0]].first = description[1];
      } else {
        child[description[0]].second = description[1];
      }
      notRoot[description[1]] = true;
    }
    queue<TreeNode *> q;
    int rootN;
    for(const auto &description : descriptions) {
      if(!notRoot[description[0]]) rootN = description[0];
    }
    TreeNode *root = new TreeNode(rootN);
    q.push(root);
    while(q.size()) {
      auto current = q.front();
      q.pop();
      if(child[current->val].first) {
        current->left = new TreeNode(child[current->val].first);
        q.push(current->left);
      }
      if(child[current->val].second) {
        current->right = new TreeNode(child[current->val].second);
        q.push(current->right);
      }
    }
    return root;
  }
};
```
