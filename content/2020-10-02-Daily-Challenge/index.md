+++
title = "2020-10-02 Daily-Challenge"
path = "2020-10-02-Daily-Challenge"
date = 2020-10-02 03:40:38+08:00
updated = 2020-10-02 16:36:19+08:00
in_search_index = true

[taxonomies]
tags = ["Design",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on Page 55 and *Filter Restaurants by Vegan-Friendly, Price and Distance* on [leetcode](https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3480/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [T] style of figure
- [T] font of title
- [T] font of information
- [T] color scheme
- [F] grey people shape
- [F] distance from border
- [T] overlay of  shape and rectangle

# Reconstruct Original Digits from English

## Description

Given the array `restaurants` where  `restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]`. You have to filter the restaurants using three filters.

The `veganFriendly` filter will be either *true* (meaning you should only include restaurants with `veganFriendlyi` set to true) or *false* (meaning you can include any restaurant). In addition, you have the filters `maxPrice` and `maxDistance` which are the maximum value for price and distance of restaurants you should consider respectively.

Return the array of restaurant ***IDs*** after filtering, ordered by **rating** from highest to lowest. For restaurants with the same rating, order them by ***id*** from highest to lowest. For simplicity `veganFriendlyi` and `veganFriendly` take value *1* when it is *true*, and *0* when it is *false*.

**Example 1:**

```
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
Output: [3,1,5] 
Explanation: 
The restaurants are:
Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
After filter restaurants with veganFriendly = 1, maxPrice = 50 and maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 (ordered by rating from highest to lowest). 
```

**Example 2:**

```
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
Output: [4,3,2,1,5]
Explanation: The restaurants are the same as in example 1, but in this case the filter veganFriendly = 0, therefore all restaurants are considered.
```

**Example 3:**

```
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
Output: [4,5]
```

**Constraints:**

- `1 <= restaurants.length <= 10^4`
- `restaurants[i].length == 5`
- `1 <= idi, ratingi, pricei, distancei <= 10^5`
- `1 <= maxPrice, maxDistance <= 10^5`
- `veganFriendlyi` and `veganFriendly` are 0 or 1.
- All `idi` are distinct.

## Solution

simple fp should work for this.

fp is nothing special, but I like the way code is.

``` cpp
class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<int> id;
    vector<int> ans;
    for(int i = 0; i < restaurants.size(); ++i) {
      id.push_back(i);
    }
    // filter first is better than sort first
    copy_if(id.begin(), id.end(),back_inserter(ans), [&restaurants, veganFriendly, maxDistance, maxPrice](int x){
      return restaurants[x][2] >= veganFriendly && restaurants[x][3] <= maxPrice && restaurants[x][4] <= maxDistance;
    });
    sort(ans.begin(), ans.end(), [&restaurants](int a, int b){
      return restaurants[a][1] > restaurants[b][1] || 
        (restaurants[a][1] == restaurants[b][1] && restaurants[a][0] > restaurants[b][0]);
    });
    transform(ans.begin(), ans.end(), ans.begin(), [&restaurants](int x){ return restaurants[x][0];});
    return ans;
  }
};
```

# October LeetCoding Challenge

## Description

**Number of Recent Calls**

You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.

Implement the `RecentCounter` class:

- `RecentCounter()` Initializes the counter with zero recent requests.
- `int ping(int t)` Adds a new request at time `t`, where `t` represents some time in milliseconds, and returns the number of requests that has happened in the past `3000` milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range `[t - 3000, t]`.

It is **guaranteed** that every call to `ping` uses a strictly larger value of `t` than the previous call.

**Example 1:**

```
Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
```

**Constraints:**

- `1 <= t <= 104`
- Each test case will call `ping` with **strictly increasing** values of `t`.
- At most `104` calls will be made to `ping`.

## Solution

simple sliding window, I'd rather implement it using a queue.

``` cpp
class RecentCounter {
  queue<int> q;
public:
  int ping(int t) {
    while(q.size() && t - 3000 > q.front()) {
      q.pop();
    }
    q.push(t);
    return q.size();
  }
};
```