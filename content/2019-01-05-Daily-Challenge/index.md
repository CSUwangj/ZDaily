+++
title = "2019-01-05 Daily Challenge"
path = "2019-01-05-daily-challenge"
date = 2019-01-05T00:01:21+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Power digit sum* in *Rust* and *Swap Adjacent in LR String* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Power digit sum

Problem 16 

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
```

## Solution

Nothing to say.

## Implementation

```rust
extern crate num_bigint;

use num_bigint::{BigInt};
use std::ops::Shl;

fn main() {
    let mut num: BigInt = BigInt::from(1u32);
    num = num.shl(1000 as usize);
    let num = num.to_str_radix(10);
    let mut ans = 0;
    const MINES: i32 = 48;
    for i in num.chars() {
        ans += (i as i32) - MINES;
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

```
777. Swap Adjacent in LR String

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
```

## Solution

We could observe these pattern:

- Any one "L" and another "R" won't change their relative position.
- Position of "L"s only can be more left, "R" only can be more right.

## Implementation

```js
/**
 * @param {string} start
 * @param {string} end
 * @return {boolean}
 */
var canTransform = function(start, end) {
  let fset = [];
  let fpos = [];
  let sset = [];
  let spos = [];
  for(let i = 0, l = start.length; i < l; ++i){
    if(start[i] != "X"){
      fset.push(start[i]);
      fpos.push(i);
    }
  }
  for(let i = 0, l = start.length; i < l; ++i){
    if(end[i] != "X"){
      sset.push(end[i]);
      spos.push(i);
    }
  }
  if(fset.length != sset.length) return false;
  for(let i = 0, l = fset.length; i < l; ++i){
    if(fset[i] != sset[i]||
      (fset[i] == "L" && fpos[i] < spos[i])||
      (fset[i] == "R" && fpos[i] > spos[i])){
      return false;
    }
  }
  return true;
};
```