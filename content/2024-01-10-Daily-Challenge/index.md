+++
updated = 2024-01-10T12:19:23+08:00
title = "2024-01-10 Daily Challenge"
path = "2024-01-10-Daily-Challenge"
date = 2024-01-10T12:19:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 10

## Description

**Amount of Time for Binary Tree to Be Infected**

<p>You are given the <code>root</code> of a binary tree with <strong>unique</strong> values, and an integer <code>start</code>. At minute <code>0</code>, an <strong>infection</strong> starts from the node with value <code>start</code>.</p>

<p>Each minute, a node becomes infected if:</p>

<ul>
	<li>The node is currently uninfected.</li>
	<li>The node is adjacent to an infected node.</li>
</ul>

<p>Return <em>the number of minutes needed for the entire tree to be infected.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png" style="width: 400px; height: 306px;" />
<pre>
<strong>Input:</strong> root = [1,5,3,null,4,10,6,9,2], start = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png" style="width: 75px; height: 66px;" />
<pre>
<strong>Input:</strong> root = [1], start = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> At minute 0, the only node in the tree is infected so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>Each node has a <strong>unique</strong> value.</li>
	<li>A node with a value of <code>start</code> exists in the tree.</li>
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
  void add(TreeNode *root, map<int, vector<int>> &edges) {
    if(root->left) {
      edges[root->val].push_back(root->left->val);
      edges[root->left->val].push_back(root->val);
      add(root->left, edges);
    }
    if(root->right) {
      edges[root->val].push_back(root->right->val);
      edges[root->right->val].push_back(root->val);
      add(root->right, edges);
    }
  }
public:
  int amountOfTime(TreeNode* root, int start) {
    map<int, vector<int>> edges;
    add(root, edges);

    int time = -1;
    queue<pair<int, int>> q;
    q.push({-1, start});
    while(q.size()) {
      int sz = q.size();
      for(auto _ = 0; _ < sz; ++_) {
        auto [parent, current] = q.front();
        q.pop();
        for(auto next : edges[current]) {
          if(next == parent) continue;
          q.push({current, next});
        }
      }
      time += 1;
    }
    return time;
  }
};

// Accepted
// 80/80 cases passed (569 ms)
// Your runtime beats 21.97 % of cpp submissions
// Your memory usage beats 36.64 % of cpp submissions (165 MB)
```
