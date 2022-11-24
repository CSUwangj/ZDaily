+++
updated = 2022-11-24T12:21:08+08:00
title = "2022-11-24 Daily Challenge"
path = "2022-11-24-Daily-Challenge"
date = 2022-11-24T12:21:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/word-search/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 24

## Description

**Word Search**

<p>Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.</p>

<p>The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;ABCCED&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;SEE&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> board = [[&quot;A&quot;,&quot;B&quot;,&quot;C&quot;,&quot;E&quot;],[&quot;S&quot;,&quot;F&quot;,&quot;C&quot;,&quot;S&quot;],[&quot;A&quot;,&quot;D&quot;,&quot;E&quot;,&quot;E&quot;]], word = &quot;ABCB&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n = board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 6</code></li>
	<li><code>1 &lt;= word.length &lt;= 15</code></li>
	<li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?</p>


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
// 84/84 cases passed (724 ms)
// Your runtime beats 48.74 % of cpp submissions
// Your memory usage beats 5.54 % of cpp submissions (9.4 MB)
```
