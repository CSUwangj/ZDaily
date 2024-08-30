+++
updated = 2024-08-30T15:43:59+08:00
title = "2024-08-30 Daily Challenge"
path = "2024-08-30-Daily-Challenge"
date = 2024-08-30T15:43:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/modify-graph-edge-weights/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 30

## Description

**Modify Graph Edge Weights**

<p>You are given an <strong>undirected weighted</strong> <strong>connected</strong> graph containing <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, and an integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, w<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> with weight <code>w<sub>i</sub></code>.</p>

<p>Some edges have a weight of <code>-1</code> (<code>w<sub>i</sub> = -1</code>), while others have a <strong>positive</strong> weight (<code>w<sub>i</sub> &gt; 0</code>).</p>

<p>Your task is to modify <strong>all edges</strong> with a weight of <code>-1</code> by assigning them <strong>positive integer values </strong>in the range <code>[1, 2 * 10<sup>9</sup>]</code> so that the <strong>shortest distance</strong> between the nodes <code>source</code> and <code>destination</code> becomes equal to an integer <code>target</code>. If there are <strong>multiple</strong> <strong>modifications</strong> that make the shortest distance between <code>source</code> and <code>destination</code> equal to <code>target</code>, any of them will be considered correct.</p>

<p>Return <em>an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from </em><code>source</code><em> to </em><code>destination</code><em> equal to </em><code>target</code><em>, or an <strong>empty array</strong> if it&#39;s impossible.</em></p>

<p><strong>Note:</strong> You are not allowed to modify the weights of edges with initial positive weights.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/18/graph.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
<strong>Output:</strong> [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
<strong>Explanation:</strong> The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/18/graph-2.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
<strong>Output:</strong> []
<strong>Explanation:</strong> The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/19/graph-3.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
<strong>Output:</strong> [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
<strong>Explanation:</strong> The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code><font face="monospace">1 &lt;= edges.length &lt;= n * (n - 1) / 2</font></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i&nbsp;</sub>&lt;&nbsp;n</code></li>
	<li><code><font face="monospace">w<sub>i</sub>&nbsp;= -1&nbsp;</font></code>or <code><font face="monospace">1 &lt;= w<sub>i&nbsp;</sub>&lt;= 10<sup><span style="font-size: 10.8333px;">7</span></sup></font></code></li>
	<li><code>a<sub>i&nbsp;</sub>!=&nbsp;b<sub>i</sub></code></li>
	<li><code>0 &lt;= source, destination &lt; n</code></li>
	<li><code>source != destination</code></li>
	<li><code><font face="monospace">1 &lt;= target &lt;= 10<sup>9</sup></font></code></li>
	<li>The graph is connected, and there are no self-loops or repeated edges</li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
  void solve(
    const vector<vector<pi>> &neighbors,
    vector<vector<int>> &edges,
    vector<vector<int>> &distance,
    int source,
    int difference = 0,
    bool modify = false
  ) {
    int n = neighbors.size();
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, source});
    distance[source][modify] = 0;

    while(pq.size()) {
      auto [dist, current] = pq.top();
      pq.pop();

      if(dist > distance[current][modify]) continue;

      for(auto &[next, edge] : neighbors[current]) {
        int weight = edges[edge][2];

        if(weight == -1) weight = 1;

        if(modify && edges[edge][2] == -1) {
          int newWeight = difference + distance[next][0] - distance[current][1];
          if(newWeight > weight) {
            edges[edge][2] = newWeight;
            weight = newWeight;
          }
        }

        if(distance[next][modify] > distance[current][modify] + weight) {
          distance[next][modify] = distance[current][modify] + weight;
          pq.push({distance[next][modify], next});
        }
      }
    }
  }
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    vector<vector<pi>> neighbors(n);
    for(int i = 0; i < edges.size(); ++i) {
      neighbors[edges[i][0]].push_back({edges[i][1], i});
      neighbors[edges[i][1]].push_back({edges[i][0], i});
    }

    vector<vector<int>> distance(n, vector<int>(2, INT_MAX));
    distance[source][0] = 0;
    distance[source][1] = 0;
    
    solve(neighbors, edges, distance, source);

    int diff = target - distance[destination][0];
    if(diff < 0) return {};
    solve(neighbors, edges, distance, source, diff, true);
    if(distance[destination][1] < target) return {};

    for(auto &e : edges) {
      if(e[2] == -1) e[2] = 1;
    }
    return edges;
  }
};
```
