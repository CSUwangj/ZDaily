+++
title = "2020-11-25 Daily-Challenge"
path = "2020-11-25-Daily-Challenge"
date = 2020-11-25 00:12:13+08:00
updated = 2020-11-25 18:15:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Minimum Flips to Make a OR b Equal to c* on [leetcode](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3543/) with `cpp`.

<!-- more -->

# Minimum Flips to Make a OR b Equal to c

## Description

Given 3 positives numbers `a`, `b` and `c`. Return the minimum flips required in some bits of `a` and `b` to make ( `a` OR `b` == `c` ). (bitwise OR operation).
Flip operation consists of change **any** single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/06/sample_3_1676.png)

```
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
```

**Example 2:**

```
Input: a = 4, b = 2, c = 7
Output: 1
```

**Example 3:**

```
Input: a = 1, b = 2, c = 3
Output: 0
```

**Constraints:**

- `1 <= a <= 10^9`
- `1 <= b <= 10^9`
- `1 <= c <= 10^9`

## Solution

nothing to say

``` cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        for(int i = 0; i < 32; ++i) {
            int cur = 1 << i;
            if(cur & c) {
                if(!(cur&(a|b))) answer += 1;
            } else {
                if(cur&a) answer += 1;
                if(cur&b) answer += 1;
            }
        }
        return answer;
    }
};
```

# November LeetCoding Challenge25

## Description

**Smallest Integer Divisible by K**

Given a positive integer `K`, you need to find the **length** of the **smallest** positive integer `N` such that `N` is divisible by `K`, and `N` only contains the digit `1`.

Return *the **length** of* `N`. If there is no such `N`, return -1.

**Note:** `N` may not fit in a 64-bit signed integer.

**Example 1:**

```
Input: K = 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.
```

**Example 2:**

```
Input: K = 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.
```

**Example 3:**

```
Input: K = 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.
```

**Constraints:**

- `1 <= K <= 105`

## Solution

not so elegant

``` cpp
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K & 1 == 0) return -1;
        int cur = 1;
        int sum = 1;
        for(int i = 1; i <= K; ++i) {
            if(sum % K == 0) return i;
            sum %= K;
            cur = cur * 10;
            cur %= K;
            sum += cur;
        }
        return -1;
    }
};
```