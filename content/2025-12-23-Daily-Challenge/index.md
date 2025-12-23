+++
updated = 2025-12-23T22:18:26+01:00
title = "2025-12-23 Daily Challenge"
path = "2025-12-23-Daily-Challenge"
date = 2025-12-23T22:18:26+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/two-best-non-overlapping-events/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 23

## Description

**Two Best Non-Overlapping Events**

<p>You are given a <strong>0-indexed</strong> 2D integer array of <code>events</code> where <code>events[i] = [startTime<sub>i</sub>, endTime<sub>i</sub>, value<sub>i</sub>]</code>. The <code>i<sup>th</sup></code> event starts at <code>startTime<sub>i</sub></code><sub> </sub>and ends at <code>endTime<sub>i</sub></code>, and if you attend this event, you will receive a value of <code>value<sub>i</sub></code>. You can choose <strong>at most</strong> <strong>two</strong> <strong>non-overlapping</strong> events to attend such that the sum of their values is <strong>maximized</strong>.</p>

<p>Return <em>this <strong>maximum</strong> sum.</em></p>

<p>Note that the start time and end time is <strong>inclusive</strong>: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time <code>t</code>, the next event must start at or after <code>t + 1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture5.png" style="width: 400px; height: 75px;" />
<pre>
<strong>Input:</strong> events = [[1,3,2],[4,5,2],[2,4,3]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="Example 1 Diagram" src="https://assets.leetcode.com/uploads/2021/09/21/picture1.png" style="width: 400px; height: 77px;" />
<pre>
<strong>Input:</strong> events = [[1,3,2],[4,5,2],[1,5,5]]
<strong>Output:</strong> 5
<strong>Explanation: </strong>Choose event 2 for a sum of 5.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture3.png" style="width: 400px; height: 66px;" />
<pre>
<strong>Input:</strong> events = [[1,5,3],[1,5,1],[6,6,5]]
<strong>Output:</strong> 8
<strong>Explanation: </strong>Choose events 0 and 2 for a sum of 3 + 5 = 8.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 3</code></li>
	<li><code>1 &lt;= startTime<sub>i</sub> &lt;= endTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    vector<int> suffixMax(events.size());
    suffixMax.back() = events.back()[2];
    for(int i = events.size() - 2; i >= 0; --i) {
      suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
    }
    int answer = 0;
    for(const auto &e : events) {
      int low = 0;
      int high = events.size() - 1;
      while(low < high) {
        int mid = (low + high) / 2;
        if(events[mid][0] <= e[1]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      if(events[low][0] <= e[1]) {
        answer = max(answer, e[2]);
      } else {
        answer = max(answer, e[2] +suffixMax[low]);
      }
    }
    return answer;
  }
};

// Accepted
// 64/64 cases passed (76 ms)
// Your runtime beats 65.57 % of cpp submissions
// Your memory usage beats 90.57 % of cpp submissions (158.6 MB)
```
