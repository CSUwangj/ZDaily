+++
updated = 2022-11-05T17:54:30+08:00
title = "2022-11-05 Daily Challenge"
path = "2022-11-05-Daily-Challenge"
date = 2022-11-05T17:54:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/word-search-ii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 5

## Description

**Word Search II**

<p>Given an <code>m x n</code> <code>board</code>&nbsp;of characters and a list of strings <code>words</code>, return <em>all words on the board</em>.</p>

<p>Each word must be constructed from letters of sequentially adjacent cells, where <strong>adjacent cells</strong> are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search1.jpg" style="width: 322px; height: 322px;" />
<pre>
<strong>Input:</strong> board = [[&quot;o&quot;,&quot;a&quot;,&quot;a&quot;,&quot;n&quot;],[&quot;e&quot;,&quot;t&quot;,&quot;a&quot;,&quot;e&quot;],[&quot;i&quot;,&quot;h&quot;,&quot;k&quot;,&quot;r&quot;],[&quot;i&quot;,&quot;f&quot;,&quot;l&quot;,&quot;v&quot;]], words = [&quot;oath&quot;,&quot;pea&quot;,&quot;eat&quot;,&quot;rain&quot;]
<strong>Output:</strong> [&quot;eat&quot;,&quot;oath&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search2.jpg" style="width: 162px; height: 162px;" />
<pre>
<strong>Input:</strong> board = [[&quot;a&quot;,&quot;b&quot;],[&quot;c&quot;,&quot;d&quot;]], words = [&quot;abcb&quot;]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>board[i][j]</code> is a lowercase English letter.</li>
	<li><code>1 &lt;= words.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
	<li>All the strings of <code>words</code> are unique.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  bool end = false;
  int count = 0;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c = c - 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
    cur->count += 1;
  }
  cur->end = true;
}
int prune(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  int backStep = word.length();
  // cout << word << endl;
  for(auto c : word) {
    // cout << c ;
    c = c - 'a';
    // cout << cur->child[c]->count;
    if(cur->child[c]->count == 1) {
      // delete then RE, fuck u leetcode
      cur->child[c] = nullptr;
      break;
    } else {
      backStep -= 1;
      cur = cur->child[c];
      cur->count -= 1;
    }
  }
  if(!backStep) cur->end = false;
  // cout << endl << backStep << endl;
  return backStep;
}
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  vector<string> words;
  string current;
  int rows;
  int cols;
  TrieNode *root = new TrieNode();
  void solve(const vector<vector<char>>& board, TrieNode *currentNode, int row, int col, int &backStep) {
    currentNode = currentNode->child[board[row][col] - 'a'];
    vis[row][col] = true;
    current.push_back(board[row][col]);
    if(currentNode) {
      if(currentNode->end) {
        words.push_back(current);
        backStep = prune(root, current);
      }
      for(int i = 0; !backStep && i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        solve(board, currentNode, newRow, newCol, backStep);
      }
    }
    if(backStep) {
      backStep -= 1;
    }
    vis[row][col] = false;
    current.pop_back();
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(auto &word : w) {
      insert(root, word);
    }
    int backStep = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j, backStep);
      }
    }
    return words;
  }
};

// Accepted
// 64/64 cases passed (227 ms)
// Your runtime beats 95.83 % of cpp submissions
// Your memory usage beats 35.69 % of cpp submissions (15.3 MB)
```
