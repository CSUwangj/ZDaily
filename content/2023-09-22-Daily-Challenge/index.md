+++
updated = 2023-09-22T11:23:40+08:00
title = "2023-09-22 Daily Challenge"
path = "2023-09-22-Daily-Challenge"
date = 2023-09-22T11:23:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/is-subsequence/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 22

## Description

**Is Subsequence**

<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code><em> if </em><code>s</code><em> is a <strong>subsequence</strong> of </em><code>t</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>&quot;ace&quot;</code> is a subsequence of <code>&quot;<u>a</u>b<u>c</u>d<u>e</u>&quot;</code> while <code>&quot;aec&quot;</code> is not).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abc", t = "ahbgdc"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "axc", t = "ahbgdc"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= t.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> and <code>t</code> consist only of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Suppose there are lots of incoming <code>s</code>, say <code>s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub></code> where <code>k &gt;= 10<sup>9</sup></code>, and you want to check one by one to see if <code>t</code> has its subsequence. In this scenario, how would you change your code?

## Solution

``` cpp
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sLen = s.length();
    int tLen = t.length();
    if(sLen > tLen) return false;
    int sPos = 0;
    int tPos = 0;
    while(sPos < sLen && tPos < tLen) {
      if(s[sPos] == t[tPos]) {
        sPos += 1;
      }
      tPos += 1;
    }
    return sPos == sLen;
  }
};

// Accepted
// 19/19 cases passed (3 ms)
// Your runtime beats 49.1 % of cpp submissions
// Your memory usage beats 12.75 % of cpp submissions (6.7 MB)
```
