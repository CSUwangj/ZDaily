+++
updated = 2022-08-13 18:14:00+08:00
title = "2022-08-13 Daily-Challenge"
path = "2022-08-13-Daily-Challenge"
date = 2022-08-13 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 13

## Description

**Substring with Concatenation of All Words**

You are given a string `s` and an array of strings `words` of **the same length**. Return all starting indices of substring(s) in `s` that is a concatenation of each word in `words` **exactly once**, **in any order**, and **without any intervening characters**.

You can return the answer in **any order**.

 

**Example 1:**

```
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
```

**Example 2:**

```
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
```

**Example 3:**

```
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
```

 

**Constraints:**

- `1 <= s.length <= 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` and `words[i]` consist of lowercase English letters.


## Solution

``` cpp
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> cnt;
    int wordLen = words[0].length();
    int total = words.size();
    int slen = s.length();
    for(auto &word : words) {
      cnt[word] += 1;
    }
    vector<int> answer;
    for(int i = 0; i <= slen - total*wordLen; ++i) {
      if(cnt.count(s.substr(i, wordLen))) {
        int rest = total;
        unordered_map<string, int> cur = cnt;
        int pos = i;
        string curWord = s.substr(pos, wordLen);
        do {
          cur[curWord] -= 1;
          rest -= 1;
          if(!cur[curWord]) cur.erase(curWord);
          pos += wordLen;
          curWord = s.substr(pos, wordLen);
        }while(rest && cur.count(curWord));
        if(rest == 0) {
          answer.push_back(i);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 178/178 cases passed (329 ms)
// Your runtime beats 61.92 % of cpp submissions
// Your memory usage beats 54.83 % of cpp submissions (26.2 MB)
```
