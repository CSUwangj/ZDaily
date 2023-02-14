+++
updated = 2023-02-14T14:48:58+08:00
title = "2023-02-14 Daily Challenge"
path = "2023-02-14-Daily-Challenge"
date = 2023-02-14T14:48:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/add-binary/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 14

## Description

**Add Binary**

<p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> and <code>b</code> consist&nbsp;only of <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code> characters.</li>
	<li>Each string does not contain leading zeros except for the zero itself.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string addBinary(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pos = 0;
    int carry = 0;
    string answer;
    for(; pos < len1 && pos < len2; ++pos) {
      int result = a[pos] + b[pos] + carry;
      answer.push_back('0' + (result & 1));
      carry = ((result >> 1) & 1);
    }
    int len = len1;
    string *target = &a;
    if(len1 < len2) {
      len = len2;
      target = &b;
    }
    while(carry && pos < len) {
      if((*target)[pos++] == '1') {
        answer.push_back('0');
      } else {
        answer.push_back('1');
        carry = 0;
      }
    }
    while(pos < len) {
      answer.push_back((*target)[pos++]);
    }
    if(carry) {
      answer.push_back('1');
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 294/294 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.62 % of cpp submissions (6.1 MB)
```
