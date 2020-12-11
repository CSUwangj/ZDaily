+++
title = "2020-12-10 Daily-Challenge"
path = "2020-12-10-Daily-Challenge"
date = 2020-12-10 18:00:14+08:00
updated = 2020-12-10 18:42:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3561/) with `cpp`.

<!-- more -->

# Path with Maximum Probability

## Description

You are given an undirected weighted graph of `n` nodes (0-indexed), represented by an edge list where `edges[i] = [a, b]` is an undirected edge connecting the nodes `a` and `b` with a probability of success of traversing that edge `succProb[i]`.

Given two nodes `start` and `end`, find the path with the maximum probability of success to go from `start` to `end` and return its success probability.

If there is no path from `start` to `end`, **return 0**. Your answer will be accepted if it differs from the correct answer by at most **1e-5**.

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png)**

```
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2019/09/20/1558_ex2.png)**

```
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2019/09/20/1558_ex3.png)**

```
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
```

**Constraints:**

- `2 <= n <= 10^4`
- `0 <= start, end < n`
- `start != end`
- `0 <= a, b < n`
- `a != b`
- `0 <= succProb.length == edges.length <= 2*10^4`
- `0 <= succProb[i] <= 1`
- There is at most one edge between every two nodes.

## Solution

shortest path, using dijkstra algorithm.

``` cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> neighbors(n);
        int len = edges.size();
        for(int i = 0; i < len; ++i) {
            neighbors[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            neighbors[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        priority_queue<pair<double, int>> q;
        q.push(make_pair(1, start));
        vector<bool> visited(n);
        while(q.size()) {
            auto [prob, cur] = q.top();
            if(cur == end) return prob;
            visited[cur] = true;
            q.pop();
            for(auto [nxt, nxtProb] : neighbors[cur]) {
                if(!visited[nxt]) {
                    q.push(make_pair(nxtProb*prob, nxt));
                }
            }
        }
        return 0;
    }
};
```

# December LeetCoding Challenge10

**Valid Mountain Array**

## Description

Given an array of integers `arr`, return *`true` if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- `arr.length >= 3`

- There exists some

  ```
  i
  ```

  with 

  ```
  0 < i < arr.length - 1
  ```

   such that:

  - `arr[0] < arr[1] < ... < arr[i - 1] < A[i]`
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

![img](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

 

**Example 1:**

```
Input: arr = [2,1]
Output: false
```

**Example 2:**

```
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```
Input: arr = [0,3,2,1]
Output: true
```

**Constraints:**

- `1 <= arr.length <= 104`
- `0 <= arr[i] <= 104`

## Solution

nothing to say

``` cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        if(len < 3) return false;
        int pos = 1;
        while(pos < len && arr[pos] > arr[pos-1]) pos += 1;
        if(pos == len || pos == 1) return false;
        while(pos < len && arr[pos] < arr[pos-1]) pos += 1;
        return pos == len;
    }
};
```