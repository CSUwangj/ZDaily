+++
title = "2021-03-27 Daily-Challenge"
path = "2021-03-27-Daily-Challenge"
date = 2021-03-27 13:00:00+08:00
updated = 2021-03-27 23:20:29+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3686/) with `cpp`.


<!-- more -->

# LeetCode Review

## Minimum Number of Refueling Stops

there's no need to use a large DP array, because maximum amount of fuel is fixed for a test case, so we can use heap to quick get answer.

``` cpp
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel >= target) return 0;
    priority_queue<int> q;
    sort(stations.begin(), stations.end());
    int answer = 0;
    for(auto &station : stations) {
      while(q.size() && startFuel < station[0]) {
        startFuel += q.top();
        q.pop();
        answer += 1;
        if(startFuel >= target) return answer;
      }
      if(startFuel >= station[0]) {
        q.push(station[1]);
      } else {
        return -1;
      }
    }
    while(q.size() && startFuel < target) {
      startFuel += q.top();
      q.pop();
      answer += 1;
    }
    return startFuel < target ? -1 : answer;
  }
};
```

## Defuse the Bomb

too easy to review

## Reverse Integer

too easy to review

## Water Bottles

too easy to review

## Search Insert Position

``` cpp
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    nums.push_back(INT_MAX);
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};
```

## Word Subsets

too easy to review

## Advantage Shuffle

too easy to review

## Vowel Spellchecker

too easy to review

## 3Sum With Multiplicity

too easy to review

## Pacific Atlantic Water Flow

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
  int rows;
  int cols;
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col) {
    if(vis[row][col]) return;
    vis[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(heights[row][col] > heights[newRow][newCol]) continue;
      dfs(heights, vis, newRow, newCol);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> answer;
    if(heights.empty() || heights.front().empty()) return answer;
    rows = heights.size();
    cols = heights.front().size();
    vector<vector<bool>> visPac(rows, vector<bool>(cols));
    vector<vector<bool>> visAtl(rows, vector<bool>(cols));
    
    for(int i = 0; i < cols; ++i) {
      dfs(heights, visPac, 0, i);
      dfs(heights, visAtl, rows - 1, i);
    }
    for(int i = 0; i < rows; ++i) {
      dfs(heights, visPac, i, 0);
      dfs(heights, visAtl, i, cols - 1);
    }
    
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(visPac[i][j] && visAtl[i][j]) answer.push_back({i, j});
      }
    }
    
    return answer;
  }
};
```

# March LeetCoding Challenge27

## Description

**Palindromic Substrings**

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

**Example 1:**

```
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

 

**Example 2:**

```
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

 

**Note:**

1. The input string length won't exceed 1000.

## Solution

``` cpp
class Solution {
public:
  int countSubstrings(string s) {
    int dp[1001][1001] = {0};
    int len = s.length();
    int answer = len;
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1;
    }
    for(int l = 2; l <= len; ++l) {
      for(int j = 0; j + l <= len; ++j) {
        if(dp[j + 1][j + l - 1] && s[j] == s[j + l - 1]) {
          dp[j][j + l] = 1;
          answer += 1;
        }
      }
    }
    
    return answer;
  }
};
```
