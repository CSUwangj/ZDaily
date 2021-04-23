+++
title = "2021-02-14 Daily-Challenge"
path = "2021-02-14-Daily-Challenge"
date = 2021-02-14 16:00:59+08:00
updated = 2021-02-14 16:30:38+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3639/) with `cpp`.

<!-- more -->

# LeetCode Review

## Get Watched Videos by Your Friends

too easy to review

## Find K Pairs with Smallest Sums

using priority queue

``` cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> answer;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(!len1 || !len2 || !k) return answer;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        for(int i = 0; i < len1; ++i) {
            q.push(make_tuple(nums1[i] + nums2[0], i, 0));
        }
        while(k-- && q.size()) {
            auto [sum, i1, i2] = q.top();
            q.pop();
            answer.push_back(vector<int>{nums1[i1], nums2[i2]});
            if(i2 != len2 - 1) q.push(make_tuple(nums1[i1] + nums2[i2+1], i1, i2+1));
        }
        return answer;
    }
};
```

# February LeetCoding Challenge14

## Description

**Is Graph Bipartite?**

## Description

Given an undirected `graph`, return `true` if and only if it is bipartite.

Recall that a graph is *bipartite* if we can split its set of nodes into two independent subsets A and B, such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: `graph[i]` is a list of indexes `j` for which the edge between nodes `i` and `j` exists. Each node is an integer between `0` and `graph.length - 1`. There are no self edges or parallel edges: `graph[i]` does not contain `i`, and it doesn't contain any element twice.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg)

```
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can divide the vertices into two groups: {0, 2} and {1, 3}.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg)

```
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: We cannot find a way to divide the set of nodes into two independent subsets.
```

 

**Constraints:**

- `1 <= graph.length <= 100`
- `0 <= graph[i].length < 100`
- `0 <= graph[i][j] <= graph.length - 1`
- `graph[i][j] != i`
- All the values of `graph[i]` are **unique**.
- The graph is **guaranteed** to be **undirected**. 

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
```
