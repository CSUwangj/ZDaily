+++
title = "2021-03-17 Daily-Challenge"
path = "2021-03-17-Daily-Challenge"
date = 2021-03-17 16:31:03+08:00
updated = 2021-03-17 20:49:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Subarray To Maximize Array Value](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3675/) with `cpp`.

<!-- more -->

# Reverse Subarray To Maximize Array Value

## Description

You are given an integer array `nums`. The *value* of this array is defined as the sum of `|nums[i]-nums[i+1]|` for all `0 <= i < nums.length-1`.

You are allowed to select any subarray of the given array and reverse it. You can perform this operation **only once**.

Find maximum possible value of the final array.

 

**Example 1:**

```
Input: nums = [2,3,1,5,4]
Output: 10
Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
```

**Example 2:**

```
Input: nums = [2,4,9,24,2,1,10]
Output: 68
```

 

**Constraints:**

- `1 <= nums.length <= 3*10^4`
- `-10^5 <= nums[i] <= 10^5`

## Solution

check [O(n) Solution with explanation
](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489882/O(n)-Solution-with-explanation), very clear explanation with helpful image which helps me a lot.

``` cpp
class Solution {
public:
  int maxValueAfterReverse(vector<int>& nums) {
    int len = nums.size();
    int value = 0;
    for(int i = 1; i < len; ++i) value += abs(nums[i] - nums[i - 1]);
    if(len < 3) return value;
    
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    for(int i = 0; i < len - 1; ++i) {
      mmin = min(mmin, max(nums[i], nums[i + 1]));
      mmax = max(mmax, min(nums[i], nums[i + 1]));
    }
    int change = (mmax - mmin) * 2;
    for(int i = 1; i < len; ++i) {
      int swap = abs(nums[0] - nums[i]) - abs(nums[i] - nums[i - 1]);
      change = max(swap, change);
    }
    for(int i = 0; i < len - 1; ++i) {
      int swap = abs(nums.back() - nums[i]) - abs(nums[i] - nums[i + 1]);
      change = max(swap, change);
    }
    return value + change;
  }
};
```

# March LeetCoding Challenge 17

## Description

**Generate Random Point in a Circle**

Given the radius and x-y positions of the center of a circle, write a function `randPoint` which generates a uniform random point in the circle.

Note:

1. input and output values are in [floating-point](https://www.webopedia.com/TERM/F/floating_point_number.html).
2. radius and x-y position of the center of the circle is passed into the class constructor.
3. a point on the circumference of the circle is considered to be in the circle.
4. `randPoint` returns a size 2 array containing x-position and y-position of the random point, in that order.

**Example 1:**

```
Input: 
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
```

**Example 2:**

```
Input: 
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
```

**Explanation of Input Syntax:**

The input is two lists: the subroutines called and their arguments. `Solution`'s constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. `randPoint` has no arguments. Arguments are always wrapped with a list, even if there aren't any.

## Solution

already done before

``` cpp
const double pi = 3.14159265358979323846264338327950288419;

class Solution {
  random_device rd;
  mt19937 gen;
  uniform_real_distribution<double> distr;
  double r;
  double x;
  double y;
public:
  Solution(double radius, double x_center, double y_center): r(radius), x(x_center), y(y_center) {
    gen = mt19937(rd());
    distr = uniform_real_distribution<double>(0, 1);
  }

  vector<double> randPoint() {
    double r = this->r * sqrt(distr(gen));
    double t = distr(gen) * 2 * pi;
    return {x + r * cos(t), y + r * sin(t)};
  }
};
```
