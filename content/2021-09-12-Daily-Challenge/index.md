+++
title = "2021-09-12 Daily-Challenge"
path = "2021-09-12-Daily-Challenge"
date = 2021-09-12 15:12:22+08:00
updated = 2021-09-12 15:59:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3972/) with `cpp`.

After this week(end with Sunday), I'll not random a problem and solve it, but just write what I want to, and Daily LeetCoding Challenge, there will be no review anymore unless I found something interesting. I'll try something different, LeetCode bored me already.

<!-- more -->

# September LeetCoding Challenge 12

## Description

**Reachable Nodes In Subdivided Graph**

You are given an undirected graph (the **"original graph"**) with `n` nodes labeled from `0` to `n - 1`. You decide to **subdivide** each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

The graph is given as a 2D array of `edges` where `edges[i] = [ui, vi, cnti]` indicates that there is an edge between nodes `ui` and `vi` in the original graph, and `cnti` is the total number of new nodes that you will **subdivide** the edge into. Note that `cnti == 0` means you will not subdivide the edge.

To **subdivide** the edge `[ui, vi]`, replace it with `(cnti + 1)` new edges and `cnti` new nodes. The new nodes are `x1`, `x2`, ..., `xcnti`, and the new edges are `[ui, x1]`, `[x1, x2]`, `[x2, x3]`, ..., `[xcnti+1, xcnti]`, `[xcnti, vi]`.

In this **new graph**, you want to know how many nodes are **reachable** from the node `0`, where a node is **reachable** if the distance is `maxMoves` or less.

Given the original graph and `maxMoves`, return *the number of nodes that are **reachable** from node* `0` *in the new graph*.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/01/origfinal.png)

```
Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
Output: 13
Explanation: The edge subdivisions are shown in the image above.
The nodes that are reachable are highlighted in yellow.
```

**Example 2:**

```
Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
Output: 23
```

**Example 3:**

```
Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
Output: 1
Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.
```

 

**Constraints:**

<ul>
	<li><code>0 &lt;= edges.length &lt;= min(n * (n - 1) / 2, 10<sup>4</sup>)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub> &lt; v<sub>i</sub> &lt; n</code></li>
	<li>There are <strong>no multiple edges</strong> in the graph.</li>
	<li><code>0 &lt;= cnt<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= maxMoves &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= n &lt;= 3000</code></li>
</ul>

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MAX = INT_MAX / 2;
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> neighbors;
  vector<int> distance;
  void init(int n, vector<vector<int>>& edges) {
    neighbors.resize(n);
    distance.resize(n, MAX);

    for(auto &edge : edges) {
      neighbors[edge[0]].push_back({edge[1], edge[2] + 1});
      neighbors[edge[1]].push_back({edge[0], edge[2] + 1});
    }
  }
  void dijkstra() {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});

    while(pq.size()) {
      auto [moves, cur] = pq.top();
      pq.pop();
      if(distance[cur] != MAX) continue;
      distance[cur] = moves;
      for(auto [nxt, edge] : neighbors[cur]) {
        if(distance[nxt] != MAX) continue;
        pq.push({edge + moves, nxt});
      }
    }
  }
public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    init(n, edges);
    dijkstra();

    int answer = 0;
    for(auto &edge : edges) {
      if(distance[edge[0]] + edge[2] <= maxMoves \
      || distance[edge[1]] + edge[2] <= maxMoves \
      || 2 * maxMoves - distance[edge[0]] - distance[edge[1]] >= edge[2]) {
        answer += edge[2];
      } else {
        if(distance[edge[0]] < maxMoves) {
          answer += maxMoves - distance[edge[0]];
        }
        if(distance[edge[1]] < maxMoves) {
          answer += maxMoves - distance[edge[1]];
        }
      }
    }

    for(int i = 0; i < n; ++i) {
      answer += distance[i] <= maxMoves;
    }
    
    return answer;
  }
};

// Accepted
// 47/47 cases passed (137 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 91.4 % of cpp submissions (38.8 MB)
```