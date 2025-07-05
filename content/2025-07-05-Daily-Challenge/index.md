+++
updated = 2025-07-06T04:16:26+08:00
title = "2025-07-05 Daily Challenge"
path = "2025-07-05-Daily-Challenge"
date = 2025-07-06T04:16:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-lucky-integer-in-an-array/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 5

## Description

**Find Lucky Integer in an Array**

<p>Given an array of integers <code>arr</code>, a <strong>lucky integer</strong> is an integer that has a frequency in the array equal to its value.</p>

<p>Return <em>the largest <strong>lucky integer</strong> in the array</em>. If there is no <strong>lucky integer</strong> return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,2,3,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only lucky number in the array is 2 because frequency[2] == 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,2,3,3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 1, 2 and 3 are all lucky numbers, return the largest of them.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,2,2,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no lucky numbers in the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 500</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findLucky(vector<int>& arr) {
    map<int, int> count;
    for(auto n : arr) count[n] += 1;
    int answer = -1;
    for(auto [n, c] : count) {
      if(n == c) answer = n;
    }
    return answer;
  }
};

// Accepted
// 101/101 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 37.37 % of cpp submissions (13.9 MB)
```
