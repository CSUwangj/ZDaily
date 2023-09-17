+++
updated = 2023-09-17T23:10:56+08:00
title = "2023-09-17 Daily Challenge"
path = "2023-09-17-Daily-Challenge"
date = 2023-09-17T23:10:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 17

## Description

**Shortest Path Visiting All Nodes**

<p>You have an undirected, connected graph of <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given an array <code>graph</code> where <code>graph[i]</code> is a list of all the nodes connected with node <code>i</code> by an edge.</p>

<p>Return <em>the length of the shortest path that visits every node</em>. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/12/shortest1-graph.jpg" style="width: 222px; height: 183px;" />
<pre>
<strong>Input:</strong> graph = [[1,2,3],[0],[0],[0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible path is [1,0,2,0,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/12/shortest2-graph.jpg" style="width: 382px; height: 222px;" />
<pre>
<strong>Input:</strong> graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible path is [0,1,4,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 12</code></li>
	<li><code>0 &lt;= graph[i].length &lt;&nbsp;n</code></li>
	<li><code>graph[i]</code> does not contain <code>i</code>.</li>
	<li>If <code>graph[a]</code> contains <code>b</code>, then <code>graph[b]</code> contains <code>a</code>.</li>
	<li>The input graph is always connected.</li>
</ul>


## Solution

``` cpp
pair<int, int> getState(int state) {
  int visited = ((1 << 12) - 1) & state;
  state >>= 12;
  int current;
  for(int i = 0; i < 12; ++i) {
    if((1 << i) & state) current = i;
  }
  return {current, visited};
}
inline constexpr int genState(int current, int visited) {
  return (1 << (current + 12)) | visited;
}
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int len = graph.size();
    const int TARGET = (1 << len) - 1;
    queue<int> q;
    set<int> states;
    for(int i = 0; i < len; ++i) {
      int state = genState(i, (1 << i));
      q.push(state);
      states.insert(state);
    }
    int answer = 0;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [current, visited] = getState(q.front());
        q.pop();
        if(visited == TARGET) return answer;
        for(auto nxt : graph[current]) {
          int state = genState(nxt, visited | (1 << nxt));
          if(states.count(state))continue;
          states.insert(state);
          q.push(state);
        }
      }
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 51/51 cases passed (99 ms)
// Your runtime beats 42.96 % of cpp submissions
// Your memory usage beats 51.19 % of cpp submissions (17.2 MB)
```
