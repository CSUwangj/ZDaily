+++
title = "2022-01-06 Daily-Challenge"
path = "2022-01-06-Daily-Challenge"
date = 2022-01-06 18:16:00+08:00
updated = 2022-01-05 18:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/palindrome-partitioning/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 6

## Description

**Car Pooling**

There is a car with `capacity` empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer `capacity` and an array `trips` where `trip[i] = [numPassengersi, fromi, toi]` indicates that the `ith` trip has `numPassengersi` passengers and the locations to pick them up and drop them off are `fromi` and `toi` respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return `true` *if it is possible to pick up and drop off all passengers for all the given trips, or* `false` *otherwise*.

 

**Example 1:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

**Example 2:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

 

**Constraints:**

- `1 <= trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= numPassengersi <= 100`
- `0 <= fromi < toi <= 1000`
- `1 <= capacity <= 10^5`

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
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> people;
    people.reserve(trips.size() * 2);
    for(auto &trip : trips) {
      people.push_back({trip[1], trip[0]});
      people.push_back({trip[2], -trip[0]});
    }
    sort(people.begin(), people.end());
    for(auto [_, people] : people) {
      capacity -= people;
      if(capacity < 0) return false;
    }

    return true;
  }
};

// Accepted
// 58/58 cases passed (9 ms)
// Your runtime beats 78.76 % of cpp submissions
// Your memory usage beats 95.84 % of cpp submissions (9.8 MB)
```
