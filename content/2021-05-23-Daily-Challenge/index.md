+++
title = "2021-05-23 Daily-Challenge"
path = "2021-05-23-Daily-Challenge"
date = 2021-05-23 15:03:55+08:00
updated = 2021-05-23 18:48:25+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge23

## Description

**Find the Shortest Superstring**

Given an array of strings `words`, return *the smallest string that contains each string in* `words` *as a substring*. If there are multiple valid strings of the smallest length, return **any of them**.

You may assume that no string in `words` is a substring of another string in `words`.

 

**Example 1:**

```
Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
```

**Example 2:**

```
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
```

 

**Constraints:**

- `1 <= words.length <= 12`
- `1 <= words[i].length <= 20`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are **unique**.

## Solution

DP

``` cpp
int prefix(string &pre, string &post) {
  int lPre = pre.length();
  int lPost = post.length();
  for(int len = min(lPre, lPost); len; --len) {
    bool ok = true;
    for(int i = 0; ok && i < len; ++i) {
      ok = pre[lPre - len + i] == post[i];
    }
    if(ok) return len;
  }
  return 0;
}
class Solution {
  int n;
  vector<int> len;
  vector<vector<int>> overlap;
  vector<unordered_map<int, int>> dp;
  vector<unordered_map<int, int>> next;

  void init(vector<string>& words) {
    n = words.size();
    dp.resize(n);
    len.resize(n);
    next.resize(n);
    overlap.resize(n, vector<int>(n));

    for(int i = 0; i < n; ++i) {
      len[i] = words[i].length();
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j) continue;
        overlap[i][j] = prefix(words[i], words[j]);
      }
    }
  }

  int solve(int idx, int mask) {
    // cout << idx << ' '<< mask<<endl;
    if(mask == (1 << n) - 1) return 0;
    if(dp[idx].count(mask)) return dp[idx][mask];
    dp[idx][mask] = INT_MAX;
    for(int i = 0; i < n; i++) {
      if(!(mask & (1 << i))) {
        int tmp = len[i] - overlap[idx][i] + solve(i, mask | (1 << i));
        if(tmp < dp[idx][mask]) {
          dp[idx][mask] = tmp;
          next[idx][mask] = i;
        }
      }
    }
    
    return dp[idx][mask];
  }

  string construct(vector<string>& words, int start) {
    int index = start;
    string answer = words[index];
    int state = 1 << index;
    while(state != (1 << n) - 1) {
      int nextIndex = next[index][state];
      answer += words[nextIndex].substr(overlap[index][nextIndex]);
      index = nextIndex;
      state |= 1 << nextIndex;
    }
    return answer;
  }
public:
  string shortestSuperstring(vector<string>& words) {
    init(words);
    int minLength = INT_MAX;
    int start = -1;
    for(int i = 0; i < n; ++i) {
      int cur = len[i] + solve(i, 1 << i);
      if(minLength > cur) {
        minLength = cur;
        start = i;
      }
    }
    
    return construct(words, start);
  }
};

// 83 / 83 test cases passed.
// Status: Accepted
// Runtime: 348 ms
// Memory Usage: 49.2 MB
```

using raw array

``` cpp
int prefix(string &pre, string &post) {
  int lPre = pre.length();
  int lPost = post.length();
  for(int len = min(lPre, lPost); len; --len) {
    bool ok = true;
    for(int i = 0; ok && i < len; ++i) {
      ok = pre[lPre - len + i] == post[i];
    }
    if(ok) return len;
  }
  return 0;
}
class Solution {
  int n;
  int len[20] = {};
  int overlap[20][20] = {};
  int dp[20][1 << 12] = {};
  int next[20][1 << 12];

  void init(vector<string>& words) {
    n = words.size();
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; ++i) {
      len[i] = words[i].length();
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j) continue;
        overlap[i][j] = prefix(words[i], words[j]);
      }
    }
  }

  int solve(int idx, int mask) {
    // cout << idx << ' '<< mask<<endl;
    if(mask == (1 << n) - 1) return 0;
    if(dp[idx][mask] != -1) return dp[idx][mask];
    dp[idx][mask] = INT_MAX;
    for(int i = 0; i < n; i++) {
      if(!(mask & (1 << i))) {
        int tmp = len[i] - overlap[idx][i] + solve(i, mask | (1 << i));
        if(tmp < dp[idx][mask]) {
          dp[idx][mask] = tmp;
          next[idx][mask] = i;
        }
      }
    }
    
    return dp[idx][mask];
  }

  string construct(vector<string>& words, int start) {
    int index = start;
    string answer = words[index];
    int state = 1 << index;
    while(state != (1 << n) - 1) {
      int nextIndex = next[index][state];
      answer += words[nextIndex].substr(overlap[index][nextIndex]);
      index = nextIndex;
      state |= 1 << nextIndex;
    }
    return answer;
  }
public:
  string shortestSuperstring(vector<string>& words) {
    init(words);
    int minLength = INT_MAX;
    int start = -1;
    for(int i = 0; i < n; ++i) {
      int cur = len[i] + solve(i, 1 << i);
      if(minLength > cur) {
        minLength = cur;
        start = i;
      }
    }
    
    return construct(words, start);
  }
};

// 83 / 83 test cases passed.
// Status: Accepted
// Runtime: 24 ms
// Memory Usage: 8.7 MB
```
