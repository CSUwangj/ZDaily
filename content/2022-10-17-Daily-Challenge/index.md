+++
updated = 2022-10-17T12:33:34+08:00
title = "2022-10-17 Daily Challenge"
path = "2022-10-17-Daily-Challenge"
date = 2022-10-17T12:33:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/check-if-the-sentence-is-pangram/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 17

## Description

**Check if the Sentence Is Pangram**

<p>A <strong>pangram</strong> is a sentence where every letter of the English alphabet appears at least once.</p>

<p>Given a string <code>sentence</code> containing only lowercase English letters, return<em> </em><code>true</code><em> if </em><code>sentence</code><em> is a <strong>pangram</strong>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> sentence = &quot;thequickbrownfoxjumpsoverthelazydog&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> sentence contains at least one of every letter of the English alphabet.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> sentence = &quot;leetcode&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
	<li><code>sentence</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool checkIfPangram(string sentence) {
    set<char> st(sentence.begin(), sentence.end());
    return st.size() == 26;
  }
};

// Accepted
// 79/79 cases passed (3 ms)
// Your runtime beats 80.34 % of cpp submissions
// Your memory usage beats 31.31 % of cpp submissions (6.7 MB)
```
