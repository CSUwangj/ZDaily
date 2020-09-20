+++
title = "2019-01-04 Daily Challenge"
path = "2019-01-04-daily-challenge"
date = 2019-01-04T14:50:05+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Lattice paths* in *Rust* and *Robot Return to Origin* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Lattice paths

Problem 15 

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?
```

![img](https://projecteuler.net/project/images/p015.gif)

## Solution

To a $n*n$ grid, the answer is $C_{2n}^{n}$.

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;

use num_bigint::{BigUint};
use num_traits::{One};

fn main() {
    let mut f1: BigUint = One::one();
    for i in 21u32..41u32 {
        let f2 = BigUint::from(i);
        f1 = f1 * &f2;
    }
    for i in 1u32..21u32 {
        let f2 = BigUint::from(i);
        f1 = f1 / &f2;
    }
    println!("Answer is {}", f1.to_str_radix(10));
}
```

# Algorithm

## Problem

```
657. Robot Return to Origin

There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.

Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

Example 1:

Input: "UD"
Output: true 
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
 

Example 2:

Input: "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
```

## Solution

Nothing to say.

## Implemtation

```js
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
  let up = 0;
  let left = 0;
  for(const i of moves){
    if(i === "L") left++;
    else if(i === "R") left--;
    else if(i === "U") up++;
    else up--;
  }
  return up==left&&up==0;
};
```