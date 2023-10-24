+++
updated = 2023-10-24T08:57:16+08:00
title = "2023-10-24 Daily Challenge"
path = "2023-10-24-Daily-Challenge"
date = 2023-10-24T08:57:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 24

## Description

**Find Largest Value in Each Tree Row**

<p>Given the <code>root</code> of a binary tree, return <em>an array of the largest value in each row</em> of the tree <strong>(0-indexed)</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 300px; height: 172px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> [1,3,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> [1,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    if(!root) return {};
    vector<int> answer;
    queue<TreeNode *> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      int maximum = INT_MIN;
      for(int _ = 0; _ < sz; ++_) {
        auto current = q.front();
        q.pop();
        maximum = max(maximum, current->val);
        if(current->left) {
          q.push(current->left);
        }
        if(current->right) {
          q.push(current->right);
        }
      }
      answer.push_back(maximum);
    }

    return answer;
  }
};

// Accepted
// 78/78 cases passed (8 ms)
// Your runtime beats 68.56 % of cpp submissions
// Your memory usage beats 50.91 % of cpp submissions (22.5 MB)
```
