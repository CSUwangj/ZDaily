+++
title = "2022-01-16 Daily-Challenge"
path = "2022-01-16-Daily-Challenge"
date = 2022-01-16 13:30:00+08:00
updated = 2022-01-16 13:33:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximize-distance-to-closest-person/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 16

## Description

**Maximize Distance to Closest Person**

You are given an array representing a row of `seats` where `seats[i] = 1` represents a person sitting in the `ith` seat, and `seats[i] = 0` represents that the `ith` seat is empty **(0-indexed)**.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return *that maximum distance to the closest person*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/10/distance.jpg)

```
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```

**Example 2:**

```
Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
```

**Example 3:**

```
Input: seats = [0,1]
Output: 1
```

 

**Constraints:**

- `2 <= seats.length <= 2 * 10^4`
- `seats[i]` is `0` or `1`.
- At least one seat is **empty**.
- At least one seat is **occupied**.

## Solution

``` cpp
class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    bool begin = true;
    int count = 0;
    int answer = 0;
    for(auto seat : seats) {
      if(!seat) {
        count += 1;
        continue;
      }
      if(begin) {
        count *= 2;
        begin = false;
      }
      answer = max(answer, count / 2);
      count = 1;
    }
    if(count > 1) answer = max(answer, count - 1);
    return answer;
  }
};

// Accepted
// 81/81 cases passed (8 ms)
// Your runtime beats 96.68 % of cpp submissions
// Your memory usage beats 63.67 % of cpp submissions (17 MB)
```
