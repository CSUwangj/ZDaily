+++
updated = 2023-01-02T14:07:04+08:00
title = "2023-01-02 Daily Challenge"
path = "2023-01-02-Daily-Challenge"
date = 2023-01-02T14:07:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/detect-capital/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 2

## Description

**Detect Capital**

<p>We define the usage of capitals in a word to be right when one of the following cases holds:</p>

<ul>
	<li>All letters in this word are capitals, like <code>&quot;USA&quot;</code>.</li>
	<li>All letters in this word are not capitals, like <code>&quot;leetcode&quot;</code>.</li>
	<li>Only the first letter in this word is capital, like <code>&quot;Google&quot;</code>.</li>
</ul>

<p>Given a string <code>word</code>, return <code>true</code> if the usage of capitals in it is right.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word = "USA"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word = "FlaG"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists of lowercase and uppercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool detectCapitalUse(string word) {
    int count = 0;
    for(auto c : word) {
      count += !!isupper(c);
    }
    // int count = count_if(word.begin(), word.end(), isupper);
    return count == word.length() || count == 0 || (count == 1 && isupper(word.front()));
  }
};

// Accepted
// 550/550 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.65 % of cpp submissions (6 MB)
```
