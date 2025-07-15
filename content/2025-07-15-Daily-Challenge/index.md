+++
updated = 2025-07-16T03:57:50+08:00
title = "2025-07-15 Daily Challenge"
path = "2025-07-15-Daily-Challenge"
date = 2025-07-16T03:57:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/valid-word/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 15

## Description

**Valid Word**

<p>A word is considered <strong>valid</strong> if:</p>

<ul>
	<li>It contains a <strong>minimum</strong> of 3 characters.</li>
	<li>It contains only digits (0-9), and English letters (uppercase and lowercase).</li>
	<li>It includes <strong>at least</strong> one <strong>vowel</strong>.</li>
	<li>It includes <strong>at least</strong> one <strong>consonant</strong>.</li>
</ul>

<p>You are given a string <code>word</code>.</p>

<p>Return <code>true</code> if <code>word</code> is valid, otherwise, return <code>false</code>.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li><code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, <code>&#39;u&#39;</code>, and their uppercases are <strong>vowels</strong>.</li>
	<li>A <strong>consonant</strong> is an English letter that is not a vowel.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;234Adas&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>This word satisfies the conditions.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;b3&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>The length of this word is fewer than 3, and does not have a vowel.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;a3$e&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>This word contains a <code>&#39;$&#39;</code> character and does not have a consonant.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> consists of English uppercase and lowercase letters, digits, <code>&#39;@&#39;</code>, <code>&#39;#&#39;</code>, and <code>&#39;$&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool isvowel(char c) {
    switch(c) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
    }
    return false;
  }
public:
  bool isValid(string word) {
    if(word.size() < 3) return false;
    bool hasVowel = false;
    bool hasConsonant = false;
    for(auto c : word) {
      if(!isalnum(c)) return false;
      hasVowel = isvowel(c) || hasVowel;
      hasConsonant = (isalpha(c) && !isvowel(c)) || hasConsonant;
    }
    return hasConsonant && hasVowel;
  }
};

// Accepted
// 677/677 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 33.95 % of cpp submissions (8 MB)
```
