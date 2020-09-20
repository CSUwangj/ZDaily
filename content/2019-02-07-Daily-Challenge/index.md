+++
title = "2019-02-07 Daily Challenge"
path = "2019-02-07-daily-challenge"
date = 2019-02-07T00:11:58+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Self powers* in *Rust* and *Average of Levels in Binary Tree* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Prime permutations

### Problem 49

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

## Solution

I thought there is only (i) and (ii) required, but `each of the terms increases by 3330` is required, too......

## Implementation

Wrong solution

```rust
extern crate primal;

use primal::Sieve;
use std::collections::HashMap;
use std::string::String;

fn main() {
    let sieve: Sieve = Sieve::new(10000);
    let up_bound = sieve.prime_pi(10000) + 1;
    let down_bound = sieve.prime_pi(1000) + 1;
    let mut map: HashMap<usize, usize> = HashMap::new();
    for i in down_bound..up_bound {
        let tmp = sieve.nth_prime(i);
        if tmp != 1487 && tmp != 4817 && tmp != 8147 {
            let key = f(tmp);
            if map.contains_key(&key) {
                *map.get_mut(&key).unwrap() += 1;
            } else {
                map.insert(key, 1);
            }
        }
    }
    let mut k = 0;
    let mut ans: String = String::new();
    for (key, value) in map {
        if value == 3 {
            k = key;
        }
    }
    for i in down_bound..up_bound {
        let tmp = sieve.nth_prime(i);
        if f(tmp) == k {
            ans = format!("{}{}", ans, tmp);
        }
    }
    println!("Answer is {}", ans);
}

fn f(mut tmp: usize) -> usize {
    let mut tmp_vec = vec![];
    while tmp != 0 {
        tmp_vec.push(tmp % 10);
        tmp /= 10;
    }
    tmp_vec.sort();
    let mut key = 0;
    for i in tmp_vec {
        key *= 10;
        key += i;
    }
    key
}
```

Right solution:

```rust
extern crate primal;

use primal::Sieve;
use std::string::String;

fn main() {
    let sieve: Sieve = Sieve::new(10000);
    let up_bound = sieve.prime_pi(3330) + 1;
    let down_bound = sieve.prime_pi(1000) + 1;
    let mut ans: String = String::new();
    for i in down_bound..up_bound {
        let tmp = sieve.nth_prime(i);
        if tmp != 1487 {
            if f(tmp) == f(tmp+3330) && sieve.is_prime(tmp+3330) && f(tmp) == f(tmp+6660) && sieve.is_prime(tmp+6660) {
                ans = format!("{}{}{}", tmp, tmp+3330, tmp+6660)
            }
        }
    }
    println!("Answer is {}", ans);
}

fn f(mut tmp: usize) -> usize {
    let mut tmp_vec = vec![];
    while tmp != 0 {
        tmp_vec.push(tmp % 10);
        tmp /= 10;
    }
    tmp_vec.sort();
    let mut key = 0;
    for i in tmp_vec {
        key *= 10;
        key += i;
    }
    key
}
```

# Algorithm

## Problem

### 125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

**Note:** For the purpose of this problem, we define empty string as valid palindrome.

**Example 1:**

```
Input: "A man, a plan, a canal: Panama"
Output: true
```

**Example 2:**

```
Input: "race a car"
Output: false
```

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
  s = s.replace(/[^0-9a-zA-Z]/gm, "").toLocaleLowerCase();
  return s.split("").reverse().join("") === s;
};

// console.log(isPalindrome("A man, a plan, a canal: Panama"));
// console.log(isPalindrome("race a car"));
```