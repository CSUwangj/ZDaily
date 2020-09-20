+++
title = "2019-01-21 Daily Challenge"
path = "2019-01-21-daily-challenge"
date = 2019-01-21T00:05:04+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Pandigital products* in *Rust* and *Candy* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Pandigital products

### Problem 32

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

## Solution

Because there are nine digits, so multiplication will be $a\times bcde=fghi$ or $ab\times cde=fghi$.

But apart from brute force approach, I can't find another solution.

## Implementation

```rust
use std::collections::HashSet;

fn main() {
    let mut set: HashSet<i32> = HashSet::new();
    let mut ans = 0;
    for i in 1..10 {
        for j in 1234..9877 {
            if i*j > 9999 {
                break;
            }
            if check(i, j, i*j) {
                println!("{} * {} = {}", i, j, i*j);
                set.insert(i*j);
            }
        }
    }
    for i in 12..99 {
        for j in 123..988{
            if i*j > 9999 {
                break;
            }
            if check(i, j, i*j) {
                println!("{} * {} = {}", i, j, i*j);
                set.insert(i*j);
            }
        }
    }
    for num in set {
        ans += num;
    }
    println!("Answer is {}", ans);
}

fn check(mut multiplicand: i32, mut multiplier: i32, mut product: i32) -> bool {
    let mut ok: [bool; 10] = [false; 10];
    while multiplicand > 0 {
        let tmp = multiplicand % 10;
        multiplicand /= 10;
        if tmp == 0 || ok[tmp as usize] {
            return false;
        }
        ok[tmp as usize] = true;
    }
    while multiplier > 0 {
        let tmp = multiplier % 10;
        multiplier /= 10;
        if tmp == 0 || ok[tmp as usize] {
            return false;
        }
        ok[tmp as usize] = true;
    }
    while product > 0 {
        let tmp = product % 10;
        product /= 10;
        if tmp == 0 || ok[tmp as usize] {
            return false;
        }
        ok[tmp as usize] = true;
    }
    return true;
}

```

# Algorithm

## Problem

### 135. Candy

There are *N* children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

**Example 1:**

```
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

**Example 2:**

```
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
```

## Solution

If ultimate answer is arr[n], consider one position k, arr[k] can only be arr[k-1] + 1, 1, or arr[k+1] + 1, which means all we need is scanning ratings from left, and scanning ratings from right.

## Implementation

```js
/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
  let n = ratings.length;
  let ans = 0;
  let left = new Array(n);
  let right = new Array(n);
  left[0] = 1;
  right[n-1] = 1;
  for(let i = 1; i < n; ++i){
    left[i] = ratings[i] > ratings[i-1]? left[i-1] + 1: 1;
    right[n-1-i] = ratings[n-1-i] > ratings[n-i]? right[n-i] + 1: 1;
  }
  for(let i = 0; i < n; ++i){
    ans += Math.max(left[i], right[i]);
  }
  return ans;
};

// console.log(candy([1,0,2]));
// console.log(candy([1,2,2]));
```