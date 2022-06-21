+++
updated = 2022-06-21 18:14:00+08:00
title = "2022-06-21 Daily-Challenge"
path = "2022-06-21-Daily-Challenge"
date = 2022-06-21 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/furthest-building-you-can-reach/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 21

## Description

**Furthest Building You Can Reach**

You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or ladders.

While moving from building `i` to building `i+1` (**0-indexed**),

- If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.
- If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` **bricks**.

*Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/27/q4.gif)

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

**Example 2:**

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

**Example 3:**

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

 

**Constraints:**

- `1 <= heights.length <= 10^5`
- `1 <= heights[i] <= 10^6`
- `0 <= bricks <= 10^9`
- `0 <= ladders <= heights.length`

## Solution

``` cpp
class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int len = heights.size();
    int pos = 0;
    priority_queue<int> q;
    for(;pos < len - 1; pos += 1) {
      // cout << pos << ' ' << bricks << ' ' << ladders << endl;
      int diff = heights[pos + 1] - heights[pos];
      if(diff <= 0) {
        continue;
      }
      if(diff <= bricks) {
        bricks -= diff;
        q.push(diff);
      } else {
        if(!ladders) break;
        if(q.size() && q.top() > diff) {
          bricks += q.top() - diff;
          q.pop();
          q.push(diff);
        }
        ladders -= 1;
      }
    }
    return pos;
  }
};

// Accepted
// 76/76 cases passed (157 ms)
// Your runtime beats 47.53 % of cpp submissions
// Your memory usage beats 27.49 % of cpp submissions (53.9 MB)
```
