+++
title = "2021-07-31 Daily-Challenge"
path = "2021-07-31-Daily-Challenge"
date = 2021-07-31 20:10:03+08:00
updated = 2021-07-31 20:34:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3833/) with `cpp`.

<!-- more -->

# LeetCode Review

## Map Sum Pairs

too easy to review

## 01 Matrix

too easy to review

## Beautiful Array

too easy to review

## 3Sum Closest

too easy to review

## Convert Sorted Array to Binary Search Tree

too easy to review

## Shuffle String

too easy to review

## Most Visited Sector in a Circular Track

too easy to review

## K-diff Pairs in an Array

too easy to review

## Longest Substring Of All Vowels in Order

too easy to review

## Range Sum Query - Immutable

too easy to review

# July LeetCoding Challenge 31

## Description

**Trapping Rain Water**

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
- `0 <= n <= 3 * 10^4`
- `0 <= height[i] <= 10^5`

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
  int trap(vector<int>& height) {
    vector<int> maxRights{0};
    int len = height.size();
    for(int i = len - 1; i >= 0; --i) {
      if(height[i] >= maxRights.back()) {
        maxRights.push_back(height[i]);
      }
    }
    int maxLeft = 0;
    int answer = 0;
    for(auto h : height) {
      maxLeft = max(maxLeft, h);
      int maxRight = maxRights.back();
      int waterHeight = maxLeft > maxRight ? maxRight : maxLeft;
      answer += waterHeight > h ? (waterHeight - h) : 0;
      if(h == maxRight) {
        maxRights.pop_back();
      }
    }
    return answer;
  }
};

// Accepted
// 320/320 cases passed (4 ms)
// Your runtime beats 89.31 % of cpp submissions
// Your memory usage beats 42.07 % of cpp submissions (14.4 MB)
```
