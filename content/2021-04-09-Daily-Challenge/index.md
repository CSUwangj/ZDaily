+++
title = "2021-04-09 Daily-Challenge"
path = "2021-04-09-Daily-Challenge"
date = 2021-04-09 17:00:02+08:00
updated = 2021-04-09 17:22:16+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3702/) with `cpp`.

<!-- more -->

# Maximum Number of Occurrences of a Substring

## Description

Given a string `s`, return the maximum number of ocurrences of **any** substring under the following rules:

- The number of unique characters in the substring must be less than or equal to `maxLetters`.
- The substring size must be between `minSize` and `maxSize` inclusive.

 

**Example 1:**

```
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
```

**Example 2:**

```
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
```

**Example 3:**

```
Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
```

**Example 4:**

```
Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `1 <= maxLetters <= 26`
- `1 <= minSize <= maxSize <= min(26, s.length)`
- `s` only contains lowercase English letters.

## Solution

why this problem is `medium`?

``` cpp
class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int len = s.length();
    for(int i = minSize; i <= maxSize; ++i) {
      vector<int> cnt(26);
      unordered_map<string, int> sCnt;
      int letters = 0;
      for(int j = 0; j < i; ++j) {
        if(!cnt[s[j] - 'a']) letters += 1;
        cnt[s[j] - 'a'] += 1;
      }
      if(letters <= maxLetters) sCnt[s.substr(0, i)] += 1;
      for(int j = i; j < len; ++j) {
        if(!cnt[s[j] - 'a']) letters += 1;
        cnt[s[j] - 'a'] += 1;
        cnt[s[j - i] - 'a'] -= 1;
        if(!cnt[s[j - i] - 'a']) letters -= 1;
        if(letters <= maxLetters) sCnt[s.substr(j - i + 1, i)] += 1;
      }
      if(sCnt.size()) {
        int answer = 0;
        for(auto &[s, c] : sCnt) answer = max(answer, c);
        return answer;
      }
    }
    return 0;
  }
};
```

# April LeetCoding challenge9

## Description

**Verifying an Alien Dictionary**

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographicaly in this alien language.

 

**Example 1:**

```
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
```

**Example 2:**

```
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

**Example 3:**

```
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

 

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 20`
- `order.length == 26`
- All characters in `words[i]` and `order` are English lowercase letters.

## Solution

``` cpp
class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    int orderIndex[128] = {};
    int pos = 0;
    for(auto c : order) orderIndex[c] = pos++;
    return is_sorted(words.begin(), words.end(), [&](const string &a, const string &b) {
      for(int i = 0; i < min(a.length(), b.length()); ++i) {
        if(a[i] != b[i]) return orderIndex[a[i]] < orderIndex[b[i]];
      }
      return a.length() < b.length();
    });
  }
};
```
