+++
title = "2021-04-16 Daily-Challenge"
path = "2021-04-16-Daily-Challenge"
date = 2021-04-16 18:23:49+08:00
updated = 2021-04-16 19:26:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3710/) with `cpp`.

<!-- more -->

# Implement Trie (Prefix Tree)

## Description

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
- At most <code>3 * 10<sup>4</sup></code> calls **in total** will be made to `insert`, `search`, and `startsWith`.

``` cpp
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

# April LeetCoding challenge 16

## Description

**Remove All Adjacent Duplicates in String II**

Given a string `s`, a *k* *duplicate removal* consists of choosing `k` adjacent and equal letters from `s` and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` duplicate removals on `s` until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

**Example 1:**

```
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
```

**Example 2:**

```
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
```

**Example 3:**

```
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `2 <= k <= 10^4`
- `s` only contains lower case English letters.

## Solution

``` cpp
class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st;
    for(auto c : s) {
      if(st.empty() || st.back().first != c) {
        st.push_back(make_pair(c, 1));
      } else {
        st.back().second += 1;
        if(st.back().second == k) st.pop_back();
      }
    }
    string answer;
    for(auto [c, cnt] : st) {
      for(int i = 0; i < cnt; ++i) answer.push_back(c);
    }
    return answer;
  }
};
```
