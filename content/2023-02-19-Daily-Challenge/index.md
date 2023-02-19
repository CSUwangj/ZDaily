+++
updated = 2023-02-19T12:47:15+08:00
title = "2023-02-19 Daily Challenge"
path = "2023-02-19-Daily-Challenge"
date = 2023-02-19T12:47:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 19

## Description

**Binary Tree Zigzag Level Order Traversal**

<p>Given the <code>root</code> of a binary tree, return <em>the zigzag level order traversal of its nodes&#39; values</em>. (i.e., from left to right, then right to left for the next level and alternate between).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[20,9],[15,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};
    stack<TreeNode*> stackForth;
    stack<TreeNode*> stackBack;
    stackForth.push(root);
    vector<vector<int>> answer;
    while(stackForth.size()) {
      vector<int> result;
      while(stackForth.size()) {
        auto cur = stackForth.top();
        stackForth.pop();
        result.push_back(cur->val);
        if(cur->left) stackBack.push(cur->left);
        if(cur->right) stackBack.push(cur->right);
      }
      answer.push_back(result);
      if(!stackBack.size()) break;
      result.clear();
      while(stackBack.size()) {
        auto cur = stackBack.top();
        stackBack.pop();
        result.push_back(cur->val);
        if(cur->right) stackForth.push(cur->right);
        if(cur->left) stackForth.push(cur->left);
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 33/33 cases passed (3 ms)
// Your runtime beats 73.66 % of cpp submissions
// Your memory usage beats 48.4 % of cpp submissions (12.2 MB)
```
