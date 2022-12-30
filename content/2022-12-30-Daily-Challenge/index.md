+++
updated = 2022-12-30T12:14:19+08:00
title = "2022-12-30 Daily Challenge"
path = "2022-12-30-Daily-Challenge"
date = 2022-12-30T12:14:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/all-paths-from-source-to-target/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 30

## Description

**All Paths From Source to Target**

<p>Given a directed acyclic graph (<strong>DAG</strong>) of <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, find all possible paths from node <code>0</code> to node <code>n - 1</code> and return them in <strong>any order</strong>.</p>

<p>The graph is given as follows: <code>graph[i]</code> is a list of all nodes you can visit from node <code>i</code> (i.e., there is a directed edge from node <code>i</code> to node <code>graph[i][j]</code>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> graph = [[1,2],[3],[3],[]]
<strong>Output:</strong> [[0,1,3],[0,2,3]]
<strong>Explanation:</strong> There are two paths: 0 -&gt; 1 -&gt; 3 and 0 -&gt; 2 -&gt; 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg" style="width: 423px; height: 301px;" />
<pre>
<strong>Input:</strong> graph = [[4,3,1],[3,2,4],[3],[4],[]]
<strong>Output:</strong> [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>0 &lt;= graph[i][j] &lt; n</code></li>
	<li><code>graph[i][j] != i</code> (i.e., there will be no self-loops).</li>
	<li>All the elements of <code>graph[i]</code> are <strong>unique</strong>.</li>
	<li>The input graph is <strong>guaranteed</strong> to be a <strong>DAG</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int degree[15] = {};
    int n = graph.size();
    for(auto &nexts : graph) {
      for(auto next : nexts) {
        degree[next] += 1;
      }
    }
    if(degree[0]) return {};

    queue<int> q;
    vector<vector<int>> result[n];
    q.push(0);
    result[0].push_back({0});

    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto next : graph[cur]) {
        for(auto path : result[cur]) {
          path.push_back(next);
          result[next].emplace_back(path);
        }
        degree[next] -= 1;
        if(!degree[next]) {
          q.push(next);
        }
      }
    }
    return result[n - 1];
  }
};

// Accepted
// 30/30 cases passed (28 ms)
// Your runtime beats 33.13 % of cpp submissions
// Your memory usage beats 15.98 % of cpp submissions (18.2 MB)
```
