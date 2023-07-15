+++
updated = 2023-07-15T08:08:19+08:00
title = "2023-07-15 Daily Challenge"
path = "2023-07-15-Daily-Challenge"
date = 2023-07-15T08:08:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 15

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
    int len = events.size();
    vector<int> index(len);
    for(int i = 0; i < len; ++i) index[i] = i;
    sort(index.begin(), index.end(), [&](int a, int b) {
      return events[a][1] < events[b][1];
    });
    vector<int> dp(len);
    vector<int> compatible(len, -1);
    for(int i = 0; i < len; ++i) {
      for(int j = i - 1; j >= 0; --j) {
        if(events[index[j]][1] < events[index[i]][0]) {
          compatible[i] = j;
          break;
        }
      }
    }

    int answer = 0;
    for(int i = 0; i < len; ++i) dp[i] = events[index[i]][2];
    for(int i = 1; i < k; ++i) {
      for(int j = len-1; j >= 0; --j) {
        if(compatible[j] != -1) {
          for(int pos = compatible[j]; pos >= 0; --pos) {
            dp[j] = max(dp[j], dp[pos] + events[index[j]][2]);
          }
          
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Accepted
// 67/67 cases passed (314 ms)
// Your runtime beats 82.15 % of cpp submissions
// Your memory usage beats 98.26 % of cpp submissions (51.6 MB)
```
