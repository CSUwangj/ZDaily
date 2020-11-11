+++
title = "2020-11-11 Daily-Challenge"
path = "2020-11-11-Daily-Challenge"
date = 2020-11-11 07:57:55+08:00
updated = 2020-11-11 18:46:38+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Check If It Is a Good Array* on [leetcode](https://leetcode.com/problems/check-if-it-is-a-good-array/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3527/) with `cpp`.

<!-- more -->

# Check If It Is a Good Array

## Description

Given an array `nums` of positive integers. Your task is to select some subset of `nums`, multiply each element by an integer and add all these numbers. The array is said to be **good** if you can obtain a sum of `1` from the array by any possible subset and multiplicand.

Return `True` if the array is **good** otherwise return `False`.

**Example 1:**

```
Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
```

**Example 2:**

```
Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1
```

**Example 3:**

```
Input: nums = [3,6]
Output: false
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

## Solution

it's obvious that a array is good when it has a pair of elements which their greatest common divisor is 1.

``` cpp
class Solution {
  vector<int> primes;
  vector<bool> isPrime;
  void init(int maxNum) {
    maxNum = ceil(sqrt(maxNum));
    isPrime.resize(maxNum+1);
    for(int i = 2; i <= maxNum; ++i) {
      if(isPrime[i]) {
        primes.push_back(i);
      }
      for(int j = i*i; j <= maxNum; j += i) {
        isPrime[j] = false;
      }
    }
  }
public:
  bool isGoodArray(vector<int>& nums) {
    int minNum = *min_element(nums.begin(), nums.end());
    if(minNum == 1) return true;
    int maxNum = *max_element(nums.begin(), nums.end());
    init(maxNum);
    unordered_map<int, bool> visited;
    for(auto num : nums) {
      
      for(auto prime : primes) {
        if(num % prime == 0) {
          if(visited[num]) return
        }
      }
    }
  }
};
```

# November LeetCoding Challenge11

**Valid Square**

## Description

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

**Example:**

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
```

Note:

1. All the input integers are in the range [-10000, 10000].
2. A valid square has four equal sides with positive length and four equal angles (90-degree angles).
3. Input points have no order.

## Solution

not so elegant.

``` cpp
class Solution {
public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>> points{p1, p2, p3, p4};
    sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2) {
      return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    });
    int diffX1 = points[0][0] - points[3][0], diffX2 = points[1][0] - points[2][0];
    int diffY1 = points[0][1] - points[3][1], diffY2 = points[1][1] - points[2][1];
    int len1 = (diffX1*diffX1 + diffY1*diffY1), len2 = (diffX2*diffX2 + diffY2*diffY2);
    int len3 = (points[0][0] - points[1][0])*(points[0][0] - points[1][0]) + (points[0][1] - points[1][1])*(points[0][1] - points[1][1]);
    int len4 = (points[2][0] - points[3][0])*(points[2][0] - points[3][0]) + (points[2][1] - points[3][1])*(points[2][1] - points[3][1]);
    if(len1 == len2 && len3 == len4 && len3 != 0 && len1 != 0 && diffX2*diffX1 + diffY1*diffY2 == 0) return true;
    return false;
  }
};
```
