+++
updated = 2022-05-18 18:24:00+08:00
title = "2022-05-18 Daily-Challenge"
path = "2022-05-18-Daily-Challenge"
date = 2022-05-18 18:21:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/critical-connections-in-a-network/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 18

## Description

**Critical Connections in a Network**

There are `n` servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between servers `ai` and `bi`. Any server can reach other servers directly or indirectly through the network.

A *critical connection* is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png)

```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
```

**Example 2:**

```
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
```

 

**Constraints:**

- `2 <= n <= 10^5`
- `n - 1 <= connections.length <= 10^5`
- `0 <= ai, bi <= n - 1`
- `ai != bi`
- There are no repeated connections.

## Solution

``` cpp
class Solution {
  vector<vector<int>> neighbors;
  vector<int> num;
  vector<int> low;
  int count = 0;
  void init(int n, vector<vector<int>>& connections) {
    num.resize(n);
    low.resize(n);
    neighbors.resize(n);
    for(auto &edge : connections) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }
  void tarjan(int u, int father, vector<vector<int>> &answer) {
    low[u] = num[u] = ++count;
    for(auto child : neighbors[u]) {
      if(child == father) continue;
      if(!num[child]) {
        tarjan(child, u, answer);
        low[u] = min(low[u], low[child]);
        if(low[child] > num[u]) {
          answer.push_back({u, child});
        }
      } else if (num[child] < num[u]) {
        low[u] = min(low[u], num[child]);
      }
    }
  }
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    init(n, connections);
    vector<vector<int>> answer;
    tarjan(0, 0, answer);
    return answer;
  }
};

// Accepted
// 17/17 cases passed (794 ms)
// Your runtime beats 62.32 % of cpp submissions
// Your memory usage beats 89.75 % of cpp submissions (165.4 MB)
```
