+++
title = "2022-01-28 Daily-Challenge"
path = "2022-01-28-Daily-Challenge"
date = 2022-01-28 18:02:00+08:00
updated = 2022-01-28 18:38:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/design-add-and-search-words-data-structure/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 28

## Description

**Design Add and Search Words Data Structure**

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

- `WordDictionary()` Initializes the object.
- `void addWord(word)` Adds `word` to the data structure, it can be matched later.
- `bool search(word)` Returns `true` if there is any string in the data structure that matches `word` or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.

 

**Example:**

```
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
```

 

**Constraints:**

- `1 <= word.length <= 500`
- `word` in `addWord` consists lower-case English letters.
- `word` in `search` consist of `'.'` or lower-case English letters.
- At most `50000` calls will be made to `addWord` and `search`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  bool end = false;
  TrieNode *children[26] = {};
  ~TrieNode() {
    for(auto child : children) delete child;
  }
};

class WordDictionary {
  TrieNode *root;

  bool helper(const string &word, TrieNode *cur, int pos = 0) {
    int len = word.length();
    for(int i = pos; i < len; ++i) {
      if(word[i] != '.') {
        if(!cur->children[word[i] - 'a']) return false;
        cur = cur->children[word[i] - 'a'];
      } else {
        for(auto child : cur->children) {
          if(child && helper(word, child, i + 1)) return true;
        }
        return false;
      }
    }
    return cur->end;
  }
public:
  WordDictionary() {
    root = new TrieNode();
  }

  ~WordDictionary() {
    delete root;
  }
  
  void addWord(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      c -= 'a';
      if(!cur->children[c]) {
        cur->children[c] = new TrieNode();
      }
      cur = cur->children[c];
    }
    cur->end = true;
  }
  
  bool search(string word) {
    return helper(word, root);
  }
};

// Accepted
// 13/13 cases passed (84 ms)
// Your runtime beats 75.72 % of cpp submissions
// Your memory usage beats 57.03 % of cpp submissions (43.7 MB)
```
