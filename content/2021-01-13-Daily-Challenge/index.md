+++
title = "2021-01-13 Daily-Challenge"
path = "2021-01-13-Daily-Challenge"
date = 2021-01-13 18:00:59+08:00
updated = 2021-01-13 18:59:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Nth Magical Number](https://leetcode.com/problems/nth-magical-number/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3600/) with `cpp`.

<!-- more -->

# Nth Magical Number

## Description

A positive integer is *magical* if it is divisible by either `a` or `b`.

Given the three integers `n`, `a`, and `b`, return the `nth` magical number. Since the answer may be very large, **return it modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 1, a = 2, b = 3
Output: 2
```

**Example 2:**

```
Input: n = 4, a = 2, b = 3
Output: 6
```

**Example 3:**

```
Input: n = 5, a = 2, b = 4
Output: 10
```

**Example 4:**

```
Input: n = 3, a = 6, b = 4
Output: 8
```

 

**Constraints:**

- $1 \le n \le 10^9$
- $2 \le a, b \le 4 * 10^4$

## Solution

``` cpp
class Solution {
    const long long MOD = 1e9 + 7;
    int gcd(int a, int b) {
        int c = a % b;
        while(c) {
            a = b;
            b = c;
            c = a % b;
        }
        return b;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        int gcdAB = gcd(a, b);
        int lcmAB = a / gcdAB * b;
        long long roundNum = a / gcdAB + b / gcdAB - 1;
        long long answer = n / roundNum * lcmAB % MOD;
        int rest = n % roundNum;
        if(!rest) return answer;
        long long begin = 1, end = lcmAB-1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(mid / a + mid / b < rest) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return (answer + begin) % MOD;
    }
};
```

# January LeetCoding Challenge13

## Description

**Boats to Save People**

The `i`-th person has weight `people[i]`, and each boat can carry a maximum weight of `limit`.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most `limit`.

Return the minimum number of boats to carry every given person. (It is guaranteed each person can be carried by a boat.)

 

**Example 1:**

```
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
```

**Example 2:**

```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```

**Example 3:**

```
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

**Note**:

- `1 <= people.length <= 50000`
- `1 <= people[i] <= limit <= 30000`

## Solution

``` cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.empty()) return 0;
        sort(people.begin(), people.end());
        int len = people.size();
        int begin = 0, end = len-1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(people[mid] < limit) {
                begin = mid+1;
            } else {
                end = mid;
            }
        }
        int answer = len - end - 1;
        begin = 0;
        while(begin < end) {
            if(people[begin] + people[end] <= limit) {
                answer += 1;
                begin += 1;
                end -= 1;
            } else {
                answer += 1;
                end -= 1;
            }
        }
        if(begin == end) answer += 1;
        return answer;
    }
};
```
