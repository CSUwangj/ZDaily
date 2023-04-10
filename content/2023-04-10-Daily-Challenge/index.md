+++
updated = 2023-04-10T08:15:31+08:00
title = "2023-04-10 Daily Challenge"
path = "2023-04-10-Daily-Challenge"
date = 2023-04-10T08:15:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/valid-parentheses/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 10

## Description

**Valid Parentheses**

<p>Given a string <code>s</code> containing just the characters <code>&#39;(&#39;</code>, <code>&#39;)&#39;</code>, <code>&#39;{&#39;</code>, <code>&#39;}&#39;</code>, <code>&#39;[&#39;</code> and <code>&#39;]&#39;</code>, determine if the input string is valid.</p>

<p>An input string is valid if:</p>

<ol>
	<li>Open brackets must be closed by the same type of brackets.</li>
	<li>Open brackets must be closed in the correct order.</li>
	<li>Every close bracket has a corresponding open bracket of the same type.</li>
</ol>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;()&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;()[]{}&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(]&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of parentheses only <code>&#39;()[]{}&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool isValid(string s) {
    vector<char> st;
    for(auto c : s) {
      switch(c) {
        case '(':
        case '[':
        case '{':
          st.push_back(c);
          break;
        case ')':
          if(st.empty() || st.back() != '(') {
            return false;
          }
          st.pop_back();
          break;
        case ']':
          if(st.empty() || st.back() != '[') {
            return false;
          }
          st.pop_back();
          break;
        case '}':
          if(st.empty() || st.back() != '{') {
            return false;
          }
          st.pop_back();
          break;
        default:
          return false;
      }
    }
    return st.empty();
  }
};

// Accepted
// 93/93 cases passed (2 ms)
// Your runtime beats 46.33 % of cpp submissions
// Your memory usage beats 56.25 % of cpp submissions (6.4 MB)
```
