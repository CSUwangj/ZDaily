+++
updated = 2023-06-15T08:17:11+08:00
title = "2023-06-15 Daily Challenge"
path = "2023-06-15-Daily-Challenge"
date = 2023-06-15T08:17:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 15

## Description

**Maximum Level Sum of a Binary Tree**

<p>Given the <code>root</code> of a binary tree, the level of its root is <code>1</code>, the level of its children is <code>2</code>, and so on.</p>

<p>Return the <strong>smallest</strong> level <code>x</code> such that the sum of all the values of nodes at level <code>x</code> is <strong>maximal</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/capture.JPG" style="width: 200px; height: 175px;" />
<pre>
<strong>Input:</strong> root = [1,7,0,7,-8,null,null]
<strong>Output:</strong> 2
<strong>Explanation: </strong>
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [989,null,10250,98693,-89388,null,null,null,-32127]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
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
  int maxLevelSum(TreeNode* root) {
    int answer;
    int sum = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(q.size()) {
      int sz = q.size();
      int currentSum = 0;
      level += 1;
      for(int _ = 0; _ < sz; ++_) {
        auto current = q.front();
        q.pop();
        currentSum += current->val;
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
      }
      if(currentSum > sum) {
        sum = currentSum;
        answer = level;
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (184 ms)
// Your runtime beats 95.85 % of cpp submissions
// Your memory usage beats 13.54 % of cpp submissions (107.5 MB)
```
