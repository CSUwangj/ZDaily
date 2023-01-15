+++
updated = 2023-01-15T16:06:43+08:00
title = "2023-01-15 Daily Challenge"
path = "2023-01-15-Daily-Challenge"
date = 2023-01-15T16:06:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/number-of-good-paths/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 15

## Description

**Number of Good Paths**

<p>There is a tree (i.e. a connected, undirected graph with no cycles) consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> and exactly <code>n - 1</code> edges.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>vals</code> of length <code>n</code> where <code>vals[i]</code> denotes the value of the <code>i<sup>th</sup></code> node. You are also given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>A <strong>good path</strong> is a simple path that satisfies the following conditions:</p>

<ol>
	<li>The starting node and the ending node have the <strong>same</strong> value.</li>
	<li>All nodes between the starting node and the ending node have values <strong>less than or equal to</strong> the starting node (i.e. the starting node&#39;s value should be the maximum value along the path).</li>
</ol>

<p>Return <em>the number of distinct good paths</em>.</p>

<p>Note that a path and its reverse are counted as the <strong>same</strong> path. For example, <code>0 -&gt; 1</code> is considered to be the same as <code>1 -&gt; 0</code>. A single node is also considered as a valid path.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/f9caaac15b383af9115c5586779dec5.png" style="width: 400px; height: 333px;" />
<pre>
<strong>Input:</strong> vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -&gt; 0 -&gt; 2 -&gt; 4.
(The reverse path 4 -&gt; 2 -&gt; 0 -&gt; 1 is treated as the same as 1 -&gt; 0 -&gt; 2 -&gt; 4.)
Note that 0 -&gt; 2 -&gt; 3 is not a good path because vals[2] &gt; vals[0].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/149d3065ec165a71a1b9aec890776ff.png" style="width: 273px; height: 350px;" />
<pre>
<strong>Input:</strong> vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -&gt; 1 and 2 -&gt; 3.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/31705e22af3d9c0a557459bc7d1b62d.png" style="width: 100px; height: 88px;" />
<pre>
<strong>Input:</strong> vals = [1], edges = []
<strong>Output:</strong> 1
<strong>Explanation:</strong> The tree consists of only one node, so there is one good path.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == vals.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= vals[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
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
  vector<vector<int>> neighbors;
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int len = vals.size();
    neighbors.resize(len);
    UnionSet us(len);

    map<int, vector<int>> nodes;
    for(int i = 0; i < len; ++i) {
      nodes[vals[i]].push_back(i);
    }
    for(const auto &edge : edges) {
      if(vals[edge[0]] >= vals[edge[1]]) {
        neighbors[edge[0]].push_back(edge[1]);
      }
      if(vals[edge[0]] <= vals[edge[1]]) {
        neighbors[edge[1]].push_back(edge[0]);
      }
    }

    int answer = len;
    for(const auto &[_val, nodes] : nodes) {
      for(auto node : nodes) {
        for(auto next : neighbors[node]) {
          us.merge(node, next);
        }
      }
      map<int, int> counts;
      for(auto node : nodes) {
        counts[us.find(node)] += 1;
      }
      for(const auto &[root, count] : counts) {
        answer += (count) * (count - 1) / 2;
      }
    }

    return answer;
  }
};

// Accepted
// 134/134 cases passed (627 ms)
// Your runtime beats 97.53 % of cpp submissions
// Your memory usage beats 82.68 % of cpp submissions (190.8 MB)
```
