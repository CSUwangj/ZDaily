+++
updated = 2023-03-26T15:25:58+08:00
title = "2023-03-26 Daily Challenge"
path = "2023-03-26-Daily-Challenge"
date = 2023-03-26T15:25:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/longest-cycle-in-a-graph/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 26

## Description

**Longest Cycle in a Graph**

<p>You are given a <strong>directed</strong> graph of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>, where each node has <strong>at most one</strong> outgoing edge.</p>

<p>The graph is represented with a given <strong>0-indexed</strong> array <code>edges</code> of size <code>n</code>, indicating that there is a directed edge from node <code>i</code> to node <code>edges[i]</code>. If there is no outgoing edge from node <code>i</code>, then <code>edges[i] == -1</code>.</p>

<p>Return <em>the length of the <strong>longest</strong> cycle in the graph</em>. If no cycle exists, return <code>-1</code>.</p>

<p>A cycle is a path that starts and ends at the <strong>same</strong> node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png" style="width: 335px; height: 191px;" />
<pre>
<strong>Input:</strong> edges = [3,3,4,2,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest cycle in the graph is the cycle: 2 -&gt; 4 -&gt; 3 -&gt; 2.
The length of this cycle is 3, so 3 is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png" style="width: 171px; height: 161px;" />
<pre>
<strong>Input:</strong> edges = [2,-1,3,1]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no cycles in this graph.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    if(n < 2) return -1;
    vector<int> degree(n);
    set<int> visit;

    int answer = -1;
    for(int i = 0; i < n; ++i) {
      if(degree[i]) continue;
      int current = i;
      int prev;
      int d = 1;
      visit.clear();
      while(current != -1) {
        if(degree[current] && !visit.count(current)) break;
        if(visit.count(current)) {
          answer = max(answer, degree[prev] - degree[current] + 1);
          break;
        }
        degree[current] = d;
        d += 1;
        visit.insert(current);
        prev = current;
        current = edges[current];
      }
    }

    return answer;
  }
};

// Accepted
// 76/76 cases passed (554 ms)
// Your runtime beats 32.08 % of cpp submissions
// Your memory usage beats 43.72 % of cpp submissions (153.5 MB)
```
