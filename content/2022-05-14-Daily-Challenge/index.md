+++
updated = 2022-05-14 19:51:00+08:00
title = "2022-05-14 Daily-Challenge"
path = "2022-05-14-Daily-Challenge"
date = 2022-05-14 19:39:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/network-delay-time/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 14

## Description

**Network Delay Time**

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the time it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

 

**Constraints:**

- `1 <= k <= n <= 100`
- `1 <= times.length <= 6000`
- `times[i].length == 3`
- `1 <= ui, vi <= n`
- `ui != vi`
- `0 <= wi <= 100`
- All the pairs `(ui, vi)` are **unique**. (i.e., no multiple edges.)

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> nextJump;
  vector<int> delays;
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    nextJump.resize(n);
    delays.resize(n);
    fill(delays.begin(), delays.end(), -1);
    for(const auto &time : times) {
      nextJump[time[0] - 1].push_back({time[1] - 1, time[2]});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, k - 1});
    int answer = 0;
    for(int _node = 0; _node < n; ++_node) {
      while(pq.size() && delays[pq.top().second] != -1) {
        pq.pop();
      }
      if(pq.empty()) return -1;
      auto [delay, node] = pq.top();
      // cout << "Node " << node << ": " << delay << endl; 
      pq.pop();
      delays[node] = delay;
      answer = delay;
      for(const auto &[next, addDelay] : nextJump[node]) {
        if(delays[next] != -1) continue;
        pq.push({delay + addDelay, next});
      }
    }
    return answer;
  }
};

// Accepted
// 52/52 cases passed (126 ms)
// Your runtime beats 84.67 % of cpp submissions
// Your memory usage beats 50.01 % of cpp submissions (41.2 MB)
```
