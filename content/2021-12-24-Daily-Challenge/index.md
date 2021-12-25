+++
title = "2021-12-24 Daily-Challenge"
path = "2021-12-24-Daily-Challenge"
date = 2021-12-24 18:14:00+08:00
updated = 2021-12-24 18:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/merge-intervals/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 24

## Description

**Merge Intervals**

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

 

**Example 1:**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints**

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answer;
    vector<int> cur = intervals.front();
    for(auto &interval : intervals) {
      if(interval[0] > cur[1]) {
        answer.push_back(cur);
        cur[0] = interval[0];
      }
      cur[1] = max(interval[1], cur[1]);
    }
    answer.emplace_back(cur);
    return answer;
  }
};

// Accepted
// 168/168 cases passed (16 ms)
// Your runtime beats 88.84 % of cpp submissions
// Your memory usage beats 94.91 % of cpp submissions (14.1 MB)
```
