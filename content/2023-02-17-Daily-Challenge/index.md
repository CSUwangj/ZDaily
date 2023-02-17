+++
updated = 2023-02-17T13:46:10+08:00
title = "2023-02-17 Daily Challenge"
path = "2023-02-17-Daily-Challenge"
date = 2023-02-17T13:46:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/minimum-distance-between-bst-nodes/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 17

## Description

**Minimum Distance Between BST Nodes**

<p>Given the <code>root</code> of a Binary Search Tree (BST), return <em>the minimum difference between the values of any two different nodes in the tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>Input:</strong> root = [4,2,6,1,3]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg" style="width: 282px; height: 301px;" />
<pre>
<strong>Input:</strong> root = [1,0,48,null,null,12,49]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 530: <a href="https://leetcode.com/problems/minimum-absolute-difference-in-bst/" target="_blank">https://leetcode.com/problems/minimum-absolute-difference-in-bst/</a></p>


## Solution

``` cpp
class Solution {
  int answer = INT_MAX;
  void solve(TreeNode* root, set<int> &st) {
    if(!root) return;
    // cout << root->val << ' ' << answer << ' ';
    if(st.size()) {
      auto lessIt = st.upper_bound(root->val);
      if(lessIt != st.begin()) {
        --lessIt;
        // cout << "less " << *lessIt << ' ';
        answer = min(answer, root->val - *lessIt);
      }
      auto moreOrEqualIt = st.lower_bound(root->val);
      if(moreOrEqualIt != st.end()) {
        // cout << "more " << *moreOrEqualIt;
        answer = min(answer, *moreOrEqualIt - root->val);
      }
    }
    // cout << endl;
    st.insert(root->val);
    solve(root->left, st);
    solve(root->right, st);
  }
public:
  int minDiffInBST(TreeNode* root) {
    set<int> st;
    solve(root, st);
    return answer;
  }
};

// Accepted
// 48/48 cases passed (3 ms)
// Your runtime beats 67.12 % of cpp submissions
// Your memory usage beats 6.62 % of cpp submissions (11.6 MB)
```
