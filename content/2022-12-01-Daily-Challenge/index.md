+++
updated = 2022-12-01T12:11:56+08:00
title = "2022-12-01 Daily Challenge"
path = "2022-12-01-Daily-Challenge"
date = 2022-12-01T12:11:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/determine-if-string-halves-are-alike/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 1

## Description

**Determine if String Halves Are Alike**

<p>You are given a string <code>s</code> of even length. Split this string into two halves of equal lengths, and let <code>a</code> be the first half and <code>b</code> be the second half.</p>

<p>Two strings are <strong>alike</strong> if they have the same number of vowels (<code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, <code>&#39;u&#39;</code>, <code>&#39;A&#39;</code>, <code>&#39;E&#39;</code>, <code>&#39;I&#39;</code>, <code>&#39;O&#39;</code>, <code>&#39;U&#39;</code>). Notice that <code>s</code> contains uppercase and lowercase letters.</p>

<p>Return <code>true</code><em> if </em><code>a</code><em> and </em><code>b</code><em> are <strong>alike</strong></em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;book&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> a = &quot;b<u>o</u>&quot; and b = &quot;<u>o</u>k&quot;. a has 1 vowel and b has 1 vowel. Therefore, they are alike.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;textbook&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> a = &quot;t<u>e</u>xt&quot; and b = &quot;b<u>oo</u>k&quot;. a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s.length</code> is even.</li>
	<li><code>s</code> consists of <strong>uppercase and lowercase</strong> letters.</li>
</ul>


## Solution

``` cpp
constexpr int vowel(char c) {
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1;
  }
  return 0;
}
class Solution {
public:
  bool halvesAreAlike(string s) {
    int front = 0;
    int back = 0;
    int len = s.length();
    for(int i = 0; i < len / 2; ++i) {
      front += vowel(s[i]);
    }
    for(int i = len / 2; i < len; ++i) {
      back += vowel(s[i]);
    }
    return front == back;
  }
};

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 56.35 % of cpp submissions (6.6 MB)
```
