+++
updated = 2023-01-13T20:49:49+08:00
title = "2023-01-13 Daily Challenge"
path = "2023-01-13-Daily-Challenge"
date = 2023-01-13T20:49:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 13

## Description

**Longest Path With Different Adjacent Characters**

<p>You are given a <strong>tree</strong> (i.e. a connected, undirected graph that has no cycles) <strong>rooted</strong> at node <code>0</code> consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>. The tree is represented by a <strong>0-indexed</strong> array <code>parent</code> of size <code>n</code>, where <code>parent[i]</code> is the parent of node <code>i</code>. Since node <code>0</code> is the root, <code>parent[0] == -1</code>.</p>

<p>You are also given a string <code>s</code> of length <code>n</code>, where <code>s[i]</code> is the character assigned to node <code>i</code>.</p>

<p>Return <em>the length of the <strong>longest path</strong> in the tree such that no pair of <strong>adjacent</strong> nodes on the path have the same character assigned to them.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/testingdrawio.png" style="width: 201px; height: 241px;" />
<pre>
<strong>Input:</strong> parent = [-1,0,0,1,1,2], s = &quot;abacbe&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -&gt; 1 -&gt; 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/graph2drawio.png" style="width: 201px; height: 221px;" />
<pre>
<strong>Input:</strong> parent = [-1,0,0,0], s = &quot;aabc&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest path where each two adjacent nodes have different characters is the path: 2 -&gt; 0 -&gt; 3. The length of this path is 3, so 3 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == parent.length == s.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= parent[i] &lt;= n - 1</code> for all <code>i &gt;= 1</code></li>
	<li><code>parent[0] == -1</code></li>
	<li><code>parent</code> represents a valid tree.</li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  vector<vector<int>> neighbors;
  int answer = 0;
  int dfs(int current, const string &s) {
    int mmax1 = 0;
    int mmax2 = 0;
    for(auto next : neighbors[current]) {
      int l = dfs(next, s);
      answer = max(answer, l);
      if(s[next] == s[current]) continue;
      if(l > mmax1) {
        mmax2 = mmax1;
        mmax1 = l;
      } else {
        mmax2 = max(mmax2, l);
      }
    }
    answer = max(answer, 1 + mmax1 + mmax2);
    return 1 + mmax1;
  }
public:
  int longestPath(vector<int>& parent, string s) {
    int len = parent.size();
    neighbors.resize(len);
    for(int i = 1; i < len; ++i) {
      neighbors[parent[i]].push_back(i);
    }
    dfs(0, s);
    return answer;
  }
};

// Accepted
// 141/141 cases passed (392 ms)
// Your runtime beats 93.15 % of cpp submissions
// Your memory usage beats 71.15 % of cpp submissions (181.1 MB)
```
