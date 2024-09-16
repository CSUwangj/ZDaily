+++
updated = 2024-09-15T10:09:07+08:00
title = "2024-09-15 Daily Challenge"
path = "2024-09-15-Daily-Challenge"
date = 2024-09-15T10:09:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/minimum-time-difference/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 16

## Description

**Minimum Time Difference**

Given a list of 24-hour clock time points in <strong>&quot;HH:MM&quot;</strong> format, return <em>the minimum <b>minutes</b> difference between any two time-points in the list</em>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> timePoints = ["23:59","00:00"]
<strong>Output:</strong> 1
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> timePoints = ["00:00","23:59","00:00"]
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= timePoints.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>timePoints[i]</code> is in the format <strong>&quot;HH:MM&quot;</strong>.</li>
</ul>



## Solution

``` cpp
class Solution {
  int diff(const string &a, const string &b) {
    return (a[0] - b[0]) * 600 + (a[1] - b[1]) * 60 + (a[3] - b[3]) * 10 + a[4] - b[4];
  }
public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int answer = diff(timePoints.front(), timePoints.back()) + 1440;
    for(int i = 1; i < timePoints.size(); ++i) {
      answer = min(answer, diff(timePoints[i], timePoints[i - 1]));
    }
    return answer;
  }
};
```
