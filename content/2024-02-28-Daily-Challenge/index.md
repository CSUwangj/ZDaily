+++
updated = 2024-02-28T21:53:04+08:00
title = "2024-02-28 Daily Challenge"
path = "2024-02-28-Daily-Challenge"
date = 2024-02-28T21:53:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/find-bottom-left-tree-value/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 28

## Description

**Find Bottom Left Tree Value**

<p>Given the <code>root</code> of a binary tree, return the leftmost value in the last row of the tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg" style="width: 302px; height: 182px;" />
<pre>
<strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg" style="width: 432px; height: 421px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,null,5,6,null,null,7]
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
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
  pair<int, int> solve(TreeNode *root, int level) {
    if(!root) return {-1, -1};
    auto [llevel, lvalue] = solve(root->left, level + 1);
    auto [rlevel, rvalue] = solve(root->right, level + 1);
    if(llevel == -1 && rlevel == -1) return {level, root->val};
    if(llevel >= rlevel) return {llevel, lvalue};
    return {rlevel, rvalue};
  }
public:
  int findBottomLeftValue(TreeNode* root) {
    return solve(root, 0).second;
  }
};

// Accepted
// 77/77 cases passed (11 ms)
// Your runtime beats 42.78 % of cpp submissions
// Your memory usage beats 96.27 % of cpp submissions (20 MB)
```
