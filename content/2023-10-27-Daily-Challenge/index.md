+++
updated = 2023-10-27T12:37:58+08:00
title = "2023-10-27 Daily Challenge"
path = "2023-10-27-Daily-Challenge"
date = 2023-10-27T12:37:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/max-dot-product-of-two-subsequences) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 27

## Description

**Longest Palindromic Substring**

<p>Given a string <code>s</code>, return <em>the longest</em> <span data-keyword="palindromic-string"><em>palindromic</em></span> <span data-keyword="substring-nonempty"><em>substring</em></span> in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;babad&quot;
<strong>Output:</strong> &quot;bab&quot;
<strong>Explanation:</strong> &quot;aba&quot; is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbbd&quot;
<strong>Output:</strong> &quot;bb&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consist of only digits and English letters.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    int answer = 1;
    int begin = 0;
    for(int i = 0; i < len; ++i) {
      int left = i, right = i;
      while(left > 0 && right < len && s[left-1] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left > answer) {
        answer = right - left;
        begin = left;
      }
      left = i, right = i;
      while(left >= 0 && right < len && s[left] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left - 1 > answer) {
        answer = right - left - 1;
        begin = left + 1;
      }
      
    }
    return s.substr(begin, answer);
  }
};

// Accepted
// 180/180 cases passed (34 ms)
// Your runtime beats 76.7 % of cpp submissions
// Your memory usage beats 81.58 % of cpp submissions (7.2 MB)
```
