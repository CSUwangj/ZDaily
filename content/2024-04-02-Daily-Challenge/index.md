+++
updated = 2024-04-02T14:20:57+08:00
title = "2024-04-02 Daily Challenge"
path = "2024-04-02-Daily-Challenge"
date = 2024-04-02T14:20:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/isomorphic-strings/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 2

## Description

**Isomorphic Strings**

<p>Given two strings <code>s</code> and <code>t</code>, <em>determine if they are isomorphic</em>.</p>

<p>Two strings <code>s</code> and <code>t</code> are isomorphic if the characters in <code>s</code> can be replaced to get <code>t</code>.</p>

<p>All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "egg", t = "add"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "foo", t = "bar"
<strong>Output:</strong> false
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "paper", t = "title"
<strong>Output:</strong> true
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>s</code> and <code>t</code> consist of any valid ascii character.</li>
</ul>


## Solution

``` cpp
class Solution {
  int mp[128] = {};
  int rev[128] = {};
public:
  bool isIsomorphic(string s, string t) {
    int len = s.length();
    for(int i = 0; i < len; ++i) {
      if(mp[s[i]] && mp[s[i]] != t[i]) return false;
      if(rev[t[i]] && rev[t[i]] != s[i]) return false;
      mp[s[i]] = t[i];
      rev[t[i]] = s[i];
    }
    return true;
  }
};
```
