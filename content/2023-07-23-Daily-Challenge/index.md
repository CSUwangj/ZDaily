+++
updated = 2023-07-23T12:24:56+08:00
title = "2023-07-23 Daily Challenge"
path = "2023-07-23-Daily-Challenge"
date = 2023-07-23T12:24:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/all-possible-full-binary-trees/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 23

## Description

**All Possible Full Binary Trees**

<p>Given an integer <code>n</code>, return <em>a list of all possible <strong>full binary trees</strong> with</em> <code>n</code> <em>nodes</em>. Each node of each tree in the answer must have <code>Node.val == 0</code>.</p>

<p>Each element of the answer is the root node of one possible tree. You may return the final list of trees in <strong>any order</strong>.</p>

<p>A <strong>full binary tree</strong> is a binary tree where each node has exactly <code>0</code> or <code>2</code> children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png" style="width: 700px; height: 400px;" />
<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[0,0,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


## Solution

``` cpp
class Solution {
  vector<vector<TreeNode*>> FBTs;
  void generateFBTs(int N) {
    FBTs.resize(N+1);
    FBTs[1].push_back(new TreeNode(0));
    for(int i = 3; i <= N; i += 2) {
      for(int j = 1; j < i; j += 2) {
        for(auto left : FBTs[j]) {
          for(auto right: FBTs[i-j-1]) {
            FBTs[i].push_back(new TreeNode(0, deepcopy(left), deepcopy(right)));
          }
        }
      }
    }
  }
  
  TreeNode* deepcopy(TreeNode *root) {
    if(!root) return nullptr;
    return new TreeNode(0, deepcopy(root->left), deepcopy(root->right));
  }
  
public:
  vector<TreeNode*> allPossibleFBT(int N) {
    if(N % 2 == 0) return vector<TreeNode*>();
    generateFBTs(N);
    return FBTs[N];
  }
};

// Accepted
// 20/20 cases passed (131 ms)
// Your runtime beats 19.55 % of cpp submissions
// Your memory usage beats 19.62 % of cpp submissions (37.5 MB)
```
