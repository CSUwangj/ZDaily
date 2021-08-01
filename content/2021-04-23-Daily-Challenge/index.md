+++
title = "2021-04-23 Daily-Challenge"
path = "2021-04-23-Daily-Challenge"
date = 2021-04-23 18:26:00+08:00
updated = 2021-04-23 19:24:56+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/) with `cpp`.

<!-- more -->

# K Closest Points to Origin

## Description

Given an array of `points` where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., <code>√(x<sub>1</sub> - x<sub>2</sub>)<sub>2</sub> + (y<sub>1</sub> - y<sub>2</sub>)<sup>2</sup></code>).

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

- <code>1 <= k <= points.length <= 10<sup>4</sup></code>
- <code>-10<sup>4</sup> < xi, yi < 10<sup>4</sup></code>

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
    vector<vector<int>> answer;
    vector<int> index;
    for(int i = 0; i < points.size(); ++i) index.push_back(i);
    nth_element(index.begin(), index.begin() + k - 1, index.end(), [&](int a, int b) {
      return points[a][0] * points[a][0] + points[a][1] * points[a][1] <
             points[b][0] * points[b][0] + points[b][1] * points[b][1];
    });
    for(int i = 0; i < k; ++i) answer.push_back(points[index[i]]);
    return answer;
  }
};

// Accepted
// 84/84 cases passed (108 ms)
// Your runtime beats 99.8 % of cpp submissions
// Your memory usage beats 73.75 % of cpp submissions (53.3 MB)
```

# April LeetCoding challenge 23

## Description

**Count Binary Substrings**

Give a string `s`, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

**Example 1:**

```
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
```



**Example 2:**

```
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
```



**Note:**

`s.length` will be between 1 and 50,000.

`s` will only consist of "0" or "1" characters.

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
  int countBinarySubstrings(string s) {
    int prev = 0;
    int cur = 0;
    int answer = 0;
    char curChar = '#';
    for(auto c : s) {
      if(c != curChar) {
        answer += min(prev, cur);
        prev = cur;
        cur = 0;
        curChar = c;
      }
      cur += 1;
    }
    answer += min(prev, cur);
    return answer;
  }
};
// 
// Accepted
// 90/90 cases passed (12 ms)
// Your runtime beats 99.74 % of cpp submissions
// Your memory usage beats 91.29 % of cpp submissions (10.3 MB)
```
