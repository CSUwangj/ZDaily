+++
updated = 2022-03-25 18:54:00+08:00
title = "2022-03-25 Daily-Challenge"
path = "2022-03-25-Daily-Challenge"
date = 2022-03-25 18:53:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/two-city-scheduling/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 25

## Description

**Two City Scheduling**

<p>A company is planning to interview <code>2n</code> people. Given the array <code>costs</code> where <code>costs[i] = [aCost<sub>i</sub>, bCost<sub>i</sub>]</code>,&nbsp;the cost of flying the <code>i<sup>th</sup></code> person to city <code>a</code> is <code>aCost<sub>i</sub></code>, and the cost of flying the <code>i<sup>th</sup></code> person to city <code>b</code> is <code>bCost<sub>i</sub></code>.</p>

<p>Return <em>the minimum cost to fly every person to a city</em> such that exactly <code>n</code> people arrive in each city.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> costs = [[10,20],[30,200],[400,50],[30,20]]
<strong>Output:</strong> 110
<strong>Explanation: </strong>
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
<strong>Output:</strong> 1859
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
<strong>Output:</strong> 3086
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 * n == costs.length</code></li>
	<li><code>2 &lt;= costs.length &lt;= 100</code></li>
	<li><code>costs.length</code> is even.</li>
	<li><code>1 &lt;= aCost<sub>i</sub>, bCost<sub>i</sub> &lt;= 1000</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] - a[1] < b[0] - b[1];
    });
    int len = costs.size();
    int answer = 0;
    for(int i = 0; i * 2 < len; ++i) {
      answer += costs[i][0] + costs[len - 1 - i][1];
    }
    return answer;
  }
};

// Accepted
// 50/50 cases passed (4 ms)
// Your runtime beats 78.71 % of cpp submissions
// Your memory usage beats 78.35 % of cpp submissions (7.9 MB)
```
