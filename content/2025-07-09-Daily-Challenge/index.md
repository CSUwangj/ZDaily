+++
updated = 2025-07-10T00:52:34+08:00
title = "2025-07-09 Daily Challenge"
path = "2025-07-09-Daily-Challenge"
date = 2025-07-10T00:52:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 9

## Description

**Reschedule Meetings for Maximum Free Time I**

<p>You are given an integer <code>eventTime</code> denoting the duration of an event, where the event occurs from time <code>t = 0</code> to time <code>t = eventTime</code>.</p>

<p>You are also given two integer arrays <code>startTime</code> and <code>endTime</code>, each of length <code>n</code>. These represent the start and end time of <code>n</code> <strong>non-overlapping</strong> meetings, where the <code>i<sup>th</sup></code> meeting occurs during the time <code>[startTime[i], endTime[i]]</code>.</p>

<p>You can reschedule <strong>at most</strong> <code>k</code> meetings by moving their start time while maintaining the <strong>same duration</strong>, to <strong>maximize</strong> the <strong>longest</strong> <em>continuous period of free time</em> during the event.</p>

<p>The <strong>relative</strong> order of all the meetings should stay the<em> same</em> and they should remain non-overlapping.</p>

<p>Return the <strong>maximum</strong> amount of free time possible after rearranging the meetings.</p>

<p><strong>Note</strong> that the meetings can <strong>not</strong> be rescheduled to a time outside the event.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/21/example0_rescheduled.png" style="width: 375px; height: 123px;" /></p>

<p>Reschedule the meeting at <code>[1, 2]</code> to <code>[2, 3]</code>, leaving no meetings during the time <code>[0, 2]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/21/example1_rescheduled.png" style="width: 375px; height: 125px;" /></p>

<p>Reschedule the meeting at <code>[2, 4]</code> to <code>[1, 3]</code>, leaving no meetings during the time <code>[3, 9]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no time during the event not occupied by meetings.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= eventTime &lt;= 10<sup>9</sup></code></li>
	<li><code>n == startTime.length == endTime.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>0 &lt;= startTime[i] &lt; endTime[i] &lt;= eventTime</code></li>
	<li><code>endTime[i] &lt;= startTime[i + 1]</code> where <code>i</code> lies in the range <code>[0, n - 2]</code>.</li>
</ul>


## Solution

``` cpp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<int> intervals(n + 1);
    intervals[0] = startTime[0] - 0;
    intervals[n] = eventTime - endTime[n - 1];
    for(int i = 1; i < n; ++i) {
      intervals[i] = startTime[i] - endTime[i - 1];
    }

    // cout << intervals << endl;
    int current = 0;
    for(int i = 0; i < min(k + 1, n + 1); ++i) {
      current += intervals[i];
    }
    int answer = current;
    for(int i = k + 1; i < n + 1; ++i) {
      current -= intervals[i - k - 1];
      current += intervals[i];
      answer = max(answer, current);
    }
    return answer;
  }
};

// Accepted
// 689/689 cases passed (4 ms)
// Your runtime beats 60 % of cpp submissions
// Your memory usage beats 79.76 % of cpp submissions (123.2 MB)
```
