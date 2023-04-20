+++
updated = 2023-04-20T12:15:33+08:00
title = "2023-04-20 Daily Challenge"
path = "2023-04-20-Daily-Challenge"
date = 2023-04-20T12:15:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/maximum-width-of-binary-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 20

## Description

**Maximum Width of Binary Tree**

<p>Given the <code>root</code> of a binary tree, return <em>the <strong>maximum width</strong> of the given tree</em>.</p>

<p>The <strong>maximum width</strong> of a tree is the maximum <strong>width</strong> among all levels.</p>

<p>The <strong>width</strong> of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.</p>

<p>It is <strong>guaranteed</strong> that the answer will in the range of a <strong>32-bit</strong> signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg" style="width: 359px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum width exists in the third level with length 4 (5,3,null,9).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg" style="width: 442px; height: 422px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,null,null,9,6,null,7]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg" style="width: 289px; height: 299px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum width exists in the second level with length 2 (3,2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
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
public:
  int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    long long answer = 0;
    queue<pair<long long, TreeNode*>> q;
    q.push({0, root});
    while(q.size()) {
      int sz = q.size();
      long long mmin = INT_MAX;
      long long mmax = INT_MIN;
      for(int _ = 0; _ < sz; ++_) {
        auto [index, cur] = q.front();
        mmin = min(index, mmin);
        mmax = max(index, mmax);
        q.pop();
        if(cur->left) q.push({index * 2 - mmin, cur->left});
        if(cur->right) q.push({index * 2 + 1 - mmin, cur->right});
      }
      answer = max(answer, mmax - mmin + 1);
    }
    return answer;
  }
};

// Accepted
// 114/114 cases passed (7 ms)
// Your runtime beats 84.83 % of cpp submissions
// Your memory usage beats 63.85 % of cpp submissions (17.4 MB)
```
