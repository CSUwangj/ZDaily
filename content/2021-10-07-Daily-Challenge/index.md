+++
title = "2021-10-07 Daily-Challenge"
path = "2021-10-07-Daily-Challenge"
date = 2021-10-07 18:01:33+08:00
updated = 2021-10-07 18:15:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/word-search/) and [Word Search II](https://leetcode.com/problems/word-search-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 7

## Description

**Word Search**

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

 

**Constraints:**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.

 

**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

## Solution

``` cpp
struct TrieNode {
  bool end = false;
  TrieNode *child[128] = {};
};
void insert(TrieNode *root, string word) {
  TrieNode *cur = root;
  for(auto c : word) {
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
  }
  cur->end = true;
}
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  vector<string> words;
  string current;
  int rows;
  int cols;
  void solve(vector<vector<char>>& board, TrieNode *root, int row, int col) {
    root = root->child[board[row][col]];
    vis[row][col] = true;
    current.push_back(board[row][col]);
    if(root) {
      if(root->end) words.push_back(current);
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        solve(board, root, newRow, newCol);
      }
    }
    vis[row][col] = false;
    current.pop_back();
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    TrieNode *root = new TrieNode();
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    insert(root, word);
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j);
      }
    }
    return words.size();
  }
};

// Accepted
// 57/57 cases passed (312 ms)
// Your runtime beats 62.95 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (8.2 MB)
```

# Word Search II

## Description

Given an `m x n` `board` of characters and a list of strings `words`, return *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

 

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 12`
- `board[i][j]` is a lowercase English letter.
- `1 <= words.length <= 3 * 10^4`
- `1 <= words[i].length <= 10`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.

## Solution

``` cpp
struct TrieNode {
  bool end = false;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c = c - 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
  }
  cur->end = true;
}
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  vector<string> words;
  string current;
  int rows;
  int cols;
  void solve(vector<vector<char>>& board, TrieNode *root, int row, int col) {
    root = root->child[board[row][col] - 'a'];
    vis[row][col] = true;
    current.push_back(board[row][col]);
    if(root) {
      if(root->end) words.push_back(current);
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        solve(board, root, newRow, newCol);
      }
    }
    vis[row][col] = false;
    current.pop_back();
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
    TrieNode *root = new TrieNode();
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(auto &word : w) {
      insert(root, word);
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j);
      }
    }
    sort(words.begin(), words.end());
    words.resize(unique(words.begin(), words.end()) - words.begin());
    return words;
  }
};

// Accepted
// 51/51 cases passed (1948 ms)
// Your runtime beats 5.01 % of cpp submissions
// Your memory usage beats 5.12 % of cpp submissions (290.5 MB)
```
