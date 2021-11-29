+++
title = "2021-11-28 Daily-Challenge"
path = "2021-11-28-Daily-Challenge"
date = 2021-11-28 08:35:00+08:00
updated = 2021-11-28 08:52:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/product-of-array-except-self/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 28

## Description

**All Paths From Source to Target**

Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)

```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg)

```
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

**Example 3:**

```
Input: graph = [[1],[]]
Output: [[0,1]]
```

**Example 4:**

```
Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
```

**Example 5:**

```
Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
```

 

**Constraints:**

- `n == graph.length`
- `2 <= n <= 15`
- `0 <= graph[i][j] < n`
- `graph[i][j] != i` (i.e., there will be no self-loops).
- All the elements of `graph[i]` are **unique**.
- The input graph is **guaranteed** to be a **DAG**.

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
