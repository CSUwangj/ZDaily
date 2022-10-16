+++
title = "2021-11-24 Daily-Challenge"
path = "2021-11-24-Daily-Challenge"
date = 2021-11-24 15:33:00+08:00
updated = 2021-11-24 15:46:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/interval-list-intersections/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 24

## Description

**Interval List Intersections**

You are given two lists of closed intervals, `firstList` and `secondList`, where `firstList[i] = [starti, endi]` and `secondList[j] = [startj, endj]`. Each list of intervals is pairwise **disjoint** and in **sorted order**.

Return *the intersection of these two interval lists*.

A **closed interval** `[a, b]` (with `a <= b`) denotes the set of real numbers `x` with `a <= x <= b`.

The **intersection** of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of `[1, 3]` and `[2, 4]` is `[2, 3]`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/01/30/interval1.png)

```
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

**Example 2:**

```
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
```

**Example 3:**

```
Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []
```

**Example 4:**

```
Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]
```

 

**Constraints:**

<ul>
	<li><code>0 &lt;= firstList.length, secondList.length &lt;= 1000</code></li>
	<li><code>firstList.length + secondList.length &gt;= 1</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>end<sub>i</sub> &lt; start<sub>i+1</sub></code></li>
	<li><code>0 &lt;= start<sub>j</sub> &lt; end<sub>j</sub> &lt;= 10<sup>9</sup> </code></li>
	<li><code>end<sub>j</sub> &lt; start<sub>j+1</sub></code></li>
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
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    auto it1 = firstList.begin();
    auto end1 = firstList.end();
    auto it2 = secondList.begin();
    auto end2 = secondList.end();
    vector<vector<int>> answer;
    while(it1 != end1 && it2 != end2) {
      int begin = max((*it1)[0], (*it2)[0]);
      int end = min((*it1)[1], (*it2)[1]);
      if(end >= begin) {
        answer.push_back({begin, end});
      }
      if(end == (*it1)[1]) ++it1;
      if(end == (*it2)[1]) ++it2;
    }
    return answer;
  }
};

// Accepted
// 85/85 cases passed (24 ms)
// Your runtime beats 98.21 % of cpp submissions
// Your memory usage beats 75.13 % of cpp submissions (18.6 MB)
```
