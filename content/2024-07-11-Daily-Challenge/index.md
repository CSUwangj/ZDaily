+++
updated = 2024-07-11T18:47:33+08:00
title = "2024-07-11 Daily Challenge"
path = "2024-07-11-Daily-Challenge"
date = 2024-07-11T18:47:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 11

## Description

**Reverse Substrings Between Each Pair of Parentheses**

<p>You are given a string <code>s</code> that consists of lower case English letters and brackets.</p>

<p>Reverse the strings in each pair of matching parentheses, starting from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any brackets.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(abcd)&quot;
<strong>Output:</strong> &quot;dcba&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(u(love)i)&quot;
<strong>Output:</strong> &quot;iloveu&quot;
<strong>Explanation:</strong> The substring &quot;love&quot; is reversed first, then the whole string is reversed.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(ed(et(oc))el)&quot;
<strong>Output:</strong> &quot;leetcode&quot;
<strong>Explanation:</strong> First, we reverse the substring &quot;oc&quot;, then &quot;etco&quot;, and finally, the whole string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It is guaranteed that all parentheses are balanced.</li>
</ul>


## Solution

``` cpp
class Solution {
  string helper(string &s, int &pos, bool r = false) {
    string result;
    for(int i = pos; pos < s.length() && s[pos] != ')'; ++pos) {
      if(s[pos] != '(') {
        result.push_back(s[pos]);
      } else {
        pos += 1;
        result += helper(s, pos, true);
      }
    }
    if(r) reverse(result.begin(), result.end());
    return result;
  }
public:
  string reverseParentheses(string s) {
    int pos = 0;
    string answer;
    while(pos < s.length()) {
      answer += helper(s, pos);
      pos += 1;
    }
    return answer;
  }
};
```
