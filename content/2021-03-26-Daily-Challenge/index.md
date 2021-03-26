+++
title = "2021-03-26 Daily-Challenge"
path = "2021-03-26-Daily-Challenge"
date = 2021-03-26 18:14:17+08:00
updated = 2021-03-26 20:26:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3684/) with `cpp`.

<!-- more -->

# Minimum Number of Refueling Stops

## Description

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

why this problem is `hard`?

``` cpp
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel >= target) return 0;
    sort(stations.begin(), stations.end());
    int len = stations.size();
    vector<long long> dp(len + 1);
    dp[0] = startFuel;
    int answer = INT_MAX;
    for(int i = 0; i < len; ++i) {
      for(int j = 1 + i; j > 0; --j) {
        if(dp[j - 1] >= stations[i][0]) {
          dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
        } else {
          break;
        }
        if(dp[j] >= target) answer = min(answer, j);
      }
    }
    
    return answer == INT_MAX ? -1 : answer;
  }
};
```

# March LeetCoding challenge26

**Word Subsets**

We are given two arrays `A` and `B` of words. Each word is a string of lowercase letters.

Now, say that word `b` is a subset of word `a` if every letter in `b` occurs in `a`, **including multiplicity**. For example, `"wrr"` is a subset of `"warrior"`, but is not a subset of `"world"`.

Now say a word `a` from `A` is *universal* if for every `b` in `B`, `b` is a subset of `a`. 

Return a list of all universal words in `A`. You can return the words in any order.

 



**Example 1:**

```
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
```

**Example 2:**

```
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
```

**Example 3:**

```
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
```

**Example 4:**

```
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
```

**Example 5:**

```
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
```

 

**Note:**

1. `1 <= A.length, B.length <= 10000`
2. `1 <= A[i].length, B[i].length <= 10`
3. `A[i]` and `B[i]` consist only of lowercase letters.
4. All words in `A[i]` are unique: there isn't `i != j` with `A[i] == A[j]`.

## Solution

``` cpp
class Solution {
public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> count(26);
    for(auto &b : B) {
      vector<int> tmpCount(26);
      for(auto c : b) tmpCount[c - 'a'] += 1;
      for(int i = 0; i < 26; ++i) count[i] = max(count[i], tmpCount[i]);
    }
    
    vector<string> answer;
    for(auto &a : A) {
      vector<int> tmpCount(26);
      for(auto c : a) tmpCount[c - 'a'] += 1;
      bool universal = true;
      for(int i = 0; i < 26; ++i) universal &= tmpCount[i] >= count[i];
      if(universal) answer.push_back(a);
    }
    return answer;
  }
};
```
