+++
updated = 2022-11-04T12:09:57+08:00
title = "2022-11-04 Daily Challenge"
path = "2022-11-04-Daily-Challenge"
date = 2022-11-04T12:09:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/reverse-vowels-of-a-string/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 4

## Description

**Reverse Vowels of a String**

<p>Given a string <code>s</code>, reverse only all the vowels in the string and return it.</p>

<p>The vowels are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>, and they can appear in both lower and upper cases, more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "hello"
<strong>Output:</strong> "holle"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> "leotcede"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consist of <strong>printable ASCII</strong> characters.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int vowel[128] = {
  ['A'] = 1,
  ['E'] = 1,
  ['I'] = 1,
  ['O'] = 1,
  ['U'] = 1,
  ['a'] = 1,
  ['e'] = 1,
  ['i'] = 1,
  ['o'] = 1,
  ['u'] = 1
};
class Solution {
public:
  string reverseVowels(string s) {
    int front = 0;
    int back = s.length() - 1;
    while(front < back) {
      while(!vowel[s[front]] && front != back) {
        front += 1;
      }
      while(!vowel[s[back]] && front != back) {
        back -= 1;
      }
      swap(s[front], s[back]);
      front += 1;
      back -= 1;
    }
    return s;
  }
};

// Accepted
// 480/480 cases passed (12 ms)
// Your runtime beats 67.07 % of cpp submissions
// Your memory usage beats 32.73 % of cpp submissions (8 MB)
```
