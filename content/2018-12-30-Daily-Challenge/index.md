+++
title = "2018-12-30 Daily Challenge"
path = "2018-12-30-daily-challenge"
date = 2018-12-30T01:10:04+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Summation of primes* in *Rust* and *Best Time to Buy and Sell Stock with Transaction Fee* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Summation of primes

Problem 10 

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
```

## Solution

Sieve for prime!!!!

Extern crate again ;D

## Implementation

```rust
extern crate primal;

fn main() {
    let sieve = primal::Sieve::new(2_000_000);
    let mut ans64: i64 = 0;
    for p in sieve.primes_from(2) {
        ans64 += p as i64;
    }
    println!("Answer is {}", ans64);
}
```

# Algorithm

## Problem

```
714. Best Time to Buy and Sell Stock with Transaction Fee


Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
```

## Solution

I remembered that similar question is example problem of *Divide and Conquer* algorithm in *Introduction to Algorithm*. But this question can not be done with this method.

We should maintain the max profit of holding stock and not holding stock, and recursively conquer it.

## Implementation

```js
/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = (prices, fee) => {
  let nothold = 0;
  let hold = -prices[0] - fee;
  for(const p of prices){
    nothold = (nothold>hold+p)?nothold:hold+p;
    hold = (hold>nothold-p-fee)?hold:nothold-p-fee;
  }
  return nothold;
};
```