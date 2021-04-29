+++
title = "2021-04-28 Daily-Challenge"
path = "2021-04-28-Daily-Challenge"
date = 2021-04-28 20:03:30+08:00
updated = 2021-04-28 22:08:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [K-Similar Strings](https://leetcode.com/problems/k-similar-strings/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3722/) with `cpp`.

<!-- more -->

# K-Similar Strings

## Description

Strings `s1` and `s2` are `k`**-similar** (for some non-negative integer `k`) if we can swap the positions of two letters in `s1` exactly `k` times so that the resulting string equals `s2`.

Given two anagrams `s1` and `s2`, return the smallest `k` for which `s1` and `s2` are `k`**-similar**.

 

**Example 1:**

```
Input: s1 = "ab", s2 = "ba"
Output: 1
```

**Example 2:**

```
Input: s1 = "abc", s2 = "bca"
Output: 2
```

**Example 3:**

```
Input: s1 = "abac", s2 = "baca"
Output: 2
```

**Example 4:**

```
Input: s1 = "aabc", s2 = "abca"
Output: 2
```

 

**Constraints:**

- `1 <= s1.length <= 20`
- `s2.length == s1.length`
- `s1` and `s2` contain only lowercase letters from the set `{'a', 'b', 'c', 'd', 'e', 'f'}`.
- `s2` is an anagram of `s1`.

## Solution

first I wrote a ugly code and failed...

``` cpp
class Solution {
  int len;
  vector<int> path;
  vector<bool> ok;
  int minLen;
  bool findLoop(string &s1, string &s2, int loopLen) {
    // cout << "?" << loopLen << endl;
    for(int i = 0; i < len; ++i) {
      if(ok[i]) continue;
      // cout<<  "%" << i << endl;
      path.clear();
      path.push_back(i);
      findLoop(s1, s2, s2[i]);
      int result;
      for(int j = path.size() - 2; j >= 0; --j) {
        if(s1[path[j]] == s2[path.back()]) {
          result = path.size() - j;
        }
      }
      // cout << i << ' ' << result << endl;
      minLen = min(minLen, result);
      // cout << 'r' << i << s1[i] << s2[i] << ' ' << result << ' ' << path.size() << endl;
      if(result != loopLen) continue;
      char begin = s2[path.back()];
      while(s1[path.back()] != begin) {
        // cout << '[' << path.back() << ", " << s1[path.back()] << ", " << s2[path.back()] << "] ";
        ok[path.back()] = true;
        path.pop_back();
      }
      // cout << '[' << path.back() << ", "<< s1[path.back()] << ", " << s2[path.back()] << "] ";
      ok[path.back()] = true;
      path.pop_back();
      // cout << endl;
      return true;
    }
    return false;
  }
  void findLoop(string &s1, string &s2, char end) {
    // cout << '@' << end<< endl;
    int pos = -1;
    int next = -1;
    int nextLoop;
    for(int i = 0; i < len; ++i) {
      if(ok[i]) continue;
      if(s1[i] != end) continue;
      for(int j = path.size() - 1; j >= max(pos, 0); --j) {
        // cout << j << ' ' << path[j] << endl;
        if(s2[i] == s1[path[j]]) {
          if(j > pos) {
            pos = j;
            next = i;
          }
        }
      }
      nextLoop = i;
    }
    if(pos == -1) {
      path.push_back(nextLoop);
      findLoop(s1, s2, s2[nextLoop]);
    } else {
      path.push_back(next);
    }
  }
public:
  int kSimilarity(string s1, string s2) {
    // cout << s1 << ' ' << s2 << endl;
    len = s1.length();
    ok.resize(len);
    for(int i = 0; i < len; i++) {
      if(s1[i] == s2[i]) ok[i] = true;
    }
    int cnt = accumulate(ok.begin(), ok.end(), 0);
    int answer = 0;
    int cur = 2;
    while(cnt < len) {
      // cout << cnt << endl;
      minLen = INT_MAX;
      if(findLoop(s1, s2, cur)) {
        cout << cur << endl;
        answer += cur - 1;
        cnt += cur;
      } else {
        cur = minLen;
      }
    }
    return answer;
  }
};
```

then rewrite using bfs:

``` cpp
class Solution {
  int realKSimilarity(string s1, string s2) {
    queue<string> q;
    q.push(s1);
    unordered_set<string> vis;
    int count = -1;
    while(q.size()) {
      int sz = q.size();
      count += 1;
      while(sz--) {
        string s = q.front();
        q.pop();
        if(s == s2) return count;
        for(int i = count; i < s.length(); ++i) {
          for(int j = i + 1; j < s.length(); ++j) {
            swap(s[i], s[j]);
            if(!vis.count(s) && s[count] == s2[count]) {
              q.push(s);
              vis.insert(s);
            }
            swap(s[i], s[j]);
          }
        }
      }      
    }
    return -1;
  }
public:
  int kSimilarity(string s1, string s2) {
    if(s1 == s2) return 0;
    string ns1, ns2;
    for(int i = 0; i < s1.length(); ++i) {
      if(s1[i] != s2[i]) {
        ns1.push_back(s1[i]);
        ns2.push_back(s2[i]);
      }
    }
    return realKSimilarity(ns1, ns2);
  }
};

// Accepted
// 57/57 cases passed (668 ms)
// Your runtime beats 12.62 % of cpp submissions
// Your memory usage beats 27.91 % of cpp submissions (61.3 MB)
```

# April LeetCoding challenge28

## Description

**Unique Paths II**

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as `1` and `0` respectively in the grid.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

```
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

**Constraints:**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.

## Solution

basic dp, already done before

``` cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<int> dp(m*n);
        dp[0] = 1;
        for(int i = 1; i < m*n; ++i) {
            if(obstacleGrid[i/n][i%n] == 1) continue;
            if(i >= n) dp[i] += dp[i-n];
            if(i % n != 0) dp[i] += dp[i-1];
        }
        return dp.back();
    }
};
```
