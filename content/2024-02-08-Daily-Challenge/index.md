+++
updated = 2024-02-08T14:24:14+08:00
title = "2024-02-08 Daily Challenge"
path = "2024-02-08-Daily-Challenge"
date = 2024-02-08T14:24:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/perfect-squares/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 8

## Description

**Perfect Squares**

<p>Given an integer <code>n</code>, return <em>the least number of perfect square numbers that sum to</em> <code>n</code>.</p>

<p>A <strong>perfect square</strong> is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, <code>1</code>, <code>4</code>, <code>9</code>, and <code>16</code> are perfect squares while <code>3</code> and <code>11</code> are not.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 12
<strong>Output:</strong> 3
<strong>Explanation:</strong> 12 = 4 + 4 + 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 13
<strong>Output:</strong> 2
<strong>Explanation:</strong> 13 = 4 + 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int answer[10001];
auto _ = [](){
  for(int i = 1; i < 10001; ++i) {
    answer[i] = INT_MAX;
    int bound = sqrt(i);
    for(int j = 1; j <= bound; ++j) {
      answer[i] = min(answer[i], answer[i - j * j] + 1);
    }
  }
  return 0;
}();
class Solution {
public:
  int numSquares(int n) {
    return answer[n];
  }
};

// Accepted
// 588/588 cases passed (4 ms)
// Your runtime beats 98.05 % of cpp submissions
// Your memory usage beats 95 % of cpp submissions (6 MB)
```
