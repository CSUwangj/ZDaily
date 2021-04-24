+++
title = "2021-03-11 Daily-Challenge"
path = "2021-03-11-Daily-Challenge"
date = 2021-03-11 21:03:31+08:00
updated = 2021-03-11 21:18:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Generate Random Point in a Circle](https://leetcode.com/problems/generate-random-point-in-a-circle/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3668/) with `cpp`.

<!-- more -->

# Generate Random Point in a Circle

## Description

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

``` cpp
constexpr double pi = 3.14159265358979732384626433832795;

class Solution {
  mt19937 gen;
  double x;
  double y;
  double r;
  uniform_real_distribution<double> distr;
  
public:
  Solution(double radius, double x_center, double y_center): r(radius), x(x_center), y(y_center), distr(0.0, 1.0){}
    
  vector<double> randPoint() {
    double angle = 2 * pi * distr(gen);
    double length = r * sqrt(distr(gen));
    return vector<double>{x + length * cos(angle), y + length * sin(angle)};
  }
};

```

# March LeetCoding Challenge11

## Description

**Coin Change**

You are given coins of different denominations and a total amount of money *amount*. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

 

**Example 1:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```
Input: coins = [1], amount = 0
Output: 0
```

**Example 4:**

```
Input: coins = [1], amount = 1
Output: 1
```

**Example 5:**

```
Input: coins = [1], amount = 2
Output: 2
```

 

**Constraints:**

- $1 \le coins.length \le 12$
- $1 \le coins[i] \le 2^{31} - 1$
- $0 \le amount \le 10^4$

## Solution

``` cpp
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount+1);
    dp[0] = 0;
    for(auto coin : coins){
      for(int i = coin; i <= amount; ++i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
    return dp.back() > amount ? -1 : dp.back();
  }
};
```
