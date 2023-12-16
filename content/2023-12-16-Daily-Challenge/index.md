+++
updated = 2023-12-16T11:30:49+08:00
title = "2023-12-16 Daily Challenge"
path = "2023-12-16-Daily-Challenge"
date = 2023-12-16T11:30:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/valid-anagram/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 16

## Description

**Valid Anagram**

<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if</em> <code>t</code> <em>is an anagram of</em> <code>s</code><em>, and</em> <code>false</code> <em>otherwise</em>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "anagram", t = "nagaram"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "rat", t = "car"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if the inputs contain Unicode characters? How would you adapt your solution to such a case?</p>


## Solution

``` cpp
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> sc(26);
    vector<int> tc(26);
    for(auto c : s) sc[c - 'a'] += 1;
    for(auto c : t) tc[c - 'a'] += 1;
    return sc == tc;
  }
};

// Accepted
// 42/42 cases passed (7 ms)
// Your runtime beats 76.44 % of cpp submissions
// Your memory usage beats 20.94 % of cpp submissions (7.9 MB)
```
