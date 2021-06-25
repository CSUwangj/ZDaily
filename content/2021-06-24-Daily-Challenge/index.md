+++
title = "2021-06-24 Daily-Challenge"
path = "2021-06-24-Daily-Challenge"
date = 2021-06-24 18:11:03+08:00
updated = 2021-06-24 19:56:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Guess the Word](https://leetcode.com/problems/guess-the-word/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3790/) with `cpp`.

<!-- more -->

# Guess the Word

## Description

This is an ***interactive problem***.

You are given an array of **unique** strings `wordlist` where `wordlist[i]` is `6` letters long, and one word in this list is chosen as `secret`.

You may call `Master.guess(word)` to guess a word. The guessed word should have type `string` and must be from the original list with `6` lowercase letters.

This function returns an `integer` type, representing the number of exact matches (value and position) of your guess to the `secret` word. Also, if your guess is not in the given wordlist, it will return `-1` instead.

For each test case, you have exactly `10` guesses to guess the word. At the end of any number of calls, if you have made `10` or fewer calls to `Master.guess` and at least one of these guesses was `secret`, then you pass the test case.

 

**Example 1:**

```
Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"], numguesses = 10
Output: You guessed the secret word correctly.
Explanation:
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
```

**Example 2:**

```
Input: secret = "hamada", wordlist = ["hamada","khaled"], numguesses = 10
Output: You guessed the secret word correctly.
```

 

**Constraints:**

- `1 <= wordlist.length <= 100`
- `wordlist[i].length == 6`
- `wordlist[i]` consist of lowercase English letters.
- All the strings of `wordlist` are **unique**.
- `secret` exists in `wordlist`.
- `numguesses == 10`

## Solution

``` cpp
const int N = 6;
inline int match(const string &a, const string &b) {
  int result = 0;
  for(int i = 0; i < 6; ++i) {
    result += a[i] == b[i];
  }
  return result;
}
class Solution {
  vector<vector<int>> adj;
  int len;
  void init(vector<string> & wordlist) {
    len = wordlist.size();
    adj.resize(len, vector<int>(len));
    for(int i = 0; i < len; ++i) {
      for(int j = i + 1; j < len; ++j) {
        adj[i][j] = adj[j][i] = match(wordlist[i], wordlist[j]);
      }
    }
    for(int i = 0; i < len; ++i) {
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        adj[i][i] += adj[i][j];
      }
    }
  }

  int getNextGuess() {
    int idx = -1;
    int maxAdj = -1;
    for(int i = 0; i < len; ++i) {
      if(adj[i][i] > maxAdj) {
        idx = i;
        maxAdj = adj[i][i];
      }
    }
    return idx;
  }

  void pruneGuess(int idx, int guess) {
    vector<int> toRemove{idx};
    if(!guess) {
      for(int i = 0; i < len; ++i) {
        if(adj[i][idx] > 0) toRemove.push_back(i);
      }
    } else {
      for(int i = 0; i < len; ++i) {
        if(adj[i][idx] < guess) toRemove.push_back(i);
      }
    }
    for(auto i : toRemove) {
      adj[i][i] = -1;
    }
  }
public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    if(wordlist.size() < 11) {
      for(auto &s : wordlist) master.guess(s);
      return;
    }
    init(wordlist);
    for(int i = 0; i < 10; ++i) {
      int g = getNextGuess();
      int result = master.guess(wordlist[g]);
      // cout << g << ' ' << result << ' ' << wordlist[g] << endl;
      if(result == 6) break;
      pruneGuess(g, result);
    }
  }
};
```

# June LeetCoding Challenge24

## Description

**Out of Boundary Paths**

There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of the grid crossing the grid boundary). You can apply **at most** `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** `109 + 7`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png)

```
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png)

```
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
```

 

**Constraints:**

- `1 <= m, n <= 50`
- `0 <= maxMove <= 50`
- `0 <= startRow <= m`
- `0 <= startColumn <= n`

## Solution

``` cpp
const int SZ = 50;
const int MOD = 1e9 + 7;
int path[2][SZ][SZ];
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(path[0], 0, sizeof(path[0]));
    path[0][startRow][startColumn] = 1;
    int result = 0;
    for(int cnt = 0; cnt < maxMove; cnt++) {
      int parity = cnt & 1;
      memset(path[!parity], 0, sizeof(path[0]));
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          // cout << path[parity][i][j] << ' ' ;
          for(int c = 0; c < 4; ++c) {
            int newRow = i + moves[c][0];
            int newCol = j + moves[c][1];
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
            path[!parity][newRow][newCol] += path[parity][i][j];
            path[!parity][newRow][newCol] %= MOD;
          }
        }
        // cout << endl;
      }
      // cout << endl;
      for(int i = 0; i < m; ++i) {
        result += path[parity][i][0];
        result %= MOD;
        result += path[parity][i][n - 1];
        result %= MOD;
      }
      for(int i = 0; i < n; ++i) {
        result += path[parity][0][i];
        result %= MOD;
        result += path[parity][m - 1][i];
        result %= MOD;
      }
    }
    return result;
  }
};
```
