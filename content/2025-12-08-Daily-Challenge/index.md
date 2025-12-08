+++
updated = 2025-12-08T23:31:47+01:00
title = "2025-12-08 Daily Challenge"
path = "2025-12-08-Daily-Challenge"
date = 2025-12-08T23:31:47+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/count-square-sum-triples/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 8

## Description

**Count Square Sum Triples**

<p>A <strong>square triple</strong> <code>(a,b,c)</code> is a triple where <code>a</code>, <code>b</code>, and <code>c</code> are <strong>integers</strong> and <code>a<sup>2</sup> + b<sup>2</sup> = c<sup>2</sup></code>.</p>

<p>Given an integer <code>n</code>, return <em>the number of <strong>square triples</strong> such that </em><code>1 &lt;= a, b, c &lt;= n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 2
<strong>Explanation</strong>: The square triples are (3,4,5) and (4,3,5).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation</strong>: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 250</code></li>
</ul>


## Solution

``` cpp
constexpr int isqrt(int n) {
  if (n < 0) return -1;
  int x = n;
  int y = (x + 1) / 2;
  while (y < x) {
    x = y;
    y = (x + n / x) / 2;
  }
  return x;
}

// Using std::array is the standard way to return fixed-size arrays in constexpr
constexpr array<int, 251> answer = []() {
  array<int, 251> result{}; // Initialize with 0s

  // Iterate to find Pythagorean triples
  for (int i = 1; i < 250; ++i) {
    for (int j = i + 1; j < 250; ++j) {
      int sum_sq = i * i + j * j;
      
      if (sum_sq >= 251 * 251) break; 

      int k = isqrt((int)sum_sq);

      if (k * k == sum_sq && k < 251) {
        result[k] += 1 + (i != j); 
      }
    }
  }

  for (int i = 1; i < 251; ++i) {
    result[i] += result[i - 1];
  }

  return result;
}();
class Solution {
public:
  int countTriples(int n) {
  return answer[n];
  }
};

// Accepted
// 91/91 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.32 % of cpp submissions (7.8 MB)
```
