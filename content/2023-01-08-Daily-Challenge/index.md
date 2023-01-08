+++
updated = 2023-01-08T15:26:06+08:00
title = "2023-01-08 Daily Challenge"
path = "2023-01-08-Daily-Challenge"
date = 2023-01-08T15:26:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/max-points-on-a-line/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 8

## Description

**Max Points on a Line**

<p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the <strong>X-Y</strong> plane, return <em>the maximum number of points that lie on the same straight line</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 300</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>All the <code>points</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int len = points.size();
    if(len < 3) return len;
    int answer = 0;
    for(int i = 0; i < len - 1; ++i) {
      map<double, int> count;
      int overlap = 0;
      int y = 0;
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];
        if(dx == 0 && dy == 0) {
          overlap += 1;
        }else if (dy == 0) {
          y += 1;
        } else {
          count[dx * 1.0 / dy] += 1;
        }
      }
      for(const auto &[_, c] : count) {
        answer = max(answer, 1 + overlap + c);
      }
      answer = max(answer, 1 + y);
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (48 ms)
// Your runtime beats 80.56 % of cpp submissions
// Your memory usage beats 37.28 % of cpp submissions (17.4 MB)
```
