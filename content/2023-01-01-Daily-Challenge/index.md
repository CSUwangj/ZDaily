+++
updated = 2023-01-01T12:19:28+08:00
title = "2023-01-01 Daily Challenge"
path = "2023-01-01-Daily-Challenge"
date = 2023-01-01T12:19:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/word-pattern/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 1

## Description

**Word Pattern**

<p>Given a <code>pattern</code> and a string <code>s</code>, find if <code>s</code>&nbsp;follows the same pattern.</p>

<p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> word in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pattern = &quot;abba&quot;, s = &quot;dog cat cat dog&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pattern = &quot;abba&quot;, s = &quot;dog cat cat fish&quot;
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> pattern = &quot;aaaa&quot;, s = &quot;dog cat cat dog&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 300</code></li>
	<li><code>pattern</code> contains only lower-case English letters.</li>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code> contains only lowercase English letters and spaces <code>&#39; &#39;</code>.</li>
	<li><code>s</code> <strong>does not contain</strong> any leading or trailing spaces.</li>
	<li>All the words in <code>s</code> are separated by a <strong>single space</strong>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int countWords(string &s) {
    bool isSpace = true;
    int result = 0;
    for(auto c : s) {
      result += (c != ' ') * isSpace;
      isSpace = c == ' ';
    }
    return result;
  }
  string nextWord(string &s, int &index) {
    while(s[index] == ' ') index += 1;
    int len = 0;
    while(index + len < s.length() && s[index + len] != ' ') len += 1;
    index += len;
    return s.substr(index - len, len);
  }
public:
  bool wordPattern(string pattern, string s) {
    if(pattern.length() != countWords(s)) return false;
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    int pos = 0;
    for(auto c : pattern) {
      auto word = nextWord(s, pos);
      if(mp.count(c) && mp[c] != word) return false;
      if(!mp.count(c)){
        mp[c] = word;
        cnt[word] += 1;
      } 
    }
    for(auto [_word, c] : cnt) if(c > 1) return false;
    return true;
  }
};

// Accepted
// 36/36 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.42 % of cpp submissions (6.3 MB)
```
