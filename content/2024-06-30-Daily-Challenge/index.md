+++
updated = 2024-06-30T19:05:30+08:00
title = "2024-06-30 Daily Challenge"
path = "2024-06-30-Daily-Challenge"
date = 2024-06-30T19:05:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 30

## Description

**Remove Max Number of Edges to Keep Graph Fully Traversable**

<p>Alice and Bob have an undirected graph of <code>n</code> nodes and three types of edges:</p>

<ul>
	<li>Type 1: Can be traversed by Alice only.</li>
	<li>Type 2: Can be traversed by Bob only.</li>
	<li>Type 3: Can be traversed by both Alice and Bob.</li>
</ul>

<p>Given an array <code>edges</code> where <code>edges[i] = [type<sub>i</sub>, u<sub>i</sub>, v<sub>i</sub>]</code> represents a bidirectional edge of type <code>type<sub>i</sub></code> between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.</p>

<p>Return <em>the maximum number of edges you can remove, or return</em> <code>-1</code> <em>if Alice and Bob cannot fully traverse the graph.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/ex1.png" style="width: 179px; height: 191px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
<strong>Output:</strong> 2
<strong>Explanation: </strong>If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/ex2.png" style="width: 178px; height: 190px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
<strong>Output:</strong> 0
<strong>Explanation: </strong>Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/ex3.png" style="width: 178px; height: 190px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
<strong>Output:</strong> -1
<b>Explanation: </b>In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it&#39;s impossible to make the graph fully traversable.</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10<sup>5</sup>, 3 * n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>1 &lt;= type<sub>i</sub> &lt;= 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub> &lt; v<sub>i</sub> &lt;= n</code></li>
	<li>All tuples <code>(type<sub>i</sub>, u<sub>i</sub>, v<sub>i</sub>)</code> are distinct.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
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
  bool addEdge(UnionSet &graph, const vector<int> &edge) {
    if(graph.find(edge[1] - 1) != graph.find(edge[2] - 1)) {
      graph.merge(edge[2] - 1, edge[1] - 1);
      return true;
    }
    return false;
  }
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UnionSet alice(n), bob(n);
    sort(edges.begin(), edges.end(), greater<vector<int>>());

    int answer = 0;
    for(const auto &edge : edges) {
      if(edge[0] == 3) {
        bool result = !addEdge(alice, edge);
        result = !addEdge(bob, edge) && result;
        answer += result;
      } else if(edge[0] == 2) {
        answer += !addEdge(bob, edge);
      } else {
        answer += !addEdge(alice, edge);
      }
      // cout << edge << ' ' << answer << endl;
    }
    int ag0 = alice.find(0);
    int bg0 = bob.find(0);
    for(int i = 1; i < n; ++i) {
      // cout << ag0 << ' '<< alice.find(i) << endl;
      // cout << bg0 << ' ' << bob.find(i) << endl;
      if(alice.find(i) != ag0) return -1;
      if(bob.find(i) != bg0) return -1;
    }

    return answer;
  }
};
```
