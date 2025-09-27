+++
updated = 2025-09-27T22:46:00+02:00
title = "2025-09-27 Daily Challenge"
path = "2025-09-27-Daily-Challenge"
date = 2025-09-27T22:46:00+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/largest-triangle-area/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 27

## Description

**Largest Triangle Area**

<p>Given an array of points on the <strong>X-Y</strong> plane <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>, return <em>the area of the largest triangle that can be formed by any three different points</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png" style="height: 369px; width: 450px;" />
<pre>
<strong>Input:</strong> points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
<strong>Output:</strong> 2.00000
<strong>Explanation:</strong> The five points are shown in the above figure. The red triangle is the largest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> points = [[1,0],[0,0],[0,1]]
<strong>Output:</strong> 0.50000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 50</code></li>
	<li><code>-50 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 50</code></li>
	<li>All the given points are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double mmax = 0;
    int n = points.size();
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int x3 = points[k][0], y3 = points[k][1];
          double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
          mmax = max(mmax, area);
        }
      }
    }
    return mmax;
  }
};

// Accepted
// 57/57 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.28 % of cpp submissions (10.4 MB)
```
