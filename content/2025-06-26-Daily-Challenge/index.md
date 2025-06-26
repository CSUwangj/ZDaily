+++
updated = 2025-06-27T03:58:12+08:00
title = "2025-06-26 Daily Challenge"
path = "2025-06-26-Daily-Challenge"
date = 2025-06-27T03:58:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 26

## Description

**Longest Binary Subsequence Less Than or Equal to K**

<p>You are given a binary string <code>s</code> and a positive integer <code>k</code>.</p>

<p>Return <em>the length of the <strong>longest</strong> subsequence of </em><code>s</code><em> that makes up a <strong>binary</strong> number less than or equal to</em> <code>k</code>.</p>

<p>Note:</p>

<ul>
	<li>The subsequence can contain <strong>leading zeroes</strong>.</li>
	<li>The empty string is considered to be equal to <code>0</code>.</li>
	<li>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1001010&quot;, k = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence of s that makes up a binary number less than or equal to 5 is &quot;00010&quot;, as this number is equal to 2 in decimal.
Note that &quot;00100&quot; and &quot;00101&quot; are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;00101001&quot;, k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> &quot;000001&quot; is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestSubsequence(string s, int k) {
    reverse(s.begin(), s.end());
    int current = 0;
    int exp = 1;
    int answer = 0;
    for(auto c : s) {
      if(c == '1') {
        if(exp > k || exp + current > k) continue;
        current += exp;
        answer += 1;
      } else {
        answer += 1;
      }
      if(INT_MAX / 2 > exp) exp *= 2;
    }
    return answer;
  }
};

// Accepted
// 153/153 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50.75 % of cpp submissions (9.5 MB)
```
