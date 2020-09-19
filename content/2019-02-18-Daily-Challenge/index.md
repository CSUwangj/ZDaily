+++
title = "2019-02-18 Daily Challenge"
path = "2019-02-18-daily-challenge"
date = 2019-02-18T00:01:36+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Prime pair sets* in *Rust* and *Generate Parentheses* in *JavaScript*.

<!--more-->

# Math

## Problem

### Prime pair sets

### Problem 60

The primes 3, 7, 109, and 673, are quite remarkable. By taking any 
two primes and concatenating them in any order the result will always 
be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. 
The sum of these four primes, 792, represents the lowest sum for a set 
of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

## Solution

Brute force.

## Implementation

```rust
extern crate primal;

use primal::Sieve;

fn main() {
    let sieve: Sieve = Sieve::new(1_000_000_000);
    let mut ans = 0;
    let mut found = false;
    let mut cur = sieve.prime_pi(673);
    let mut buf: [usize; 5] = [0; 5];
    while !found {
        buf[0] = sieve.nth_prime(cur);
        match dfs(1, cur, &mut buf, &sieve) {
            true => found = true,
            false => cur += 1,
        }
    }
    println!("{:?}", buf);
    for i in &buf {
        ans += i;
    }
    println!("Answer is {}", ans);
}

fn dfs(n: usize, index: usize, mut buf: &mut [usize], sieve: &Sieve) -> bool {
    if n == 5 {
        return true;
    }
    // if n == 4 {
    //     println!("{:?}", buf);
    // }
    for i in (2..index).rev() {
        let tmp = sieve.nth_prime(i);
        if test_it(n, tmp, &buf, &sieve) {
            buf[n] = tmp;
            if dfs(n+1, i, &mut buf, &sieve) {
                return true
            }
        }
    }
    false
}

fn test_it(index: usize, num: usize, buf: &[usize], sieve: &Sieve) -> bool {
    for i in 0..index {
        if !(sieve.is_prime(append_num(num, buf[i]))&&sieve.is_prime(append_num(buf[i], num))) {
            return false;
        }
    }
    true
}

fn append_num(mut left: usize, mut right: usize) -> usize {
    let mut tmp = 0;
    while right != 0 {
        tmp = tmp * 10 + right % 10;
        right /= 10;
    }
    while tmp != 0 {
        left = left * 10 + tmp % 10;
        tmp /= 10;
    }
    left
}
```

# Algorithm

## Problem

### 22. Generate Parentheses

Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given *n* = 3, a solution set is:

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

## Solution

Solve it recursively.

## Implementation

```js
var generateParenthesis = function(n) {
  if (n === 0) return [""];
  let ans = [];
  for (let i = 0; i < n; i += 1) {
    for (const left of generateParenthesis(i)) {
      for (const right of generateParenthesis(n-1-i)){
        ans.push(`(${left})${right}`);
      }
    }
  }
  return ans;
};
```