+++
updated = 2023-03-03T08:47:53+08:00
title = "2023-03-03 Daily Challenge"
path = "2023-03-03-Daily-Challenge"
date = 2023-03-03T08:47:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 3

## Description

**Find the Index of the First Occurrence in a String**

<p>Given two strings <code>needle</code> and <code>haystack</code>, return the index of the first occurrence of <code>needle</code> in <code>haystack</code>, or <code>-1</code> if <code>needle</code> is not part of <code>haystack</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> haystack = &quot;sadbutsad&quot;, needle = &quot;sad&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> &quot;sad&quot; occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> haystack = &quot;leetcode&quot;, needle = &quot;leeto&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> &quot;leeto&quot; did not occur in &quot;leetcode&quot;, so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= haystack.length, needle.length &lt;= 10<sup>4</sup></code></li>
	<li><code>haystack</code> and <code>needle</code> consist of only lowercase English characters.</li>
</ul>


## Solution

``` cpp
class KMP {
  vector<int> table{-1};
  string pattern;
  int patternLen;
public:
  KMP(string &pattern): pattern(pattern) {
    patternLen = pattern.length();
    table.resize(patternLen);
    int pos = 1;
    int cnd = 0;
    while(pos < patternLen) {
      if(pattern[pos] == pattern[cnd]) {
        table[pos] = table[cnd];
      } else {
        table[pos] = cnd;
        while(cnd >= 0 && pattern[pos] != pattern[cnd]) {
          cnd = table[cnd];
        }
      }
      pos += 1;
      cnd += 1;
    }
  }

  int search(const string &s) const {
    int posPattern = 0;
    int posStr = 0;
    int len = s.length();
    while(posStr < len) {
      if(s[posStr] == pattern[posPattern]) {
        posStr += 1;
        posPattern += 1;
        if(posPattern == patternLen) return posStr - patternLen;
      } else {
        posPattern = table[posPattern];
        if(posPattern < 0) {
          posPattern += 1;
          posStr += 1;
        }
      }
    }
    return -1;
  }
};

class Solution {
public:
  int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    if(needle.length() > haystack.length()) return -1;
    return KMP(needle).search(haystack);
  }
};

// Accepted
// 79/79 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.81 % of cpp submissions (6.3 MB)
```
