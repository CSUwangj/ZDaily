+++
title = "2019-02-15 Daily Challenge"
path = "2019-02-15-daily-challenge"
date = 2019-02-15T00:08:00+00:00
updated = 2020-09-19T20:01:27.630319+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Square root convergents* in *Rust* and *Merge Intervals* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Square root convergents

### Problem 57

It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 
1393/985, is the first example where the number of digits in the numerator exceeds 
the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?

## Solution

Check [A000129](https://oeis.org/A000129)/[A001541](https://oeis.org/A001541)/[A002315](https://oeis.org/A002315)

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;

use num_bigint::BigInt;
use num_traits::FromPrimitive;
use std::mem::replace;

fn main() {
    let mut ans = 0;
    let mut den0: BigInt = FromPrimitive::from_i32(2).unwrap();
    let mut den1: BigInt = FromPrimitive::from_i32(5).unwrap();
    let mut num00: BigInt = FromPrimitive::from_i32(1).unwrap();
    let mut num01: BigInt = FromPrimitive::from_i32(3).unwrap();
    let mut num10: BigInt = FromPrimitive::from_i32(1).unwrap();
    let mut num11: BigInt = FromPrimitive::from_i32(7).unwrap();
    let six: BigInt = FromPrimitive::from_i32(6).unwrap();
    let two: BigInt = FromPrimitive::from_i32(2).unwrap();
    for i in 0..1000 {
        let den_s = den0.to_str_radix(10).len();
        let den2 = den0 + &two * &den1;
        den0 = replace(&mut den1, den2);
        if i & 1 == 0 {
            let num02 = -num00 + &six * &num01;
            num00 = replace(&mut num01, num02);
            let num_s = num00.to_str_radix(10).len();
            if num_s > den_s {
                ans += 1;
            }
        } else {
            let num12 = -num10 + &six * &num11;
            num10 = replace(&mut num11, num12);
            let num_s = num10.to_str_radix(10).len();
            if num_s > den_s {
                ans += 1;
            }
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## Solution

Nothing to say.

## Implementation

```js
/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
  let ans = [];
  if (!intervals.length) return ans;
  intervals.sort( (a, b) => a.start-b.start );
  let cur = intervals[0];
  for (let i = 1; i < intervals.length; ++i) {
    if (intervals[i].start <= cur.end) cur.end = Math.max(cur.end, intervals[i].end);
    else {
      ans.push(cur);
      cur = intervals[i];
    }
  }
  ans.push(cur);
  return ans;
};
```

![haha](47.png);D