+++
title = "2022-01-21 Daily-Challenge"
path = "2022-01-21-Daily-Challenge"
date = 2022-01-21 18:18:00+08:00
updated = 2022-01-21 18:31:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/gas-station/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 21

## Description

**Gas Station**

There are `n` gas stations along a circular route, where the amount of gas at the `ith` station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `ith` station to its next `(i + 1)th` station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return *the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return* `-1`. If there exists a solution, it is **guaranteed** to be **unique**

 

**Example 1:**

```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

**Example 2:**

```
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

 

**Constraints:**

- `gas.length == n`
- `cost.length == n`
- `1 <= n <= 10^5`
- `0 <= gas[i], cost[i] <= 10^4`

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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    for(int i = 0; i < len; ++i) {
      gas[i] -= cost[i];
    }
    int begin = 0;
    while(begin < len) {
      int current = 0;
      for(int i = 0; i < len; ++i) {
        current += gas[(begin + i) % len];
        if(current < 0) {
          begin = begin + i + 1;
          break;
        }
      }
      if(current >= 0) return begin;
    }
    return -1;
  }
};

// Accepted
// 35/35 cases passed (69 ms)
// Your runtime beats 45.23 % of cpp submissions
// Your memory usage beats 45.28 % of cpp submissions (49.8 MB)
```
