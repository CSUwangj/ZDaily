+++
updated = 2025-03-25T11:18:09+08:00
title = "2025-03-25 Daily Challenge"
path = "2025-03-25-Daily-Challenge"
date = 2025-03-25T11:18:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 25

## Description

**Check if Grid can be Cut into Sections**

<p>You are given an integer <code>n</code> representing the dimensions of an <code>n x n</code><!-- notionvc: fa9fe4ed-dff8-4410-8196-346f2d430795 --> grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates <code>rectangles</code>, where <code>rectangles[i]</code> is in the form <code>[start<sub>x</sub>, start<sub>y</sub>, end<sub>x</sub>, end<sub>y</sub>]</code>, representing a rectangle on the grid. Each rectangle is defined as follows:</p>

<ul>
	<li><code>(start<sub>x</sub>, start<sub>y</sub>)</code>: The bottom-left corner of the rectangle.</li>
	<li><code>(end<sub>x</sub>, end<sub>y</sub>)</code>: The top-right corner of the rectangle.</li>
</ul>

<p><strong>Note </strong>that the rectangles do not overlap. Your task is to determine if it is possible to make <strong>either two horizontal or two vertical cuts</strong> on the grid such that:</p>

<ul>
	<li>Each of the three resulting sections formed by the cuts contains <strong>at least</strong> one rectangle.</li>
	<li>Every rectangle belongs to <strong>exactly</strong> one section.</li>
</ul>

<p>Return <code>true</code> if such cuts can be made; otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/23/tt1drawio.png" style="width: 285px; height: 280px;" /></p>

<p>The grid is shown in the diagram. We can make horizontal cuts at <code>y = 2</code> and <code>y = 4</code>. Hence, output is true.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/23/tc2drawio.png" style="width: 240px; height: 240px;" /></p>

<p>We can make vertical cuts at <code>x = 2</code> and <code>x = 3</code>. Hence, output is true.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>3 &lt;= rectangles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= rectangles[i][0] &lt; rectangles[i][2] &lt;= n</code></li>
	<li><code>0 &lt;= rectangles[i][1] &lt; rectangles[i][3] &lt;= n</code></li>
	<li>No two rectangles overlap.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> verticalLines;
    vector<pair<int, int>> horizontalLines;
    for(auto &rec : rectangles) {
      verticalLines.push_back({rec[0], 1});
      verticalLines.push_back({rec[2], -1});
      horizontalLines.push_back({rec[1], 1});
      horizontalLines.push_back({rec[3], -1});
    }
    sort(verticalLines.begin(), verticalLines.end());
    sort(horizontalLines.begin(), horizontalLines.end());

    int zeroCount = 1;
    int count = 0;
    for(auto [_coordinateX, c] : verticalLines) {
      count += c;
      zeroCount += (count == 0);
    }
    cout << zeroCount << endl;
    if(zeroCount > 3) return true;
    zeroCount = 1;
    for(auto [_coordinateY, c] : horizontalLines) {
      count += c;
      zeroCount += (count == 0);
    }
    return zeroCount > 3;
  }
};

// Accepted
// 694/694 cases passed (149 ms)
// Your runtime beats 63.46 % of cpp submissions
// Your memory usage beats 54.27 % of cpp submissions (225.8 MB)
```
