+++
updated = 2024-06-07T08:49:18+08:00
title = "2024-06-07 Daily Challenge"
path = "2024-06-07-Daily-Challenge"
date = 2024-06-07T08:49:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/replace-words/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 7

## Description

**Replace Words**

<p>In English, we have a concept called <strong>root</strong>, which can be followed by some other word to form another longer word - let&#39;s call this word <strong>derivative</strong>. For example, when the <strong>root</strong> <code>&quot;help&quot;</code> is followed by the word <code>&quot;ful&quot;</code>, we can form a derivative <code>&quot;helpful&quot;</code>.</p>

<p>Given a <code>dictionary</code> consisting of many <strong>roots</strong> and a <code>sentence</code> consisting of words separated by spaces, replace all the derivatives in the sentence with the <strong>root</strong> forming it. If a derivative can be replaced by more than one <strong>root</strong>, replace it with the <strong>root</strong> that has <strong>the shortest length</strong>.</p>

<p>Return <em>the <code>sentence</code></em> after the replacement.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dictionary = [&quot;cat&quot;,&quot;bat&quot;,&quot;rat&quot;], sentence = &quot;the cattle was rattled by the battery&quot;
<strong>Output:</strong> &quot;the cat was rat by the bat&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dictionary = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;], sentence = &quot;aadsfasf absbs bbab cadsfafs&quot;
<strong>Output:</strong> &quot;a a b c&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dictionary.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 100</code></li>
	<li><code>dictionary[i]</code> consists of only lower-case letters.</li>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>6</sup></code></li>
	<li><code>sentence</code> consists of only lower-case letters and spaces.</li>
	<li>The number of words in <code>sentence</code> is in the range <code>[1, 1000]</code></li>
	<li>The length of each word in <code>sentence</code> is in the range <code>[1, 1000]</code></li>
	<li>Every two consecutive words in <code>sentence</code> will be separated by exactly one space.</li>
	<li><code>sentence</code> does not have leading or trailing spaces.</li>
</ul>


## Solution

``` cpp
struct TrieNode {
  bool isEnd;
  TrieNode *next[26];
  TrieNode() : isEnd(false) {
    for(int i = 0; i < 26; ++i) next[i] = nullptr;
  }
};

void insertTrie(string &s, TrieNode *root) {
  TrieNode *cur = root;
  for(auto c : s) {
    if(!cur->next[c - 'a']) {
      cur->next[c - 'a'] = new TrieNode();
    }
    cur = cur->next[c - 'a'];
  }
  cur->isEnd = true;
}

class Solution {
public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    TrieNode *root = new TrieNode();
    for(auto &word : dictionary) {
      insertTrie(word, root);
    }
    string answer;
    bool ok = true;
    bool found = false;
    TrieNode *current = root;
    for(int i = 0; i < sentence.length(); ++i) {
      if(!ok && sentence[i] != ' '){
        answer.push_back(sentence[i]);
      } else if(sentence[i] != ' ' && !found) {
        current = current->next[sentence[i] - 'a'];
        answer.push_back(sentence[i]);
        if(current == nullptr) ok = false;
        else if(current->isEnd) found = true;
      }
      if(sentence[i] == ' ') {
        answer.push_back(' ');
        ok = true;
        found = false;
        current = root;
      }
    }
    return answer;
  }
};
```
