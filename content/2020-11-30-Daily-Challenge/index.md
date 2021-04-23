+++
title = "2020-11-30 Daily-Challenge"
path = "2020-11-30-Daily-Challenge"
date = 2020-11-30 20:03:18+08:00
updated = 2020-11-30 21:53:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Power of Two* on [leetcode](https://leetcode.com/problems/power-of-two/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3549) with `cpp`.

<!-- more -->

# Power of Two

## Description

Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

 **Example 1:**

```
Input: n = 1
Output: true
Explanation: 20 = 1
```

**Example 2:**

```
Input: n = 16
Output: true
Explanation: 24 = 16
```

**Example 3:**

```
Input: n = 3
Output: false
```

**Example 4:**

```
Input: n = 4
Output: true
```

**Example 5:**

```
Input: n = 5
Output: false
```

**Constraints:**

- $-2^{31} <= n <= 2^{31} - 1$

## Solution

first I used `__builtint_popcount`

``` cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && __builtin_popcount(n) == 1;
    }
};
```

then I remembered low bit used in `BITS`

``` cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n&(-n)) == n;
    }
};

```

# November LeetCoding Challenge30

## Description

**The Skyline Problem**

## Description

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are **given the locations and height of all the buildings** as shown on a cityscape photo (Figure A), write a program to **output the skyline** formed by these buildings collectively (Figure B).

[![Buildings](https://assets.leetcode.com/uploads/2018/10/22/skyline1.png) ](https://leetcode.com/static/images/problemset/skyline1.jpg)[![Skyline Contour](https://assets.leetcode.com/uploads/2018/10/22/skyline2.png)](https://leetcode.com/static/images/problemset/skyline2.jpg)

The geometric information of each building is represented by a triplet of integers `[Li, Ri, Hi]`, where `Li` and `Ri` are the x coordinates of the left and right edge of the ith building, respectively, and `Hi` is its height. It is guaranteed that `0 ≤ Li, Ri ≤ INT_MAX`, `0 < Hi ≤ INT_MAX`, and `Ri - Li > 0`. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: `[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] `.

The output is a list of "**key points**" (red dots in Figure B) in the format of `[ [x1,y1], [x2, y2], [x3, y3], ... ]` that uniquely defines a skyline. **A key point is the left endpoint of a horizontal line segment**. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:`[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]`.

**Notes:**

- The number of buildings in any input list is guaranteed to be in the range `[0, 10000]`.
- The input list is already sorted in ascending order by the left x position `Li`.
- The output list must be sorted by the x position.
- There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...[2 3], [4 5], [7 5], [11 5], [12 7]...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...[2 3], [4 5], [12 7], ...]`

## Solution

scan from left to right, use a priority queue to maintain buildings.

``` cpp
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, int>> points;
    for(auto &building : buildings) {
      points.push_back(make_tuple(building[0], building[1], building[2]));
      points.push_back(make_tuple(building[1], -1, building[2]));
    }
    sort(points.begin(), points.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
      auto [a1, a2, a3] = a;
      auto [b1, b2, b3] = b; 
      return a1 < b1 || (a1 == b1 && (a2 != -1 && b2 == -1)) || (a1 == b1 && a3 > b3);
    });
    vector<vector<int>> answer;
    priority_queue<pair<int, int>> q;
    int currentHeight = 0;
    for(auto [point, rightPoint, height] : points) {
      if(rightPoint == -1) {
        while(q.size() && q.top().second <= point) q.pop();
        int newHeight = q.empty() ? 0 : q.top().first;
        if(newHeight != currentHeight) {
          answer.push_back(vector<int>{point, newHeight});
          currentHeight = newHeight;
        }
      } else {
        if(height > currentHeight) {
          answer.push_back(vector<int>{point, height});
          currentHeight = height;
        }
        q.push(make_pair(height, rightPoint));
      }
    }
    return answer;
  }
};
```

time complexity of this solution is $O(n \log n)$(sorting)