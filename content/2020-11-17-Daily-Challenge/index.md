+++
title = "2020-11-17 Daily-Challenge"
path = "2020-11-17-Daily-Challenge"
date = 2020-11-17 19:33:33+08:00
updated = 2020-11-17 19:58:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Trapping Rain Water* on [leetcode](https://leetcode.com/problems/trapping-rain-water/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3534/) with `cpp`.

<!-- more -->

# Trapping Rain Water

## Description

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

- `n == height.length`
- `0 <= n <= 3 * 104`
- `0 <= height[i] <= 105`

## Solution

we just need to find which heights are trapping the water, then find next greater height, if there is not next greater height, we solve it backward.

I use monotonic stack to keep track of both conditions, but seems dp will be more elegant ;)

``` cpp
class Solution {
public:
  int trap(vector<int>& height) {
    int len = height.size();
    vector<int> nextEqualGreater(len);
    vector<int> lastEqualGreater(len);
    vector<int> monoStack;
    for(int i = len-1; i >= 0; --i) {
      while(monoStack.size() && height[monoStack.back()] < height[i]) monoStack.pop_back();
      nextEqualGreater[i] = monoStack.empty() ? -1 : monoStack.back();
      monoStack.push_back(i);
    }
    while(monoStack.size()) monoStack.pop_back();
    for(int i = 0; i < len; ++i) {
      while(monoStack.size() && height[monoStack.back()] < height[i]) monoStack.pop_back();
      lastEqualGreater[i] = monoStack.empty() ? -1 : monoStack.back();
      monoStack.push_back(i);
    }
    int leftPos = 1;
    while(leftPos < len && height[leftPos] >= height[leftPos-1]) leftPos += 1;
    if(leftPos == len) return 0;
    int rightPos = len - 2;
    while(rightPos >= 0 && height[rightPos] >= height[rightPos+1]) rightPos -= 1;
    if(rightPos == -1) return 0;

    leftPos -= 1;
    rightPos += 1;
    int answer = 0;
    while(leftPos < rightPos) {
      if(nextEqualGreater[leftPos] != -1) {
        int waterHeight = min(height[leftPos], height[nextEqualGreater[leftPos]]);
        for(int current = leftPos + 1, end = nextEqualGreater[leftPos] -1; current <= end; ++current) {
          answer += waterHeight - height[current];
        }
        leftPos = nextEqualGreater[leftPos];
      } else if (lastEqualGreater[rightPos] != -1) {
        int waterHeight = min(height[rightPos], height[lastEqualGreater[rightPos]]);
        for(int current = lastEqualGreater[rightPos] + 1, end = rightPos -1; current <= end; ++current) {
          answer += waterHeight - height[current];
        }
        rightPos = lastEqualGreater[rightPos];
      }
    }
    return answer;
  }
};
```

# November LeetCoding Challenge 17

## Description

**Mirror Reflection**

There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p`, and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0`th receptor.

Return the number of the receptor that the ray meets first. (It is guaranteed that the ray will meet a receptor eventually.)

**Example 1:**

```
Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
```

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png)

**Note:**

1. `1 <= p <= 1000`
2. `0 <= q <= p`

## Solution

just imagine that the ray reflected by mirrors is crossing the wall and hits further corners, where we just expand room by flip to top over and over again.

``` cpp
class Solution {
public:
  int mirrorReflection(int p, int q) {
    if(q == 0) return 0;
    int answer = -1;
    int minRound = INT_MAX;
    for(int i = 0; i < q; ++i) {
      if((i*2+1)*p % q == 0) {
        minRound = i*2 + 1;
        answer = 2 - (((i*2+1)*p/q) & 1);
        break;
      }
    }
    int end = q / gcd(p, q);
    for(int i = 0; i < end; ++i) {
      if((2*i+2)*p % q == 0) {
        if((i*2+2) < minRound) {
          answer = 0;
        }
        break;
      }
    }
    return answer;
  }
};
```
