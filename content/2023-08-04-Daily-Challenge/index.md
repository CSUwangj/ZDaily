+++
updated = 2023-08-04T23:18:26+08:00
title = "2023-08-04 Daily Challenge"
path = "2023-08-04-Daily-Challenge"
date = 2023-08-04T23:18:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/word-break/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 4

## Description

**Word Break**

<p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, return <code>true</code> if <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.</p>

<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetcode&quot;, wordDict = [&quot;leet&quot;,&quot;code&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because &quot;leetcode&quot; can be segmented as &quot;leet code&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;applepenapple&quot;, wordDict = [&quot;apple&quot;,&quot;pen&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because &quot;applepenapple&quot; can be segmented as &quot;apple pen apple&quot;.
Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;,&quot;dog&quot;,&quot;sand&quot;,&quot;and&quot;,&quot;cat&quot;]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
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
  vector<bool> visit;
  bool solve(const string &s, int pos) {
    TrieNode *cur = root;
    if(len == pos) return true;
    if(visit[pos]) return false;
    int start = pos;
    while(pos < len) {
      if(!cur->child[s[pos] - 'a']) {
        visit[start] = true;
        return false;
      }
      cur = cur->child[s[pos] - 'a'];
      pos += 1;
      if(cur->end && solve(s, pos)) return true;
    }
    visit[pos] = true;
    return false;
  }
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    root = new TrieNode();
    len = s.length();
    visit.resize(len);
    for(const auto &word : wordDict) {
      insert(root, word);
    }
    return solve(s, 0);
  }
};

// Accepted
// 46/46 cases passed (3 ms)
// Your runtime beats 91.38 % of cpp submissions
// Your memory usage beats 54.73 % of cpp submissions (10.1 MB)
```
