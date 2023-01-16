+++
updated = 2023-01-16T11:42:06+08:00
title = "2023-01-16 Daily Challenge"
path = "2023-01-16-Daily-Challenge"
date = 2023-01-16T11:42:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/insert-interval/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 16

## Description

**Insert Interval**

<p>You are given an array of non-overlapping intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represent the start and the end of the <code>i<sup>th</sup></code> interval and <code>intervals</code> is sorted in ascending order by <code>start<sub>i</sub></code>. You are also given an interval <code>newInterval = [start, end]</code> that represents the start and end of another interval.</p>

<p>Insert <code>newInterval</code> into <code>intervals</code> such that <code>intervals</code> is still sorted in ascending order by <code>start<sub>i</sub></code> and <code>intervals</code> still does not have any overlapping intervals (merge overlapping intervals if necessary).</p>

<p>Return <code>intervals</code><em> after the insertion</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,3],[6,9]], newInterval = [2,5]
<strong>Output:</strong> [[1,5],[6,9]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
<strong>Output:</strong> [[1,2],[3,10],[12,16]]
<strong>Explanation:</strong> Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals</code> is sorted by <code>start<sub>i</sub></code> in <strong>ascending</strong> order.</li>
	<li><code>newInterval.length == 2</code></li>
	<li><code>0 &lt;= start &lt;= end &lt;= 10<sup>5</sup></code></li>
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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.insert(lower_bound(intervals.begin(), intervals.end(), newInterval), newInterval);
    intervals.push_back({100002, -1});
    int len = intervals.size();
    int pos = 0;
    int begin = intervals.front()[0];
    int end = intervals.front()[1];
    for(int i = 0; i < len; ++i) {
      if(intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
      } else {
        intervals[pos][0] = begin;
        intervals[pos][1] = end;
        pos += 1;
        begin = intervals[i][0];
        end = intervals[i][1];
      }
    }
    intervals.resize(pos);
    return intervals;
  }
};

// Accepted
// 156/156 cases passed (16 ms)
// Your runtime beats 83.48 % of cpp submissions
// Your memory usage beats 92.65 % of cpp submissions (17 MB)
```
