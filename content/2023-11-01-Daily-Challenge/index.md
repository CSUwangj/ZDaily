+++
updated = 2023-11-01T11:58:54+08:00
title = "2023-11-01 Daily Challenge"
path = "2023-11-01-Daily-Challenge"
date = 2023-11-01T11:58:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/find-mode-in-binary-search-tree/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 1

## Description

**Find Mode in Binary Search Tree**

<p>Given the <code>root</code> of a binary search tree (BST) with duplicates, return <em>all the <a href="https://en.wikipedia.org/wiki/Mode_(statistics)" target="_blank">mode(s)</a> (i.e., the most frequently occurred element) in it</em>.</p>

<p>If the tree has more than one mode, return them in <strong>any order</strong>.</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than or equal to</strong> the node&#39;s key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than or equal to</strong> the node&#39;s key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg" style="width: 142px; height: 222px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

## Solution

``` cpp
class Solution {
  void solve(map<int, int> &mp, TreeNode *current) {
    if(!current) return;
    mp[current->val] += 1;
    solve(mp, current->left);
    solve(mp, current->right);
  }
public:
  vector<int> findMode(TreeNode* root) {
    map<int, int> mp;
    solve(mp, root);
    int occurs = 0;
    for(const auto &[k, v]: mp) {
      occurs = max(occurs, v);
    }
    vector<int> answer;
    for(const auto &[k, v]: mp) {
      if(v == occurs) answer.push_back(k);
    }

    return answer;
  }
};

// Accepted
// 23/23 cases passed (21 ms)
// Your runtime beats 28.08 % of cpp submissions
// Your memory usage beats 19.38 % of cpp submissions (25.9 MB)
```
