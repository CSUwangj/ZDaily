+++
updated = 2023-11-09T19:35:47+08:00
title = "2023-11-09 Daily Challenge"
path = "2023-11-09-Daily-Challenge"
date = 2023-11-09T19:35:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/count-number-of-homogenous-substrings/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 9

## Description

**Count Number of Homogenous Substrings**

<p>Given a string <code>s</code>, return <em>the number of <strong>homogenous</strong> substrings of </em><code>s</code><em>.</em> Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A string is <strong>homogenous</strong> if all the characters of the string are the same.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abbcccaa&quot;
<strong>Output:</strong> 13
<strong>Explanation:</strong> The homogenous substrings are listed as below:
&quot;a&quot;   appears 3 times.
&quot;aa&quot;  appears 1 time.
&quot;b&quot;   appears 2 times.
&quot;bb&quot;  appears 1 time.
&quot;c&quot;   appears 3 times.
&quot;cc&quot;  appears 2 times.
&quot;ccc&quot; appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;xy&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The homogenous substrings are &quot;x&quot; and &quot;y&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;zzzzz&quot;
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase letters.</li>
</ul>

## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int countHomogenous(string s) {
    int count = 0;
    int answer = 0;
    int current = s.front();
    for(auto c : s) {
      if(current == c) {
        count += 1;
      } else {
        answer += 1LL * count * (count + 1) / 2 % MOD;
        answer %= MOD;
        count = 1;
        current = c;
      }
    }
    answer += 1LL * count * (count + 1) / 2 % MOD;
    answer %= MOD;
    return answer;
  }
};

// Accepted
// 84/84 cases passed (24 ms)
// Your runtime beats 71.96 % of cpp submissions
// Your memory usage beats 53.48 % of cpp submissions (12 MB)
```
