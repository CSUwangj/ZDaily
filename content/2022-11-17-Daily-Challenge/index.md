+++
updated = 2022-11-17T12:47:19+08:00
title = "2022-11-17 Daily Challenge"
path = "2022-11-17-Daily-Challenge"
date = 2022-11-17T12:47:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/rectangle-area/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 17

## Description

**Rectangle Area**

<p>Given the coordinates of two <strong>rectilinear</strong> rectangles in a 2D plane, return <em>the total area covered by the two rectangles</em>.</p>

<p>The first rectangle is defined by its <strong>bottom-left</strong> corner <code>(ax1, ay1)</code> and its <strong>top-right</strong> corner <code>(ax2, ay2)</code>.</p>

<p>The second rectangle is defined by its <strong>bottom-left</strong> corner <code>(bx1, by1)</code> and its <strong>top-right</strong> corner <code>(bx2, by2)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Rectangle Area" src="https://assets.leetcode.com/uploads/2021/05/08/rectangle-plane.png" style="width: 700px; height: 365px;" />
<pre>
<strong>Input:</strong> ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
<strong>Output:</strong> 45
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>4</sup> &lt;= ax1 &lt;= ax2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= ay1 &lt;= ay2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= bx1 &lt;= bx2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= by1 &lt;= by2 &lt;= 10<sup>4</sup></code></li>
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
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int x = min({ax2 - bx1, bx2 - ax1, ax2 - ax1, bx2 - bx1});
    if(x < 0) x = 0;
    int y = min({ay2 - by1, by2 - ay1, ay2 - ay1, by2 - by1});
    if(y < 0) y = 0;
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - x * y;
  }
};

// Accepted
// 3080/3080 cases passed (15 ms)
// Your runtime beats 57.3 % of cpp submissions
// Your memory usage beats 5.6 % of cpp submissions (6.1 MB)
```
