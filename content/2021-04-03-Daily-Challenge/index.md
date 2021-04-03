+++
title = "2021-04-03 Daily-Challenge"
path = "2021-04-03-Daily-Challenge"
date = 2021-04-03 17:44:47+08:00
updated = 2021-04-03 21:59:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3686/) with `cpp`.

I was busy moving today, hope this post could come soon.



<!-- more -->

# LeetCode Review

## Search Suggestions System

already done a good work

## Longest Increasing Subsequence

too easy to review

## Unique Paths

if grid is `m x n`, image we have a list of commands robots need to execute, it must contain `m - 1` move right, and `n - 1` move down.

so answer is $C^{m + n -2}_{m - 1}$ or $C^{m + n - 2}_{n - 1}$

``` cpp
constexpr int combination(int total, int pick) {
  long long result = 1;
  for(int i = 0; i < pick; ++i) {
    result *= (total - i);
    result /= (i + 1);
  }
  return result;
}

class Solution {
public:
  int uniquePaths(int m, int n) {
    return combination(m + n - 2, min(n - 1, m - 1));
  }
};
```

## Coin Change 2

too easy to review

## Count Unique Characters of All Substrings of a Given String

``` cpp
const int MOD = 1e9 + 7;

class Solution {
public:
  int uniqueLetterString(string s) {
    int len = s.length();
    int answer = 0;
    int dp[26][2];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < len; ++i) {
      int ci = s[i] - 'A';
      answer += (dp[ci][1] - dp[ci][0]) * (i - dp[ci][1]);
      answer %= MOD;
      dp[ci][0] = dp[ci][1];
      dp[ci][1] = i;
    }
    for(int i = 0; i < 26; ++i) {
      if(dp[i][1] != -1) {
        answer += (len - dp[i][1]) * (dp[i][1] - dp[i][0]);
        answer %= MOD;
      }
    }
    
    return answer;
  }
};
```

## Stamping The Sequence

``` cpp
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    int sLen = stamp.length();
    int tLen = target.length();
    vector<int> answer;
    string helper(tLen, '?');
    bool found = false;
    do {
      found = false;
      for(int i = 0; i <= tLen - sLen; ++i) {
        bool add = false;
        int match = 0;
        for(int j = 0; j < sLen; ++j) {
          if(helper[i + j] != '?') {
            match += 1;
          } else if(stamp[j] == target[i + j]) {
            match += 1;
            add = true;
          }
        }
        if(add && match == sLen) {
          for(int j = 0; j < sLen; ++j) if(helper[i + j] == '?') helper[i + j] = stamp[j];
          answer.push_back(i);
          found = true;
        }
      }
    } while(found);
    if(find(helper.begin(), helper.end(), '?') != helper.end()) return {};
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
```

## Russian Doll Envelopes

``` cpp
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> dp;
    for(auto &e : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), e[1]);
      if(it == dp.end()) {
        dp.push_back(e[1]);
      } else {
        *it = e[1];
      }
    }
    return dp.size();
  }
};
```

## Flip Binary Tree To Match Preorder Traversal

``` cpp
class Solution {
  bool flipMatchVoyage(TreeNode *root, const vector<int>& voyage, int &pos, vector<int> &answer) {
    if(!root) return true;
    if(root->val != voyage[pos]) return false;
    pos += 1;
    if(root->left && root->left->val != voyage[pos]) {
      answer.push_back(root->val);
      return flipMatchVoyage(root->right, voyage, pos, answer) && flipMatchVoyage(root->left, voyage, pos, answer);
    }
    return flipMatchVoyage(root->left, voyage, pos, answer) && flipMatchVoyage(root->right, voyage, pos, answer);
  }
public:
  vector<int> flipMatchVoyage(TreeNode* root, const vector<int>& voyage) {
    int pos = 0;
    vector<int> answer;
    if(!flipMatchVoyage(root, voyage, pos, answer)) return {-1};
    return answer;
  }
};
```

## Single Number

too easy to review

## Single Number II

too easy to review

## Single Number III

too easy to review

## Palindrome Linked List

too easy to review

## Ones and Zeroes

too easy to review

# April LeetCoding Challenge3

**Longest Valid Parentheses**

## Description

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

 

**Example 1:**

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

**Example 2:**

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Example 3:**

```
Input: s = ""
Output: 0
```

 

**Constraints:**

- <code>0 <= s.length <= 3 * 10<sup>4</sup></code>
- `s[i]` is `'('`, or `')'`.

## Solution

``` cpp
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> st;
    int answer = 0;
    int cur = 0;
    for(auto c : s) {
      if(c == '(') {
        st.push_back(cur);
        cur = 0;
      } else {
        if(!st.size()) {
          cur = 0;
          continue;
        }
        cur += st.back() + 2;
        st.pop_back();
        answer = max(answer, cur);
      }
    }
    return answer;
  }
};
```
