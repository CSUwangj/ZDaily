+++
updated = 2025-07-09T05:03:23+08:00
title = "2025-07-08 Daily Challenge"
path = "2025-07-08-Daily-Challenge"
date = 2025-07-09T05:03:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 8

## Description

**Maximum Number of Events That Can Be Attended II**

<p>You are given an array of <code>events</code> where <code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>, value<sub>i</sub>]</code>. The <code>i<sup>th</sup></code> event starts at <code>startDay<sub>i</sub></code><sub> </sub>and ends at <code>endDay<sub>i</sub></code>, and if you attend this event, you will receive a value of <code>value<sub>i</sub></code>. You are also given an integer <code>k</code> which represents the maximum number of events you can attend.</p>

<p>You can only attend one event at a time. If you choose to attend an event, you must attend the <strong>entire</strong> event. Note that the end day is <strong>inclusive</strong>: that is, you cannot attend two events where one of them starts and the other ends on the same day.</p>

<p>Return <em>the <strong>maximum sum</strong> of values that you can receive by attending events.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60048-pm.png" style="width: 400px; height: 103px;" /></p>

<pre>
<strong>Input:</strong> events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
<strong>Output:</strong> 7
<strong>Explanation: </strong>Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60150-pm.png" style="width: 400px; height: 103px;" /></p>

<pre>
<strong>Input:</strong> events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do <strong>not</strong> have to attend k events.</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60703-pm.png" style="width: 400px; height: 126px;" /></strong></p>

<pre>
<strong>Input:</strong> events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
<strong>Output:</strong> 9
<strong>Explanation:</strong> Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= events.length</code></li>
	<li><code>1 &lt;= k * events.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= startDay<sub>i</sub> &lt;= endDay<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1];
    });

    int len = events.size();
    vector<vector<int>> dp(len + 1, vector<int>(k + 1, 0));
    auto findPos = [](const vector<vector<int>> &events, int day) {
      int low = 0;
      int high = events.size() - 1;

      while(low < high) {
        int mid = (low + high) / 2;
        if(events[mid][1] < day) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      return low;
    };

    for(int i = 1; i <= len; ++i) {
      int pos = findPos(events, events[i - 1][0]);

      for(int j = 1; j <= k; ++j) {
        dp[i][j] = max(dp[i - 1][j], dp[pos][j - 1] + events[i - 1][2]);
      }
    }
    return dp[len][k];
  }
};

// Accepted
// 70/70 cases passed (137 ms)
// Your runtime beats 67.14 % of cpp submissions
// Your memory usage beats 7.3 % of cpp submissions (157.3 MB)
```
