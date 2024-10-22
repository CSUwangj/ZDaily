+++
updated = 2024-10-22T08:56:11+08:00
title = "2024-10-22 Daily Challenge"
path = "2024-10-22-Daily-Challenge"
date = 2024-10-22T08:56:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 22

## Description

**Kth Largest Sum in a Binary Tree**

<p>You are given the <code>root</code> of a binary tree and a positive integer <code>k</code>.</p>

<p>The <strong>level sum</strong> in the tree is the sum of the values of the nodes that are on the <strong>same</strong> level.</p>

<p>Return<em> the </em><code>k<sup>th</sup></code><em> <strong>largest</strong> level sum in the tree (not necessarily distinct)</em>. If there are fewer than <code>k</code> levels in the tree, return <code>-1</code>.</p>

<p><strong>Note</strong> that two nodes are on the same level if they have the same distance from the root.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" />
<pre>
<strong>Input:</strong> root = [5,8,9,2,1,3,7,4,6], k = 2
<strong>Output:</strong> 13
<strong>Explanation:</strong> The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2<sup>nd</sup> largest level sum is 13.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png" style="width: 181px; height: 181px;" />
<pre>
<strong>Input:</strong> root = [1,2,null,3], k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest level sum is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


## Solution

``` cpp
class Solution {
  map<int, long long> sum;
  void getSum(TreeNode *root, int level) {
    if(!root) return;
    sum[level] += root->val;
    getSum(root->left, level + 1);
    getSum(root->right, level + 1);
  }
public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    getSum(root, 0);
    vector<long long> sums(sum.size());
    for(int i = 0; i < sum.size(); ++i) {
      sums[i] = sum[i];
    }
    sort(sums.begin(), sums.end(), greater<long long>());;
    return k > sums.size() ? -1 : sums[k - 1];
  }
};
```
