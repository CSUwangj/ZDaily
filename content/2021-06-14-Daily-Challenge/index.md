+++
title = "2021-06-14 Daily-Challenge"
path = "2021-06-14-Daily-Challenge"
date = 2021-06-14 15:33:44+08:00
updated = 2021-06-15 21:23:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Preimage Size of Factorial Zeroes Function](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3778/) with `cpp`.

<!-- more -->

# Preimage Size of Factorial Zeroes Function

## Description

Let `f(x)` be the number of zeroes at the end of `x!`. (Recall that `x! = 1 * 2 * 3 * ... * x`, and by convention, `0! = 1`.)

For example, `f(3) = 0` because 3! = 6 has no zeroes at the end, while `f(11) = 2` because 11! = 39916800 has 2 zeroes at the end. Given `k`, find how many non-negative integers `x` have the property that `f(x) = k`.

```
Example 1:
Input: k = 0
Output: 5
Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.

Example 2:
Input: k = 5
Output: 0
Explanation: There is no x such that x! ends in k = 5 zeroes.
```

**Note:**

- `k` will be an integer in the range `[0, 10^9]`.

## Solution

``` cpp
constexpr long long zeros(long long x) {
  long long result = 0;
  while(x) {
    result += x / 5;
    x /= 5;
  }
  return result;
}
class Solution {
public:
  int preimageSizeFZF(int k) {
    long long start = 0;
    long long end = LONG_LONG_MAX;
    while(start < end) {
      auto mid = (start + end) >> 1;
      if(zeros(mid) < k) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    int begin = start;
    if(zeros(start) != k) return 0;
    start = 0;
    end = LONG_LONG_MAX - 1;
    while(start < end) {
      auto mid = (start + end + 1) >> 1;
      if(zeros(mid) > k) {
        end = mid - 1;
      } else {
        start = mid;
      }
    }
    return start - begin + 1;
  }
};
```

# June LeetCoding Challenge 14

## Description

**Maximum Units on a Truck**

You are assigned to put some amount of boxes onto **one truck**. You are given a 2D array `boxTypes`, where `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]`:

- `numberOfBoxesi` is the number of boxes of type `i`.
- `numberOfUnitsPerBoxi` is the number of units in each box of the type `i`.

You are also given an integer `truckSize`, which is the **maximum** number of **boxes** that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed `truckSize`.

Return *the **maximum** total number of **units** that can be put on the truck.*

 

**Example 1:**

```
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
```

**Example 2:**

```
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
```

 

**Constraints:**

- `1 <= boxTypes.length <= 1000`
- `1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000`
- `1 <= truckSize <= 10^6`

## Solution

``` cpp
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] > b[1];
    });
    int answer = 0;
    for(auto &boxType : boxTypes) {
      int n = min(truckSize, boxType[0]);
      answer += n * boxType[1];
      truckSize -= n;
      if(!truckSize) break;
    }
    return answer;
  }
};
```
