+++
updated = 2024-10-06T08:18:43+08:00
title = "2024-10-06 Daily Challenge"
path = "2024-10-06-Daily-Challenge"
date = 2024-10-06T08:18:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/sentence-similarity-iii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 6

## Description

**Sentence Similarity III**

<p>You are given two strings <code>sentence1</code> and <code>sentence2</code>, each representing a <strong>sentence</strong> composed of words. A sentence is a list of <strong>words</strong> that are separated by a <strong>single</strong> space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.</p>

<p>Two sentences <code>s1</code> and <code>s2</code> are considered <strong>similar</strong> if it is possible to insert an arbitrary sentence (<em>possibly empty</em>) inside one of these sentences such that the two sentences become equal. <strong>Note</strong> that the inserted sentence must be separated from existing words by spaces.</p>

<p>For example,</p>

<ul>
	<li><code>s1 = &quot;Hello Jane&quot;</code> and <code>s2 = &quot;Hello my name is Jane&quot;</code> can be made equal by inserting <code>&quot;my name is&quot;</code> between <code>&quot;Hello&quot;</code><font face="monospace"> </font>and <code>&quot;Jane&quot;</code><font face="monospace"> in s1.</font></li>
	<li><font face="monospace"><code>s1 = &quot;Frog cool&quot;</code> </font>and<font face="monospace"> <code>s2 = &quot;Frogs are cool&quot;</code> </font>are <strong>not</strong> similar, since although there is a sentence <code>&quot;s are&quot;</code> inserted into <code>s1</code>, it is not separated from <code>&quot;Frog&quot;</code> by a space.</li>
</ul>

<p>Given two sentences <code>sentence1</code> and <code>sentence2</code>, return <strong>true</strong> if <code>sentence1</code> and <code>sentence2</code> are <strong>similar</strong>. Otherwise, return <strong>false</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sentence1 = &quot;My name is Haley&quot;, sentence2 = &quot;My Haley&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p><code>sentence2</code> can be turned to <code>sentence1</code> by inserting &quot;name is&quot; between &quot;My&quot; and &quot;Haley&quot;.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sentence1 = &quot;of&quot;, sentence2 = &quot;A lot of words&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>No single sentence can be inserted inside one of the sentences to make it equal to the other.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sentence1 = &quot;Eating right now&quot;, sentence2 = &quot;Eating&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p><code>sentence2</code> can be turned to <code>sentence1</code> by inserting &quot;right now&quot; at the end of the sentence.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 100</code></li>
	<li><code>sentence1</code> and <code>sentence2</code> consist of lowercase and uppercase English letters and spaces.</li>
	<li>The words in <code>sentence1</code> and <code>sentence2</code> are separated by a single space.</li>
</ul>


## Solution

``` cpp
vector<string> split(string &s, char spliter) {
  vector<string> result;
  for(int i = 0; i < s.length(); ++i) {
    string st;
    while(i < s.length() && s[i] != spliter) {
      st += s[i];
      i += 1;
    }
    if(st.size()) result.emplace_back(st);
  }
  return result;
}

class Solution {
  bool solve(vector<string> &a, vector<string> &b, int i, int j, int skipStatus) {
    if(i == a.size() && j == b.size()) return true;

    if(i == a.size()) return skipStatus != 2;

    if(j == b.size()) return false;

    if(a[i] != b[j]) {
      if(skipStatus == 2) return false;
      return solve(a, b, i, j + 1, 1);
    }
    if(skipStatus == 1) {
      return solve(a, b, i + 1, j + 1,(skipStatus == 1) ? 2 : skipStatus) || solve(a, b, i, j + 1, 1);
    }
    return solve(a, b, i + 1, j + 1, (skipStatus == 1) ? 2 : skipStatus);
  }
public:
  bool areSentencesSimilar(string s1, string s2) {
    if(s1 == s2) return true;
    vector<string> a = split(s1, ' ');
    vector<string> b = split(s2, ' ');
    if(a.size() > b.size()) swap(a, b);
    return solve(a, b, 0, 0, 0);
  }
};
```
