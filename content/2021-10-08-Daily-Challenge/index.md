+++
title = "2021-10-08 Daily-Challenge"
path = "2021-10-08-Daily-Challenge"
date = 2021-10-08 18:01:33+08:00
updated = 2021-10-08 18:15:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/implement-trie-prefix-tree/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 8

## Description

**Implement Trie (Prefix Tree)**

A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

 

**Example 1:**

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

 

**Constraints:**

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 10^4` calls **in total** will be made to `insert`, `search`, and `startsWith`.

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
