+++
updated = 2025-03-24T13:38:39+08:00
title = "2025-03-24 Daily Challenge"
path = "2025-03-24-Daily-Challenge"
date = 2025-03-24T13:38:39+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/count-days-without-meetings/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 24

## Description

**Count Days Without Meetings**

<p>You are given a positive integer <code>days</code> representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array <code>meetings</code> of size <code>n</code> where, <code>meetings[i] = [start_i, end_i]</code> represents the starting and ending days of meeting <code>i</code> (inclusive).</p>

<p>Return the count of days when the employee is available for work but no meetings are scheduled.</p>

<p><strong>Note: </strong>The meetings may overlap.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 10, meetings = [[5,7],[1,3],[9,10]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no meeting scheduled on the 4<sup>th</sup> and 8<sup>th</sup> days.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 5, meetings = [[2,4],[1,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no meeting scheduled on the 5<sup>th </sup>day.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 6, meetings = [[1,6]]</span></p>

<p><strong>Output:</strong> 0</p>

<p><strong>Explanation:</strong></p>

<p>Meetings are scheduled for all working days.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code><font face="monospace">1 &lt;= meetings[i][0] &lt;= meetings[i][1] &lt;= days</font></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int lastZero = 0;
    map<int, int> count;
    for(auto &m : meetings) {
      count[m[0]] += 1;
      count[m[1]] -= 1;
    }
    int answer = 0;
    int meetingCount = 0;
    for(const auto &[time, c] : count) {
      if(time > days) break;
      if(!meetingCount) answer += max(0, time - lastZero - 1);
      meetingCount += c;
      if(!meetingCount) lastZero = time;
    }
    if(!meetingCount) answer += max(0, days - lastZero);
    return answer;
  }
};

// Accepted
// 578/578 cases passed (190 ms)
// Your runtime beats 14.19 % of cpp submissions
// Your memory usage beats 7.44 % of cpp submissions (160.2 MB)
```
