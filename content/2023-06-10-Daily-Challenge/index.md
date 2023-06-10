+++
updated = 2023-06-10T12:16:53+08:00
title = "2023-06-10 Daily Challenge"
path = "2023-06-10-Daily-Challenge"
date = 2023-06-10T12:16:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 10

## Description

**Maximum Value at a Given Index in a Bounded Array**

<p>You are given three positive integers:&nbsp;<code>n</code>, <code>index</code>, and <code>maxSum</code>. You want to construct an array <code>nums</code> (<strong>0-indexed</strong>)<strong> </strong>that satisfies the following conditions:</p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>nums[i]</code> is a <strong>positive</strong> integer where <code>0 &lt;= i &lt; n</code>.</li>
	<li><code>abs(nums[i] - nums[i+1]) &lt;= 1</code> where <code>0 &lt;= i &lt; n-1</code>.</li>
	<li>The sum of all the elements of <code>nums</code> does not exceed <code>maxSum</code>.</li>
	<li><code>nums[index]</code> is <strong>maximized</strong>.</li>
</ul>

<p>Return <code>nums[index]</code><em> of the constructed array</em>.</p>

<p>Note that <code>abs(x)</code> equals <code>x</code> if <code>x &gt;= 0</code>, and <code>-x</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4, index = 2,  maxSum = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> nums = [1,2,<u><strong>2</strong></u>,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 6, index = 1,  maxSum = 10
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= maxSum &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= index &lt; n</code></li>
</ul>

## Solution

``` cpp
int64_t S(int64_t h, int64_t l) {
  return (2 * h - l + 1) * l / 2;
}

int FindExtra(int start, int increment, int maxSum) {
  int64_t b = start * 2 / increment - 1;
  int64_t c = 2 * maxSum / increment;

  int64_t d = sqrt(b * b + 4 * c);
  int n = (d - b) / 2;
  return n;
}

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int left = index + 1;
    int right = n - index;
    auto [small, large] = minmax(left, right);

    int64_t A = S(large, large) + S(large, small) - large;
    if(maxSum >= A) {
      return large + (maxSum - A) / n + 1;
    }
    int64_t B = S(small, small) * 2 - small;
    if(maxSum >= B) {
      return small + FindExtra(small * 2, 1, maxSum - B) + 1;
    }
    return FindExtra(1, 2, maxSum) + 1;
  }
};

// Accepted
// 370/370 cases passed (4 ms)
// Your runtime beats 42.79 % of cpp submissions
// Your memory usage beats 46.27 % of cpp submissions (6 MB)
```
