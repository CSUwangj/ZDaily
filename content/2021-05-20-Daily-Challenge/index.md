+++
title = "2021-05-20 Daily-Challenge"
path = "2021-05-20-Daily-Challenge"
date = 2021-05-20 18:03:10+08:00
updated = 2021-05-20 18:41:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 20

## Description

**Binary Tree Level Order Traversal**

<p>Given the <code>root</code> of a binary tree, return <em>the level order traversal of its nodes&#39; values</em>. (i.e., from left to right, level by level).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre><code><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]</code></pre>

<p><strong>Example 3:</strong></p>

<pre><code><strong>Input:</strong> root = []
<strong>Output:</strong> []
</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> curLevel;
      for(int i = 0; i < sz; ++i) {
        auto node = q.front();
        q.pop();
        curLevel.push_back(node->val);
        if(node->left) {
          q.push(node->left);
        }
        if(node->right) {
          q.push(node->right);
        }
      }
      answer.push_back(curLevel);
    }
    return answer;
  }
};
```
