+++
updated = 2023-06-29T23:46:16+08:00
title = "2023-06-29 Daily Challenge"
path = "2023-06-29-Daily-Challenge"
date = 2023-06-29T23:46:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/shortest-path-to-get-all-keys/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 29

## Description

**Shortest Path to Get All Keys**

<p>You are given an <code>m x n</code> grid <code>grid</code> where:</p>

<ul>
	<li><code>&#39;.&#39;</code> is an empty cell.</li>
	<li><code>&#39;#&#39;</code> is a wall.</li>
	<li><code>&#39;@&#39;</code> is the starting point.</li>
	<li>Lowercase letters represent keys.</li>
	<li>Uppercase letters represent locks.</li>
</ul>

<p>You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.</p>

<p>If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.</p>

<p>For some <code><font face="monospace">1 &lt;= k &lt;= 6</font></code>, there is exactly one lowercase and one uppercase letter of the first <code>k</code> letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.</p>

<p>Return <em>the lowest number of moves to acquire all keys</em>. If it is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg" style="width: 404px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [&quot;@.a..&quot;,&quot;###.#&quot;,&quot;b.A.B&quot;]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Note that the goal is to obtain all the keys not to open all the locks.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-key2.jpg" style="width: 404px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [&quot;@..aA&quot;,&quot;..B#.&quot;,&quot;....b&quot;]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-keys3.jpg" style="width: 244px; height: 85px;" />
<pre>
<strong>Input:</strong> grid = [&quot;@Aa&quot;]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either an English letter, <code>&#39;.&#39;</code>, <code>&#39;#&#39;</code>, or <code>&#39;@&#39;</code>.</li>
	<li>The number of keys in the grid is in the range <code>[1, 6]</code>.</li>
	<li>Each key in the grid is <strong>unique</strong>.</li>
	<li>Each key in the grid has a matching lock.</li>
</ul>

## Solution

``` cpp
const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int shortestPathAllKeys(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    vector<set<int>> visit(rows * cols);

    int startR;
    int startC;
    int keys = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(grid[i][j] == '@') {
          startR = i;
          startC = j;
        } else if(islower(grid[i][j])) {
          keys = max(keys, grid[i][j] - 'a' + 1);
        } 
      }
    }

    int step = 0;
    queue<pair<int, int>> q;
    q.push({0, startR * cols + startC});
    visit[startR * cols + startC].insert(0);
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [state, position] = q.front();
        q.pop();
        if(state == (1 << keys) - 1) return step;
        int currentR = position / cols;
        int currentC = position % cols;
        for(int m = 0; m < 4; ++m) {
          int newR = currentR + MOVES[m][0];
          int newC = currentC + MOVES[m][1];
          if(newR < 0 || newC < 0 || newR >= rows || newC >= cols) continue; // out of bound
          if(grid[newR][newC] == '#') continue; // wall
          if(isupper(grid[newR][newC]) && !(state & (1 << (grid[newR][newC] - 'A')))) continue; // lock without key
          int newState = state;
          int newPosition = newR * cols + newC;
          if(islower(grid[newR][newC])) newState |= (1 << (grid[newR][newC] - 'a'));
          if(visit[newPosition].count(newState)) continue; // visited
          q.push({newState, newPosition});
          visit[newPosition].insert(newState);
        }
      }
      step += 1;
    }

    return -1;
  }
};

// Accepted
// 35/35 cases passed (108 ms)
// Your runtime beats 51.68 % of cpp submissions
// Your memory usage beats 55.37 % of cpp submissions (22.1 MB)
```
