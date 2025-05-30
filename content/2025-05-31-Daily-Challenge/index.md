+++
updated = 2025-06-01T02:47:06+08:00
title = "2025-05-31 Daily Challenge"
path = "2025-05-31-Daily-Challenge"
date = 2025-06-01T02:47:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/snakes-and-ladders/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 31

## Description

**Snakes and Ladders**

<p>You are given an <code>n x n</code> integer matrix <code>board</code> where the cells are labeled from <code>1</code> to <code>n<sup>2</sup></code> in a <a href="https://en.wikipedia.org/wiki/Boustrophedon" target="_blank"><strong>Boustrophedon style</strong></a> starting from the bottom left of the board (i.e. <code>board[n - 1][0]</code>) and alternating direction each row.</p>

<p>You start on square <code>1</code> of the board. In each move, starting from square <code>curr</code>, do the following:</p>

<ul>
	<li>Choose a destination square <code>next</code> with a label in the range <code>[curr + 1, min(curr + 6, n<sup>2</sup>)]</code>.

	<ul>
		<li>This choice simulates the result of a standard <strong>6-sided die roll</strong>: i.e., there are always at most 6 destinations, regardless of the size of the board.</li>
	</ul>
	</li>
	<li>If <code>next</code> has a snake or ladder, you <strong>must</strong> move to the destination of that snake or ladder. Otherwise, you move to <code>next</code>.</li>
	<li>The game ends when you reach the square <code>n<sup>2</sup></code>.</li>
</ul>

<p>A board square on row <code>r</code> and column <code>c</code> has a snake or ladder if <code>board[r][c] != -1</code>. The destination of that snake or ladder is <code>board[r][c]</code>. Squares <code>1</code> and <code>n<sup>2</sup></code> are not the starting points of any snake or ladder.</p>

<p>Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do <strong>not</strong> follow the subsequent&nbsp;snake or ladder.</p>

<ul>
	<li>For example, suppose the board is <code>[[-1,4],[-1,3]]</code>, and on the first move, your destination square is <code>2</code>. You follow the ladder to square <code>3</code>, but do <strong>not</strong> follow the subsequent ladder to <code>4</code>.</li>
</ul>

<p>Return <em>the least number of dice rolls required to reach the square </em><code>n<sup>2</sup></code><em>. If it is not possible to reach the square, return </em><code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/09/23/snakes.png" style="width: 500px; height: 394px;" />
<pre>
<strong>Input:</strong> board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> board = [[-1,-1],[-1,3]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == board.length == board[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>board[i][j]</code> is either <code>-1</code> or in the range <code>[1, n<sup>2</sup>]</code>.</li>
	<li>The squares labeled <code>1</code> and <code>n<sup>2</sup></code> are not the starting points of any snake or ladder.</li>
</ul>


## Solution

``` cpp
class Solution {
  pair<int, int> getCoordinate(int n, int pos) {
    int rowOffset = (pos - 1) / n;
    int colOffset = (pos - 1) % n;

    int row = n - 1 - rowOffset;
    int col = rowOffset % 2 ? n - 1 - colOffset : colOffset;
    return {row, col};
  }
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> visits(n * n + 1);

    queue<int> q;
    q.push(1);
    visits[1] = true;
    int step = 0;

    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        int cur = q.front();
        // cout << cur << ':' << endl;
        if(cur == n * n) return step;
        q.pop();
        for(int i = 1; i < 7; ++i) {
          int next = cur + i;
          if(next > n * n) break;
          auto [row, col] = getCoordinate(n, next);
          // cout << row << ' ' << col;
          if(board[row][col] != -1) {
            next = board[row][col];
          }
          // cout << ' ' << next << endl;
          if(visits[next]) continue;
          visits[next] = true;
          q.push(next);
        }
      }
      step += 1;
    }

    return -1;
  }
};

// Accepted
// 216/216 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 57.46 % of cpp submissions (17.1 MB)
```
