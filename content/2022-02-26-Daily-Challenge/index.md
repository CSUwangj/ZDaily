+++
title = "2022-02-26 Daily-Challenge"
path = "2022-02-26-Daily-Challenge"
date = 2022-02-26 15:23:00+08:00
updated = 2022-02-26 15:33:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 26

## Description

**Shortest Path Visiting All Nodes**

You have an undirected, connected graph of `n` nodes labeled from `0` to `n - 1`. You are given an array `graph` where `graph[i]` is a list of all the nodes connected with node `i` by an edge.

Return *the length of the shortest path that visits every node*. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/12/shortest1-graph.jpg)

```
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/12/shortest2-graph.jpg)

```
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
```

 

**Constraints:**

- `n == graph.length`
- `1 <= n <= 12`
- `0 <= graph[i].length < n`
- `graph[i]` does not contain `i`.
- If `graph[a]` contains `b`, then `graph[b]` contains `a`.
- The input graph is always connected.

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
    unordered_set<int> states;
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
// 51/51 cases passed (101 ms)
// Your runtime beats 49.34 % of cpp submissions
// Your memory usage beats 59.24 % of cpp submissions (16.3 MB)
```
