+++
updated = 2024-10-05T08:21:01+08:00
title = "2024-10-05 Daily Challenge"
path = "2024-10-05-Daily-Challenge"
date = 2024-10-05T08:21:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/permutation-in-string/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 5

## Description

**Permutation in String**

<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code> if <code>s2</code> contains a <span data-keyword="permutation-string">permutation</span> of <code>s1</code>, or <code>false</code> otherwise.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>&#39;s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;ab&quot;, s2 = &quot;eidbaooo&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 (&quot;ba&quot;).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;ab&quot;, s2 = &quot;eidboaoo&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    map<char, int> count;
    for(auto c : s1) {
      count[c] += 1;
    }
    int len1 = s1.length();
    for(int i = 0; i < len1; ++i) {
      count[s2[i]] -= 1;
      if(!count[s2[i]]) count.erase(s2[i]);
    }
    if(count.empty()) return true;
    for(int i = s1.length(); i < s2.length(); ++i) {
      count[s2[i - len1]] += 1;
      if(!count[s2[i - len1]]) count.erase(s2[i - len1]);
      count[s2[i]] -= 1;
      if(!count[s2[i]]) count.erase(s2[i]);
      if(count.empty()) return true;
    }
    return false;
  }
};
```
