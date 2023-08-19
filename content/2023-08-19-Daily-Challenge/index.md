+++
updated = 2023-08-19T19:26:26+08:00
title = "2023-08-19 Daily Challenge"
path = "2023-08-19-Daily-Challenge"
date = 2023-08-19T19:26:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 19

## Description

**Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree**

<p>Given a weighted undirected connected graph with <code>n</code>&nbsp;vertices numbered from <code>0</code> to <code>n - 1</code>,&nbsp;and an array <code>edges</code>&nbsp;where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, weight<sub>i</sub>]</code> represents a bidirectional and weighted edge between nodes&nbsp;<code>a<sub>i</sub></code>&nbsp;and <code>b<sub>i</sub></code>. A minimum spanning tree (MST) is a subset of the graph&#39;s edges that connects all vertices without cycles&nbsp;and with the minimum possible total edge weight.</p>

<p>Find <em>all the critical and pseudo-critical edges in the given graph&#39;s minimum spanning tree (MST)</em>. An MST edge whose deletion from the graph would cause the MST weight to increase is called a&nbsp;<em>critical edge</em>. On&nbsp;the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.</p>

<p>Note that you can return the indices of the edges in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/06/04/ex1.png" style="width: 259px; height: 262px;" /></p>

<pre>
<strong>Input:</strong> n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
<strong>Output:</strong> [[0,1],[2,3,4,5]]
<strong>Explanation:</strong> The figure above describes the graph.
The following figure shows all the possible MSTs:
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/04/msts.png" style="width: 540px; height: 553px;" />
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/06/04/ex2.png" style="width: 247px; height: 253px;" /></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
<strong>Output:</strong> [[],[0,1,2,3]]
<strong>Explanation:</strong> We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(200, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub> &lt; b<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= weight<sub>i</sub>&nbsp;&lt;= 1000</code></li>
	<li>All pairs <code>(a<sub>i</sub>, b<sub>i</sub>)</code> are <strong>distinct</strong>.</li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};

class Solution {
  int findMST(
    const vector<vector<int>>& edges,
    int n,
    int ignore,
    int mustHave
  ) {
    UnionSet us(n);

    int weight = 0;
    if(mustHave != -1) {
      us.merge(edges[mustHave][0], edges[mustHave][1]);
      weight += edges[mustHave][2];
    }

    for(int i = 0; i < edges.size(); ++i) {
      if(i == ignore) continue;
      if(us.find(edges[i][0]) == us.find(edges[i][1])) continue;
      us.merge(edges[i][0], edges[i][1]);
      weight += edges[i][2];
    }

    for(int i = 0; i < n; ++i) {
      if(us.find(i) != us.find(0)) {
        weight = INT_MAX;
        continue;
      }
    }

    return weight;
  }
public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    vector<int> critical, pseudoCritical;

    for(int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[2] < b[2];
    });

    int MSTWeight = findMST(edges, n, -1, -1);

    for(int i = 0; i < edges.size(); ++i) {
      if(MSTWeight < findMST(edges, n, i, -1)) {
        critical.push_back(edges[i][3]);
      } else if(MSTWeight == findMST(edges, n, -1, i)) {
        pseudoCritical.push_back(edges[i][3]);
      }
    }

    return {critical, pseudoCritical};
  }
};

// Accepted
// 66/66 cases passed (160 ms)
// Your runtime beats 58.42 % of cpp submissions
// Your memory usage beats 86.58 % of cpp submissions (14.8 MB)
```
