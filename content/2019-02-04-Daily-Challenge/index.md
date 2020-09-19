+++
title = "2019-02-04 Daily Challenge"
path = "2019-02-04-daily-challenge"
date = 2019-02-04T00:00:50+00:00
updated = 2020-09-19T20:01:27.630319+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Triangular, pentagonal, and hexagonal* in *Rust* and *LRU Cache* in *JavaScript*.

<!--more-->

# Math

## Problem

### Goldbach's other conjecture

### Problem 46

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

## Solution

Nothing to say.

## Implementation

```rust
extern crate primal;

use primal::Sieve;

fn main() {
    const LIMIT: usize = 1_000_000;
    let sieve: Sieve = Sieve::new(LIMIT);
    let mut found = false;
    let mut cur: usize = 9;
    let mut ans: usize = 0;
    while !found {
        while sieve.is_prime(cur) {
            cur += 2;
        }
        let bound = sieve.prime_pi(cur-1);
        let mut ok = false;
        for i in 1..(bound+1) {
            if is_twice_a_square(cur - sieve.nth_prime(i)) {
                ok = true;
                break;
            }
        }
        if !ok {
            ans = cur;
            found = true;
        }
        cur += 2;
    }
    println!("Answer is {}", ans);
}

fn is_twice_a_square(n: usize) -> bool {
    let tmp = (n/2) as f64;
    let tmp = tmp.sqrt();
    let tmp = tmp as usize;
    tmp*tmp == n/2
}
```

# Algorithm

## Problem

### 55. Jump Game

Medium

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

## Solution

Simple DP.

## Implementation

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
  let dp = 0;
  for (let i = 0; i <= Math.min(nums.length-1, dp); ++i) {
    dp = Math.max(i+nums[i], dp);
    if (dp >= nums.length-1) return true;
  }
  return false;
};
```