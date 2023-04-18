+++
updated = 2023-04-18T14:24:55+08:00
title = "2023-04-18 Daily Challenge"
path = "2023-04-18-Daily-Challenge"
date = 2023-04-18T14:24:55+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/merge-strings-alternately/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 18

## Description

**Merge Strings Alternately**

<p>You are given two strings <code>word1</code> and <code>word2</code>. Merge the strings by adding letters in alternating order, starting with <code>word1</code>. If a string is longer than the other, append the additional letters onto the end of the merged string.</p>

<p>Return <em>the merged string.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word1 = &quot;abc&quot;, word2 = &quot;pqr&quot;
<strong>Output:</strong> &quot;apbqcr&quot;
<strong>Explanation:</strong>&nbsp;The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word1 = &quot;ab&quot;, word2 = &quot;pqrs&quot;
<strong>Output:</strong> &quot;apbqrs&quot;
<strong>Explanation:</strong>&nbsp;Notice that as word2 is longer, &quot;rs&quot; is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word1 = &quot;abcd&quot;, word2 = &quot;pq&quot;
<strong>Output:</strong> &quot;apbqcd&quot;
<strong>Explanation:</strong>&nbsp;Notice that as word1 is longer, &quot;cd&quot; is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 100</code></li>
	<li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int pos = 0;

    string answer;
    answer.reserve(len1 + len2);
    for(; pos < len1 && pos < len2; ++pos) {
      answer.push_back(word1[pos]);
      answer.push_back(word2[pos]);
    }
    for(; pos < len1; ++pos) {
      answer.push_back(word1[pos]);
    }
    for(; pos < len2; ++pos) {
      answer.push_back(word2[pos]);
    }

    return answer;
  }
};

// Accepted
// 108/108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 60.87 % of cpp submissions (6.4 MB)
```
