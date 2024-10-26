+++
updated = 2024-10-26T09:16:42+08:00
title = "2024-10-26 Daily Challenge"
path = "2024-10-26-Daily-Challenge"
date = 2024-10-26T09:16:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 26

## Description

**Height of Binary Tree After Subtree Removal Queries**

<p>You are given the <code>root</code> of a <strong>binary tree</strong> with <code>n</code> nodes. Each node is assigned a unique value from <code>1</code> to <code>n</code>. You are also given an array <code>queries</code> of size <code>m</code>.</p>

<p>You have to perform <code>m</code> <strong>independent</strong> queries on the tree where in the <code>i<sup>th</sup></code> query you do the following:</p>

<ul>
	<li><strong>Remove</strong> the subtree rooted at the node with the value <code>queries[i]</code> from the tree. It is <strong>guaranteed</strong> that <code>queries[i]</code> will <strong>not</strong> be equal to the value of the root.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> of size </em><code>m</code><em> where </em><code>answer[i]</code><em> is the height of the tree after performing the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p><strong>Note</strong>:</p>

<ul>
	<li>The queries are independent, so the tree returns to its <strong>initial</strong> state after each query.</li>
	<li>The height of a tree is the <strong>number of edges in the longest simple path</strong> from the root to some node in the tree.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/07/binaryytreeedrawio-1.png" style="width: 495px; height: 281px;" />
<pre>
<strong>Input:</strong> root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -&gt; 3 -&gt; 2).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/07/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" />
<pre>
<strong>Input:</strong> root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
<strong>Output:</strong> [3,2,3,2]
<strong>Explanation:</strong> We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -&gt; 8 -&gt; 2 -&gt; 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -&gt; 8 -&gt; 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -&gt; 8 -&gt; 2 -&gt; 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -&gt; 9 -&gt; 3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>All the values in the tree are <strong>unique</strong>.</li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= m &lt;= min(n, 10<sup>4</sup>)</code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
	<li><code>queries[i] != root.val</code></li>
</ul>


## Solution

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> maxHeightSubTree;
  map<int, int> level;
  int generateInfo(TreeNode *root, int lv = 0) {
    if(!root) return -1;
    level[root->val] = lv;
    while(maxHeightSubTree.size() <= lv) {
      maxHeightSubTree.push_back({});
    }
    int leftLevel = generateInfo(root->left, lv + 1);
    int rightLevel = generateInfo(root->right, lv + 1);
    int maxLevel = max({lv, leftLevel, rightLevel});
    maxHeightSubTree[lv].push_back({maxLevel, root->val});
    // cout << root->val << ' ' << maxLevel << endl;
    return maxLevel;
  }
  void sortLevels() {
    for(auto &maxHeights : maxHeightSubTree) {
      sort(maxHeights.begin(), maxHeights.end(), greater<pi>());
    }
  }
public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    generateInfo(root);
    sortLevels();
    vector<int> answer;
    answer.reserve(queries.size());
    for(auto query : queries) {
      int lv = level[query];
      if(maxHeightSubTree[lv].size() == 1) {
        answer.push_back(lv - 1);
      } else if(maxHeightSubTree[lv][0].second == query) {
        answer.push_back(maxHeightSubTree[lv][1].first);
      } else {
        answer.push_back(maxHeightSubTree[lv][0].first);
      }
    }
    return answer;
  }
};
```
