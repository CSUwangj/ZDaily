+++
updated = 2023-08-21T12:52:32+08:00
title = "2023-08-21 Daily Challenge"
path = "2023-08-21-Daily-Challenge"
date = 2023-08-21T12:52:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/repeated-substring-pattern/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 21

## Description

**Repeated Substring Pattern**

<p>Given a string <code>s</code>, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abab&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring &quot;ab&quot; twice.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aba&quot;
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcabcabcabc&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring &quot;abc&quot; four times or the substring &quot;abcabc&quot; twice.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    if(len == 1) return false;
    vector<int> factors;
    for(int i = 1; i * i <= len; ++i) {
      if(len % i == 0) {
        factors.push_back(i);
        if(i * i != len && i != 1) factors.push_back(len / i);
      }
    }
    for(auto factor : factors) {
      bool ok = true;
      for(int pos = factor; pos < len && ok; ++pos) {
        if(s[pos % factor] != s[pos]) {
          ok = false;
        }
      }
      if(ok) return true;
    }
    return false;
  }
};

// Accepted
// 129/129 cases passed (18 ms)
// Your runtime beats 67.67 % of cpp submissions
// Your memory usage beats 93.58 % of cpp submissions (9.4 MB)
```
