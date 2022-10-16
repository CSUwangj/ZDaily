+++
title = "2021-06-12 Daily-Challenge"
path = "2021-06-12-Daily-Challenge"
date = 2021-06-12 14:21:08+08:00
updated = 2021-06-12 23:18:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3776/) with `cpp`.

<!-- more -->

# LeetCode Review

## Min Cost Climbing Stairs

too easy to review

## Construct Binary Tree from Preorder and Inorder Traversal

too easy to review

## Jump Game VI

already reviewed

## Longest Uncommon Subsequence II

too easy to review

## Distance Between Bus Stops

too easy to review

## Subarray Sums Divisible by K

too easy to review

## Array Nesting

too easy to review

## Scramble String

I thought substr is slow, but it seems blazing fast

``` cpp
unordered_map<string, bool> result;
int cnt[26];
bool sameChars(string &a, string &b) {
  memset(cnt, 0, sizeof(cnt));
  for(auto c : a) {
    cnt[c - 'a'] += 1;
  }
  for(auto c : b) {
    if(!cnt[c - 'a']) return false;
    cnt[c - 'a'] -= 1;
  }
  return true;
}

bool isOk(string a, string b) {
  if(a.length() == 1) return a[0] == b[0];
  if(a == b) return true;
  string key = a + "#" + b;
  if(result.count(key)) return result[key];
  if(!sameChars(a, b)) {
    result[key] = false;
    return false;
  }
  int len = a.length();
  for(int i = 1; i < len; i++) {
    if(isOk(a.substr(0, i), b.substr(0, i)) && isOk(a.substr(i), b.substr(i))) {
      result[key] = true;
      return true;
    }
    if(isOk(a.substr(0, i), b.substr(len - i)) && isOk(a.substr(i), b.substr(0, len - i))) {
      result[key] = true;
      return true;
    }
  }
  result[key] = false;
  return false;
}

class Solution {
public:
  bool isScramble(string a, string b) {
    return isOk(a, b);
  }
};
```

# June LeetCoding Challenge 12

## Description

**Minimum Number of Refueling Stops**

A car travels from a starting position to a destination which is `target` miles east of the starting position.

Along the way, there are gas stations. Each `station[i]` represents a gas station that is `station[i][0]` miles east of the starting position, and has `station[i][1]` liters of gas.

The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination? If it cannot reach the destination, return `-1`.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

 

**Example 1:**

```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```

**Example 2:**

```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
```

**Example 3:**

```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: 
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```

 

**Note:**

1. `1 <= target, startFuel, stations[i][1] <= 10^9`
2. `0 <= stations.length <= 500`
3. `0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target`

## Solution

``` cpp
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel >= target) return 0;
    int curFuel = startFuel;
    int len = stations.size();
    if(!len) return -1;
    bool vis[len];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < len; ++i) {
      int maxFuel = curFuel;
      int idx = -1;
      for(int j = 0; j < len; ++j) {
        if(vis[j]) continue;
        if(curFuel < stations[j][0]) break;
        if(curFuel + stations[j][1] > maxFuel) {
          idx = j;
          maxFuel = curFuel + stations[j][1];
        }
      }
      if(idx == -1) return -1;
      if(maxFuel >= target) return i + 1;
      curFuel = maxFuel;
      vis[idx] = true;
    }
    return -1;
  }
};
```
