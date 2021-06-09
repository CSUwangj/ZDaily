+++
title = "2021-06-09 Daily-Challenge"
path = "2021-06-09-Daily-Challenge"
date = 2021-06-09 18:06:35+08:00
updated = 2021-06-09 18:44:08+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Distance Between Bus Stops](https://leetcode.com/problems/distance-between-bus-stops/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3772/) with `cpp`.

<!-- more -->

# Distance Between Bus Stops

## Description

A bus has `n` stops numbered from `0` to `n - 1` that form a circle. We know the distance between all pairs of neighboring stops where `distance[i]` is the distance between the stops number `i` and `(i + 1) % n`.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given `start` and `destination` stops.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1.jpg)

```
Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
```

 

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1-1.jpg)

```
Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
```

 

**Example 3:**

![img](https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1-2.jpg)

```
Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
```

 

**Constraints:**

- `1 <= n <= 10^4`
- `distance.length == n`
- `0 <= start, destination < n`
- `0 <= distance[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int sum = 0;
    int d = 0;
    for(auto i : distance) sum += i;
    for(int i = min(start, destination); i < max(start, destination); ++i) {
      d += distance[i];
    }
    return min(d, sum - d);
  }
};
```

# June LeetCoding Challenge9

## Description

**Jump Game VI**

You are given a **0-indexed** integer array `nums` and an integer `k`.

You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.

You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.

Return *the **maximum score** you can get*.

 

**Example 1:**

```
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
```

**Example 2:**

```
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
```

**Example 3:**

```
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
```

 

**Constraints:**

-  `1 <= nums.length, k <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    int len = nums.size();
    int answer = nums[0];
    pq.push({nums[0], 0});
    for(int i = 1; i < len; ++i) {
      while(pq.top().second + k < i) pq.pop();
      answer = pq.top().first + nums[i];
      pq.push({answer, i});
    }
    return answer;
  }
};
```
