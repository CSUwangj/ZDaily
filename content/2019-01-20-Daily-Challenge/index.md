+++
title = "2019-01-20 Daily Challenge"
path = "2019-01-20-daily-challenge"
date = 2019-01-20T00:17:53+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Digit fifth powers* in *Rust* and *Valid Square* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Coin sums

### Problem 31

In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

> 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

> 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

## Solution

Use DP to solve it.

## Implementation

```rust
use std::vec::Vec;

fn main() {
    println!("Answer is {}", solve(200));
}

fn solve(n: usize) -> i32 {
    let mut arr: Vec<i32> = vec![0; n + 1];
    let coins: [usize; 8] = [1, 2, 5, 10, 20, 50, 100, 200];
    arr[0] = 1;
    for coin in coins.iter() {
        if *coin <= n {
            for i in *coin..(n+1) {
                arr[i] += arr[i - coin];
            }
        }
    }
    return arr[n];
}

```

# Algorithm

## Problem

### 168. Excel Sheet Column Title

Easy

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```

**Example 1:**

```
Input: 1
Output: "A"
```

**Example 2:**

```
Input: 28
Output: "AB"
```

**Example 3:**

```
Input: 701
Output: "ZY"
```

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
  n -= 1;
  let base = 26;
  let len = 1;
  let ans = "";
  while(n >= base){
    n -= base;
    len += 1;
    base *= 26;
  }
  while(len){
    ans += String.fromCharCode(n%26+65);
    len -= 1;
    n = Math.floor(n/26);
  }
  return ans.split('').reverse().join('');
};
```