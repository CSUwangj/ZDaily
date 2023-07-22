+++
updated = 2023-07-22T12:10:06+08:00
title = "2023-07-22 Daily Challenge"
path = "2023-07-22-Daily-Challenge"
date = 2023-07-22T12:10:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/knight-probability-in-chessboard/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 22

## Description

**Knight Probability in Chessboard**

<p>On an <code>n x n</code> chessboard, a knight starts at the cell <code>(row, column)</code> and attempts to make exactly <code>k</code> moves. The rows and columns are <strong>0-indexed</strong>, so the top-left cell is <code>(0, 0)</code>, and the bottom-right cell is <code>(n - 1, n - 1)</code>.</p>

<p>A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.</p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 300px; height: 300px;" />
<p>Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.</p>

<p>The knight continues moving until it has made exactly <code>k</code> moves or has moved off the chessboard.</p>

<p>Return <em>the probability that the knight remains on the board after it has stopped moving</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3, k = 2, row = 0, column = 0
<strong>Output:</strong> 0.06250
<strong>Explanation:</strong> There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 0, row = 0, column = 0
<strong>Output:</strong> 1.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 25</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
	<li><code>0 &lt;= row, column &lt;= n - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOVES[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
  const double EPS = 1e-10;
public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> probability(n, vector<double>(n));
    probability[row][column] = 1;
    queue<pair<int, int>> q;
    q.push({row, column});

    while(k--) {
      vector<vector<double>> next(n, vector<double>(n));
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int m = 0; m < 8; ++m) {
          int newRow = row + MOVES[m][0];
          int newCol = col + MOVES[m][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(next[newRow][newCol] < EPS) {
            q.push({newRow, newCol});
          }
          next[newRow][newCol] += probability[row][col] / 8;
        }
      }
      probability = next;
    }
    double answer = 0;
    for(int i = 0; i < n; ++i) {
      answer += accumulate(probability[i].begin(), probability[i].end(), 0.0);
    }

    return answer;
  }
};

// Accepted
// 22/22 cases passed (26 ms)
// Your runtime beats 43.39 % of cpp submissions
// Your memory usage beats 23.55 % of cpp submissions (10 MB)
```
