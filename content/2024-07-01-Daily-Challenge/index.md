+++
updated = 2024-07-01T19:49:33+08:00
title = "2024-07-01 Daily Challenge"
path = "2024-07-01-Daily-Challenge"
date = 2024-07-01T19:49:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/three-consecutive-odds/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 1

## Description

**Three Consecutive Odds**

Given an integer array <code>arr</code>, return <code>true</code>&nbsp;if there are three consecutive odd numbers in the array. Otherwise, return&nbsp;<code>false</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,6,4,1]
<strong>Output:</strong> false
<b>Explanation:</b> There are no three consecutive odds.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,34,3,4,5,7,23,12]
<strong>Output:</strong> true
<b>Explanation:</b> [5,7,23] are three consecutive odds.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    for(int i = 2; i < arr.size(); ++i) {
      if(arr[i] % 2 == 0) {
        i += 2;
        continue;
      }
      if(arr[i - 1] % 2 == 1 && arr[i - 2] % 2 == 1) return true;
    }  
    return false;
  }
};
```
