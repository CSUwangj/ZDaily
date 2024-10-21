+++
updated = 2024-10-21T10:15:03+08:00
title = "2024-10-21 Daily Challenge"
path = "2024-10-21-Daily-Challenge"
date = 2024-10-21T10:15:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 21

## Description

**Split a String Into the Max Number of Unique Substrings**

<p>Given a string&nbsp;<code>s</code><var>,</var>&nbsp;return <em>the maximum&nbsp;number of unique substrings that the given string can be split into</em>.</p>

<p>You can split string&nbsp;<code>s</code> into any list of&nbsp;<strong>non-empty substrings</strong>, where the concatenation of the substrings forms the original string.&nbsp;However, you must split the substrings such that all of them are <strong>unique</strong>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ababccc&quot;
<strong>Output:</strong> 5
<strong>Explanation</strong>: One way to split maximally is [&#39;a&#39;, &#39;b&#39;, &#39;ab&#39;, &#39;c&#39;, &#39;cc&#39;]. Splitting like [&#39;a&#39;, &#39;b&#39;, &#39;a&#39;, &#39;b&#39;, &#39;c&#39;, &#39;cc&#39;] is not valid as you have &#39;a&#39; and &#39;b&#39; multiple times.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aba&quot;
<strong>Output:</strong> 2
<strong>Explanation</strong>: One way to split maximally is [&#39;a&#39;, &#39;ba&#39;].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;
<strong>Output:</strong> 1
<strong>Explanation</strong>: It is impossible to split the string any further.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 16</code></p>
	</li>
	<li>
	<p><code>s</code> contains&nbsp;only lower case English letters.</p>
	</li>
</ul>


## Solution

``` cpp
class Solution {
  int maxCount = 0;
  int len;
  unordered_set<string_view> sequences;
  void solve(int pos, int count, string &s) {
    if(len - pos < maxCount - count) return;
    if(pos >= len) {
      maxCount = max(maxCount, count);
      return;
    }
    for(int i = 0; i + pos < len; ++i) {
      string_view t(s.data() + pos, i + 1);
      if(sequences.count(t)) continue;
      sequences.insert(t);
      solve(pos + i + 1, count + 1, s);
      sequences.erase(t);
    }
  }
public:
  int maxUniqueSplit(string s) {
    len = s.length();
    solve(0, 0, s);
    return maxCount;
  }
};
```
