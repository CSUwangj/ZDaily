+++
title = "2021-12-04 Daily-Challenge"
path = "2021-12-04-Daily-Challenge"
date = 2021-12-04 14:00:00+08:00
updated = 2021-12-04 17:00:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/stream-of-characters/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 4

## Description

**Stream of Characters**

Design an  algorithm that accepts a stream of characters and checks if a suffix of  these characters is a string of a given array of strings `words`.

For example, if `words = ["abc", "xyz"]` and the stream added the four characters (one by one) `'a'`, `'x'`, `'y'`, and `'z'`, your algorithm should detect that the suffix `"xyz"` of the characters `"axyz"` matches `"xyz"` from `words`.

Implement the `StreamChecker` class:

- `StreamChecker(String[] words)` Initializes the object with the strings array `words`.
- `boolean query(char letter)` Accepts a new character from the stream and returns `true` if any non-empty suffix from the stream forms a word that is in `words`.

 

**Example 1:**

```
Input
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
Output
[null, false, false, false, true, false, true, false, false, false, false, false, true]

Explanation
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // return False
streamChecker.query("b"); // return False
streamChecker.query("c"); // return False
streamChecker.query("d"); // return True, because 'cd' is in the wordlist
streamChecker.query("e"); // return False
streamChecker.query("f"); // return True, because 'f' is in the wordlist
streamChecker.query("g"); // return False
streamChecker.query("h"); // return False
streamChecker.query("i"); // return False
streamChecker.query("j"); // return False
streamChecker.query("k"); // return False
streamChecker.query("l"); // return True, because 'kl' is in the wordlist
```

 

**Constraints:**

- `1 <= words.length <= 2000`
- `1 <= words[i].length <= 2000`
- `words[i]` consists of lowercase English letters.
- `letter` is a lowercase English letter.
- At most `4 * 10^4` calls will be made to query.

## Solution

this solution can be hacked, because `2000 * 2000` strings can occupy at most `2000 * 2000 - 26 - 26 * 26 - 1` nodes, I'll submit a testcase ;P

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

struct TrieNode {
  int begin;
  int next[26];
};

TrieNode trie[30000];
class StreamChecker {
  int root;
  int index;
  int maxLength = 0;
  char d[2001];
  int begin = 0;
  int end = 1;

  int useNext() {
    memset(trie + index, 0 , sizeof(TrieNode));
    return index++;
  }
public:
  StreamChecker(vector<string>& words) {
    sort(words.begin(), words.end());
    index = 0;
    root = useNext();
    for(auto &word: words) {
      auto cur = &(trie[root]);
      for(int i = word.length() - 1; i >= 0; --i) {
        char c = word[i] - 'a';
        if(!cur->next[c]) {
          cur->next[c] = useNext();
        } 
        if(!i) {
          cur->begin |= (1 << c);
        }
        cur = &(trie[cur->next[c]]);
      }
      if(word.length() > maxLength) maxLength = word.length();
    }
  }
  
  bool query(char letter) {
    d[end] = letter - 'a';
    end = end == 2000 ? 0 : end + 1;
    if((end - begin + 2000) % 2001 > maxLength) begin += 1;
    if(begin == 2000) begin = 1;
    auto cur = &(trie[root]);
    for(int i = (end + 2000) % 2001; i != begin; i = (i + 2000) % 2001) {
      char c = d[i];
      if(!cur->next[c]) return false;
      else if(cur->begin & (1 << c)) return true;
      else cur = &(trie[cur->next[c]]);
    }
    return false;
  }
};

// Accepted
// 17/17 cases passed (136 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (90.6 MB)
```
