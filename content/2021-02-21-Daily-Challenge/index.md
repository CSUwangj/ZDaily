+++
title = "2021-02-21 Daily-Challenge"
path = "2021-02-21-Daily-Challenge"
date = 2021-02-21 18:20:59+08:00
updated = 2021-02-21 22:21:15+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3647/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge21

## Description

**Broken Calculator**

On a broken calculator that has a number showing on its display, we can perform two operations:

- **Double**: Multiply the number on the display by 2, or;
- **Decrement**: Subtract 1 from the number on the display.

Initially, the calculator is displaying the number `X`.

Return the minimum number of operations needed to display the number `Y`.

 

**Example 1:**

```
Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
```

**Example 2:**

```
Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
```

**Example 3:**

```
Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
```

**Example 4:**

```
Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.
```

 

**Note:**

1. $1 \le X \le 10^9$
2. $1 \le Y \le 10^9$

## Solution

``` cpp
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int answer = 0;
        while(Y > X) {
            if(Y & 1) Y += 1;
            else Y /= 2;
            answer += 1;
        }
        return answer + X - Y;
    }
};


```
