+++
title = "2020-09-30 Daily-Challenge"
path = "2020-09-30-Daily-Challenge"
date = 2020-09-30
updated = 2020-09-30 15:33:42+08:00

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on Page 45 and *As Far from Land as Possible* on [leetcode](https://leetcode.com/problems/as-far-from-land-as-possible/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:
  - first one
    - [F] there too many ways of alignment, use unified alignment like left align.
    - [HT] separate contact information
  - second one
    - [F] there are central align and left align, where central align with multiple midlines. use
left align and align with fewer alignments
    - [HT] remove unnecessary information like `Horseback Riding`、`For more ... ride call:`
    - [HT] remove `Est. 2003`

finding differences is so different from thinking about improvements, the later one is so hard...

# As Far from Land as Possible

## Description

Given an N x N `grid` containing only values `0` and `1`, where `0` represents water and `1` represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the *Manhattan distance*: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

If no land or water exists in the grid, return `-1`.

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG)**

```
Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG)**

```
Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.
```

**Note:**

1. `1 <= grid.length == grid[0].length <= 100`
2. `grid[i][j]` is `0` or `1`

## Solution

simple bfs with multiple starting points.

``` cpp
class Solution {
public:
  int bfs(vector<vector<int>>& grid, queue<int>& q) {
    int ans = 0;
    while(q.size()) {
      int i = q.front();
      q.pop();
      int j = q.front();
      q.pop();
      int cnt = q.front();
      q.pop();
      if (cnt > ans) {
        ans = cnt;
      }
      for (int m = 0; m < 4; ++m) {
        if (i+move[m][0] >= 0 && i+move[m][0] < len && j+move[m][1] >= 0 && j+move[m][1] < len &&
            !visited[i+move[m][0]][j+move[m][1]] && !grid[i+move[m][0]][j+move[m][1]]) {
          visited[i+move[m][0]][j+move[m][1]] = true;
          q.push(i+move[m][0]);
          q.push(j+move[m][1]);
          q.push(cnt+1);
        }
      }
    }
    return ans;
  }
  int maxDistance(vector<vector<int>>& grid) {
    queue<int> q;
    len = grid[0].size();
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        if(grid[i][j] == 1) {
          q.push(i);
          q.push(j);
          q.push(0);
        }
      }
    }
    if (q.size() == len*len*3 || !q.size()) {
      return -1;
    }
    return bfs(grid, q);
  }
private:
  bool visited[100][100] = {};
  int move[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
  int len;
};
```