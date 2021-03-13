+++
title = "2021-03-13 Daily-Challenge"
path = "2021-03-13-Daily-Challenge"
date = 2021-03-13 15:12:45+08:00
updated = 2021-03-13 23:36:41+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3670/) with `cpp`.


<!-- more -->

# LeetCode Review

## Add to Array-Form of Integer

too easy to review

## Guess Number Higher or Lower

too easy to review

## Generate Random Point in a Circle

too easy to review

## Remove Palindromic Subsequences

too easy to review

## Add One Row to Tree

too easy to review

## Integer to Roman

too easy to review

## Coin Change

too easy to review

## Check If a String Contains All Binary Codes of Size K

too easy to review

## Find Servers That Handled Most Number of Requests

``` cpp
using pii = pair<int, int>;
class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    set<int> ok;
    for(int i = 0; i < k; ++i) ok.insert(i);
    
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> count(k);
    int len = arrival.size();
    for(int i = 0; i < len; ++i) {
      while(!q.empty() && q.top().first <= arrival[i]) {
        ok.insert(q.top().second);
        q.pop();
      }
      if(ok.empty()) continue;
      auto it = ok.lower_bound(i % k);
      it = it == ok.end() ? ok.begin() : it;
      int server = *it;
      count[server] += 1;
      ok.erase(server);
      q.push(make_pair(arrival[i] + load[i], server));
    }
    
    int maxRequest = *max_element(count.begin(), count.end());
    vector<int> answer;
    for(int i = 0; i < k; ++i) if(count[i] == maxRequest) answer.push_back(i);
    
    return answer;
  }
};
```

## Minimum Moves to Move a Box to Their Target Location

I try to optimize memory usage by using int to represent position, but get a far worse performance.

``` cpp
struct State {
  char boxR;
  char boxC;
  char playerR;
  char playerC;
};

struct Position {
  char row;
  char col;
};

constexpr State recover(int state) {
  return State {
    .boxR = char(state / 8000),
    .boxC = char(state / 400 % 20),
    .playerR = char(state / 20 % 20),
    .playerC = char(state % 20),
  };
}

constexpr Position position(int pos) {
  return Position {
    .row = char(pos / 20),
    .col = char(pos % 20),
  };
}

constexpr int calPos(int row, int col) {
  return row * 20 + col;
}

const int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
  int rows;
  int cols;
  
  vector<int> checkMap(vector<vector<char>> &grid, int boxR, int boxC, int playerR, int playerC) {
    unordered_set<int> vis;
    queue<int> q;
    q.push(calPos(playerR, playerC));
    vis.insert(calPos(playerR, playerC));
    int boxPos = calPos(boxR, boxC);
    vector<int> pushes;
    while(!q.empty()) {
      auto [row, col] = position(q.front());
      q.pop();
      int diffRow = boxR - row;
      int diffCol = boxC - col;
      if(diffRow == 0 && abs(diffCol) == 1 && boxC + diffCol >= 0 && boxC + diffCol < cols && grid[boxR][boxC + diffCol] != '#') {
        pushes.push_back(diffCol);
      }
      if(diffCol == 0 && abs(diffRow) == 1 && boxR + diffRow >= 0 && boxR + diffRow < rows && grid[boxR + diffRow][boxC] != '#') {
        pushes.push_back(diffRow * 20);
      }
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] == '#') continue;
        int newPos = calPos(newRow, newCol);
        if(vis.count(newPos) || newPos == boxPos) continue;
        vis.insert(newPos);
        q.push(newPos);
      }
    }
    return move(pushes);
  }
  
  constexpr int applyPush(int state, int push) const {
    int boxPos = state / 400;
    int newBoxPos = boxPos + push;
    return newBoxPos * 400 + boxPos;
  }
public:
  int minPushBox(vector<vector<char>>& grid) {
    rows = grid.size();
    cols = grid.front().size();
    unordered_map<int, int> pushes;
    
    int initState = 0;
    int targetR = 0;
    int targetC = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(grid[i][j] == 'T') {
          targetR = i;
          targetC = j;
          grid[i][j] = '.';
        } else if(grid[i][j] == 'B') {
          initState += i * 8000 + j * 400;
          grid[i][j] = '.';
        } else if(grid[i][j] == 'S') {
          initState += i * 20 + j;
          grid[i][j] = '.';
        }
      }
    }
    queue<int> q;
    q.push(initState);
    pushes[initState] = 0;
    
    while(!q.empty()) {
      int state = q.front();
      auto [boxR, boxC, playerR, playerC] = recover(state);
      // cout << int(boxR) << ' ' << int(boxC) << ' ' << int(playerR) << ' ' << int(playerC) << endl;
      q.pop();
      if(boxR == targetR && boxC == targetC) return pushes[state];
      auto validPushes = checkMap(grid, boxR, boxC, playerR, playerC);
      for(auto validPush : validPushes) {
        int newState = applyPush(state, validPush);
        if(pushes.count(newState)) continue;
        pushes[newState] = pushes[state] + 1;
        q.push(newState);
      }
    }
    return -1;
  }
};


// 18 / 18 test cases passed.
// Status: Accepted
// Runtime: 188 ms
// Memory Usage: 46.8 MB
```

maybe I need to run some profile to get reason...

# March LeetCoding Challenge14

**Binary Trees With Factors**

## Description

Given an array of unique integers, `arr`, where each integer `arr[i]` is strictly greater than `1`.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return *the number of binary trees we can make*. The answer may be too large so return the answer **modulo** `109 + 7`.

 

**Example 1:**

```
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
```

**Example 2:**

```
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
```

 

**Constraints:**

- `1 <= arr.length <= 1000`
- $2 \le arr[i] \le 10^9$

## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<int> count(len, 1);
    for(int i = 1; i < len; ++i) {
      for(int j = 0; arr[i] / arr[j] >= arr[j]; ++j) {
        if(arr[i] % arr[j]) continue;
        int pos = lower_bound(arr.begin(), arr.end(), arr[i] / arr[j]) - arr.begin();
        if(arr[i] / arr[j] != arr[pos]) continue;
        count[i] += (2LL - (arr[j] == arr[pos])) * count[j] * count[pos] % MOD;
        count[i] %= MOD;
      }
    }
    
    int answer = accumulate(count.begin(), count.end(), 0, [](int prev, int cur) {
      return (prev + cur) % MOD;
    });
    return answer;
  }
};

// 47 / 47 test cases passed.
// Status: Accepted
// Runtime: 36 ms
// Memory Usage: 8.2 MB

// Runtime: 32 ms, faster than 100.00% of C++ online submissions for Binary Trees With Factors.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Binary Trees With Factors.
```
