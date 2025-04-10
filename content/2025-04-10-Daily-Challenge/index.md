+++
updated = 2025-04-10T10:20:38+08:00
title = "2025-04-10 Daily Challenge"
path = "2025-04-10-Daily-Challenge"
date = 2025-04-10T10:20:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-powerful-integers/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 10

## Description

**Count the Number of Powerful Integers**

<p>You are given three integers <code>start</code>, <code>finish</code>, and <code>limit</code>. You are also given a <strong>0-indexed</strong> string <code>s</code> representing a <strong>positive</strong> integer.</p>

<p>A <strong>positive</strong> integer <code>x</code> is called <strong>powerful</strong> if it ends with <code>s</code> (in other words, <code>s</code> is a <strong>suffix</strong> of <code>x</code>) and each digit in <code>x</code> is at most <code>limit</code>.</p>

<p>Return <em>the <strong>total</strong> number of powerful integers in the range</em> <code>[start..finish]</code>.</p>

<p>A string <code>x</code> is a suffix of a string <code>y</code> if and only if <code>x</code> is a substring of <code>y</code> that starts from some index (<strong>including </strong><code>0</code>) in <code>y</code> and extends to the index <code>y.length - 1</code>. For example, <code>25</code> is a suffix of <code>5125</code> whereas <code>512</code> is not.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> start = 1, finish = 6000, limit = 4, s = &quot;124&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit &lt;= 4, and &quot;124&quot; as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
It can be shown that there are only 5 powerful integers in this range.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> start = 15, finish = 215, limit = 6, s = &quot;10&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The powerful integers in the range [15..215] are 110 and 210. All these integers have each digit &lt;= 6, and &quot;10&quot; as a suffix.
It can be shown that there are only 2 powerful integers in this range.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> start = 1000, finish = 2000, limit = 4, s = &quot;3000&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> All integers in the range [1000..2000] are smaller than 3000, hence &quot;3000&quot; cannot be a suffix of any integer in this range.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= start &lt;= finish &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 9</code></li>
	<li><code>1 &lt;= s.length &lt;= floor(log<sub>10</sub>(finish)) + 1</code></li>
	<li><code>s</code> only consists of numeric digits which are at most <code>limit</code>.</li>
	<li><code>s</code> does not have leading zeros.</li>
</ul>


## Solution

``` cpp
class Solution {
  int numLen;
  long long countPowerfulInt(
    const string &num, 
    const string &suffix, 
    const int numLen, 
    const int suffixLen,
    const int limit, 
    vector<vector<long long>> &dp,
    const int index, 
    const int tight
  ) {
    if(index == numLen) return 1;
    if(dp[index][tight] != -1) return dp[index][tight];

    long long count = 0;

    int lowerBound = 0;
    int upperBound = tight ? min(limit, num[index] - '0') : limit;
    int suffixIndex = numLen - suffixLen;
    if(suffixIndex <= index) {
      lowerBound = suffix[index - suffixIndex] - '0';
      upperBound = min(upperBound, suffix[index - suffixIndex] - '0');
    }

    for(int i = lowerBound; i <= upperBound; ++i) {
      count += countPowerfulInt(num, suffix, numLen, suffixLen, limit, dp, index + 1, tight && (i == num[index] - '0'));
    }
    return dp[index][tight] = count;
  }
public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string high = to_string(finish);
    string low = to_string(start - 1);

    long long highResult = 0;
    long long lowResult = 0;
    vector<vector<long long>> dp(17, vector<long long>(2, -1));

    if(s.length() <= high.length()) {
      highResult = countPowerfulInt(high, s, high.length(), s.length(), limit, dp, 0, 1);
    }
    
    dp.assign(17, vector<long long>(2, -1));
    if(s.length() <= low.length()) {
      lowResult = countPowerfulInt(low, s, low.length(), s.length(), limit, dp, 0, 1);
    }

    return highResult - lowResult;
  }
};

// Accepted
// 932/932 cases passed (3 ms)
// Your runtime beats 52.63 % of cpp submissions
// Your memory usage beats 32.75 % of cpp submissions (11 MB)
```
