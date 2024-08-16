+++
updated = 2024-08-16T16:22:50+08:00
title = "2024-08-16 Daily Challenge"
path = "2024-08-16-Daily-Challenge"
date = 2024-08-16T16:22:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/maximum-distance-in-arrays/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 16

## Description

**Maximum Distance in Arrays**

<p>You are given <code>m</code> <code>arrays</code>, where each array is sorted in <strong>ascending order</strong>.</p>

<p>You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers <code>a</code> and <code>b</code> to be their absolute difference <code>|a - b|</code>.</p>

<p>Return <em>the maximum distance</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arrays = [[1,2,3],[4,5],[1,2,3]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arrays = [[1],[1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == arrays.length</code></li>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrays[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= arrays[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>arrays[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>There will be at most <code>10<sup>5</sup></code> integers in all the arrays.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int mmin = arrays.front().front();
    int mmax = arrays.front().back();
    int answer = 0;
    for(int i = 1; i < arrays.size(); ++i) {
      answer = max(answer, abs(arrays[i].front() - mmax));
      answer = max(answer, abs(arrays[i].back() - mmin));
      mmin = min(mmin, arrays[i].front());
      mmax = max(mmax, arrays[i].back());
    }

    return answer;
  }
};
```
