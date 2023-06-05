+++
updated = 2023-06-05T13:20:09+08:00
title = "2023-06-05 Daily Challenge"
path = "2023-06-05-Daily-Challenge"
date = 2023-06-05T13:20:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/check-if-it-is-a-straight-line/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 5

## Description

**Check If It Is a Straight Line**

<p>You are given an array&nbsp;<code>coordinates</code>, <code>coordinates[i] = [x, y]</code>, where <code>[x, y]</code> represents the coordinate of a point. Check if these points&nbsp;make a straight line in the XY plane.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg" style="width: 336px; height: 336px;" /></p>

<pre>
<strong>Input:</strong> coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg" style="width: 348px; height: 336px;" /></strong></p>

<pre>
<strong>Input:</strong> coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;=&nbsp;coordinates.length &lt;= 1000</code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>-10^4 &lt;=&nbsp;coordinates[i][0],&nbsp;coordinates[i][1] &lt;= 10^4</code></li>
	<li><code>coordinates</code>&nbsp;contains no duplicate point.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    bool result = true;
    for(int i = 2; i < coordinates.size() && result; ++i) {
      int ndx = coordinates[i][0] - coordinates[0][0];
      int ndy = coordinates[i][1] - coordinates[0][1];
      if(dx && ndy * dx != ndx * dy) result = false;
      if(!dx && ndx) result = false;
    }

    return result;
  }
};

// Accepted
// 79/79 cases passed (7 ms)
// Your runtime beats 90.62 % of cpp submissions
// Your memory usage beats 63.27 % of cpp submissions (10 MB)
```
