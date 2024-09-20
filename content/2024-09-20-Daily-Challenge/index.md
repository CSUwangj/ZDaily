+++
updated = 2024-09-20T19:51:37+08:00
title = "2024-09-20 Daily Challenge"
path = "2024-09-20-Daily-Challenge"
date = 2024-09-20T19:51:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/shortest-palindrome/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 20

## Description

**Shortest Palindrome**

<p>You are given a string <code>s</code>. You can convert <code>s</code> to a <span data-keyword="palindrome-string">palindrome</span> by adding characters in front of it.</p>

<p>Return <em>the shortest palindrome you can find by performing this transformation</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aacecaaa"
<strong>Output:</strong> "aaacecaaa"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> "dcbabcd"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


## Solution

``` cpp
class Solution {
  int solve(const string &s) {
    string rs = string(s.rbegin(), s.rend());
    string ns = s + '#' + rs;
    vector<int> c(ns.length());
    int i = 1;
    int k = 0;
    while(i < ns.length()) {
      if(ns[i] == ns[k]) {
        k += 1;
        c[i] = k;
        i += 1;
      } else {
        if(k > 0) {
          k = c[k - 1];
        } else {
          c[i] = 0;
          i += 1;
        }
      }
    }
    return c.back();
  }
public:
  string shortestPalindrome(string s) {
    int count = solve(s);
    return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
  }
};
```
