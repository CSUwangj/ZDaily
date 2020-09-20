+++
title = "2019-01-24 Daily Challenge"
path = "2019-01-24-daily-challenge"
date = 2019-01-24T00:13:03+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Circular primes* in *Rust* and *Super Ugly Number* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Circular primes

### Problem 35

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

## Solution

Nothing to say.

## Implementation

```rust
extern crate primal;

use primal::Sieve;
use std::string::ToString;

fn main() {
    const LIMIT: usize = 1_000_000;
    let sieve: Sieve = Sieve::new(LIMIT);
    let count = sieve.prime_pi(LIMIT) + 1usize;
    let mut ans = 0;
    for i in 1..count {
        let mut num = sieve.nth_prime(i);
        let l = num.to_string().len();
        let base = 10usize.pow(l as u32 - 1);
        // println!("{},{}",num,base);
        let mut is_ok = true;
        for _i in 1..l {
            num = num / base + num % base * 10;
            // println!("{}",num);
            if !sieve.is_prime(num) {
                is_ok = false;
                break;
            }
        }
        if is_ok {
            ans += 1;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 313. Super Ugly Number

Medium

Write a program to find the `nth` super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list `primes` of size `k`.

**Example:**

```
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
```

**Note:**

- `1` is a super ugly number for any given `primes`.
- The given numbers in `primes` are in ascending order.
- 0 < `k` ≤ 100, 0 < `n` ≤ 1e6, 0 < `primes[i]` < 1000.
- The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

## Solution

One way to solve it is priority queue, but ES6 doesn't have it.

Another way is use a array to maintain every position which primes should multiply.

## Implementation

```js
/**
 * @param {number} n
 * @param {number[]} primes
 * @return {number}
 */
var nthSuperUglyNumber = function(n, primes) {
  let pos = new Array(primes.length).fill(0);
  let ugly = [1];
  for (let i = 1; i < n; ++i) {
    let mn = Number.MAX_SAFE_INTEGER;
    for (let j = 0; j < primes.length; ++j) {
      mn = Math.min(mn, primes[j] * ugly[pos[j]]);
    }
    for (let j = 0; j < primes.length; ++j){
      if (!(mn%primes[j]))
        ++pos[j];
    }
    ugly[i] = mn;
  }
  return ugly[n-1];
};

// console.log(nthSuperUglyNumber(n = 12, primes = [2,7,13,19]));
```