+++
updated = 2022-09-18 18:14:00+08:00
title = "2022-09-18 Daily-Challenge"
path = "2022-09-18-Daily-Challenge"
date = 2022-09-18 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/trapping-rain-water/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 18

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
- `1 <= n <= 2 * 10^4`
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
// 322/322 cases passed (21 ms)
// Your runtime beats 72.47 % of cpp submissions
// Your memory usage beats 43.13 % of cpp submissions (20.2 MB)
```
