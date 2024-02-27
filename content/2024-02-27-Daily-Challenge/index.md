+++
updated = 2024-02-27T16:35:57+08:00
title = "2024-02-27 Daily Challenge"
path = "2024-02-27-Daily-Challenge"
date = 2024-02-27T16:35:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/diameter-of-binary-tree/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 27

## Description

**Diameter of Binary Tree**

<p>Given the <code>root</code> of a binary tree, return <em>the length of the <strong>diameter</strong> of the tree</em>.</p>

<p>The <strong>diameter</strong> of a binary tree is the <strong>length</strong> of the longest path between any two nodes in a tree. This path may or may not pass through the <code>root</code>.</p>

<p>The <strong>length</strong> of a path between two nodes is represented by the number of edges between them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the length of the path [4,2,1,3] or [5,2,1,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
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
  int answer;
  int pathLength(TreeNode * root) {
    if(!root) return 0;
    int left = pathLength(root->left);
    int right = pathLength(root->right);
    answer = max(answer, left + right);
    return 1 + max(left, right);
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    pathLength(root);
    return answer;
  }
};

// Accepted
// 105/105 cases passed (3 ms)
// Your runtime beats 95.23 % of cpp submissions
// Your memory usage beats 70.17 % of cpp submissions (19 MB)
```
