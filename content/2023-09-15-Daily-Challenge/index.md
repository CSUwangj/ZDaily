+++
updated = 2023-09-15T19:47:43+08:00
title = "2023-09-15 Daily Challenge"
path = "2023-09-15-Daily-Challenge"
date = 2023-09-15T19:47:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/reconstruct-itinerary/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 15

## Description

**Min Cost to Connect All Points**

<p>You are given an array <code>points</code> representing integer coordinates of some points on a 2D-plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>The cost of connecting two points <code>[x<sub>i</sub>, y<sub>i</sub>]</code> and <code>[x<sub>j</sub>, y<sub>j</sub>]</code> is the <strong>manhattan distance</strong> between them: <code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>, where <code>|val|</code> denotes the absolute value of <code>val</code>.</p>

<p>Return <em>the minimum cost to make all points connected.</em> All points are connected if there is <strong>exactly one</strong> simple path between any two points.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/d.png" style="width: 214px; height: 268px;" />
<pre>
<strong>Input:</strong> points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>Output:</strong> 20
<strong>Explanation:</strong> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/c.png" style="width: 214px; height: 268px;" />
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> points = [[3,12],[-2,5],[-4,1]]
<strong>Output:</strong> 18
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are distinct.</li>
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
  using pi = pair<int, int>;
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    vector<bool> connected(len);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    connected[0] = true;
    for(int i = 1; i < len; ++i) {
      pq.push({abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]), i});
    }
    int answer = 0;
    int rest = len - 1;
    while(pq.size() && rest) {
      auto [cost, point] = pq.top();
      pq.pop();
      if(connected[point]) continue;
      connected[point] = true;
      answer += cost;
      rest -= 1;
      for(int i = 1; i < len; ++i) {
        if(connected[i]) continue;
        pq.push({abs(points[i][0] - points[point][0]) + abs(points[i][1] - points[point][1]), i});
      }
    }
    return answer;
  }
};

// Accepted
// 72/72 cases passed (136 ms)
// Your runtime beats 84.36 % of cpp submissions
// Your memory usage beats 77.28 % of cpp submissions (42.6 MB)
```
