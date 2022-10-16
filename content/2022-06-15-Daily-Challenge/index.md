+++
updated = 2022-06-15 18:14:00+08:00
title = "2022-06-15 Daily-Challenge"
path = "2022-06-15-Daily-Challenge"
date = 2022-06-15 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-string-chain/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 15

## Description

**Longest String Chain**

You are given an array of `words` where each word consists of lowercase English letters.

`wordA` is a **predecessor** of `wordB` if and only if we can insert **exactly one** letter anywhere in `wordA` **without changing the order of the other characters** to make it equal to `wordB`.

- For example, `"abc"` is a **predecessor** of `"abac"`, while `"cba"` is not a **predecessor** of `"bcad"`.

A **word chain** is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where `word1` is a **predecessor** of `word2`, `word2` is a **predecessor** of `word3`, and so on. A single word is trivially a **word chain** with `k == 1`.

Return *the **length** of the **longest possible word chain** with words chosen from the given list of* `words`.

 

**Example 1:**

```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
```

**Example 2:**

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

**Example 3:**

```
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
```

 

**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.

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
      }
    }
    return answer;
  }
};

// Accepted
// 79/79 cases passed (50 ms)
// Your runtime beats 96.49 % of cpp submissions
// Your memory usage beats 47.02 % of cpp submissions (17.7 MB)
```
