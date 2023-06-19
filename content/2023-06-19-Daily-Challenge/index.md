+++
updated = 2023-06-19T15:52:38+08:00
title = "2023-06-19 Daily Challenge"
path = "2023-06-19-Daily-Challenge"
date = 2023-06-19T15:52:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/find-the-highest-altitude/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 19

## Description

**Find the Highest Altitude**

<p>There is a biker going on a road trip. The road trip consists of <code>n + 1</code> points at different altitudes. The biker starts his trip on point <code>0</code> with altitude equal <code>0</code>.</p>

<p>You are given an integer array <code>gain</code> of length <code>n</code> where <code>gain[i]</code> is the <strong>net gain in altitude</strong> between points <code>i</code>​​​​​​ and <code>i + 1</code> for all (<code>0 &lt;= i &lt; n)</code>. Return <em>the <strong>highest altitude</strong> of a point.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> gain = [-5,1,5,0,-7]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> gain = [-4,-3,-2,-1,4,3,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == gain.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= gain[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int a = 0;
    int answer = 0;
    for(auto i : gain) {
      a += i;
      answer = max(a, answer);
    }
    return answer;
  }
};

// Accepted
// 80/80 cases passed (6 ms)
// Your runtime beats 28.46 % of cpp submissions
// Your memory usage beats 93.43 % of cpp submissions (7.9 MB)
```
