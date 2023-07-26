+++
updated = 2023-07-26T12:04:29+08:00
title = "2023-07-26 Daily Challenge"
path = "2023-07-26-Daily-Challenge"
date = 2023-07-26T12:04:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 26

## Description

**Minimum Speed to Arrive on Time**

<p>You are given a floating-point number <code>hour</code>, representing the amount of time you have to reach the office. To commute to the office, you must take <code>n</code> trains in sequential order. You are also given an integer array <code>dist</code> of length <code>n</code>, where <code>dist[i]</code> describes the distance (in kilometers) of the <code>i<sup>th</sup></code> train ride.</p>

<p>Each train can only depart at an integer hour, so you may need to wait in between each train ride.</p>

<ul>
	<li>For example, if the <code>1<sup>st</sup></code> train ride takes <code>1.5</code> hours, you must wait for an additional <code>0.5</code> hours before you can depart on the <code>2<sup>nd</sup></code> train ride at the 2 hour mark.</li>
</ul>

<p>Return <em>the <strong>minimum positive integer</strong> speed <strong>(in kilometers per hour)</strong> that all the trains must travel at for you to reach the office on time, or </em><code>-1</code><em> if it is impossible to be on time</em>.</p>

<p>Tests are generated such that the answer will not exceed <code>10<sup>7</sup></code> and <code>hour</code> will have <strong>at most two digits after the decimal point</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dist = [1,3,2], hour = 6
<strong>Output:</strong> 1
<strong>Explanation: </strong>At speed 1:
- The first train ride takes 1/1 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 1 hour mark. The second train takes 3/1 = 3 hours.
- Since we are already at an integer hour, we depart immediately at the 4 hour mark. The third train takes 2/1 = 2 hours.
- You will arrive at exactly the 6 hour mark.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dist = [1,3,2], hour = 2.7
<strong>Output:</strong> 3
<strong>Explanation: </strong>At speed 3:
- The first train ride takes 1/3 = 0.33333 hours.
- Since we are not at an integer hour, we wait until the 1 hour mark to depart. The second train ride takes 3/3 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
- You will arrive at the 2.66667 hour mark.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> dist = [1,3,2], hour = 1.9
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible because the earliest the third train can depart is at the 2 hour mark.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == dist.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= dist[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= hour &lt;= 10<sup>9</sup></code></li>
	<li>There will be at most two digits after the decimal point in <code>hour</code>.</li>
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
  const double EPS = 1e-10;
  bool satisfy(const vector<int>& dist, double hour, double speed) {
    double result = 0;
    for(int i = 0; i + 1 < dist.size(); ++i) {
      result += max<double>(1, ceil(dist[i] / speed));
    }
    result += dist.back() / speed;
    return result <= hour;
  }
public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    if(dist.size() > hour + 1) return -1;
    int high = 100000000;
    int low = 0;
    while(high > low) {
      double mid = (high + low) / 2;
      if(satisfy(dist, hour, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low > 1e7 ? -1 : low;
  }
};

// Accepted
// 65/65 cases passed (275 ms)
// Your runtime beats 92.81 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (101.1 MB)
```
