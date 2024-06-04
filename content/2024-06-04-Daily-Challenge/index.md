+++
updated = 2024-06-04T19:04:08+08:00
title = "2024-06-04 Daily Challenge"
path = "2024-06-04-Daily-Challenge"
date = 2024-06-04T19:04:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-palindrome/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 4

## Description

**Longest Palindrome**

<p>Given a string <code>s</code> which consists of lowercase or uppercase letters, return the length of the <strong>longest <span data-keyword="palindrome-string">palindrome</span></strong>&nbsp;that can be built with those letters.</p>

<p>Letters are <strong>case sensitive</strong>, for example, <code>&quot;Aa&quot;</code> is not considered a palindrome.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abccccdd&quot;
<strong>Output:</strong> 7
<strong>Explanation:</strong> One longest palindrome that can be built is &quot;dccaccd&quot;, whose length is 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The longest palindrome that can be built is &quot;a&quot;, whose length is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists of lowercase <strong>and/or</strong> uppercase English&nbsp;letters only.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestPalindrome(string s) {
    vector<int> count(128);
    for(auto c : s) {
      count[c] += 1;
    }

    int hasOdd = 0;
    int answer = 0;
    for(auto n : count) {
      answer += n - (n % 2);
      hasOdd += n % 2;
    }
    return answer + !!hasOdd;
  }
};
```
