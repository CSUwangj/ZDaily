+++
updated = 2023-01-27T15:31:09+08:00
title = "2023-01-27 Daily Challenge"
path = "2023-01-27-Daily-Challenge"
date = 2023-01-27T15:31:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/concatenated-words/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 27

## Description

**Concatenated Words**

<p>Given an array of strings <code>words</code> (<strong>without duplicates</strong>), return <em>all the <strong>concatenated words</strong> in the given list of</em> <code>words</code>.</p>

<p>A <strong>concatenated word</strong> is defined as a string that is comprised entirely of at least two shorter words in the given array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;cats&quot;,&quot;catsdogcats&quot;,&quot;dog&quot;,&quot;dogcatsdog&quot;,&quot;hippopotamuses&quot;,&quot;rat&quot;,&quot;ratcatdogcat&quot;]
<strong>Output:</strong> [&quot;catsdogcats&quot;,&quot;dogcatsdog&quot;,&quot;ratcatdogcat&quot;]
<strong>Explanation:</strong> &quot;catsdogcats&quot; can be concatenated by &quot;cats&quot;, &quot;dog&quot; and &quot;cats&quot;; 
&quot;dogcatsdog&quot; can be concatenated by &quot;dog&quot;, &quot;cats&quot; and &quot;dog&quot;; 
&quot;ratcatdogcat&quot; can be concatenated by &quot;rat&quot;, &quot;cat&quot;, &quot;dog&quot; and &quot;cat&quot;.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;dog&quot;,&quot;catdog&quot;]
<strong>Output:</strong> [&quot;catdog&quot;]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
	<li>All the strings of <code>words</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= sum(words[i].length) &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  TrieNode* children[26];
  int count = 0;
  bool end = false;
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c -= 'a';
    if(!(cur->children[c])) {
      cur->children[c] = new TrieNode();
    }
    cur = cur->children[c];
    cur->count += 1;
  }
  cur->end = true;
}
void remove(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  vector<TrieNode*> path;
  for(auto c : word) {
    path.push_back(cur);
    c -= 'a';
    cur = cur->children[c];
  }
  cur->end = false;
  TrieNode *prev;
  for(auto it = word.rbegin(); it != word.rend(); ++it) {
    prev = cur;
    cur = path.back();
    path.pop_back();
    int c = *it - 'a';
    prev->count -= 1;
    if(prev->count == 0) {
      // memory leak, but delete will slow down the code
      // delete cur->children[c];
      cur->children[c] = nullptr;
    }
  }
}
class Solution {
  unordered_map<string, bool> valid;
  TrieNode *root;
  bool check(const string &word, int pos) {
    if(pos && valid.count(word.substr(pos))) {
      return valid[word.substr(pos)];
    }
    TrieNode *cur = root;
    for(int i = pos; i < word.length(); ++i) {
      int c = word[i] - 'a';
      if(!(cur->children[c])) return valid[word] = false;
      cur = cur->children[c];
      if(cur->end && check(word, i + 1)) return valid[word] = true;
    }
    
    return pos && (valid[word] = cur->end);
  }
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    int minLen = INT_MAX;
    set<string> basicWords;
    root = new TrieNode();
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.length() < b.length();
    });

    for(const auto &word : words) {
      minLen = min<int>(minLen, word.length());
      valid[word] = true;
      insert(root, word);
    }
    
    vector<string> answer;
    for(const auto &word: words) {
      if(word.length() < minLen * 2) continue;
      if(check(word, 0)) {
        answer.push_back(word);
        remove(root, word);
      }
      valid[word] = true;
    }

    return answer;
  }
};

// Accepted
// 42/42 cases passed (211 ms)
// Your runtime beats 82.87 % of cpp submissions
// Your memory usage beats 11.55 % of cpp submissions (239 MB)
```
