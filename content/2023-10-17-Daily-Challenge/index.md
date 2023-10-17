+++
updated = 2023-10-17T12:51:38+08:00
title = "2023-10-17 Daily Challenge"
path = "2023-10-17-Daily-Challenge"
date = 2023-10-17T12:51:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/validate-binary-tree-nodes/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 17

## Description

**Validate Binary Tree Nodes**

<p>You have <code>n</code> binary tree nodes numbered from <code>0</code> to <code>n - 1</code> where node <code>i</code> has two children <code>leftChild[i]</code> and <code>rightChild[i]</code>, return <code>true</code> if and only if <strong>all</strong> the given nodes form <strong>exactly one</strong> valid binary tree.</p>

<p>If node <code>i</code> has no left child then <code>leftChild[i]</code> will equal <code>-1</code>, similarly for the right child.</p>

<p>Note that the nodes have no values and that we only use the node numbers in this problem.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png" style="width: 195px; height: 287px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png" style="width: 183px; height: 272px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png" style="width: 82px; height: 174px;" />
<pre>
<strong>Input:</strong> n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == leftChild.length == rightChild.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
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
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<bool> root(n, true);
    for(int i = 0; i < n; ++i) {
      if(leftChild[i] != -1) root[leftChild[i]] = false;
      if(rightChild[i] != -1) root[rightChild[i]] = false;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) {
      if(root[i]) q.push(i);
    }
    if(q.size() != 1) return false;

    set<int> visit;
    while(q.size()) {
      auto current = q.front();
      q.pop();
      if(visit.count(current)) return false;
      visit.insert(current);
      if(leftChild[current] != -1) {
        q.push(leftChild[current]);
      }
      if(rightChild[current] != -1) {
        q.push(rightChild[current]);
      }
    }

    return visit.size() == n;
    
  }
};

// Accepted
// 44/44 cases passed (50 ms)
// Your runtime beats 46.81 % of cpp submissions
// Your memory usage beats 42.86 % of cpp submissions (37.5 MB)
```
