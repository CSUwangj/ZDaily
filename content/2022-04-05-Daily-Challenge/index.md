+++
updated = 2022-04-05 19:49:00+08:00
title = "2022-04-05 Daily-Challenge"
path = "2022-04-05-Daily-Challenge"
date = 2022-04-05 19:47:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/container-with-most-water/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 5

## Description

**Container With Most Water**

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

**Example 2:**

```
Input: height = [1,1]
Output: 1
```

 

**Constraints:**

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

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
  int maxArea(vector<int>& height) {
    int len = height.size();
    int left = 0, right = len - 1;
    int answer = (right - left) * min(height[left], height[right]);
    while(left < right) {
      if(height[left] < height[right]) {
        int tmp = height[left];
        while(left < right && height[left] <= tmp) ++left;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      } else {
        int tmp = height[right];
        while(left < right && height[right] <= tmp) --right;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      }
    }
    return answer;
  }
};

// Accepted
// 60/60 cases passed (150 ms)
// Your runtime beats 25.72 % of cpp submissions
// Your memory usage beats 38.72 % of cpp submissions (59.4 MB)
```
