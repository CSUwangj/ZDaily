+++
title = "2021-07-29 Daily-Challenge"
path = "2021-07-29-Daily-Challenge"
date = 2021-07-29 15:33:22+08:00
updated = 2021-07-29 16:09:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3831/) with `cpp`.

<!-- more -->

# Longest Substring Of All Vowels in Order

## Description

A string is considered **beautiful** if it satisfies the following conditions:

- Each of the 5 English vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`) must appear **at least once** in it.
- The letters must be sorted in **alphabetical order** (i.e. all `'a'`s before `'e'`s, all `'e'`s before `'i'`s, etc.).

For example, strings `"aeiou"` and `"aaaaaaeiiiioou"` are considered **beautiful**, but `"uaeio"`, `"aeoiu"`, and `"aaaeeeooo"` are **not beautiful**.

Given a string `word` consisting of English vowels, return *the **length of the longest beautiful substring** of* `word`*. If no such substring exists, return* `0`.

A **substring** is a contiguous sequence of characters in a string.

 

**Example 1:**

```
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
```

**Example 2:**

```
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.
```

**Example 3:**

```
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.
```

 

**Constraints:**

- `1 <= word.length <= 5 * 10^5`
- `word` consists of characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int len = word.length();
    int vPos = 0;
    int answer = 0;
    int cur = 0;
    int pos = 0;
    while(pos < len) {
      if(word[pos] != vowels[vPos]) {
        if(vPos) vPos = 0;
        else pos += 1;
        cur = 0;
      } else {
        while(pos < len && word[pos] == vowels[vPos]) {
          pos += 1;
          cur += 1;
        }
        vPos += 1;
        if(vPos == 5) {
          answer = max(answer, cur);
          vPos = 0;
          cur = 0;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 120/120 cases passed (51 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.36 % of cpp submissions (26.7 MB)
```

# July LeetCoding Challenge29

## Description

**01 Matrix**

Given an `m x n` binary matrix `mat`, return *the distance of the nearest* `0` *for each cell*.

The distance between two adjacent cells is `1`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)

```
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 104`
- `1 <= m * n <= 104`
- `mat[i][j]` is either `0` or `1`.
- There is at least one `0` in `mat`.

## Solution

just construct it

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<vector<bool>> vis(rows, vector<bool>(cols));
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j]) {
          vis[i][j] = true;
          q.push({i, j});
        }
      }
    }
    int cnt = 1;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int newRow = row + moves[i][0];
          int newCol = col + moves[i][1];
          if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
          if(vis[newRow][newCol]) continue;
          // cout << newRow << ' ' << newCol << ' ' << cnt << endl;
          vis[newRow][newCol] = true;
          mat[newRow][newCol] = cnt;
          q.push({newRow, newCol});
        }
      }
      cnt += 1;
    }
    return mat;
  }
};

// Accepted
// 49/49 cases passed (60 ms)
// Your runtime beats 90.4 % of cpp submissions
// Your memory usage beats 31.48 % of cpp submissions (30.8 MB)
```

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(auto &row : mat) {
      for(auto &i : row) if(i) i = 10000;
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j]) continue;
        if(i) mat[i][j] = min(mat[i][j], mat[i - 1][j] + 1);
        if(j) mat[i][j] = min(mat[i][j], mat[i][j - 1] + 1);
      }
    }
    for(int i = rows - 1; i >= 0; --i) {
      for(int j = cols - 1; j >= 0; --j) {
        if(!mat[i][j]) continue;
        if(i != rows - 1) mat[i][j] = min(mat[i][j], mat[i + 1][j] + 1);
        if(j != cols - 1) mat[i][j] = min(mat[i][j], mat[i][j + 1] + 1);
      }
    }
    return mat;
  }
};

// Accepted
// 49/49 cases passed (56 ms)
// Your runtime beats 95.88 % of cpp submissions
// Your memory usage beats 96.98 % of cpp submissions (26.1 MB)
```
