+++
updated = 2025-04-11T12:35:34+08:00
title = "2025-04-11 Daily Challenge"
path = "2025-04-11-Daily-Challenge"
date = 2025-04-11T12:35:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-symmetric-integers/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 11

## Description

**Count Symmetric Integers**

<p>You are given two positive integers <code>low</code> and <code>high</code>.</p>

<p>An integer <code>x</code> consisting of <code>2 * n</code> digits is <strong>symmetric</strong> if the sum of the first <code>n</code> digits of <code>x</code> is equal to the sum of the last <code>n</code> digits of <code>x</code>. Numbers with an odd number of digits are never symmetric.</p>

<p>Return <em>the <strong>number of symmetric</strong> integers in the range</em> <code>[low, high]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> low = 1, high = 100
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 1200, high = 1230
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  static vector<int> result;
public:
  int countSymmetricIntegers(int low, int high) {
    return result[high] - result[low - 1];
  }
};

vector<int> Solution::result = []() {
  vector<int> result(10001);
  for(int i = 11; i < 10001; ++i) {
    result[i] = result[i - 1];
    if((i < 100 && i / 10 == i % 10) || (i > 1000 && (i / 1000 + i / 100 % 10 == i % 10 + i / 10 % 10))) result[i] += 1; 
  }
  return result;
}();

// Accepted
// 1967/1967 cases passed (4 ms)
// Your runtime beats 91.74 % of cpp submissions
// Your memory usage beats 84.15 % of cpp submissions (9.6 MB)
```
