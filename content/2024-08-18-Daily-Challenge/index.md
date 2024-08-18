+++
updated = 2024-08-18T13:14:00+08:00
title = "2024-08-18 Daily Challenge"
path = "2024-08-18-Daily-Challenge"
date = 2024-08-18T13:14:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/ugly-number-ii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 18

## Description

**Ugly Number II**

<p>An <strong>ugly number</strong> is a positive integer whose prime factors are limited to <code>2</code>, <code>3</code>, and <code>5</code>.</p>

<p>Given an integer <code>n</code>, return <em>the</em> <code>n<sup>th</sup></code> <em><strong>ugly number</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 12
<strong>Explanation:</strong> [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1690</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int nthUglyNumber(int n) {
    int dp[n];
    dp[0] = 1;
    int two = 0, three = 0, five = 0;
    int cnt = 1;
    while(cnt < n) {
      int new_two = dp[two]*2;
      int new_three = dp[three]*3;
      int new_five = dp[five]*5;
      int new_num = min({new_two, new_three, new_five});
      if(new_two == new_num) two += 1;
      if(new_three == new_num) three += 1;
      if(new_five == new_num) five += 1;
      dp[cnt++] = new_num;
    }
    return dp[n - 1];
  }
};
```
