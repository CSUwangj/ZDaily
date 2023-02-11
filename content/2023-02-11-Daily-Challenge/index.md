+++
updated = 2023-02-11T18:20:49+08:00
title = "2023-02-11 Daily Challenge"
path = "2023-02-11-Daily-Challenge"
date = 2023-02-11T18:20:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/shortest-path-with-alternating-colors/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 11

## Description

**Shortest Path with Alternating Colors**

<p>You are given an integer <code>n</code>, the number of nodes in a directed graph where the nodes are labeled from <code>0</code> to <code>n - 1</code>. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.</p>

<p>You are given two arrays <code>redEdges</code> and <code>blueEdges</code> where:</p>

<ul>
	<li><code>redEdges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is a directed red edge from node <code>a<sub>i</sub></code> to node <code>b<sub>i</sub></code> in the graph, and</li>
	<li><code>blueEdges[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> indicates that there is a directed blue edge from node <code>u<sub>j</sub></code> to node <code>v<sub>j</sub></code> in the graph.</li>
</ul>

<p>Return an array <code>answer</code> of length <code>n</code>, where each <code>answer[x]</code> is the length of the shortest path from node <code>0</code> to node <code>x</code> such that the edge colors alternate along the path, or <code>-1</code> if such a path does not exist.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
<strong>Output:</strong> [0,1,-1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
<strong>Output:</strong> [0,1,-1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= redEdges.length,&nbsp;blueEdges.length &lt;= 400</code></li>
	<li><code>redEdges[i].length == blueEdges[j].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>, u<sub>j</sub>, v<sub>j</sub> &lt; n</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> neighbors[2];
    neighbors[0].resize(n);
    neighbors[1].resize(n);
    for(const auto &redEdge : redEdges) {
      neighbors[0][redEdge[0]].push_back(redEdge[1]);
    }
    for(const auto &blueEdge : blueEdges) {
      neighbors[1][blueEdge[0]].push_back(blueEdge[1]);
    }
    vector<int> distance[2];
    distance[0].resize(n, INT_MAX);
    distance[1].resize(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});
    distance[0][0] = 0;
    distance[1][0] = 0;

    int current = 0;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [pos, color] = q.front();
        q.pop();
        for(auto next : neighbors[!color][pos]) {
          if(distance[!color][next] != INT_MAX) continue;
          distance[!color][next] = current + 1;
          q.push({next, !color});
        }
      }
      current += 1;
    }

    for(int i = 0; i < n; ++i) {
      distance[0][i] = min(distance[0][i], distance[1][i]);
      if(distance[0][i] == INT_MAX) {
        distance[0][i] = -1;
      }
    }

    return distance[0];
  }
};

// Accepted
// 90/90 cases passed (15 ms)
// Your runtime beats 95.27 % of cpp submissions
// Your memory usage beats 89.64 % of cpp submissions (14.7 MB)
```
