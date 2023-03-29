+++
updated = 2023-03-29T16:36:41+08:00
title = "2023-03-29 Daily Challenge"
path = "2023-03-29-Daily-Challenge"
date = 2023-03-29T16:36:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/reducing-dishes/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 29

## Description

**Reducing Dishes**

<p>A chef has collected data on the <code>satisfaction</code> level of his <code>n</code> dishes. Chef can cook any dish in 1 unit of time.</p>

<p><strong>Like-time coefficient</strong> of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. <code>time[i] * satisfaction[i]</code>.</p>

<p>Return <em>the maximum sum of <strong>like-time coefficient</strong> that the chef can obtain after dishes preparation</em>.</p>

<p>Dishes can b…d in any order, (2*1 + 3*2 + 4*3 = 20)
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> satisfaction = [-1,-4,-5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> People do not like the dishes. No dish is prepared.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == satisfaction.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-1000 &lt;= satisfaction[i] &lt;= 1000</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());

    int answer = 0;
    int count = 0;
    int sum = 0;
    for(auto sat : satisfaction) {
      if(sum + sat < 0) break;
      answer += sum + sat;
      sum += sat;
    }
    return answer;
  }
};
```
