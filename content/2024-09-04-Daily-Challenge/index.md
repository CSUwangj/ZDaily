+++
updated = 2024-09-04T16:13:57+08:00
title = "2024-09-04 Daily Challenge"
path = "2024-09-04-Daily-Challenge"
date = 2024-09-04T16:13:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/walking-robot-simulation/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 4

## Description

**Walking Robot Simulation**

<p>A robot on an infinite XY-plane starts at point <code>(0, 0)</code> facing north. The robot can receive a sequence of these three possible types of <code>commands</code>:</p>

<ul>
	<li><code>-2</code>: Turn left <code>90</code> degrees.</li>
	<li><code>-1</code>: Turn right <code>90</code> degrees.</li>
	<li><code>1 &lt;= k &lt;= 9</code>: Move forward <code>k</code> units, one unit at a time.</li>
</ul>

<p>Some of the grid squares are <code>obstacles</code>. The <code>i<sup>th</sup></code> obstacle is at grid point <code>obstacles[i] = (x<sub>i</sub>, y<sub>i</sub>)</code>. If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.</p>

<p>Return <em>the <strong>maximum Euclidean distance</strong> that the robot ever gets from the origin <strong>squared</strong> (i.e. if the distance is </em><code>5</code><em>, return </em><code>25</code><em>)</em>.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>North means +Y direction.</li>
	<li>East means +X direction.</li>
	<li>South means -Y direction.</li>
	<li>West means -X direction.</li>
	<li>There can be obstacle in&nbsp;[0,0].</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> commands = [4,-1,3], obstacles = []
<strong>Output:</strong> 25
<strong>Explanation:</strong> The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 3<sup>2</sup> + 4<sup>2</sup> = 25 units away.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> commands = [4,-1,4,-2,4], obstacles = [[2,4]]
<strong>Output:</strong> 65
<strong>Explanation:</strong> The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
4. Turn left.
5. Move north 4 units to (1, 8).
The furthest point the robot ever gets from the origin is (1, 8), which squared is 1<sup>2</sup> + 8<sup>2</sup> = 65 units away.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> commands = [6,-1,-1,6], obstacles = []
<strong>Output:</strong> 36
<strong>Explanation:</strong> The robot starts at (0, 0):
1. Move north 6 units to (0, 6).
2. Turn right.
3. Turn right.
4. Move south 6 units to (0, 0).
The furthest point the robot ever gets from the origin is (0, 6), which squared is 6<sup>2</sup> = 36 units away.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= commands.length &lt;= 10<sup>4</sup></code></li>
	<li><code>commands[i]</code> is either <code>-2</code>, <code>-1</code>, or an integer in the range <code>[1, 9]</code>.</li>
	<li><code>0 &lt;= obstacles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 3 * 10<sup>4</sup></code></li>
	<li>The answer is guaranteed to be less than <code>2<sup>31</sup></code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    map<int, set<int>> ob;
    for(const auto &o : obstacles) {
      ob[o[0]].insert(o[1]);
    }

    int currentX = 0;
    int currentY = 0;
    int direction = 0;
    int answer = 0;
    for(auto c : commands) {
      if(c == -2) {
        direction += 3;
        direction %= 4;
      } else if (c == -1) {
        direction += 1;
        direction %= 4;
      } else {
        while(c-- && !ob[currentX + MOVES[direction][0]].count(currentY + MOVES[direction][1])) {
          currentX += MOVES[direction][0];
          currentY += MOVES[direction][1];
        }
      }
      answer = max(answer, currentX * currentX + currentY * currentY);
    }
    return answer;
  }
};
```
