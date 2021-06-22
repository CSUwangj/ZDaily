+++
title = "2021-06-22 Daily-Challenge"
path = "2021-06-22-Daily-Challenge"
date = 2021-06-22 19:44:33+08:00
updated = 2021-06-22 20:19:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3788/) with `cpp`.

<!-- more -->

# Brace Expansion II

## Description

Under the grammar given below, strings can represent a set of lowercase words. Let's use `R(expr)` to denote the set of words the expression represents.

Grammar can best be understood through simple examples:

- Single letters represent a singleton set containing that word.
  - `R("a") = {"a"}`
  - `R("w") = {"w"}`
- When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
  - `R("{a,b,c}") = {"a","b","c"}`
  - `R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)`
- When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
  - `R("{a,b}{c,d}") = {"ac","ad","bc","bd"}`
  - `R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}`

Formally, the three rules for our grammar:

- For every lowercase letter `x`, we have `R(x) = {x}`.
- For expressions `e1, e2, ... , ek` with `k >= 2`, we have `R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...`
- For expressions `e1` and `e2`, we have `R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}`, where `+` denotes concatenation, and `×` denotes the cartesian product.

Given an expression representing a set of words under the given grammar, return *the sorted list of words that the expression represents*.

 

**Example 1:**

```
Input: expression = "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]
```

**Example 2:**

```
Input: expression = "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.
```

 

**Constraints:**

- `1 <= expression.length <= 60`
- `expression[i]` consists of `'{'`, `'}'`, `','`or lowercase English letters.
- The given `expression` represents a set of words based on the grammar given in the description.

## Solution

a little bit complex...

``` cpp
int len;
vector<string> solve(string &expression, int &index) {
  vector<string> result;
  vector<string> cur = {""};
  while(index < len) {
    char c = expression[index];
    index += 1;
    if(c == '}') {
      break;
    }
    if(c == ',') {
      result.insert(
        result.end(), 
        make_move_iterator(cur.begin()),
        make_move_iterator(cur.end())
      );
      cur = {""};
    } else if(isalpha(c)) {
      for(auto &s : cur) {
        s.push_back(c);
      }
    } else if(c == '{') {
      vector<string> next;
      for(auto &res : solve(expression, index)) {
        for(auto &s : cur) {
          next.push_back(s + res);
        }
      }
      swap(next, cur);
    }
  }
  if(cur.front().length()) {
    result.insert(
        result.end(), 
        make_move_iterator(cur.begin()),
        make_move_iterator(cur.end())
    );
  }
  return result;
}

class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    len = expression.length();
    int index = 0;
    auto answer = solve(expression, index);
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};
```

# June LeetCoding Challenge22

## Description

**Number of Matching Subsequences**

Given a string `s` and an array of strings `words`, return *the number of* `words[i]` *that is a subsequence of* `s`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

 

**Example 1:**

```
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
```

**Example 2:**

```
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
```

 

**Constraints:**

- `1 <= s.length <= 5 * 104`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 50`
- `s` and `words[i]` consist of only lowercase English letters.

## Solution

interesting binary search!

``` cpp
class Solution {
  bool isSubsequence(const vector<vector<int>> &pos, string &word) {
    int prev = -1;
    for(auto c : word) {
      int cha = c - 'a';
      int idx = upper_bound(pos[cha].begin(), pos[cha].end(), prev) - pos[cha].begin();
      if(idx == pos[cha].size()) return false;
      prev = pos[cha][idx];
    }
    return true;
  }
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> pos(26);
    for(int i = 0; i < s.length(); ++i) {
      pos[s[i] - 'a'].push_back(i);
    }
    int answer = 0;
    for(auto &word : words) {
      answer += isSubsequence(pos, word);
    }
    return answer;
  }
};
```
