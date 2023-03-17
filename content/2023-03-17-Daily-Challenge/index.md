+++
updated = 2023-03-17T12:51:33+08:00
title = "2023-03-17 Daily Challenge"
path = "2023-03-17-Daily-Challenge"
date = 2023-03-17T12:51:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/implement-trie-prefix-tree/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 17

## Description

**Implement Trie (Prefix Tree)**

<p>A <a href="https://en.wikipedia.org/wiki/Trie" target="_blank"><strong>trie</strong></a> (pronounced as &quot;try&quot;) or <strong>prefix tree</strong> is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.</p>

<p>Implement the Trie class:</p>

<ul>
	<li><code>Trie()</code> Initializes the trie object.</li>
	<li><code>void insert(String word)</code> Inserts the string <code>word</code> into the trie.</li>
	<li><code>boolean search(String word)</code> Returns <code>true</code> if the string <code>word</code> is in the trie (i.e., was inserted before), and <code>false</code> otherwise.</li>
	<li><code>boolean startsWith(String prefix)</code> Returns <code>true</code> if there is a previously inserted string <code>word</code> that has the prefix <code>prefix</code>, and <code>false</code> otherwise.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;Trie&quot;, &quot;insert&quot;, &quot;search&quot;, &quot;search&quot;, &quot;startsWith&quot;, &quot;insert&quot;, &quot;search&quot;]
[[], [&quot;apple&quot;], [&quot;apple&quot;], [&quot;app&quot;], [&quot;app&quot;], [&quot;app&quot;], [&quot;app&quot;]]
<strong>Output</strong>
[null, null, true, false, true, null, true]

<strong>Explanation</strong>
Trie trie = new Trie();
trie.insert(&quot;apple&quot;);
trie.search(&quot;apple&quot;);   // return True
trie.search(&quot;app&quot;);     // return False
trie.startsWith(&quot;app&quot;); // return True
trie.insert(&quot;app&quot;);
trie.search(&quot;app&quot;);     // return True
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length, prefix.length &lt;= 2000</code></li>
	<li><code>word</code> and <code>prefix</code> consist only of lowercase English letters.</li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>insert</code>, <code>search</code>, and <code>startsWith</code>.</li>
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
  bool isEnd = false;
  TrieNode *nodes[26] = {};
  ~TrieNode() {
    for(auto node : nodes) {
      delete node;
    }
  }
};
class Trie {
  TrieNode *root;
public:
    /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }
  
  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      if(cur->nodes[c - 'a'] == nullptr) {
        cur->nodes[c - 'a'] = new TrieNode();
      }
      cur = cur->nodes[c - 'a'];
    }
    cur->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      if(cur->nodes[c - 'a'] == nullptr) return false;
      cur = cur->nodes[c - 'a'];
    }
    return cur->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for(auto c : prefix) {
      if(cur->nodes[c - 'a'] == nullptr) return false;
      cur = cur->nodes[c - 'a'];
    }
    return true;
  }
};

// Accepted
// 15/15 cases passed (40 ms)
// Your runtime beats 99.23 % of cpp submissions
// Your memory usage beats 73.15 % of cpp submissions (44.9 MB)
```
