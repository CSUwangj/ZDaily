+++
title = "2021-02-17 Daily-Challenge"
path = "2021-02-17-Daily-Challenge"
date = 2021-02-17 16:45:33+08:00
updated = 2021-02-17 16:57:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge17

**Container With Most Water**

## Description

Given `n` non-negative integers `a1, a2, ..., an` , where each represents a point at coordinate `(i, ai)`. `n` vertical lines are drawn such that the two endpoints of the line `i` is at `(i, ai)` and `(i, 0)`. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

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

**Example 3:**

```
Input: height = [4,3,2,1,4]
Output: 16
```

**Example 4:**

```
Input: height = [1,2,1]
Output: 2
```

 

**Constraints:**

- `n == height.length`
- $2 \le n \le 3 * 10^4$
- $0 \le height[i] \le 3 * 10^4$

## Solution

ah ha! done by myself without hint

``` cpp
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

// find the max (j - i) * (min(a_j, a_i))
```