+++
updated = 2023-11-12T12:36:59+08:00
title = "2023-11-12 Daily Challenge"
path = "2023-11-12-Daily-Challenge"
date = 2023-11-12T12:36:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/bus-routes/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 12

## Description

**Bus Routes**

<p>You are given an array <code>routes</code> representing bus routes where <code>routes[i]</code> is a bus route that the <code>i<sup>th</sup></code> bus repeats forever.</p>

<ul>
	<li>For example, if <code>routes[0] = [1, 5, 7]</code>, this means that the <code>0<sup>th</sup></code> bus travels in the sequence <code>1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; ...</code> forever.</li>
</ul>

<p>You will start at the bus stop <code>source</code> (You are not on any bus initially), and you want to go to the bus stop <code>target</code>. You can travel between bus stops by buses only.</p>

<p>Return <em>the least number of buses you must take to travel from </em><code>source</code><em> to </em><code>target</code>. Return <code>-1</code> if it is not possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> routes = [[1,2,7],[3,6,7]], source = 1, target = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= routes.length &lt;= 500</code>.</li>
	<li><code>1 &lt;= routes[i].length &lt;= 10<sup>5</sup></code></li>
	<li>All the values of <code>routes[i]</code> are <strong>unique</strong>.</li>
	<li><code>sum(routes[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= routes[i][j] &lt; 10<sup>6</sup></code></li>
	<li><code>0 &lt;= source, target &lt; 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if(source == target) return 0;
    map<int, vector<int>> stopRoutes;
    for(int i = 0; i < routes.size(); ++i) {
      for(auto bus : routes[i]) {
        stopRoutes[bus].push_back(i);
      }
    }

    vector<bool> visitRoutes(routes.size());
    set<int> visitStop;
    queue<int> q;
    for(auto route : stopRoutes[source]) {
      q.push(route);
    }

    int count = 1;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto route = q.front();
        q.pop();
        if(visitRoutes[route]) continue;
        visitRoutes[route] = true;

        for(auto stop : routes[route]) {
          if(stop == target) return count;
          if(visitStop.count(stop)) continue;
          for(auto route : stopRoutes[stop]) {
            q.push(route);
          }
          visitStop.insert(stop);
        }
      }
      count += 1;
    }

    return -1;
  }
};

// Accepted
// 49/49 cases passed (293 ms)
// Your runtime beats 60.83 % of cpp submissions
// Your memory usage beats 41.02 % of cpp submissions (72.5 MB)
```
