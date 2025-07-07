+++
updated = 2025-07-07T12:33:13+08:00
title = "2025-07-07 Daily Challenge"
path = "2025-07-07-Daily-Challenge"
date = 2025-07-07T12:33:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 7

## Description

**Maximum Number of Events That Can Be Attended**

<p>You are given an array of <code>events</code> where <code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>]</code>. Every event <code>i</code> starts at <code>startDay<sub>i</sub></code><sub> </sub>and ends at <code>endDay<sub>i</sub></code>.</p>

<p>You can attend an event <code>i</code> at any day <code>d</code> where <code>startDay<sub>i</sub> &lt;= d &lt;= endDay<sub>i</sub></code>. You can only attend one event at any time <code>d</code>.</p>

<p>Return <em>the maximum number of events you can attend</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" style="width: 400px; height: 267px;" src="https://assets.leetcode.com/uploads/2020/02/05/e1.png">
<pre><strong>Input:</strong> events = [[1,2],[2,3],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> events= [[1,2],[2,3],[3,4],[1,2]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 2</code></li>
	<li><code>1 &lt;= startDay<sub>i</sub> &lt;= endDay<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    int sz = events.size();
    sort(events.begin(), events.end());
    int day = 0;
    int pos = 0;
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> candidates;
    while(pos < sz || candidates.size()) {
      // cout << day << ' ' << pos << ' ' << answer << endl;
      if(candidates.empty() && pos < sz && events[pos][0] > day) day = events[pos][0];
      while(pos < sz && events[pos][0] <= day) {
        candidates.push(events[pos][1]);
        pos += 1;
      }
      while(candidates.size() && candidates.top() < day) candidates.pop();
      if(candidates.size()) {
        cout << candidates.top() << endl;
        candidates.pop();
        day += 1;
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 45/45 cases passed (484 ms)
// Your runtime beats 5.01 % of cpp submissions
// Your memory usage beats 30.62 % of cpp submissions (75 MB)
```
