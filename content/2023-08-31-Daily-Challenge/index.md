+++
updated = 2023-08-31T21:48:10+08:00
title = "2023-08-31 Daily Challenge"
path = "2023-08-31-Daily-Challenge"
date = 2023-08-31T21:48:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 31

## Description

**Minimum Number of Taps to Open to Water a Garden**

<p>There is a one-dimensional garden on the x-axis. The garden starts at the point <code>0</code> and ends at the point <code>n</code>. (i.e The length of the garden is <code>n</code>).</p>

<p>There are <code>n + 1</code> taps located at points <code>[0, 1, ..., n]</code> in the garden.</p>

<p>Given an integer <code>n</code> and an integer array <code>ranges</code> of length <code>n + 1</code> where <code>ranges[i]</code> (0-indexed) means the <code>i-th</code> tap can water the area <code>[i - ranges[i], i + ranges[i]]</code> if it was open.</p>

<p>Return <em>the minimum number of taps</em> that should be open to water the whole garden, If the garden cannot be watered return <strong>-1</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/1685_example_1.png" style="width: 525px; height: 255px;" />
<pre>
<strong>Input:</strong> n = 5, ranges = [3,4,1,1,0,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, ranges = [0,0,0,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> Even if you activate all the four taps you cannot water the whole garden.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>ranges.length == n + 1</code></li>
	<li><code>0 &lt;= ranges[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> right(n + 1);
    for(int i = 0; i <= n; ++i) {
      if(!ranges[i]) continue;
      int left = max(i - ranges[i], 0);
      if(right[left] < i + ranges[i]) {
        right[left] = i + ranges[i];
      }
    }
    int count = 0;
    int rightMost = 0;
    int end = 0;
    for(int i = 0; i <= n; ++i) {
      if(end < i) {
        if(rightMost <= end) return -1;
        end = rightMost;
        count += 1;
      }
      rightMost = max(rightMost, right[i]);
    }

    return count + (end < n);
  }
};

// Accepted
// 38/38 cases passed (14 ms)
// Your runtime beats 85.18 % of cpp submissions
// Your memory usage beats 55.15 % of cpp submissions (14.6 MB)
```
