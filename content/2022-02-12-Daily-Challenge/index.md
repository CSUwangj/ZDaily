+++
title = "2022-02-12 Daily-Challenge"
path = "2022-02-12-Daily-Challenge"
date = 2022-02-12 12:18:00+08:00
updated = 2022-02-12 12:24:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/word-ladder/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 12

## Description

**Word Ladder**

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the **number of words** in the **shortest transformation sequence** from* `beginWord` *to* `endWord`*, or* `0` *if no such sequence exists.*

 

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

 

**Constraints:**

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are **unique**.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> words;
    for(auto word : wordList) {
      words[word] = 0;
    }
    words[beginWord] = 1;
    if(!words.count(endWord)) return 0;
    queue<string> q;
    q.push(beginWord);
    while(q.size()) {
      auto cur = q.front();
      q.pop();
      if(cur == endWord) return words[endWord];
      string nxt = cur;
      for(auto &c : nxt) {
        int curChar = c;
        for(int i = 'a'; i <= 'z'; ++i) {
          c = i;
          if(words.count(nxt) && !words[nxt]) {
            words[nxt] = words[cur] + 1;
            q.push(nxt);
          }
        }
        c = curChar;
      }
    }
    return 0;
  }
};

// Accepted
// 50/50 cases passed (121 ms)
// Your runtime beats 75.11 % of cpp submissions
// Your memory usage beats 54.46 % of cpp submissions (14.7 MB)
```
