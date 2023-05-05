+++
updated = 2023-05-05T18:22:04+08:00
title = "2023-05-05 Daily Challenge"
path = "2023-05-05-Daily-Challenge"
date = 2023-05-05T18:22:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 5

## Description

**Maximum Number of Vowels in a Substring of Given Length**

<p>Given a string <code>s</code> and an integer <code>k</code>, return <em>the maximum number of vowel letters in any substring of </em><code>s</code><em> with length </em><code>k</code>.</p>

<p><strong>Vowel letters</strong> in English are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abciiidef&quot;, k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substring &quot;iii&quot; contains 3 vowel letters.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aeiou&quot;, k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Any substring of length 2 contains 2 vowels.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetcode&quot;, k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> &quot;lee&quot;, &quot;eet&quot; and &quot;ode&quot; contain 2 vowels.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>


## Solution

``` cpp
int vowel[128] = {
  ['a'] = 1,
  ['e'] = 1,
  ['i'] = 1,
  ['o'] = 1,
  ['u'] = 1
};
class Solution {
public:
  int maxVowels(string s, int k) {
    int pos = 0;
    int answer = 0;
    int count = 0;
    for(; pos < k; ++pos) {
      count += vowel[s[pos]];
    }
    answer = max(answer, count);
    for(;pos < s.length(); ++pos) {
      count += vowel[s[pos]];
      count -= vowel[s[pos - k]];
      answer = max(answer, count);
    }

    return answer;
  }
};

// Accepted
// 106/106 cases passed (11 ms)
// Your runtime beats 99.57 % of cpp submissions
// Your memory usage beats 29.12 % of cpp submissions (10 MB)
```
