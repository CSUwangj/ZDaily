+++
updated = 2022-12-10T11:44:32+08:00
title = "2022-12-10 Daily Challenge"
path = "2022-12-10-Daily-Challenge"
date = 2022-12-10T11:44:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 10

## Description

**Maximum Product of Splitted Binary Tree**

<p>Given the <code>root</code> of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.</p>

<p>Return <em>the maximum product of the sums of the two subtrees</em>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p><strong>Note</strong> that you need to maximize the answer before taking the mod and not after taking it.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png" style="width: 500px; height: 167px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> 110
<strong>Explanation:</strong> Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/sample_2_1699.png" style="width: 500px; height: 211px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,3,4,null,null,5,6]
<strong>Output:</strong> 90
<strong>Explanation:</strong> Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
class Solution {
  int sum = 0;
  int cur = 0;
  void add(TreeNode *root) {
    if(!root) return;
    sum += root->val;
    add(root->left);
    add(root->right);
  }
  int solve(TreeNode *root) {
    if(!root) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    if(abs(left + right + root->val - sum / 2) < abs(cur - sum / 2)) {
      cur = left + right + root->val;
    }
    if (abs(left - sum / 2) < abs(cur - sum / 2)) {
      cur = left;
    }
    if (abs(right - sum / 2) < abs(cur - sum / 2)) {
      cur = right;
    }
    return left + right + root->val;
  }
public:
  int maxProduct(TreeNode* root) {
    add(root);
    solve(root);
    return 1LL * (sum - cur) * cur % MOD;
  }
};

// Accepted
// 54/54 cases passed (84 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 63.53 % of cpp submissions (77.5 MB)
```
