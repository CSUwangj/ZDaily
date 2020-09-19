+++
title = "2019-01-14 Daily Challenge"
path = "2019-01-14-daily-challenge"
date = 2019-01-14T18:24:34+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *1000-digit Fibonacci number* in *Rust* and *Best Time to Buy and Sell Stock IV* in *JavaScript*.

<!--more-->

# Math

## Problem

```
1000-digit Fibonacci number

Problem 25 

The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
```

## Solution

Nothing to say.

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;

use num_bigint::BigUint;
use num_traits::{Zero, One};
use std::mem::replace;

fn main() {
    let mut f0: BigUint = Zero::zero();
    let mut f1: BigUint = One::one();
    let mut index = 0;
    while f0.to_str_radix(10).len() < 1000usize {    
        let f2 = f0 + &f1;
        f0 = replace(&mut f1, f2);
        index += 1;
    }
    println!("Answer is {}", index);
}
```

# Algorithm

## Problem

```
188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

## Solution

DP.

But I'm too tired doing school project to explain it.

Leave it for later...

## Implementation

```js
/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
  if(!prices.length) return 0;
  if(k*2 >= prices.length) return maxProf(prices);
  let n = prices.length;
  let dp = new Array(n);
  dp.fill(0);
  for(let i = 0; i < k; ++i) {
    let min_paid = prices[0];
    let prev = dp[0];
    for(let j = 1; j < n; ++j) {
      let tmp = dp[j];
      min_paid = Math.min(min_paid, prices[j] - prev);
      dp[j] = Math.max(dp[j-1], prices[j]-min_paid);
      prev = tmp;
    }
  }
  return dp[n-1];
};

/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProf(prices){
  let ans = 0;
  let n = prices.length;
  for(let i = 1; i < n; ++i) {
    if(prices[i] > prices[i-1]) ans += prices[i]-prices[i-1];
  }
  return ans;
}

// console.log(maxProfit(2,[2,1,2,0,1]));
```