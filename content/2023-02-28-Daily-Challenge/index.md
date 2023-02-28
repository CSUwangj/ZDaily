+++
updated = 2023-02-28T17:17:08+08:00
title = "2023-02-28 Daily Challenge"
path = "2023-02-28-Daily-Challenge"
date = 2023-02-28T17:17:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/find-duplicate-subtrees/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 28

## Description

**Find Duplicate Subtrees**

<p>Given the <code>root</code>&nbsp;of a binary tree, return all <strong>duplicate subtrees</strong>.</p>

<p>For each kind of duplicate subtrees, you only need to return the root node of any <b>one</b> of them.</p>

<p>Two trees are <strong>duplicate</strong> if they have the <strong>same structure</strong> with the <strong>same node values</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e1.jpg" style="width: 450px; height: 354px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,null,2,4,null,null,4]
<strong>Output:</strong> [[2,4],[4]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e2.jpg" style="width: 321px; height: 201px;" />
<pre>
<strong>Input:</strong> root = [2,1,1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e33.jpg" style="width: 450px; height: 303px;" />
<pre>
<strong>Input:</strong> root = [2,2,2,3,null,3,null]
<strong>Output:</strong> [[2,3],[3]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the tree will be in the range <code>[1, 5000]</code></li>
	<li><code>-200 &lt;= Node.val &lt;= 200</code></li>
</ul>


## Solution

``` cpp
class Solution {
  unordered_map<string, vector<TreeNode*>> sameExpr;
  string visit(TreeNode *root) {
    if(!root) return "#";
    
    string result = to_string(root->val) + "," + visit(root->left) + "," + visit(root->right);
    sameExpr[result].push_back(root);
    return result;
  }
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    string tmp;
    visit(root);

    vector<TreeNode*> answer;
    for(const auto &[ _expr, roots] : sameExpr) {
      if(roots.size() > 1) answer.push_back(roots.front());
    }
    return answer;
  }
};

// Accepted
// 175/175 cases passed (27 ms)
// Your runtime beats 79.61 % of cpp submissions
// Your memory usage beats 38.15 % of cpp submissions (43.7 MB)
```
