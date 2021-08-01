+++
title = "2021-07-25 Daily-Challenge"
path = "2021-07-25-Daily-Challenge"
date = 2021-07-25 23:03:03+08:00
updated = 2021-07-25 23:29:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3826/) with `cpp`.

<!-- more -->

# LeetCode Review

## Word Ladder II

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, vector<string>> neighbors;
  vector<string> cur;
public:
  void backtrack(
    vector<vector<string>> &answer,
    vector<string> &cur,
    string beginWord,
    string &endWord
    ) {
      if (beginWord == endWord) {
        answer.push_back(cur);
        return;
      }
      for (int i = 0; i < neighbors[beginWord].size(); i++) {
        cur.push_back(neighbors[beginWord][i]);
        backtrack(answer, cur, neighbors[beginWord][i], endWord);
        cur.pop_back();
      }
  }
  
  void init(string beginWord, string endWord, unordered_set<string> &dict) {
    queue<string> q;
    q.push(beginWord);
    if(dict.count(beginWord)) {
      dict.erase(beginWord);
    }
    while(!q.empty())  {
      unordered_set<string> visited;
      while(!q.empty()){
        string cur = q.front(); 
        q.pop();
        string temp = cur;
        for(int i = 0; i < cur.size(); ++i){
          char c = cur[i];
          for(int j = 'a'; j <= 'z'; ++j){
            cur[i] = j;
            if(dict.count(cur)){
              visited.insert(cur);
              neighbors[temp].push_back(cur);
            }
          }
          cur[i] = c;
        }
      }
      if(visited.find(endWord) != visited.end()) break;
      for(auto word : visited) {
        q.push(word);
        dict.erase(word);
      }
    }
  }
  
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    init(beginWord, endWord, dict);
    vector<vector<string>> answer;
    vector<string> container{beginWord};
    backtrack(answer, container, beginWord, endWord); 
    return answer;
  }
};

// Accepted
// 32/32 cases passed (8 ms)
// Your runtime beats 94.58 % of cpp submissions
// Your memory usage beats 81.36 % of cpp submissions (9 MB)
```

# July LeetCoding Challenge 25

## Description

**Non-negative Integers without Consecutive Ones**

Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not** contain consecutive ones.

 

**Example 1:**

```
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
```

**Example 2:**

```
Input: n = 1
Output: 2
```

**Example 3:**

```
Input: n = 2
Output: 3
```

 

**Constraints:**

- `1 <= n <= 10^9`

## Solution

I came up with a solution which counts invalid numbers

``` cpp
long long dp[31] = {0, 1, 3, 8, 19, 43, 94, 201, 423, 880, 1815, 3719, 7582, 15397, 31171, 62952, 126891, 255379, 513342, 1030865, 2068495, 4147936, 8313583, 16655823, 33358014, 66791053, 133703499, 267603416, 535524643, 1071563515, 2143959070};
class Solution {
public:
  int findIntegers(int n) {
    // for(int i = 2; i < 31; ++i) {
    //   dp[i] = (1 << (i - 1)) + dp[i - 1] + dp[i - 2];
    // }
    // for(int i = 0; i < 31; ++i) {cout << dp[i] << endl;}
    int invalid = 0;
    for(int i = 30; i > 0; --i) {
      if(n & (1 << i)) {
        invalid += dp[i - 1];
        if(n & (1 << (i - 1))) {
          invalid += ((i == 30 ? INT_MAX : ((1 <<(i + 1)) - 1)) & n) - (1 << i) - (1 << (i - 1)) + 1;
          if(i > 1) invalid += dp[i - 2];
          break;
        }
      }
    }
    return n + 1 - invalid;
  }
};
```

then check solution and get a way counting valid numbers.

``` cpp
int dp[31] = {1, 2};
class Solution {
public:
  int findIntegers(int n) {
    for(int i = 2; i < 31; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    int prebit = 0;
    int answer = 0;
    for(int shift = 31; shift >= 0; --shift) {
      if(n & (1 << shift)) {
        answer += dp[shift];
        if(prebit) return answer;
        prebit = 1;
      } else {
        prebit = 0;
      }
    }
    return answer + 1;
  }
};

// Accepted
// 527/527 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.3 % of cpp submissions (5.8 MB)
```
