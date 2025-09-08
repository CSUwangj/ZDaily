+++
updated = 2025-09-08T21:26:36+02:00
title = "2025-09-08 Daily Challenge"
path = "2025-09-08-Daily-Challenge"
date = 2025-09-08T21:26:36+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 8

## Description

**Convert Integer to the Sum of Two No-Zero Integers**

<p><strong>No-Zero integer</strong> is a positive integer that <strong>does not contain any <code>0</code></strong> in its decimal representation.</p>

<p>Given an integer <code>n</code>, return <em>a list of two integers</em> <code>[a, b]</code> <em>where</em>:</p>

<ul>
	<li><code>a</code> and <code>b</code> are <strong>No-Zero integers</strong>.</li>
	<li><code>a + b = n</code></li>
</ul>

<p>The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> [1,1]
<strong>Explanation:</strong> Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 11
<strong>Output:</strong> [2,9]
<strong>Explanation:</strong> Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  bool isNonZero(int a) {
    while(a) {
      if(a % 10 == 0) return false;
      a /= 10;
    }
    return true;
  }
public:
  vector<int> getNoZeroIntegers(int n) {
    vector<int> answer(2);
    for(int i = 1; i * 2 <= n; ++i) {
      if(isNonZero(i) && isNonZero(n - i)) {
        answer[0] = i;
        answer[1] = n - i;
      }
    }
    return answer;
  }
};

// Accepted
// 207/207 cases passed (1 ms)
// Your runtime beats 10.1 % of cpp submissions
// Your memory usage beats 85.27 % of cpp submissions (8.2 MB)
```
