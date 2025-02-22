+++
updated = 2025-02-22T21:00:47+08:00
title = "2025-02-22 Daily Challenge"
path = "2025-02-22-Daily-Challenge"
date = 2025-02-22T21:00:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 22

## Description

**Recover a Tree From Preorder Traversal**

<p>We run a&nbsp;preorder&nbsp;depth-first search (DFS) on the <code>root</code> of a binary tree.</p>

<p>At each node in this traversal, we output <code>D</code> dashes (where <code>D</code> is the depth of this node), then we output the value of this node.&nbsp; If the depth of a node is <code>D</code>, the depth of its immediate child is <code>D + 1</code>.&nbsp; The depth of the <code>root</code> node is <code>0</code>.</p>

<p>If a node has only one child, that child is guaranteed to be <strong>the left child</strong>.</p>

<p>Given the output <code>traversal</code> of this traversal, recover the tree and return <em>its</em> <code>root</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex1.png" style="width: 423px; height: 200px;" />
<pre>
<strong>Input:</strong> traversal = &quot;1-2--3--4-5--6--7&quot;
<strong>Output:</strong> [1,2,5,3,4,6,7]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex2.png" style="width: 432px; height: 250px;" />
<pre>
<strong>Input:</strong> traversal = &quot;1-2--3---4-5--6---7&quot;
<strong>Output:</strong> [1,2,5,3,null,6,null,4,null,7]
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex3.png" style="width: 305px; height: 250px;" />
<pre>
<strong>Input:</strong> traversal = &quot;1-401--349---90--88&quot;
<strong>Output:</strong> [1,401,null,349,88,90]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the original tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  int dashCount = 0;
  int getNumber(const string &pattern, int &pos) {
    int result = 0;
    while(pos < pattern.length() && isdigit(pattern[pos])) {
      result *= 10;
      result += pattern[pos] - '0';
      pos += 1;
    }
    return result;
  }
  void getDashCount(const string &pattern, int &pos) {
    dashCount = 0;
    while(pos < pattern.length() && pattern[pos] == '-') {
      dashCount += 1;
      pos += 1;
    }
  }
  TreeNode *solve(const string &pattern, int &pos, int level) {
    if(!dashCount) getDashCount(pattern, pos);
    if(dashCount != level) return nullptr;
    dashCount = 0;
    TreeNode *root = new TreeNode(getNumber(pattern, pos));
    root->left = solve(pattern, pos, level + 1);
    root->right = solve(pattern, pos, level + 1);
    return root;
  }
public:
  TreeNode* recoverFromPreorder(string traversal) {
    TreeNode *root = new TreeNode();
    int pos = 0;
    root->val = getNumber(traversal, pos);
    root->left = solve(traversal, pos, 1);
    root->right = solve(traversal, pos, 1);
    return root;
  }
};

// Accepted
// 105/105 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.58 % of cpp submissions (21.7 MB)
```
