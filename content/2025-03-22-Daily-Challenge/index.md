+++
updated = 2025-03-22T19:17:47+08:00
title = "2025-03-22 Daily Challenge"
path = "2025-03-22-Daily-Challenge"
date = 2025-03-22T19:17:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-complete-components/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 22

## Description

**Count the Number of Complete Components**

<p>You are given an integer <code>n</code>. There is an <strong>undirected</strong> graph with <code>n</code> vertices, numbered from <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting vertices <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>Return <em>the number of <strong>complete connected components</strong> of the graph</em>.</p>

<p>A <strong>connected component</strong> is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.</p>

<p>A connected component is said to be <b>complete</b> if there exists an edge between every pair of its vertices.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the picture above, one can see that all of the components of this graph are complete.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    iota(parent.begin(), parent.end(), 0);
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
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    UnionSet us(n);
    for(auto &e : edges) {
      us.merge(e[0], e[1]);
    }
    map<int, int> edgeOfComponent;
    map<int, set<int>> vertexOfComponent;
    for(int i = 0; i < n; ++i) {
      vertexOfComponent[us.find(i)].insert(i);
    }
    for(auto &e : edges) {
      edgeOfComponent[us.find(e[0])] += 1;
    }
    int answer = 0;
    for(auto [root, vertices] : vertexOfComponent) {
      int verticesCount = vertices.size();
      answer += (verticesCount * (verticesCount - 1) / 2 == edgeOfComponent[root]);
    }
    return answer;
  }
};

// Accepted
// 3355/3355 cases passed (65 ms)
// Your runtime beats 41.32 % of cpp submissions
// Your memory usage beats 67.11 % of cpp submissions (129.4 MB)
```
