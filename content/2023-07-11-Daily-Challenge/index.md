+++
updated = 2023-07-11T20:27:19+08:00
title = "2023-07-11 Daily Challenge"
path = "2023-07-11-Daily-Challenge"
date = 2023-07-11T20:27:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 11

## Description

**All Nodes Distance K in Binary Tree**

<p>Given the <code>root</code> of a binary tree, the value of a target node <code>target</code>, and an integer <code>k</code>, return <em>an array of the values of all nodes that have a distance </em><code>k</code><em> from the target node.</em></p>

<p>You can return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png" style="width: 500px; height: 429px;" />
<pre>
<strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
<strong>Output:</strong> [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1], target = 1, k = 3
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 500]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>All the values <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>target</code> is the value of one of the nodes in the tree.</li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
  void buildGraph(TreeNode *root, vector<vector<int>> &neighbors) {
    int val = root->val;
    if(root->left) {
      neighbors[val].push_back(root->left->val);
      neighbors[root->left->val].push_back(val);
      buildGraph(root->left, neighbors);
    }
    if(root->right) {
      neighbors[val].push_back(root->right->val);
      neighbors[root->right->val].push_back(val);
      buildGraph(root->right, neighbors);
    }
  }
  void solve(
    int current,
    int parent,
    int k,
    vector<int> &answer,
    const vector<vector<int>> &neighbors
  ) {
    if(!k) {
      answer.push_back(current);
      return;
    }
    for(auto next : neighbors[current]) {
      if(parent == next) continue;
      solve(next, current, k - 1, answer, neighbors);
    }
  }
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<vector<int>> neighbors(501);
    buildGraph(root, neighbors);
    vector<int> answer;
    solve(target->val, -1, k, answer, neighbors);
    return answer;
  }
};

// Accepted
// 57/57 cases passed (9 ms)
// Your runtime beats 38.57 % of cpp submissions
// Your memory usage beats 5.12 % of cpp submissions (16.9 MB)
```
