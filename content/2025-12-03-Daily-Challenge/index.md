+++
updated = 2025-12-03T10:55:14+01:00
title = "2025-12-03 Daily Challenge"
path = "2025-12-03-Daily-Challenge"
date = 2025-12-03T10:55:14+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/count-number-of-trapezoids-ii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 3

## Description

**Count Number of Trapezoids II**

<p data-end="189" data-start="146">You are given a 2D integer array <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the coordinates of the <code>i<sup>th</sup></code> point on the Cartesian plane.</p>

<p data-end="189" data-start="146">Return <em data-end="330" data-start="297">the number of unique </em><em>trapezoids</em> that can be formed by choosing any four distinct points from <code>points</code>.</p>

<p data-end="579" data-start="405">A<b> </b><strong>trapezoid</strong> is a convex quadrilateral with <strong data-end="496" data-start="475">at least one pair</strong> of parallel sides. Two lines are parallel if and only if they have the same slope.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" style="width: 250px; height: 250px;" src="https://assets.leetcode.com/uploads/2025/04/29/desmos-graph-4.png"> <img alt="" style="width: 250px; height: 250px;" src="https://assets.leetcode.com/uploads/2025/04/29/desmos-graph-3.png"></p>

<p>There are two distinct ways to pick four points that form a trapezoid:</p>

<ul>
	<li>The points <code>[-3,2], [2,3], [3,2], [2,-3]</code> form one trapezoid.</li>
	<li>The points <code>[2,3], [3,2], [3,0], [2,-3]</code> form another trapezoid.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">points = [[0,0],[1,0],[0,1],[2,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" style="width: 250px; height: 250px;" src="https://assets.leetcode.com/uploads/2025/04/29/desmos-graph-5.png"></p>

<p>There is only one trapezoid which can be formed.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>4 &lt;= points.length &lt;= 500</code></li>
	<li><code>–1000 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 1000</code></li>
	<li>All points are pairwise distinct.</li>
</ul>



## Solution

``` cpp
class Solution {
  int count(unordered_map<int, unordered_map<int, int>> &mp) {
    long long result = 0;
    for(auto &[k1, inner] : mp) {
      long long sum = 0;
      for(auto &[_k2, val] : inner) {
        sum += val;
      }

      for(auto &[_k2, val] : inner) {
        result += val * (sum - val);
        sum -= val;
      }
    }
    return result;
  }
public:
  int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<int, unordered_map<int, int>> t, v;
    int sz = points.size();
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];

        if(dx < 0 || (dx == 0 && dy < 0)) {
          dx = -dx;
          dy = -dy;
        } 

        int g = gcd(dx, abs(dy));
        int sx = dx / g;
        int sy = dy / g;

        int des = sx * points[i][1] - sy * points[i][0];

        int key1 = (sx << 12) | (sy + 2000);
        int key2 = (dx << 12) | (dy + 2000);
        t[key1][des] += 1;
        v[key2][des] += 1;
      }
    }
    return count(t) - count(v) / 2;
  }
};

// Accepted
// 550/550 cases passed (2204 ms)
// Your runtime beats 60.87 % of cpp submissions
// Your memory usage beats 46.74 % of cpp submissions (555.9 MB)
```
