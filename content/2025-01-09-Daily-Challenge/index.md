+++
updated = 2025-01-09T22:45:47+08:00
title = "2025-01-09 Daily Challenge"
path = "2025-01-09-Daily-Challenge"
date = 2025-01-09T22:45:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/counting-words-with-a-given-prefix/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 9

## Description

**Counting Words With a Given Prefix**

<p>You are given an array of strings <code>words</code> and a string <code>pref</code>.</p>

<p>Return <em>the number of strings in </em><code>words</code><em> that contain </em><code>pref</code><em> as a <strong>prefix</strong></em>.</p>

<p>A <strong>prefix</strong> of a string <code>s</code> is any leading contiguous substring of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;pay&quot;,&quot;<strong><u>at</u></strong>tention&quot;,&quot;practice&quot;,&quot;<u><strong>at</strong></u>tend&quot;], <code>pref </code>= &quot;at&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The 2 strings that contain &quot;at&quot; as a prefix are: &quot;<u><strong>at</strong></u>tention&quot; and &quot;<u><strong>at</strong></u>tend&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;leetcode&quot;,&quot;win&quot;,&quot;loops&quot;,&quot;success&quot;], <code>pref </code>= &quot;code&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no strings that contain &quot;code&quot; as a prefix.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length, pref.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>pref</code> consist of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int prefixCount(vector<string>& words, string pref) {
    int answer = 0;
    for(const auto &word : words) {
      if(word.length() < pref.length()) continue;
      bool same = true;
      for(int i = 0; i < pref.length() && same; ++i) {
        same = pref[i] == word[i];
      }
      answer += same;
    }
    return answer;
  }
};

// Accepted
// 95/95 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.06 % of cpp submissions (13.1 MB)
```
