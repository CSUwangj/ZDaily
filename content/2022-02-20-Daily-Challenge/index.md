+++
title = "2022-02-20 Daily-Challenge"
path = "2022-02-20-Daily-Challenge"
date = 2022-02-20 13:21:00+08:00
updated = 2022-02-20 13:24:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/remove-covered-intervals/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 20

## Description

**Remove Covered Intervals**

Given an array `intervals` where `intervals[i] = [li, ri]` represent the interval `[li, ri)`, remove all intervals that are covered by another interval in the list.

The interval `[a, b)` is covered by the interval `[c, d)` if and only if `c <= a` and `b <= d`.

Return *the number of remaining intervals*.

 

**Example 1:**

```
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Example 2:**

```
Input: intervals = [[1,4],[2,3]]
Output: 1
```

 

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `0 <= li <= ri <= 10^5`
- All the given intervals are **unique**.

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
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    int removed = 0;
    int end = -1;
    for(const auto &interval : intervals) {
      if(interval[1] <= end) {
        removed += 1;
      } else {
        end = interval[1];
      }
    }
    return intervals.size() - removed;
  }
};

// Accepted
// 34/34 cases passed (45 ms)
// Your runtime beats 31.8 % of cpp submissions
// Your memory usage beats 59.43 % of cpp submissions (11.4 MB)
```
