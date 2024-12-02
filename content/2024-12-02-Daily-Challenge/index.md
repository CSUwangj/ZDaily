+++
updated = 2024-12-02T13:00:58+08:00
title = "2024-12-02 Daily Challenge"
path = "2024-12-02-Daily-Challenge"
date = 2024-12-02T13:00:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 2

## Description

**Check If a Word Occurs As a Prefix of Any Word in a Sentence**

<p>Given a <code>sentence</code> that consists of some words separated by a <strong>single space</strong>, and a <code>searchWord</code>, check if <code>searchWord</code> is a prefix of any word in <code>sentence</code>.</p>

<p>Return <em>the index of the word in </em><code>sentence</code><em> (<strong>1-indexed</strong>) where </em><code>searchWord</code><em> is a prefix of this word</em>. If <code>searchWord</code> is a prefix of more than one word, return the index of the first word <strong>(minimum index)</strong>. If there is no such word return <code>-1</code>.</p>

<p>A <strong>prefix</strong> of a string <code>s</code> is any leading contiguous substring of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> sentence = &quot;i love eating burger&quot;, searchWord = &quot;burg&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> &quot;burg&quot; is prefix of &quot;burger&quot; which is the 4th word in the sentence.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> sentence = &quot;this problem is an easy problem&quot;, searchWord = &quot;pro&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> &quot;pro&quot; is prefix of &quot;problem&quot; which is the 2nd and the 6th word in the sentence, but we return 2 as it&#39;s the minimal index.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> sentence = &quot;i am tired&quot;, searchWord = &quot;you&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> &quot;you&quot; is not a prefix of any word in the sentence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= searchWord.length &lt;= 10</code></li>
	<li><code>sentence</code> consists of lowercase English letters and spaces.</li>
	<li><code>searchWord</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
vector<string> split(string &s, char spliter = ' ') {
  vector<string> result;
  for(int i = 0; i < s.length(); ++i) {
    string st;
    while(i < s.length() && s[i] != spliter) {
      st += s[i];
      i += 1;
    }
    if(st.size()) result.emplace_back(st);
  }
  return result;
}
class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    auto words = split(sentence);
    int pos = 1;
    for(const auto &word : words) {
      if(word.length() >= searchWord.length() && word.substr(0, searchWord.length()) == searchWord) return pos;
      pos += 1;
    }
    return -1;
  }
};

// Accepted
// 42/42 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 6.42 % of cpp submissions (8.3 MB)
```
