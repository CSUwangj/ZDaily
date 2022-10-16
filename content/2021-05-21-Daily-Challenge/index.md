+++
title = "2021-05-21 Daily-Challenge"
path = "2021-05-21-Daily-Challenge"
date = 2021-05-21 17:30:10+08:00
updated = 2021-05-21 17:33:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3750/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 21

## Description

**Find and Replace Pattern**

<p>Given a list of strings <code>words</code> and a string <code>pattern</code>, return <em>a list of</em> <code>words[i]</code> <em>that match</em> <code>pattern</code>. You may return the answer in <strong>any order</strong>.</p>

<p>A word matches the pattern if there exists a permutation of letters <code>p</code> so that after replacing every letter <code>x</code> in the pattern with <code>p(x)</code>, we get the desired word.</p>

<p>Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> words = [&quot;abc&quot;,&quot;deq&quot;,&quot;mee&quot;,&quot;aqq&quot;,&quot;dkd&quot;,&quot;ccc&quot;], pattern = &quot;abb&quot;
<strong>Output:</strong> [&quot;mee&quot;,&quot;aqq&quot;]
<strong>Explanation:</strong> &quot;mee&quot; matches the pattern because there is a permutation {a -&gt; m, b -&gt; e, ...}. 
&quot;ccc&quot; does not match the pattern because {a -&gt; c, b -&gt; c, ...} is not a permutation, since a and b map to the same letter.</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> words = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;], pattern = &quot;a&quot;
<strong>Output:</strong> [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;]</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 20</code></li>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>words[i].length == pattern.length</code></li>
	<li><code>pattern</code> and <code>words[i]</code> are lowercase English letters.</li>
</ul>

## Solution

``` cpp
string unify(string s) {
  char mp[26] = {};
  int cnt = 0;
  for(auto &c : s) {
    if(!mp[c - 'a']) {
      mp[c - 'a'] = 'a' + cnt;
      cnt += 1;
    }
    c = mp[c - 'a'];
  }
  return s;
}
class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<int> answer;
    pattern = unify(pattern);
    for(auto &word : words) {
      if(unify(word) == pattern) answer.push_back(word);
    }
    return answer;
  }
};
```
