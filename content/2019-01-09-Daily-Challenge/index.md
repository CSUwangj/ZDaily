+++
title = "2019-01-09 Daily Challenge"
path = "2019-01-09-daily-challenge"
date = 2019-01-09T00:29:11+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Factorial digit sum* in *Rust* and *Minimum Window Substring* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Factorial digit sum

Problem 20 

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
```

## Solution

Nothing to say.

## Implementation

```rust
extern crate num_bigint;

use num_bigint::{BigInt};

fn main() {
    let mut result: BigInt = BigInt::from(1);
    for i in 2..101 {
        let num: BigInt = BigInt::from(i);
        result = result * &num;
    }
    let result = result.to_str_radix(10);
    let mut ans = 0;
    const MINES: i32 = 48;
    for i in result.chars() {
        ans += (i as i32) - MINES;
    }
    println!("Answer is {}",ans);
}
```

# Algorithm

## Problem

```
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
```

## Solution

Just maintain a sliding window include all needed character.

## Implementation

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
  let t_map = new Map();
  let s_map = new Map();
  for(const i of t){
    if(t_map.has(i)) t_map.set(i, t_map.get(i) + 1);
    else t_map.set(i, 1);
  }
  let lft = 0;
  let rht = 0;
  let ans = [-1,-1];
  let cnt = 0;
  let min = 1e10;
  while (rht < s.length) {
    let c = s.charAt(rht);
    if(t_map.has(c)){
      if(s_map.has(c)){
        s_map.set(c, s_map.get(c) + 1)
      }else{
        s_map.set(c, 1);
      }
      if(s_map.get(c) == t_map.get(c))cnt += 1;
    }
    if(cnt == t_map.size){
      while(lft <= rht && cnt == t_map.size){
        let cc = s.charAt(lft);
        if(rht - lft + 1 < min){
          min = rht - lft + 1;
          ans[0] = lft;
          ans[1] = rht;
        }
        if(t_map.has(cc)) {
          s_map.set(cc, s_map.get(cc) - 1);
          if(s_map.get(cc) < t_map.get(cc)){
            cnt -= 1;
          }
        }
        ++lft;
      }
    }
    ++rht;
  }
  return s.slice(ans[0], ans[1] + 1);
};

// console.log(minWindow("ADOBECODEBANC","ABC"));
// console.log(minWindow("AA","AA"));
```