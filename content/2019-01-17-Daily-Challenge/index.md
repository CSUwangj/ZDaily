+++
title = "2019-01-17 Daily Challenge"
path = "2019-01-17-daily-challenge"
date = 2019-01-17T00:05:12+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Number spiral diagonals* in *Rust* and *Add Binary* in *JavaScript*.

BTW, I decided to the change style of problem section~

<!-- more -->

# Math

## Problem

### Number spiral diagonals

### Problem 28

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

**21** 22 23 24 **25**
20  **7**  8  **9** 10
19  6  **1**  2 11
18  **5**  4  **3** 12
**17** 16 15 14 **13**

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

## Solution

When you check the sequence 1, 3, 5, 7, 9, 13, 17, 21, 25, you will find that the numbers of sequence except the first one, others can be grouped by each four number.

## Implementation

```rust
fn main() {
    let mut ans: i64 = 1;
    let mut tmp: i64 = 1;
    for i in 1i64..501i64 {
        for _j in 0..4 {
            tmp += i*2;
            ans += tmp;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```

## Solution

Because of large input, naive implementation will fail.

## Implementation

Failed implementation:

```js
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  return (parseInt(a,2)+parseInt(b,2)).toString(2);
};
```

Successful submission:

```js
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  return (BigInt("0b"+a)+BigInt("0b"+b)).toString(2);
};
```

If I want to be more efficient, I should write a function do string binary add.