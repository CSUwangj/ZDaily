+++
updated = 2025-01-30T18:55:26+08:00
title = "2025-01-30 Daily Challenge"
path = "2025-01-30-Daily-Challenge"
date = 2025-01-30T18:55:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 30

## Description

**Divide Nodes Into the Maximum Number of Groups**

<p>You are given a positive integer <code>n</code> representing the number of nodes in an <strong>undirected</strong> graph. The nodes are labeled from <code>1</code> to <code>n</code>.</p>

<p>You are also given a 2D integer array <code>edges</code>, where <code>edges[i] = [a<sub>i, </sub>b<sub>i</sub>]</code> indicates that there is a <strong>bidirectional</strong> edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>. <strong>Notice</strong> that the given graph may be disconnected.</p>

<p>Divide the nodes of the graph into <code>m</code> groups (<strong>1-indexed</strong>) such that:</p>

<ul>
	<li>Each node in the graph belongs to exactly one group.</li>
	<li>For every pair of nodes in the graph that are connected by an edge <code>[a<sub>i, </sub>b<sub>i</sub>]</code>, if <code>a<sub>i</sub></code> belongs to the group with index <code>x</code>, and <code>b<sub>i</sub></code> belongs to the group with index <code>y</code>, then <code>|y - x| = 1</code>.</li>
</ul>

<p>Return <em>the maximum number of groups (i.e., maximum </em><code>m</code><em>) into which you can divide the nodes</em>. Return <code>-1</code> <em>if it is impossible to group the nodes with the given conditions</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/13/example1.png" style="width: 352px; height: 201px;" />
<pre>
<strong>Input:</strong> n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, edges = [[1,2],[2,3],[3,1]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= edges.length &lt;= 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There is at most one edge between any pair of vertices.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool isBipartite(vector<vector<int>> &neighbors, int current, vector<int> &color) {
    for(auto next : neighbors[current]) {
      if(color[next] == color[current]) return false;
      if(color[next] == -1) {
        color[next] = !color[current];
        if(!isBipartite(neighbors, next, color)) return false;
      }
    }
    return true;
  }

  int getLongestShortestPath(vector<vector<int>> &neighbors, int current, int n) {
    queue<int> q;
    vector<bool> visited(n);

    q.push(current);
    visited[current] = true;
    int distance = 0;

    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        int cur = q.front();
        q.pop();

        for(auto next : neighbors[cur]) {
          if(visited[next]) continue;
          visited[next] = true;
          q.push(next);
        }
      }
      distance += 1;
    }
    return distance;
  }
  int getGroups(vector<vector<int>> &neighbors, int current, vector<int> &distance, vector<bool> &visited) {
    int maxNumber = distance[current];
    visited[current] = true;

    for(auto next : neighbors[current]) {
      if(visited[next]) continue;
      maxNumber = max(maxNumber, getGroups(neighbors, next, distance, visited));
    }
    return maxNumber;
  }
public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> neighbors(n);
    for(auto &e : edges) {
      neighbors[e[0] - 1].push_back(e[1] - 1);
      neighbors[e[1] - 1].push_back(e[0] - 1);
    }
    vector<int> color(n, -1);
    for(int i = 0; i < n; ++i) {
      if(color[i] != -1) continue;
      color[i] = 0;
      if(!isBipartite(neighbors, i, color)) return -1;
    }

    vector<int> distance(n);
    for(int i = 0; i < n; ++i) {
      distance[i] = getLongestShortestPath(neighbors, i, n);
    }

    int answer = 0;
    vector<bool> visited(n);
    for(int i = 0; i < n; ++i) {
      if(visited[i]) continue;
      answer += getGroups(neighbors, i, distance, visited);
    }
    return answer;
  }
};

// Accepted
// 55/55 cases passed (143 ms)
// Your runtime beats 65.55 % of cpp submissions
// Your memory usage beats 90.76 % of cpp submissions (41.6 MB)
```
