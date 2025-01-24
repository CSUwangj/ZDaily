+++
updated = 2025-01-24T15:52:05+08:00
title = "2025-01-24 Daily Challenge"
path = "2025-01-24-Daily-Challenge"
date = 2025-01-24T15:52:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/find-eventual-safe-states/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 24

## Description

**Find Eventual Safe States**

<p>There is a directed graph of <code>n</code> nodes with each node labeled from <code>0</code> to <code>n - 1</code>. The graph is represented by a <strong>0-indexed</strong> 2D integer array <code>graph</code> where <code>graph[i]</code> is an integer array of nodes adjacent to node <code>i</code>, meaning there is an edge from node <code>i</code> to each node in <code>graph[i]</code>.</p>

<p>A node is a <strong>terminal node</strong> if there are no outgoing edges. A node is a <strong>safe node</strong> if every possible path starting from that node leads to a <strong>terminal node</strong> (or another safe node).</p>

<p>Return <em>an array containing all the <strong>safe nodes</strong> of the graph</em>. The answer should be sorted in <strong>ascending</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Illustration of graph" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png" style="height: 171px; width: 600px;" />
<pre>
<strong>Input:</strong> graph = [[1,2],[2,3],[5],[0],[5],[],[]]
<strong>Output:</strong> [2,4,5,6]
<strong>Explanation:</strong> The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
<strong>Output:</strong> [4]
<strong>Explanation:</strong>
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= graph[i].length &lt;= n</code></li>
	<li><code>0 &lt;= graph[i][j] &lt;= n - 1</code></li>
	<li><code>graph[i]</code> is sorted in a strictly increasing order.</li>
	<li>The graph may contain self-loops.</li>
	<li>The number of edges in the graph will be in the range <code>[1, 4 * 10<sup>4</sup>]</code>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<vector<int>> reverseGraph(len);
    vector<int> degree(len);
    for(int i = 0; i < len; ++i) {
      for(auto next : graph[i]) {
        reverseGraph[next].push_back(i);
        degree[i] += 1;
      }
    }

    queue<int> q;
    vector<int> answer;
    for(int i = 0; i < len; ++i) {
      if(!degree[i]) {
        q.push(i);
      }
    }

    while(q.size()) {
      int current = q.front();
      q.pop();
      answer.push_back(current);
      for(auto next : reverseGraph[current]) {
        degree[next] -= 1;
        if(!degree[next]) {
          q.push(next);
        }
      }
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 112/112 cases passed (52 ms)
// Your runtime beats 38.48 % of cpp submissions
// Your memory usage beats 42.62 % of cpp submissions (66.1 MB)
```
