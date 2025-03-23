+++
updated = 2025-03-23T13:51:18+08:00
title = "2025-03-23 Daily Challenge"
path = "2025-03-23-Daily-Challenge"
date = 2025-03-23T13:51:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 23

## Description

**Number of Ways to Arrive at Destination**

<p>You are in a city that consists of <code>n</code> intersections numbered from <code>0</code> to <code>n - 1</code> with <strong>bi-directional</strong> roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.</p>

<p>You are given an integer <code>n</code> and a 2D integer array <code>roads</code> where <code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, time<sub>i</sub>]</code> means that there is a road between intersections <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> that takes <code>time<sub>i</sub></code> minutes to travel. You want to know in how many ways you can travel from intersection <code>0</code> to intersection <code>n - 1</code> in the <strong>shortest amount of time</strong>.</p>

<p>Return <em>the <strong>number of ways</strong> you can arrive at your destination in the <strong>shortest amount of time</strong></em>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/02/14/1976_corrected.png" style="width: 255px; height: 400px;" />
<pre>
<strong>Input:</strong> n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, roads = [[1,0,10]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n - 1 &lt;= roads.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>There is at most one road connecting any two intersections.</li>
	<li>You can reach any intersection from any other intersection.</li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
  using plii = pair<long long, pi>;
  const int MOD = 1e9 + 7;
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pi>> neighbors(n);
    vector<int> count(n);
    vector<long long> distance(n, LONG_LONG_MAX);
    for(auto &r : roads) {
      neighbors[r[0]].push_back({r[1], r[2]});
      neighbors[r[1]].push_back({r[0], r[2]});
    }

    count[0] = 1;
    distance[0] = 0;
    priority_queue<plii, vector<plii>, greater<plii>> pq;
    pq.push({0, {-1, 0}});
    while(pq.size()) {
      auto [dist, fromTo] = pq.top();
      pq.pop();
      auto [from, current] = fromTo;
      bool visited = distance[current];
      if(distance[current] == LONG_LONG_MAX || (dist + current == 0)) {
        distance[current] = dist;
        for(auto [next, road] : neighbors[current]) {
          if(road + dist > distance[next]) continue;
          pq.push({road + dist, {current, next}});
        }
      }
      if(distance[current] == dist && from != -1) {
        count[current] += count[from];
        count[current] %= MOD;
      }
    }

    return count.back();
  }
};

// Accepted
// 55/55 cases passed (15 ms)
// Your runtime beats 34.92 % of cpp submissions
// Your memory usage beats 67.03 % of cpp submissions (36.8 MB)
```
