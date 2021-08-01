+++
title = "2021-05-17 Daily-Challenge"
path = "2021-05-17-Daily-Challenge"
date = 2021-05-17 18:15:44+08:00
updated = 2021-05-17 18:29:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3747/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 18

## Description

**Longest String Chain**

Given a list of words, each word consists of English lowercase letters.

Let's say `word1` is a predecessor of `word2` if and only if we can add exactly one letter anywhere in `word1` to make it equal to `word2`. For example, `"abc"` is a predecessor of `"abac"`.

A *word chain* is a sequence of words `[word_1, word_2, ..., word_k]` with `k >= 1`, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on.

Return the longest possible length of a word chain with words chosen from the given list of `words`.

 

**Example 1:**

```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
```

**Example 2:**

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
```

 

**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of English lowercase letters.

## Solution

``` cpp
class Solution {
  bool isPredecessor(string &shorterWord, string &longerWord) {
    bool skip = false;
    int len = shorterWord.length();
    int pos = 0;
    while(pos < len) {
      if(skip && shorterWord[pos] != longerWord[pos + 1]) return false;
      if(shorterWord[pos] == longerWord[pos + skip]) pos += 1;
      else skip = true;
    }
    return true;
  }
public:
  int longestStrChain(vector<string>& words) {
    vector<string> strs[17];
    for(auto &word : words) {
      strs[word.length()].push_back(word);
    }
    unordered_map<string, int> len;
    int answer = 1;
    for(int i = 1; i < 17; ++i) {
      for(auto &longerWord : strs[i]) {
        for(auto &shorterWord : strs[i - 1]) {
          if(isPredecessor(shorterWord, longerWord)) {
            len[longerWord] = max(len[shorterWord] + 1, len[longerWord]);
            answer = max(answer, len[longerWord] + 1);
          }
        }
        // cout << longerWord << ' ' << len[longerWord]<< endl;
      }
    }
    return answer;
  }
};
```
