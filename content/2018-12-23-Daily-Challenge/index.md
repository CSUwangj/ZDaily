+++
title = "2018-12-23 Daily Challenge"
path = "2018-12-23-daily-challenge"
date = 2018-12-23T00:48:00+00:00
updated = 2020-09-19T20:01:27.624335+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Factorize", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Largest prime factor* in *Rust* and *Coin Change* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Largest prime factor

Problem 3 

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
```

## Solution

At least we know we can factorize one number $n$ in roughly $O(\sqrt{n})$time.

There is also more complicated, more fast algorithm like Pollard's rho algorithm, but writing a implication on my own cost too much and need more knowledge with Rust, so just leave it.

There is already some tools like [factordb](http://factordb.com/), [yafu](https://github.com/DarkenCode/yafu).

By the way, I found optimization of Rust is incredible!

## Implementation

```rust
extern crate primal;

use std::vec::Vec;

fn main() {
    let mut cur_num:u64 = 2;
    let mut ans:u64 = 0;
    let mut target:u64 = 600851475143;
    let mx:u64 = 600851475143;
    while cur_num <= target && cur_num*cur_num <= mx {
        while target % cur_num == 0 {
            target /= cur_num;
            ans = cur_num;
        }
        cur_num += 1;
    }
    println!("answer is {}", ans);

    let mx:usize = 600851475143;
    let sieve = primal::Sieve::new(1<<311475143);
    let ans: Vec<(usize, usize)> = match sieve.factor(mx) {
        Ok(v) => v,
        Err(_) => Vec::new(),
    };
    for factor in ans {
        println!("({}, {})", factor.0, factor.1)
    }
}
```

# Algorithm

## Problem

```
322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
```

## Solution

I have a vague feeling this problem could be a $NP$ problem.

I guess I can do it with Dynamic Programming approach, and its time complexity is $O(coins.length*amount)$.

---

With the help of qt, I figure out that this question is the equivalence of Knapsack Problem, so it's a $NP-Hard$ problem. Dynamic Programming is the only way I know to deal with it.

## Implementation

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = (coins = [], amount) => {
  let dp = [0];
  for(let i = 1; i <= amount; ++i){
    dp.push(0x7F7F7F7F);
  }
  for(const v of coins){
    for(let i = v; i <= amount; ++i){
      if(dp[i-v]!=0x7F7F7F7F && dp[i-v] + 1 < dp[i]) dp[i] = dp[i-v] + 1;
    }
  }
  return dp[amount] == 0x7F7F7F7F? -1: dp[amount];
};

// console.log(coinChange([1, 2, 5],11));
// console.log(coinChange([2],3))
```