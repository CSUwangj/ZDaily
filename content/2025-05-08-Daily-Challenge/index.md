+++
updated = 2025-05-08T12:25:20+08:00
title = "2025-05-08 Daily Challenge"
path = "2025-05-08-Daily-Challenge"
date = 2025-05-08T12:25:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 8

## Description

**Find Minimum Time to Reach Last Room II**

<p>There is a dungeon with <code>n x m</code> rooms arranged as a grid.</p>

<p>You are given a 2D array <code>moveTime</code> of size <code>n x m</code>, where <code>moveTime[i][j]</code> represents the <strong>minimum</strong> time in seconds when you can <strong>start moving</strong> to that room. You start from the room <code>(0, 0)</code> at time <code>t = 0</code> and can move to an <strong>adjacent</strong> room. Moving between <strong>adjacent</strong> rooms takes one second for one move and two seconds for the next, <strong>alternating</strong> between the two.</p>

<p>Return the <strong>minimum</strong> time to reach the room <code>(n - 1, m - 1)</code>.</p>

<p>Two rooms are <strong>adjacent</strong> if they share a common wall, either <em>horizontally</em> or <em>vertically</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">moveTime = [[0,4],[4,4]]</span></p>

<p><strong>Output:</strong> 7</p>

<p><strong>Explanation:</strong></p>

<p>The minimum time required is 7 seconds.</p>

<ul>
	<li>At time <code>t == 4</code>, move from room <code>(0, 0)</code> to room <code>(1, 0)</code> in one second.</li>
	<li>At time <code>t == 5</code>, move from room <code>(1, 0)</code> to room <code>(1, 1)</code> in two seconds.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">moveTime = [[0,0,0,0],[0,0,0,0]]</span></p>

<p><strong>Output:</strong> 6</p>

<p><strong>Explanation:</strong></p>

<p>The minimum time required is 6 seconds.</p>

<ul>
	<li>At time <code>t == 0</code>, move from room <code>(0, 0)</code> to room <code>(1, 0)</code> in one second.</li>
	<li>At time <code>t == 1</code>, move from room <code>(1, 0)</code> to room <code>(1, 1)</code> in two seconds.</li>
	<li>At time <code>t == 3</code>, move from room <code>(1, 1)</code> to room <code>(1, 2)</code> in one second.</li>
	<li>At time <code>t == 4</code>, move from room <code>(1, 2)</code> to room <code>(1, 3)</code> in two seconds.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">moveTime = [[0,1],[1,2]]</span></p>

<p><strong>Output:</strong> 4</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == moveTime.length &lt;= 750</code></li>
	<li><code>2 &lt;= m == moveTime[i].length &lt;= 750</code></li>
	<li><code>0 &lt;= moveTime[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
inline constexpr int nextTime(int t) {
  return t % 3 ? t + 2 : t + 1;
}
class Solution {  
  using pi = pair<int, int>;
  const int MASK = (1 << 30) - 1;
  const int MOVES[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int rows = moveTime.size();
    int cols = moveTime.front().size();
    int target = rows * cols - 1;

    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, 1 << 30});
    set<int> visited;
    while(pq.size()) {
      auto [time, state] = pq.top();
      int position = state & MASK;
      pq.pop();
      if(position == target) return time;
      if(visited.count(position)) continue;
      visited.insert(position);

      int row = position / cols;
      int col = position % cols;
      int step = 2 - (state >> 30);
      for(int m = 0; m < 4; ++m) {
        int newRow = row + MOVES[m][0];
        int newCol = col + MOVES[m][1];
        int newPos = newRow * cols + newCol;
        int newState = (!(2 - step) << 30) | newPos;
        if(newCol < 0 || newRow < 0 || newCol >= cols || newRow >= rows) continue;
        if(visited.count(newPos)) continue;
        pq.push({max(time + step, moveTime[newRow][newCol] + step), newState});
      }
    }
    return -1;
  }
};

// Accepted
// 717/717 cases passed (1356 ms)
// Your runtime beats 11.81 % of cpp submissions
// Your memory usage beats 38.93 % of cpp submissions (146.5 MB)
```
