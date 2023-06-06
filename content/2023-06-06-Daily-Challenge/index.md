+++
updated = 2023-06-06T08:12:14+08:00
title = "2023-06-06 Daily Challenge"
path = "2023-06-06-Daily-Challenge"
date = 2023-06-06T08:12:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 6

## Description

**Can Make Arithmetic Progression From Sequence**

<p>A sequence of numbers is called an <strong>arithmetic progression</strong> if the difference between any two consecutive elements is the same.</p>

<p>Given an array of numbers <code>arr</code>, return <code>true</code> <em>if the array can be rearranged to form an <strong>arithmetic progression</strong>. Otherwise, return</em> <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [3,5,1]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,4]
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reorder the elements to obtain an arithmetic progression.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup> &lt;= arr[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for(int i = 2; i < arr.size(); ++i) {
      if(arr[i] - arr[i - 1] != diff) return false;
    }
    return true;
  }
};

// Accepted
// 109/109 cases passed (9 ms)
// Your runtime beats 22.98 % of cpp submissions
// Your memory usage beats 28.46 % of cpp submissions (9.1 MB)
```
