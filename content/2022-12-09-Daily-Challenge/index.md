+++
updated = 2022-12-09T12:06:41+08:00
title = "2022-12-09 Daily Challenge"
path = "2022-12-09-Daily-Challenge"
date = 2022-12-09T12:06:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 9

## Description

**Maximum Difference Between Node and Ancestor**

<p>Given the <code>root</code> of a binary tree, find the maximum value <code>v</code> for which there exist <strong>different</strong> nodes <code>a</code> and <code>b</code> where <code>v = |a.val - b.val|</code> and <code>a</code> is an ancestor of <code>b</code>.</p>

<p>A node <code>a</code> is an ancestor of <code>b</code> if either: any child of <code>a</code> is equal to <code>b</code>&nbsp;or any child of <code>a</code> is an ancestor of <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg" style="width: 400px; height: 390px;" />
<pre>
<strong>Input:</strong> root = [8,3,10,1,6,null,14,null,null,4,7,13]
<strong>Output:</strong> 7
<strong>Explanation: </strong>We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg" style="width: 250px; height: 349px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,null,0,3]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 5000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
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
public:
  int maxAncestorDiff(TreeNode* root, int mmin = INT_MAX, int mmax = INT_MIN) {
    // root node will not be nullptr by constraints
    if(!root) return mmax - mmin;
    mmin = min(mmin, root->val);
    mmax = max(mmax, root->val);
    return max(maxAncestorDiff(root->left, mmin, mmax), maxAncestorDiff(root->right, mmin, mmax));
  }
};

// Accepted
// 28/28 cases passed (3 ms)
// Your runtime beats 97.1 % of cpp submissions
// Your memory usage beats 97.32 % of cpp submissions (9.7 MB)
```
