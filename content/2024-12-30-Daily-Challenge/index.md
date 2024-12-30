+++
updated = 2024-12-30T13:56:41+08:00
title = "2024-12-30 Daily Challenge"
path = "2024-12-30-Daily-Challenge"
date = 2024-12-30T13:56:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/count-ways-to-build-good-strings/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 30

## Description

**Count Ways To Build Good Strings**

<p>Given the integers <code>zero</code>, <code>one</code>, <code>low</code>, and <code>high</code>, we can construct a string by starting with an empty string, and then at each step perform either of the following:</p>

<ul>
	<li>Append the character <code>'0'</code> <code>zero</code> times.</li>
	<li>Append the character <code>'1'</code> <code>one</code> times.</li>
</ul>

<p>This can be performed any number of times.</p>

<p>A <strong>good</strong> string is a string constructed by the above process having a <strong>length</strong> between <code>low</code> and <code>high</code> (<strong>inclusive</strong>).</p>

<p>Return <em>the number of <strong>different</strong> good strings that can be constructed satisfying these properties.</em> Since the answer can be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> low = 3, high = 3, zero = 1, one = 1
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
One possible valid good string is "011". 
It can be constructed as follows: "" -&gt; "0" -&gt; "01" -&gt; "011". 
All binary strings from "000" to "111" are good strings in this example.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> low = 2, high = 3, zero = 1, one = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good strings are "00", "11", "000", "110", and "011".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= low&nbsp;&lt;= high&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= zero, one &lt;= low</code></li>
</ul>

## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int dp[high + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = min(zero, one); i <= high; ++i) {
      if(i >= zero) {
        dp[i] += dp[i - zero];
      }
      if(i >= one) {
        dp[i] += dp[i - one];
      }
      dp[i] %= MOD;
    }

    int answer = 0;
    for(int i = low; i <= high; ++i) {
      answer += dp[i];
      answer %= MOD;
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (8 ms)
// Your runtime beats 94.56 % of cpp submissions
// Your memory usage beats 98.28 % of cpp submissions (6.5 MB)
```
