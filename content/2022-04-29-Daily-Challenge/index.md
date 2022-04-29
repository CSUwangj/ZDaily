+++
updated = 2022-04-29 18:58:00+08:00
title = "2022-04-29 Daily-Challenge"
path = "2022-04-29-Daily-Challenge"
date = 2022-04-29 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/is-graph-bipartite/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 29

## Description

**Is Graph Bipartite?**

There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:

- There are no self-edges (`graph[u]` does not contain `u`).
- There are no parallel edges (`graph[u]` does not contain duplicate values).
- If `v` is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).
- The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` *if and only if it is **bipartite***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg)

```
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg)

```
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
```

 

**Constraints:**

- `graph.length == n`
- `1 <= n <= 100`
- `0 <= graph[u].length < n`
- `0 <= graph[u][i] <= n - 1`
- `graph[u]` does not contain `u`.
- All the values of `graph[u]` are **unique**.
- If `graph[u]` contains `v`, then `graph[v]` contains `u`.

## Solution

``` cpp
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<int> type(len, -1);
    int count = 0;
    while(count < len) {
      queue<int> q;
      for(int i = 0; i < len; ++i) {
        if(type[i] != -1) continue;
        q.push(i);
        type[i] = 0;
        count += 1;
        break;
      }
      while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto neighbor : graph[cur]) {
          if(type[neighbor] == type[cur]) return false;
          if(type[neighbor] == (type[cur] ^ 1)) continue;
          q.push(neighbor);
          type[neighbor] = type[cur] ^ 1;
          count += 1;
        }
      }
    }
    return true;
  }
};

// Accepted
// 80/80 cases passed (27 ms)
// Your runtime beats 73.07 % of cpp submissions
// Your memory usage beats 41.19 % of cpp submissions (13.7 MB)
```
