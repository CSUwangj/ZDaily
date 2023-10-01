+++
updated = 2023-10-01T10:28:23+08:00
title = "2023-10-01 Daily Challenge"
path = "2023-10-01-Daily-Challenge"
date = 2023-10-01T10:28:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/reverse-words-in-a-string-iii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 1

## Description

**Reverse Words in a String III**

<p>Given a string <code>s</code>, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "Let's take LeetCode contest"
<strong>Output:</strong> "s'teL ekat edoCteeL tsetnoc"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "God Ding"
<strong>Output:</strong> "doG gniD"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> contains printable <strong>ASCII</strong> characters.</li>
	<li><code>s</code> does not contain any leading or trailing spaces.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
	<li>All the words in <code>s</code> are separated by a single space.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string reverseWords(string s) {
    bool isSpace = true;
    int start = -1;
    for (int i = 0; i < s.length(); ++i) {
      if(isSpace && s[i] != ' ') {
        start = i;
      } else if(!isSpace && s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
      }
      isSpace = s[i] == ' ';
    }
    if(!isSpace) reverse(s.begin() + start, s.end());
    return s;
  }
};

// Accepted
// 29/29 cases passed (13 ms)
// Your runtime beats 74.16 % of cpp submissions
// Your memory usage beats 59.58 % of cpp submissions (9.9 MB)
```
