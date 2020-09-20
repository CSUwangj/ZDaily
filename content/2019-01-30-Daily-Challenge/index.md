+++
title = "2019-01-30 Daily Challenge"
path = "2019-01-30-daily-challenge"
date = 2019-01-30T00:06:35+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Pandigital prime* in *Rust* and *Repeated DNA Sequences* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Pandigital prime

### Problem 41

We shall say that an *n*-digit number is pandigital if it makes use of all the digits 1 to *n* exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest *n*-digit pandigital prime that exists?

## Solution

So many pandigital problems...

## Implementation

```rust
extern crate primal;

use primal::StreamingSieve;
use primal::Primes;

fn main() {
    let mut ans = 0;
    let up_bd = StreamingSieve::prime_pi(1_000_000_000usize);
    for i in Primes::all().take(up_bd) {
        if is_pandigital(i) {
            println!("{}", i);
            ans = i;
        }
    }
    println!("Answer is {}", ans);
}

fn is_pandigital(n: usize) -> bool {
    // println!("n = {}", n);
    let l = n.to_string().len();
    for i in 1..(l+1) {
        let mut tmp = n;
        let mut is_ok = false;
        while tmp != 0 {
            if tmp % 10 == i && is_ok == false {
                is_ok = true
            } else if tmp % 10 == i && is_ok == true {
                return false;
            }
            // println!("{}", tmp);
            tmp /= 10;
        }
        if !is_ok {
            return false;
        }
    }
    true
}
```

# Algorithm

## Problem

### 187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

**Example:**

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
```

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
  let set = new Set();
  let ans = new Set();
  for (let i = 0; i <= s.length-10; ++i) {
    let tmp = s.substr(i, 10);
    if (set.has(tmp)) ans.add(tmp);
    set.add(tmp);
  }
  return Array.from(ans);
};
```