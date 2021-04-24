+++
title = "2021-04-24 Daily-Challenge"
path = "2021-04-24-Daily-Challenge"
date = 2021-04-24 13:49:53+08:00
updated = 2021-04-24 16:50:31+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3703/) with `cpp`.

<!-- more -->

# LeetCode Review

## K Closest Points to Origin

too easy to review

## Count Items Matching a Rule

too easy to review

## Decode Ways

already reviewed

## Decode Ways II

``` cpp
const int MOD = 1e9 + 7;
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
constexpr inline int mul(int a, int b) {
  int result = 0;
  while(b) {
    if(b & 1) {
      result += a;
      result %= MOD;
    }
    b >>= 1;
    a += a;
    a %= MOD;
  }
  return result;
}
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<int> dp(len + 1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      char prev = i ? s[i - 1] : -1;
      if(s[i] == '*') {
        dp[i + 1] = mul(dp[i], 9);
        if(prev == '1') {
          dp[i + 1] += mul(dp[i - 1], 9);
          dp[i + 1] %= MOD;
        }
        if(prev == '2') {
          dp[i + 1] += mul(dp[i - 1], 6);
          dp[i + 1] %= MOD;
        }
        if(prev == '*') {
          dp[i + 1] += mul(dp[i - 1], 15);
          dp[i + 1] %= MOD;
        }
      } else {
        if(s[i] < '7' && (prev == '2' || prev == '*')) {
          dp[i + 1] += dp[i - 1];
          dp[i + 1] %= MOD;
        }
        if(prev == '1' || prev == '*') {
          dp[i + 1] += dp[i - 1];
          dp[i + 1] %= MOD;
        }
        if(s[i] != '0') {
          dp[i + 1] += dp[i];
          dp[i + 1] %= MOD;
        }
      }
      if(!dp[i] && !dp[i + 1]) return 0;
      // cout << dp[i + 1][10] << ' ';
    }
    // cout << endl;
    return dp.back();
  }
};

// Runtime: 20 ms, faster than 100.00% of C++ online submissions for Decode Ways II.
// Memory Usage: 16.9 MB, less than 59.65% of C++ online submissions for Decode Ways II.
```

long long is quicker, even larger

``` cpp
const int MOD = 1e9 + 7;
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<long long> dp(len + 1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      char prev = i ? s[i - 1] : -1;
      if(s[i] == '*') {
        dp[i + 1] = dp[i] * 9;
        if(prev == '1') dp[i + 1] += dp[i - 1] * 9;
        if(prev == '2') dp[i + 1] += dp[i - 1] * 6;
        if(prev == '*') dp[i + 1] += dp[i - 1] * 15;
      } else {
        if(s[i] < '7' && (prev == '2' || prev == '*')) dp[i + 1] += dp[i - 1];
        if(prev == '1' || prev == '*') dp[i + 1] += dp[i - 1];
        if(s[i] != '0') dp[i + 1] += dp[i];
      }
      dp[i + 1] %= MOD;
      if(!dp[i] && !dp[i + 1]) return 0;
      // cout << dp[i + 1][10] << ' ';
    }
    // cout << endl;
    return dp.back();
  }
};

// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Decode Ways II.
// Memory Usage: 21.7 MB, less than 33.01% of C++ online submissions for Decode Ways II.
```

## Human Traffic of Stadium

no need to review

## Number of Lines To Write String

too easy to review

## Binary Tree Preorder Traversal

no need to review

## Binary Tree Inorder Traversal

no need to review

## Binary Tree Postorder Traversal

no need to review

## Longest Happy String

no need to review

## Combination Sum

too easy to review

## Combination Sum II

too easy to review

## Combination Sum III

too easy to review

## Combination Sum IV

too easy to review

## N-ary Tree Preorder Traversal

too easy to rewrite with recursion or stack

## Triangle

no need to review

## Brick Wall

no need to review

## Count Binary Substrings

too easy to review

# April LeetCoding Challenge24

## Description

**Critical Connections in a Network**

There are `n` servers numbered from `0` to `n-1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [a, b]` represents a connection between servers `a` and `b`. Any server can reach any other server directly or indirectly through the network.

A *critical connection* is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png)**

```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
```

 

**Constraints:**

- `1 <= n <= 10^5`
- `n-1 <= connections.length <= 10^5`
- `connections[i][0] != connections[i][1]`
- There are no repeated connections.

## Solution

learning tarjan algorithm

``` cpp
class Solution {
  vector<vector<int>> neighbors;
  vector<int> num;
  vector<int> low;
  int count = 0;
  void init(int n, vector<vector<int>>& connections) {
    num.resize(n);
    low.resize(n);
    neighbors.resize(n);
    for(auto &edge : connections) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }
  void tarjan(int u, int father, vector<vector<int>> &answer) {
    low[u] = num[u] = ++count;
    for(auto child : neighbors[u]) {
      if(child == father) continue;
      if(!num[child]) {
        tarjan(child, u, answer);
        low[u] = min(low[u], low[child]);
        if(low[child] > num[u]) {
          answer.push_back({u, child});
        }
      } else if (num[child] < num[u]) {
        low[u] = min(low[u], num[child]);
      }
    }
  }
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    init(n, connections);
    vector<vector<int>> answer;
    tarjan(0, 0, answer);
    return answer;
  }
};
```
