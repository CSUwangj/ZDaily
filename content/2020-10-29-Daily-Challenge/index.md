+++
title = "2020-10-29 Daily-Challenge"
path = "2020-10-29-Daily-Challenge"
date = 2020-10-29 00:48:47+08:00
updated = 2020-10-29 19:17:09+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Add Digits* on [leetcode](https://leetcode.com/problems/add-digits/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3512/) with `cpp`.

<!-- more -->

# Add Digits

## Description

Given a non-negative integer `num`, repeatedly add all its digits until the result has only one digit.

**Example:**

```
Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
```

**Follow up:**

Could you do it without any loop/recursion in O(1) runtime?

## Solution

first of all, we can notice that $1\equiv10\equiv100\equiv1000\mod9$

if we have a decimal number like `abcdefg` where `a-g` is digits, we can use associativity to rewrite answer to following:

$$
\begin{aligned}
  answer & = a + b + c + ... + g \mod 10\\
  answer & = (a\mod 10 + b\mod 10 + c\mod 10 + ... + g \mod 10) \mod 10\\
\end{aligned}
$$

we can see that all we need is `num%9` and deal with when num is a multiple of 9.

``` cpp
class Solution {
public:
  int addDigits(int num) {
    return num ? 1+(num-1)%9 : 0;
  }
};
```

# October LeetCoding Challenge29

**Maximize Distance to Closest Person**

## Description

You are given an array representing a row of `seats` where `seats[i] = 1` represents a person sitting in the `ith` seat, and `seats[i] = 0` represents that the `ith` seat is empty **(0-indexed)**.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return *that maximum distance to the closest person*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/10/distance.jpg)

```
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```

**Example 2:**

```
Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
```

**Example 3:**

```
Input: seats = [0,1]
Output: 1
```

**Constraints:**

- `2 <= seats.length <= 2 * 104`
- `seats[i]` is `0` or `1`.
- At least one seat is **empty**.
- At least one seat is **occupied**.

## Solution

simple simulation

``` cpp
class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    vector<int> left(seats.size());
    vector<int> right(seats.size());
    int left_most = -20000;
    int right_most = 40000;
    for(int i = 0; i < seats.size(); ++i) {
      if(seats[i] == 1) left_most = i;
      else left[i] = left_most;
    }
    for(int i = seats.size()-1; i >= 0; --i) {
      if(seats[i] == 1) right_most = i;
      else right[i] = right_most;
    }
    int ans = -1;
    for(int i = 0; i < seats.size(); ++i) {
      if(!seats[i]) ans = max(ans, min(i-left[i], right[i]-i));
    }
    return ans;
  }
};
```
