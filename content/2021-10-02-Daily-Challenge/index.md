+++
title = "2021-10-02 Daily-Challenge"
path = "2021-10-02-Daily-Challenge"
date = 2021-10-02 18:00:00+08:00
updated = 2021-10-02 18:58:35+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/dungeon-game/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 2

## Description

**Dungeon Game**

The demons had captured the princess and imprisoned her in **the bottom-right corner** of a `dungeon`. The `dungeon` consists of `m x n` rooms laid out in a 2D grid. Our valiant knight was initially positioned in **the top-left room** and must fight his way through `dungeon` to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to `0` or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only **rightward** or **downward** in each step.

Return *the knight's minimum initial health so that he can rescue the princess*.

**Note** that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/13/dungeon-grid-1.jpg)

```
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
```

**Example 2:**

```
Input: dungeon = [[0]]
Output: 1
```

 

**Constraints:**

- `m == dungeon.length`
- `n == dungeon[i].length`
- `1 <= m, n <= 200`
- `-1000 <= dungeon[i][j] <= 1000`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon.front().size();
    if(dungeon.back().back() > 0) dungeon.back().back() = 0;
    for(int row = rows - 1; row >= 0; row -= 1) {
      for(int col = cols - 1; col >= 0; col -= 1) {
        if(col == cols - 1 && row == rows - 1) continue;
        int maxDown = row == rows - 1 ? INT_MIN : dungeon[row + 1][col];
        int maxRight = col == cols - 1 ? INT_MIN : dungeon[row][col + 1];
        int target = max(maxDown, maxRight) + dungeon[row][col];
        dungeon[row][col] = target < 0 ? target : 0;
      }
    }
    return dungeon.front().front() < 1 ? 1 - dungeon.front().front() : 1;
  }
};

// Accepted
// 45/45 cases passed (4 ms)
// Your runtime beats 95.38 % of cpp submissions
// Your memory usage beats 83.37 % of cpp submissions (8.7 MB)
```
