+++
updated = 2024-05-25T13:32:21+08:00
title = "2024-05-25 Daily Challenge"
path = "2024-05-25-Daily-Challenge"
date = 2024-05-25T13:32:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/word-break-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 25

## Description

**Word Break II**

<p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, add spaces in <code>s</code> to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in <strong>any order</strong>.</p>

<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsanddog&quot;, wordDict = [&quot;cat&quot;,&quot;cats&quot;,&quot;and&quot;,&quot;sand&quot;,&quot;dog&quot;]
<strong>Output:</strong> [&quot;cats and dog&quot;,&quot;cat sand dog&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pineapplepenapple&quot;, wordDict = [&quot;apple&quot;,&quot;pen&quot;,&quot;applepen&quot;,&quot;pine&quot;,&quot;pineapple&quot;]
<strong>Output:</strong> [&quot;pine apple pen apple&quot;,&quot;pineapple pen apple&quot;,&quot;pine applepen apple&quot;]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;,&quot;dog&quot;,&quot;sand&quot;,&quot;and&quot;,&quot;cat&quot;]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
	<li>Input is generated in a way that the length of the answer doesn&#39;t exceed&nbsp;10<sup>5</sup>.</li>
</ul>


## Solution

``` cpp
struct TrieNode {
  bool end = false;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    if(!cur->child[c - 'a']) cur->child[c - 'a'] = new TrieNode();
    cur = cur->child[c - 'a'];
  }
  cur->end = true;
}
class Solution {
  TrieNode *root;
  int len;
  vector<vector<string>> cache;
  vector<bool> visit;
  void solve(
    const string &s,
    int pos
  ) {
    TrieNode *cur = root;
    if(len == pos) return;
    if(visit[pos]) return;
    int start = pos;
    while(pos < len) {
      if(!cur->child[s[pos] - 'a']) {
        visit[start] = true;
        return;
      }
      cur = cur->child[s[pos] - 'a'];
      pos += 1;
      if(cur->end) {
        solve(s, pos);
        for(const auto &rest : cache[pos]) {
          string result = s.substr(start, pos - start);
          if(rest.size()) {
            result = result + " " + rest;
          }
          cache[start].emplace_back(move(result));
        }
      }
    }
    visit[start] = true;
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    root = new TrieNode();
    len = s.length();
    visit.resize(len + 1);
    cache.resize(len + 1);
    cache[len].push_back("");
    for(const auto &word : wordDict) {
      insert(root, word);
    }
    solve(s, 0);
    return cache[0];
  }
};
```
