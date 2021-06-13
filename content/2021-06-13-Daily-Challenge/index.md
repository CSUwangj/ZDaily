+++
title = "2021-06-13 Daily-Challenge"
path = "2021-06-13-Daily-Challenge"
date = 2021-06-13 03:21:08+08:00
updated = 2021-06-13 22:10:34+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3776/) with `cpp`.

<!-- more -->

# LeetCode Review

## My Calendar I

``` cpp
class MyCalendar {
  set<pair<int, int>> times;
public:
  MyCalendar(){}
  
  bool book(int start, int end) {
    auto it = times.upper_bound({start, end});
    if(it != times.end() && it->second < end) return false;
    times.insert({end, start});
    return true;
  }
};
```

## Stone Game VII

``` cpp
class Solution {
public:
  int stoneGameVII(vector<int>& stones) {
    int len = stones.size();
    int prefix[len + 1];
    prefix[0] = 0;
    for (int i = 0; i < len; ++i) prefix[i + 1] = prefix[i] + stones[i];
    int dp[len + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len; ++i) {
      for(int j = 0; j + i <= len; ++j) {
        int left = prefix[j + i - 1] - prefix[j] - dp[j][j + i - 1];
        int right = prefix[j + i] - prefix[j + 1] - dp[j + 1][j + i];
        dp[j][j + i] = max(left, right);
        // cout << j << ' ' << j << ' ' << dp[j][j + i] << endl;
      }
    }
    return dp[0][len];
  }
};


68 / 68 test cases passed.
Status: Accepted
Runtime: 136 ms
Memory Usage: 14 MB
```

optimize using locality, seems useless

``` cpp
class Solution {
public:
  int stoneGameVII(vector<int>& stones) {
    int len = stones.size();
    int prefix[len + 1];
    prefix[0] = 0;
    for (int i = 0; i < len; ++i) prefix[i + 1] = prefix[i] + stones[i];
    int dp[len + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    for (int l = len - 1; l >= 0; --l) {
      for(int r = l + 1; r <= len; ++r) {
        int left = prefix[r - 1] - prefix[l] - dp[l][r - 1];
        int right = prefix[r] - prefix[l + 1] - dp[l + 1][r];
        dp[l][r] = max(left, right);
        // cout << j << ' ' << j << ' ' << dp[j][j + i] << endl;
      }
    }
    return dp[0][len];
  }
};

// 68 / 68 test cases passed.
// Status: Accepted
// Runtime: 160 ms
// Memory Usage: 14.1 MB
```

# June LeetCoding Challenge13

## Description

**Palindrome Pairs**

Given a list of **unique** words, return all the pairs of the ***distinct\*** indices `(i, j)` in the given list, so that the concatenation of the two words `words[i] + words[j]` is a palindrome.

 

**Example 1:**

```
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
```

**Example 2:**

```
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
```

**Example 3:**

```
Input: words = ["a",""]
Output: [[0,1],[1,0]]
```

 

**Constraints:**

- `1 <= words.length <= 5000`
- `0 <= words[i].length <= 300`
- `words[i]` consists of lower-case English letters.

## Solution

DFS + trie, very clever solution, check [An7One's solution](https://leetcode.com/problems/palindrome-pairs/discuss/1270028/Kotlin-DFS-with-Trie)

``` cpp
struct TrieNode {
  TrieNode *children[26] = {};
  int index = -1;
  vector<int> palinIndex;
};

inline bool isPalindrome(const string &word, int start, int end) {
  while(start < end) {
    if(word[start] != word[end]) return false;
    start += 1;
    end -= 1;
  }
  return true;
}

void addWord(TrieNode *root, const string &word, int index) {
  int len = word.size();
  auto cur = root;
  for(int i = len - 1; i >= 0; i--) {
    int ch = word[i] - 'a';
    if(!(cur->children[ch])) cur->children[ch] = new TrieNode();
    if(isPalindrome(word, 0, i)) cur->palinIndex.push_back(index);

    cur = cur->children[ch];
  }
  cur->palinIndex.push_back(index);
  cur->index = index;
}

void search(TrieNode *root, vector<string> &words, int index, vector<vector<int>> &answer) {
  auto cur = root;
  auto curWord = words[index];
  int len = curWord.length();

  for(int i = 0; i < len; i++) {
    if(cur->index != -1 && cur->index != index && isPalindrome(curWord, i, len - 1)) {
      answer.push_back({index, cur->index});
    }
    cur = cur->children[curWord[i] - 'a'];
    if(!cur) return;
  }
  for(auto idxPalin : cur->palinIndex) {
    if(idxPalin == index) continue;
    answer.push_back({index, idxPalin});
  }
}

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    auto root = new TrieNode();
    int len = words.size();
    vector<vector<int>> answer;

    for(int i = 0; i < words.size(); ++i) addWord(root, words[i], i);
    for(int i = 0; i < words.size(); ++i) search(root, words, i, answer);

    return answer;
  }
};
```
