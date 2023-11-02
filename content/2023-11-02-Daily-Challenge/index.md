+++
updated = 2023-11-02T19:51:23+08:00
title = "2023-11-02 Daily Challenge"
path = "2023-11-02-Daily-Challenge"
date = 2023-11-02T19:51:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 2

## Description

**Count Nodes Equal to Average of Subtree**

<p>Given the <code>root</code> of a binary tree, return <em>the number of nodes where the value of the node is equal to the <strong>average</strong> of the values in its <strong>subtree</strong></em>.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The <strong>average</strong> of <code>n</code> elements is the <strong>sum</strong> of the <code>n</code> elements divided by <code>n</code> and <strong>rounded down</strong> to the nearest integer.</li>
	<li>A <strong>subtree</strong> of <code>root</code> is a tree consisting of <code>root</code> and all of its descendants.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/03/15/image-20220315203925-1.png" style="width: 300px; height: 212px;" />
<pre>
<strong>Input:</strong> root = [4,8,5,0,1,null,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/03/26/image-20220326133920-1.png" style="width: 80px; height: 76px;" />
<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> For the node with value 1: The average of its subtree is 1 / 1 = 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int answer = 0;
  pair<int, int> solve(TreeNode *root) {
    if(!root) return {0, 0};
    auto [leftCount, leftSum] = solve(root->left);
    auto [rightCount, rightSum] = solve(root->right);
    int sum = root->val + leftSum + rightSum;
    int count = 1 + leftCount + rightCount;
    if(sum / count == root->val) {
      answer += 1;
    }
    return {count, sum};
  }
public:
  int averageOfSubtree(TreeNode* root) {
    solve(root);
    return answer;
  }
};

// Accepted
// 138/138 cases passed (4 ms)
// Your runtime beats 80.67 % of cpp submissions
// Your memory usage beats 34.12 % of cpp submissions (12.3 MB)
```
