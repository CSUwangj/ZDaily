+++
updated = 2022-09-17 18:14:00+08:00
title = "2022-09-17 Daily-Challenge"
path = "2022-09-17-Daily-Challenge"
date = 2022-09-17 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/palindrome-pairs/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 17

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

// Accepted
// 136/136 cases passed (857 ms)
// Your runtime beats 89.68 % of cpp submissions
// Your memory usage beats 16.33 % of cpp submissions (599.1 MB)
```
