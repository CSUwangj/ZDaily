+++
updated = 2024-04-23T20:29:17+08:00
title = "2024-04-23 Daily Challenge"
path = "2024-04-23-Daily-Challenge"
date = 2024-04-23T20:29:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/minimum-height-trees/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 23

## Description

**Minimum Height Trees**

<p>A tree is an undirected graph in which any two vertices are connected by&nbsp;<i>exactly</i>&nbsp;one path. In other words, any connected graph without simple cycles is a tree.</p>

<p>Given a tree of <code>n</code> nodes&nbsp;labelled from <code>0</code> to <code>n - 1</code>, and an array of&nbsp;<code>n - 1</code>&nbsp;<code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an undirected edge between the two nodes&nbsp;<code>a<sub>i</sub></code> and&nbsp;<code>b<sub>i</sub></code> in the tree,&nbsp;you can choose any node of the tree as the root. When you select a node <code>x</code> as the root, the result tree has height <code>h</code>. Among all possible rooted trees, those with minimum height (i.e. <code>min(h)</code>)&nbsp; are called <strong>minimum height trees</strong> (MHTs).</p>

<p>Return <em>a list of all <strong>MHTs&#39;</strong> root labels</em>.&nbsp;You can return the answer in <strong>any order</strong>.</p>

<p>The <strong>height</strong> of a rooted tree is the number of edges on the longest downward path between the root and a leaf.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/e1.jpg" style="width: 800px; height: 213px;" />
<pre>
<strong>Input:</strong> n = 4, edges = [[1,0],[1,2],[1,3]]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/e2.jpg" style="width: 800px; height: 321px;" />
<pre>
<strong>Input:</strong> n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
<strong>Output:</strong> [3,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>All the pairs <code>(a<sub>i</sub>, b<sub>i</sub>)</code> are distinct.</li>
	<li>The given input is <strong>guaranteed</strong> to be a tree and there will be <strong>no repeated</strong> edges.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int par[20000];
class Solution {
  vector<vector<int>> neighbors;
  void init(int n, vector<vector<int>> &edges) {
    neighbors.resize(n);
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }

  pair<int, int> bfs() {
    queue<pair<int, int>> q;
    q.push({-1, 0});
    int oneEnd;
    while(q.size()) {
      auto [parent, cur] = q.front();
      q.pop();
      // cout << parent << ' ' << cur << endl;
      oneEnd = cur;
      for(auto next : neighbors[cur]) {
        if(next == parent) continue;
        q.push({cur, next});
      }
    }
    int len = 0;
    q.push({-1, oneEnd});
    while(q.size()) {
      len += 1;
      int curSize = q.size();
      for(int _ = 0; _ < curSize; ++_) {
        auto [parent, cur] = q.front();
        q.pop();
        par[cur] = parent;
        oneEnd = cur;
        for(auto next : neighbors[cur]) {
          if(next == parent) continue;
          q.push({cur, next});
        }
      }
    }
    return {len, oneEnd};
  }
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    init(n, edges);
    auto [len, end] = bfs();
    int target = (len - 1) / 2;
    for(int i = 0; i < target; ++i) {
      end = par[end];
    }
    if (len & 1) return {end};
    return {end, par[end]};
  }
};

// Accepted
// 68/68 cases passed (61 ms)
// Your runtime beats 83.2 % of cpp submissions
// Your memory usage beats 69.44 % of cpp submissions (27.5 MB)
```
