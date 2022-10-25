+++
updated = 2022-10-25T13:12:38+08:00
title = "2022-10-25 Daily Challenge"
path = "2022-10-25-Daily-Challenge"
date = 2022-10-25T13:12:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 25

## Description

**Check If Two String Arrays are Equivalent**

<p>Given two string arrays <code>word1</code> and <code>word2</code>, return<em> </em><code>true</code><em> if the two arrays <strong>represent</strong> the same string, and </em><code>false</code><em> otherwise.</em></p>

<p>A string is <strong>represented</strong> by an array if the array elements concatenated <strong>in order</strong> forms the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word1 = [&quot;ab&quot;, &quot;c&quot;], word2 = [&quot;a&quot;, &quot;bc&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong>
word1 represents string &quot;ab&quot; + &quot;c&quot; -&gt; &quot;abc&quot;
word2 represents string &quot;a&quot; + &quot;bc&quot; -&gt; &quot;abc&quot;
The strings are the same, so return true.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word1 = [&quot;a&quot;, &quot;cb&quot;], word2 = [&quot;ab&quot;, &quot;c&quot;]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word1  = [&quot;abc&quot;, &quot;d&quot;, &quot;defg&quot;], word2 = [&quot;abcddefg&quot;]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= word1[i].length, word2[i].length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= sum(word1[i].length), sum(word2[i].length) &lt;= 10<sup>3</sup></code></li>
	<li><code>word1[i]</code> and <code>word2[i]</code> consist of lowercase letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i1 = 0, i2 = 0, s1 = 0, s2 = 0;
    int len1 = word1.size(), len2 = word2.size();
    while(i1 < len1 && i2 <len2) {
      if(word1[i1][s1] != word2[i2][s2]) return false;
      s1 += 1;
      if(s1 == word1[i1].length()) s1 = 0, i1 += 1;
      s2 += 1;
      if(s2 == word2[i2].length()) s2 = 0, i2 += 1;
    }
    if(i1 != len1 || i2 != len2) return false;
    return true;
  }
};

// Accepted
// 109/109 cases passed (3 ms)
// Your runtime beats 93.69 % of cpp submissions
// Your memory usage beats 89.94 % of cpp submissions (11.4 MB)
```
