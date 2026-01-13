+++
updated = 2026-01-13T01:24:48+01:00
title = "2026-01-13 Daily Challenge"
path = "2026-01-13-Daily-Challenge"
date = 2026-01-13T01:24:48+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/separate-squares-i/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 13

## Description

**Separate Squares I**

<p>You are given a 2D integer array <code>squares</code>. Each <code>squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>]</code> represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.</p>

<p>Find the <strong>minimum</strong> y-coordinate value of a horizontal line such that the total area of the squares above the line <em>equals</em> the total area of the squares below the line.</p>

<p>Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p><strong>Note</strong>: Squares <strong>may</strong> overlap. Overlapping areas should be counted <strong>multiple times</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">squares = [[0,0,1],[2,2,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1.00000</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2025/01/06/4062example1drawio.png" style="width: 378px; height: 352px;" /></p>

<p>Any horizontal line between <code>y = 1</code> and <code>y = 2</code> will have 1 square unit above it and 1 square unit below it. The lowest option is 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">squares = [[0,0,2],[1,1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1.16667</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2025/01/15/4062example2drawio.png" style="width: 378px; height: 352px;" /></p>

<p>The areas are:</p>

<ul>
	<li>Below the line: <code>7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5</code>.</li>
	<li>Above the line: <code>5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5</code>.</li>
</ul>

<p>Since the areas above and below the line are equal, the output is <code>7/6 = 1.16667</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= squares.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>]</code></li>
	<li><code>squares[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= l<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li>The total area of all the squares will not exceed <code>10<sup>12</sup></code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  double eps = 1e - 5;
  bool check(double line, double area, const vector<vector<int>>& squares) {
    double sum = 0;
    for(const auto &s : squares) {
      if(line < s[1]) continue;
      if(line > s[1] + s[2]) {
        sum += 1.0 * s[2] * s[2];
      } else {
        sum += (line - s[1]) * s[2];
      }
    }
    // cout << sum << ' ' << area << endl;
    return abs(sum - area / 2) < eps || sum > area / 2;
  }
public:
  double separateSquares(vector<vector<int>>& squares) {
    double low = 1e10;
    double high = -1;
    double area = 0;
    for(const auto &s : squares) {
      low = min<double>(s[1], low);
      high = max<double>(s[1] + s[2], high);
      area += 1.0 * s[2] * s[2];
    }

    while(high - low > eps) {
      // cout << high << ' ' << low << endl;
      double mid = (high + low) / 2;
      if(check(mid, area, squares)) {
        high = mid;
      } else {
        low = mid;
      }
    }
    return high;
  }
};

// Accepted
// 915/915 cases passed (93 ms)
// Your runtime beats 69.36 % of cpp submissions
// Your memory usage beats 73.99 % of cpp submissions (198.6 MB)
```
