+++
title = "2021-08-05 Daily-Challenge"
path = "2021-08-05-Daily-Challenge"
date = 2021-08-05 18:20:33+08:00
updated = 2021-08-05 18:39:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3839/) with `cpp`.

<!-- more -->

# Defanging an IP Address

## Description

Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A *defanged IP address* replaces every period `"."` with `"[.]"`.

 

**Example 1:**

```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
```

**Example 2:**

```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
```

 

**Constraints:**

- The given `address` is a valid IPv4 address.

## Solution

``` cpp
class Solution {
public:
  string defangIPaddr(string address) {
    return regex_replace(address, regex("\\."), "[.]");
  }
};

// Accepted
// 62/62 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 21.4 % of cpp submissions (6.8 MB)
```

# August LeetCoding Challenge 5

## Description

**Stone Game**

Alex and Lee play a game with piles of stones. There are an even number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first. Each turn, a player takes the entire pile of stones from either the beginning or the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return `True` if and only if Alex wins the game.

 

**Example 1:**

```
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
```

 

**Constraints:**

- `2 <= piles.length <= 500`
- `piles.length` is even.
- `1 <= piles[i] <= 500`
- `sum(piles)` is odd.

## Solution

it's easy to come up with a interval DP solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[501][501];
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int len = piles.size();
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 0;
      dp[i][i + 1] = piles[i];
    }
    for(int i = 2; i <= len; ++i) {
      if(i & 1) {
        for(int j = 0; j + i <= len; ++j) {
          dp[j][j + i] = max(dp[j][j + i - 1] + piles[j + i - 1], dp[j + 1][j + i] + piles[j]);
        }
      } else {
        for(int j = 0; i + j <= len; ++j) {
          dp[j][j + i] = min(dp[j][j + i - 1] - piles[j + i - 1], dp[j + 1][j + i] - piles[j]);
        }
      }
    }
    return true;
  }
};

// Accepted
// 46/46 cases passed (8 ms)
// Your runtime beats 53.22 % of cpp submissions
// Your memory usage beats 48.67 % of cpp submissions (8.5 MB)
```

mark all piles as black and white, Alex can take either all black piles or all white piles, because sum of piles is odd, so black and white piles can not be even. Alex will always win. brilliant illustration!

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    return true;
  }
};

// Accepted
// 46/46 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.1 % of cpp submissions (7.7 MB)
```
