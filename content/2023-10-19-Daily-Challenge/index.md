+++
updated = 2023-10-19T19:56:21+08:00
title = "2023-10-19 Daily Challenge"
path = "2023-10-19-Daily-Challenge"
date = 2023-10-19T19:56:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/backspace-string-compare/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 19

## Description

**Backspace String Compare**

<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if they are equal when both are typed into empty text editors</em>. <code>&#39;#&#39;</code> means a backspace character.</p>

<p>Note that after backspacing an empty text, the text will continue empty.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab#c&quot;, t = &quot;ad#c&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become &quot;ac&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab##&quot;, t = &quot;c#d#&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become &quot;&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a#c&quot;, t = &quot;b&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> s becomes &quot;c&quot; while t becomes &quot;b&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= s.length, t.length &lt;= 200</span></code></li>
	<li><span><code>s</code> and <code>t</code> only contain lowercase letters and <code>&#39;#&#39;</code> characters.</span></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it in <code>O(n)</code> time and <code>O(1)</code> space?</p>


## Solution

``` cpp
class Solution {
  char nextChar(const string &s, int &pos) {
    int backspace = 0;
    while(pos >= 0 && (backspace || s[pos] == '#')) {
      if(s[pos] == '#') {
        backspace += 1;
      } else {
        backspace -= 1;
      }
      pos -= 1;
    }
    if(pos < 0) return -1;
    return s[pos];
  }
public:
  bool backspaceCompare(string s, string t) {
    int sPos = s.length() - 1;
    int tPos = t.length() - 1;
    while(sPos >= 0 || tPos >= 0) {
      char cS = nextChar(s, sPos);
      char cT = nextChar(t, tPos);
      if(cS != cT) return false;
      sPos -= 1;
      tPos -= 1;
    }
    return true;
  }
};

// Accepted
// 114/114 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 54.78 % of cpp submissions (6.5 MB)
```
