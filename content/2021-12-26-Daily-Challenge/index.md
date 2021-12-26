+++
title = "2021-12-26 Daily-Challenge"
path = "2021-12-26-Daily-Challenge"
date = 2021-12-26 14:16:00+08:00
updated = 2021-12-26 16:25:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/k-closest-points-to-origin/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 26

## Description

**K Closest Points to Origin**

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be **unique** (except for the order that it is in).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

**Example 2:**

```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= k &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt; x<sub>i</sub>, y<sub>i</sub> &lt; 10<sup>4</sup></code></li>
</ul>

## Solution

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    nth_element(points.begin(), points.begin() + k - 1, points.end(), [&](const vector<int> &a, const vector<int> &b) {
      return a[0] * a[0] + a[1] * a[1] <
             b[0] * b[0] + b[1] * b[1];
    });
    points.erase(points.cbegin() + k, points.cend());
    return points;
  }
};

// Accepted
// 85/85 cases passed (92 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.48 % of cpp submissions (49.1 MB)
```
