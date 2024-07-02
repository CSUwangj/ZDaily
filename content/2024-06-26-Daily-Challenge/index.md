+++
updated = 2024-06-26T12:17:33+08:00
title = "2024-06-26 Daily Challenge"
path = "2024-06-26-Daily-Challenge"
date = 2024-06-26T12:17:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/balance-a-binary-search-tree/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 26

## Description

**Balance a Binary Search Tree**

<p>Given the <code>root</code> of a binary search tree, return <em>a <strong>balanced</strong> binary search tree with the same node values</em>. If there is more than one answer, return <strong>any of them</strong>.</p>

<p>A binary search tree is <strong>balanced</strong> if the depth of the two subtrees of every node never differs by more than <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg" style="width: 500px; height: 319px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,null,3,null,4,null,null]
<strong>Output:</strong> [2,1,3,null,null,null,4]
<b>Explanation:</b> This is not the only correct answer, [3,1,4,null,2] is also correct.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg" style="width: 224px; height: 145px;" />
<pre>
<strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,1,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  void visit(vector<int> &nums, TreeNode *root) {
    if(!root) return;
    visit(nums, root->left);
    nums.push_back(root->val);
    visit(nums, root->right);
  }
  TreeNode* build(const vector<int> &nums, int begin, int end) {
    if(begin > end) return nullptr;
    int mid = (begin + end) / 2;
    return new TreeNode(nums[mid], build(nums, begin, mid - 1), build(nums, mid + 1, end));
  }
public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    visit(nums, root);
    return build(nums, 0, nums.size() - 1);
  }
};
```
