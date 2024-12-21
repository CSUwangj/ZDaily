+++
updated = 2024-12-21T20:28:01+08:00
title = "2024-12-21 Daily Challenge"
path = "2024-12-21-Daily-Challenge"
date = 2024-12-21T20:28:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-k-divisible-components/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 21

## Description

**Maximum Number of K-Divisible Components**

<p>There is an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given the integer <code>n</code> and a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>values</code> of length <code>n</code>, where <code>values[i]</code> is the <strong>value</strong> associated with the <code>i<sup>th</sup></code> node, and an integer <code>k</code>.</p>

<p>A <strong>valid split</strong> of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by <code>k</code>, where the <strong>value of a connected component</strong> is the sum of the values of its nodes.</p>

<p>Return <em>the <strong>maximum number of components</strong> in any valid split</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/07/example12-cropped2svg.jpg" style="width: 1024px; height: 453px;" />
<pre>
<strong>Input:</strong> n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> We remove the edge connecting node 1 with 2. The resulting split is valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
It can be shown that no other valid split has more than 2 connected components.</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/07/example21svg-1.jpg" style="width: 999px; height: 338px;" />
<pre>
<strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
It can be shown that no other valid split has more than 3 connected components.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>0 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>Sum of <code>values</code> is divisible by <code>k</code>.</li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<vector<int>> graph(n);
    vector<int> degree(n);

    if(n < 2) return 1;
    for(const auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
      degree[e[0]] += 1;
      degree[e[1]] += 1;
    }

    vector<long long> nodeVals(values.begin(), values.end());
    queue<int> q;
    for(int i = 0; i < n; ++i) {
      if(degree[i] == 1) q.push(i);
    }

    int answer = 0;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      degree[cur] -= 1;
      long long carry = 0;
      if(nodeVals[cur] % k == 0) answer += 1;
      else carry = nodeVals[cur];
      for(int next : graph[cur]) {
        if(degree[next] == 0) continue;
        degree[next] -= 1;
        nodeVals[next] += carry;
        if(degree[next] == 1) q.push(next);
      }
    }

    return answer;
  }
};

// Accepted
// 736/736 cases passed (90 ms)
// Your runtime beats 93.67 % of cpp submissions
// Your memory usage beats 67.09 % of cpp submissions (176.1 MB)
```
