+++
title = "2021-02-26 Daily-Challenge"
path = "2021-02-26-Daily-Challenge"
date = 2021-02-26 18:00:36+08:00
updated = 2021-02-26 18:33:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/submissions/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3652/) with `cpp`.

<!-- more -->

# Furthest Building You Can Reach

## Description

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

- $1 \le heights.length \le 10^5$
- $1 \le heights[i] \le 10^6$
- $0 \le bricks \le 10^9$
- `0 <= ladders <= heights.length`

## Solution

``` cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int pos = 1;
        int len = heights.size();
        priority_queue<int> q;
        q.push(0);
        while(pos < len) {
            if(heights[pos] > heights[pos - 1] && heights[pos] <= heights[pos - 1] + bricks) {
                bricks -= heights[pos] - heights[pos - 1];
                q.push(heights[pos] - heights[pos - 1]);
            } else if(heights[pos] > heights[pos - 1]) {
                break;
            }
            pos += 1;
        }
        if(pos == len) return pos - 1;
        while(ladders && pos < len) {
            if(heights[pos] - heights[pos - 1] >= q.top()) {
                ladders -= 1;
                pos += 1;
            } else {
                bricks += q.top();
                q.pop();
                ladders -= 1;
            }
            for(;pos < len && heights[pos] <= heights[pos - 1] + bricks; pos += 1) {
                if(heights[pos] <= heights[pos - 1]) continue;
                bricks -= heights[pos] - heights[pos - 1];
                q.push(heights[pos] - heights[pos - 1]);
            }

        }
        
        return pos - 1;
    }
};
```

# February LeetCoding Challenge26

## Description

**Validate Stack Sequences**

Given two sequences `pushed` and `popped` **with distinct values**, return `true` if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

**Example 1:**

```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

**Example 2:**

```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

 

**Constraints:**

- `0 <= pushed.length == popped.length <= 1000`
- `0 <= pushed[i], popped[i] < 1000`
- `pushed` is a permutation of `popped`.
- `pushed` and `popped` have distinct values.

## Solution

``` cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pos = 0;
        int len = pushed.size();
        vector<int> st;
        for(int i = 0; i < len; ++i) {
            if(st.size() && st.back() == popped[i]) {
                st.pop_back();
                continue;
            }
            while(pos < len && pushed[pos] != popped[i]) {
                st.push_back(pushed[pos]);
                pos += 1;
            }
            if(pos < len && pushed[pos] == popped[i]) {
                pos += 1;
                continue;
            }
            return false;
        }
        return true;
    }
};
```
