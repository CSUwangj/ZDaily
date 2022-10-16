+++
title = "2021-06-20 Daily-Challenge"
path = "2021-06-20-Daily-Challenge"
date = 2021-06-20 15:35:47+08:00
updated = 2021-06-20 17:10:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3776/) with `cpp`.

<!-- more -->

# LeetCode Review

## K Inverse Pairs Array

try to optimize by template metaprogramming

``` cpp
const int MOD = 1e9 + 7;
const int SZ = 1000;
template<int N>
struct Table{
  constexpr Table() : values() {
    if(N < 1) return;
    values[0][0] = 1;
    for(int i = 1; i <= N; ++i) {
      int nextJ = i * (i + 1) / 2;
      int J = i * (i - 1) / 2;
      J = J > SZ ? SZ : J;
      nextJ = nextJ > SZ ? SZ : nextJ;
      for(int j = 0; j <= J; ++j) {
        values[i][j] = (j ? values[i][j - 1] : 0) + values[i - 1][j] - (i > j ? 0 : values[i - 1][j - i]);
        values[i][j] = (values[i][j] % MOD + MOD) % MOD;
      }
      for(int j = J + 1; j <= nextJ; ++j) {
        values[i][j] = values[i][j - 1];
      }
    }
  }
  int values[N + 1][SZ + 1] = {};
};
constexpr auto table = Table<333>();
int values[2][SZ + 1] = {};

void compute(int n) {
  for(int i = 0; i <= SZ; ++i) values[1][i] = table.values[333][i];
  for(int i = 334; i <= n; ++i) {
    int parity = i & 1;
    int J = i * (i - 1) / 2;
    J = J > SZ ? SZ : J;
    for(int j = 0; j <= J; ++j) {
      values[parity][j] = (j ? values[parity][j - 1] : 0) + values[!parity][j] - (i > j ? 0 : values[!parity][j - i]);
      values[parity][j] = (values[parity][j] % MOD + MOD) % MOD;
    }
    for(int j = J + 1; j <= SZ; ++j) {
      values[parity][j] = values[parity][j - 1];
    }
  }
}


class Solution {
public:
  int kInversePairs(int n, int k) {
    if(!k) return 1;
    if(k == 1) return n - 1;
    int answer;
    if(n <= 333) {
      answer = table.values[n][k] - table.values[n][k - 1];
      answer = (answer % MOD + MOD) % MOD;
    } else {
      compute(n);
      int parity = n & 1;
      answer = values[parity][k] - values[parity][k - 1];
      answer = (answer % MOD + MOD) % MOD;
    }
    return answer;
  }
};

// Accepted
// 80/80 cases passed (40 ms)
// Your runtime beats 51.87 % of cpp submissions
// Your memory usage beats 87.17 % of cpp submissions (6.6 MB)
```

then found out plain solution get best result: 

``` cpp
const int N = 1001;
const int MOD = 1e9 + 7;

int values[N][N];

struct Solution {
  Solution() {
    if (values[0][0]) return;
    values[0][0] = 1;
    for (int i = 1; i < N; ++i) {
      int sum = 0;
      int end = min(N - 1, i * (i - 1) / 2);
      for (int j = 0; j <= end; ++j) {
        sum += values[i - 1][j];
        if (j >= i) sum -= values[i - 1][j - i];
        if (sum >= MOD) sum -= MOD;
        else if (sum < 0) sum += MOD;
        values[i][j] = sum;
      }
    }
  }

  int kInversePairs(int n, int k) const {
    return values[n][k];
  }
};

// Accepted
// 80/80 cases passed (4 ms)
// Your runtime beats 99.47 % of cpp submissions
// Your memory usage beats 85.03 % of cpp submissions (9.7 MB)
```

# June LeetCoding Challenge 20

## Description

**Swim in Rising Water**

On an N x N `grid`, each square `grid[i][j]` represents the elevation at that point `(i,j)`.

Now rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square `(0, 0)`. What is the least time until you can reach the bottom right square `(N-1, N-1)`?

**Example 1:**

```
Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

**Example 2:**

```
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

**Note:**

1. `2 <= N <= 50`.
2. `grid[i][j]` is a permutation of `[0, ..., N*N - 1]`.

## Solution

simple bfs

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
using ti = tuple<int, int, int>;
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int size = grid.size();
    int maxTime = size * size - 1;
    if(grid.front().front() == maxTime || grid.back().back() == maxTime) return maxTime;
    vector<vector<bool>> vis(size, vector<bool>(size));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = true;
    while(pq.size()) {
      auto [time, row, col] = pq.top();
      pq.pop();
      if(row == size - 1 && col == size - 1) return time;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) continue;
        if(vis[newRow][newCol]) continue;
        vis[newRow][newCol] = true;
        pq.push({max(time, grid[newRow][newCol]), newRow, newCol});
      }
    }
    return -1;
  }
};

// 41 / 41 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 8.5 MB
```

using pair make no difference.

``` cpp
using pi = tuple<int, int>;
class Solution {
  const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int swimInWater(vector<vector<int>>& grid) {
    int size = grid.size();
    int maxTime = size * size - 1;
    if(grid.front().front() == maxTime || grid.back().back() == maxTime) return maxTime;
    vector<vector<bool>> vis(size, vector<bool>(size));
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({grid[0][0], 0});
    vis[0][0] = true;
    while(pq.size()) {
      auto [time, index] = pq.top();
      int row = index / size;
      int col = index % size;
      pq.pop();
      if(row == size - 1 && col == size - 1) return time;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) continue;
        if(vis[newRow][newCol]) continue;
        vis[newRow][newCol] = true;
        pq.push({max(time, grid[newRow][newCol]), newRow * size + newCol});
      }
    }
    return -1;
  }
};

// 41 / 41 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// Memory Usage: 8.6 MB
```
