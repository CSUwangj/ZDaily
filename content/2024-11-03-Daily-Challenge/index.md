+++
updated = 2024-11-03T10:40:43+08:00
title = "2024-11-03 Daily Challenge"
path = "2024-11-03-Daily-Challenge"
date = 2024-11-03T10:40:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/rotate-string/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 3

## Description

**Rotate String**

<p>Given two strings <code>s</code> and <code>goal</code>, return <code>true</code> <em>if and only if</em> <code>s</code> <em>can become</em> <code>goal</code> <em>after some number of <strong>shifts</strong> on</em> <code>s</code>.</p>

<p>A <strong>shift</strong> on <code>s</code> consists of moving the leftmost character of <code>s</code> to the rightmost position.</p>

<ul>
	<li>For example, if <code>s = &quot;abcde&quot;</code>, then it will be <code>&quot;bcdea&quot;</code> after one shift.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "cdeab"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "abced"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 100</code></li>
	<li><code>s</code> and <code>goal</code> consist of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool rotateString(string s, string goal) {
    if(s.length() != goal.length()) return false;
    for(int i = 0; i < s.length(); ++i) {
      if(s.substr(i) + s.substr(0, i) == goal) return true;
    }
    return false;
  } 
};
```
