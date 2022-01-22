+++
title = "2022-01-22 Daily-Challenge"
path = "2022-01-22-Daily-Challenge"
date = 2022-01-22 13:52:00+08:00
updated = 2022-01-22 13:54:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/stone-game-vi/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 22

## Description

**Stone Game IV**

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are `n` stones in a pile. On each player's turn, that player makes a *move* consisting of removing **any** non-zero **square number** of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer `n`, return `true` if and only if Alice wins the game otherwise return `false`, assuming both players play optimally.

 

**Example 1:**

```
Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
```

**Example 2:**

```
Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
```

**Example 3:**

```
Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
```

 

**Constraints:**

- `1 <= n <= 10^5`

## Solution

``` cpp
constexpr int LIMIT = 100000;
auto table = [](){
  array<bool, LIMIT + 1> arr{false};
  for(int i = 0; i <= LIMIT; ++i) {
    if(arr[i]) continue;
    for(int j = 1; j * j + i <= LIMIT; ++j) {
      arr[i + j * j] = true;
    }
  }
  return arr;
}();
class Solution {
public:
  bool winnerSquareGame(int n) {
    return table[n];
  }
};

// Accepted
// 72/72 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.92 % of cpp submissions (6 MB)
```
