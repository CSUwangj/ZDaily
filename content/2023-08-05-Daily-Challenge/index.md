+++
updated = 2023-08-05T17:04:33+08:00
title = "2023-08-05 Daily Challenge"
path = "2023-08-05-Daily-Challenge"
date = 2023-08-05T17:04:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/unique-binary-search-trees-ii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 5

## Description

**Unique Binary Search Trees II**

<p>Given an integer <code>n</code>, return <em>all the structurally unique <strong>BST&#39;</strong>s (binary search trees), which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>. Return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
TreeNode *copy(TreeNode *root) {
  if(!root) return nullptr;
  return new TreeNode(root->val, copy(root->left), copy(root->right));
}
class Solution {
  vector<TreeNode*> solve(int mask) {
    if(!mask) return {nullptr};
    vector<TreeNode*> answer;
    for(int i = 0; i < 8; ++i) {
      if(!(mask & (1 << i))) continue;
      auto left = solve(mask & ((1 << i) - 1));
      auto right = solve(mask & (((1 << 8) - 1) ^ ((1 << (i + 1)) - 1)));
      for(auto l : left) {
        for(auto r : right) {
          answer.push_back(new TreeNode(i + 1, copy(l), copy(r)));
        }
      }
    }
    return answer;
  }
public:
  vector<TreeNode*> generateTrees(int n) {
    return solve((1 << n) - 1);
  }
};

// Accepted
// 8/8 cases passed (20 ms)
// Your runtime beats 51.27 % of cpp submissions
// Your memory usage beats 6.95 % of cpp submissions (19.7 MB)
```
