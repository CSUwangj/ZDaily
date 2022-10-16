+++
title = "2022-01-09 Daily-Challenge"
path = "2022-01-09-Daily-Challenge"
date = 2022-01-09 17:20:00+08:00
updated = 2022-01-09 17:23:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/robot-bounded-in-circle/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 9

## Description

**Robot Bounded In Circle**

On an infinite plane, a robot initially stands at `(0, 0)` and faces north. The robot can receive one of three instructions:

- `"G"`: go straight 1 unit;
- `"L"`: turn 90 degrees to the left;
- `"R"`: turn 90 degrees to the right.

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

**Example 1:**

```
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
```

**Example 2:**

```
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
```

**Example 3:**

```
Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
```

 

**Constraints:**

- `1 <= instructions.length <= 100`
- `instructions[i]` is `'G'`, `'L'` or, `'R'`.

## Solution

``` cpp
class Solution {
public:
  bool isRobotBounded(string instructions) {
    const int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x = 0;
    int y = 0;
    int direction = 0;
    for(int _ = 0; _ < 4; ++_) {
      for(auto instruction : instructions) {
        switch(instruction) {
          case 'G':
            x += moves[direction][1];
            y += moves[direction][0];
            break;
          case 'R':
            direction = (direction + 1) % 4;
            break;
          case 'L':
            direction = (direction + 3) % 4;
            break;
        }
      }
    } 
    return !x && !y;
  }
};

// Accepted
// 116/116 cases passed (5 ms)
// Your runtime beats 7.9 % of cpp submissions
// Your memory usage beats 48.4 % of cpp submissions (6.1 MB)
```
