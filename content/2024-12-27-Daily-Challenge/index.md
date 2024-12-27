+++
updated = 2024-12-27T10:40:09+08:00
title = "2024-12-27 Daily Challenge"
path = "2024-12-27-Daily-Challenge"
date = 2024-12-27T10:40:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/best-sightseeing-pair/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 27

## Description

**Best Sightseeing Pair**

<p>You are given an integer array <code>values</code> where values[i] represents the value of the <code>i<sup>th</sup></code> sightseeing spot. Two sightseeing spots <code>i</code> and <code>j</code> have a <strong>distance</strong> <code>j - i</code> between them.</p>

<p>The score of a pair (<code>i &lt; j</code>) of sightseeing spots is <code>values[i] + values[j] + i - j</code>: the sum of the values of the sightseeing spots, minus the distance between them.</p>

<p>Return <em>the maximum score of a pair of sightseeing spots</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> values = [8,1,5,2,6]
<strong>Output:</strong> 11
<strong>Explanation:</strong> i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> values = [1,2]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= values.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= values[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    priority_queue<int> pq;
    int distance = 0;
    int answer = 0;
    pq.push(-1000);
    for(auto v : values) {
      answer = max(answer, v + pq.top() - distance);
      pq.push(v + distance);
      distance += 1;
    }
    return answer;
  }
};

Accepted
55/55 cases passed (4 ms)
Your runtime beats 23.39 % of cpp submissions
Your memory usage beats 7.51 % of cpp submissions (49.7 MB)
```
