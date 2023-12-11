+++
updated = 2023-12-11T13:34:13+08:00
title = "2023-12-11 Daily Challenge"
path = "2023-12-11-Daily-Challenge"
date = 2023-12-11T13:34:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 11

## Description

**Element Appearing More Than 25% In Sorted Array**

<p>Given an integer array <strong>sorted</strong> in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,2,6,6,6,6,7,10]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    int current = -1;
    int count = 0;
    for(auto i : arr) {
      if(current != i) {
        count = 0;
        current = i;
      }
      count += 1;
      if(count * 4 > arr.size()) {
        return current;
      }
    }
    return -1;
  }
};

// Accepted
// 25/25 cases passed (8 ms)
// Your runtime beats 78.76 % of cpp submissions
// Your memory usage beats 92.26 % of cpp submissions (12.7 MB)
```
