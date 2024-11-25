+++
updated = 2024-11-25T22:16:30+08:00
title = "2024-11-25 Daily Challenge"
path = "2024-11-25-Daily-Challenge"
date = 2024-11-25T22:16:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/sliding-puzzle/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 25

## Description

**Sliding Puzzle**

<p>On an <code>2 x 3</code> board, there are five tiles labeled from <code>1</code> to <code>5</code>, and an empty square represented by <code>0</code>. A <strong>move</strong> consists of choosing <code>0</code> and a 4-directionally adjacent number and swapping it.</p>

<p>The state of the board is solved if and only if the board is <code>[[1,2,3],[4,5,0]]</code>.</p>

<p>Given the puzzle board <code>board</code>, return <em>the least number of moves required so that the state of the board is solved</em>. If it is impossible for the state of the board to be solved, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/slide1-grid.jpg" style="width: 244px; height: 165px;" />
<pre>
<strong>Input:</strong> board = [[1,2,3],[4,0,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap the 0 and the 5 in one move.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/slide2-grid.jpg" style="width: 244px; height: 165px;" />
<pre>
<strong>Input:</strong> board = [[1,2,3],[5,4,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No number of moves will make the board solved.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/slide3-grid.jpg" style="width: 244px; height: 165px;" />
<pre>
<strong>Input:</strong> board = [[4,1,2],[5,0,3]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 2</code></li>
	<li><code>board[i].length == 3</code></li>
	<li><code>0 &lt;= board[i][j] &lt;= 5</code></li>
	<li>Each value <code>board[i][j]</code> is <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const static inline vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, 
                                                       {0, 4}, {1, 3, 5}, {2, 4}};
  using psi = pair<string, int>;
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    string target = "123450";
    string current(6, ' ');
    int position = -1;
    for(int i = 0; i < 6; ++i) {
      current[i] = '0' + board[i / 3][i % 3];
      if(current[i] == '0') position = i;
    };
    if(target == current) return 0;

    unordered_set<string> visit;
    visit.reserve(720);
    queue<psi> q;
    q.push({current, position});

    for(int move = 0; q.size(); ++move) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [current, pos] = q.front();
        if(current == target) return move;
        q.pop();

        for(auto next : neighbors[pos]) {
          swap(current[next], current[pos]);

          if(!visit.count(current)) {
            visit.insert(current);
            q.push({current, next});
          }
          swap(current[next], current[pos]);
        }
      }
    }
    return -1;
  }
};
```
