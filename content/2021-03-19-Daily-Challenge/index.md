+++
title = "2021-03-19 Daily-Challenge"
path = "2021-03-19-Daily-Challenge"
date = 2021-03-19 17:00:23+08:00
updated = 2021-03-19 18:00:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Prime Arrangements](https://leetcode.com/problems/prime-arrangements/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3677/) with `cpp`.

<!-- more -->

# Prime Arrangements

## Description

You are given two integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`. The arrays are **1-indexed**.

You begin with a score of `0`. You want to perform **exactly** `m` operations. On the `ith` operation **(1-indexed)**, you will:

- Choose one integer `x` from **either the start or the end** of the array `nums`.
- Add `multipliers[i] * x` to your score.
- Remove `x` from the array `nums`.

Return *the **maximum** score after performing* `m` *operations.*

 

**Example 1:**

```
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```

**Example 2:**

```
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
```

 

**Constraints:**

- `n == nums.length`
- `m == multipliers.length`
- `1 <= m <= 10^3`
- `m <= n <= 10^5`
- `-1000 <= nums[i], multipliers[i] <= 1000`

## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr int permutation(int x) {
  long long result = 1;
  while(x) {
    result *= x;
    result %= MOD;
    x -= 1;
  }
  return result;
}
class Solution {
  
public:
  int numPrimeArrangements(int n) {
    int primes = 0;
    for(int i = 2; i <= n; ++i) {
      bool isPrime = true;
      for(int j = 2; j * j <= i; ++j) {
        if(i % j == 0) isPrime = false;
      }
      primes += isPrime;
    }
    // cout << primes << ' ' << n - primes << ' ' << n << endl;
    return 1LL * permutation(primes) * permutation(n - primes) % MOD;
  }
};
```

# March LeetCoding Challenge 19

## Description

**Keys and Rooms**

There are `N` rooms and you start in room `0`. Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. 

Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`. A key `rooms[i][j] = v` opens the room with number `v`.

Initially, all the rooms start locked (except for room `0`). 

You can walk back and forth between rooms freely.

Return `true` if and only if you can enter every room.



**Example 1:**

```
Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
```

**Example 2:**

```
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
```

**Note:**

1. `1 <= rooms.length <= 1000`
2. `0 <= rooms[i].length <= 1000`
3. The number of keys in all rooms combined is at most `3000`.

## Solution

``` cpp
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> opened;
    queue<int> toOpen;
    
    opened.insert(0);
    toOpen.push(0);
    while(toOpen.size()) {
      int cur = toOpen.front();
      toOpen.pop();
      for(auto key : rooms[cur]) {
        if(opened.count(key)) continue;
        toOpen.push(key);
        opened.insert(key);
      }
    }
    
    return opened.size() == rooms.size();
  }
};
```
