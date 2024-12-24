+++
updated = 2024-12-24T10:36:27+08:00
title = "2024-12-24 Daily Challenge"
path = "2024-12-24-Daily-Challenge"
date = 2024-12-24T10:36:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 24

## Description

**Find Minimum Diameter After Merging Two Trees**

<p>There exist two <strong>undirected </strong>trees with <code>n</code> and <code>m</code> nodes, numbered from <code>0</code> to <code>n - 1</code> and from <code>0</code> to <code>m - 1</code>, respectively. You are given two 2D integer arrays <code>edges1</code> and <code>edges2</code> of lengths <code>n - 1</code> and <code>m - 1</code>, respectively, where <code>edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the first tree and <code>edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that there is an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> in the second tree.</p>

<p>You must connect one node from the first tree with another node from the second tree with an edge.</p>

<p>Return the <strong>minimum </strong>possible <strong>diameter </strong>of the resulting tree.</p>

<p>The <strong>diameter</strong> of a tree is the length of the <em>longest</em> path between any two nodes in the tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong><img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example11-transformed.png" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.</p>
</div>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example211.png" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>edges1.length == n - 1</code></li>
	<li><code>edges2.length == m - 1</code></li>
	<li><code>edges1[i].length == edges2[i].length == 2</code></li>
	<li><code>edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; m</code></li>
	<li>The input is generated such that <code>edges1</code> and <code>edges2</code> represent valid trees.</li>
</ul>


## Solution

``` cpp
class Solution {
  void dfs(
    int current,
    int parent,
    int &furthest,
    vector<int> &distance,
    const vector<vector<int>> &neighbors
  ) {
    for(auto next : neighbors[current]) {
      if(next == parent) continue;
      distance[next] = distance[current] + 1;
      if(distance[next] > distance[furthest]) furthest = next;
      dfs(next, current, furthest, distance, neighbors);
    } 
  }
  int diameter(vector<vector<int>> & edges) {
    int n = edges.size() + 1;
    vector<vector<int>> neighbors(n);
    for(auto &e : edges) {
      neighbors[e[0]].push_back(e[1]);
      neighbors[e[1]].push_back(e[0]);
    }
    vector<int> distance(n, 0);
    int start = 0;
    dfs(0, -1, start, distance, neighbors);
    int end = start;
    distance[start] = 0;
    dfs(start, -1, end, distance, neighbors);

    return distance[end];
  }
public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int d1 = diameter(edges1);
    int d2 = diameter(edges2);
    return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
  }
};

// Accepted
// 723/723 cases passed (303 ms)
// Your runtime beats 55.76 % of cpp submissions
// Your memory usage beats 53.58 % of cpp submissions (305.5 MB)
```
