+++
updated = 2022-09-30 18:14:00+08:00
title = "2022-09-30 Daily-Challenge"
path = "2022-09-30-Daily-Challenge"
date = 2022-09-30 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/find-k-closest-elements/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 30

## Description

**The Skyline Problem**

A city's **skyline** is the outer contour of the silhouette formed by all the buildings in  that city when viewed from a distance. Given the locations and heights  of all the buildings, return *the **skyline** formed by these buildings collectively*.

The geometric information of each building is given in the array `buildings` where `buildings[i] = [lefti, righti, heighti]`:

- `lefti` is the x coordinate of the left edge of the `ith` building.
- `righti` is the x coordinate of the right edge of the `ith` building.
- `heighti` is the height of the `ith` building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The **skyline** should be represented as a list of "key points" **sorted by their x-coordinate** in the form `[[x1,y1],[x2,y2],...]`. Each key point is the left endpoint of some horizontal segment in the  skyline except the last point in the list, which always has a  y-coordinate `0` and is used to mark the skyline's  termination where the rightmost building ends. Any ground between the  leftmost and rightmost buildings should be part of the skyline's  contour.

**Note:** There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/12/01/merged.jpg)

```
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
```

**Example 2:**

```
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= buildings.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left<sub>i</sub> &lt; right<sub>i</sub> &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= height<sub>i</sub> &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>buildings</code> is sorted by <code>left<sub>i</sub></code> in&nbsp;non-decreasing order.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, int>> points;
    for(auto &b : buildings) {
      points.push_back(make_tuple(b[0], b[1], b[2]));
      points.push_back(make_tuple(b[1], -1, b[2]));
    }
    sort(points.begin(), points.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
      auto [al, ar, ah] = a;
      auto [bl, br, bh] = b;
      return al < bl || (al == bl && ((ar != -1 && br == -1) || (ar != -1 && br != -1 && ah > bh)));
    });
    int curHeight = 0;
    priority_queue<pair<int, int>> q;
    vector<vector<int>> answer;
    for(auto [curPos, rightPos, height] : points) {
      cout << curPos << ' ' << rightPos << ' ' << height << endl;
      if(rightPos == -1) {
        while(q.size() && q.top().second >= -curPos) cout << '#' << q.top().first << ' ' << q.top().second << endl, q.pop();
        int newHeight = q.size() ? q.top().first : 0;
        if(newHeight != curHeight) answer.push_back({curPos, newHeight});
        curHeight = newHeight;
      } else {
        q.push(make_pair(height, -rightPos));
        if(height > curHeight) {
          curHeight = height;
          answer.push_back({curPos, curHeight});
        }
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (157 ms)
// Your runtime beats 7.99 % of cpp submissions
// Your memory usage beats 82.66 % of cpp submissions (14.4 MB)
```
