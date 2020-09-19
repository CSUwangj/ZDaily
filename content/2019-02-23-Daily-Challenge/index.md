+++
title = "2019-02-23 Daily Challenge"
path = "2019-02-23-daily-challenge"
date = 2019-02-23T20:42:12+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Convergents of e* in *Rust* and *Sum of two lowest positive integers* in *JavaScript*.

<!--more-->

# Math

## Problem

### Convergents of e

### Problem 65

The square root of 2 can be written as an infinite continued fraction.

{% asset_img 1.png %}

The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats *ad infinitum*. In a similar way, √23 = [4;(1,3,1,8)].

It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations. Let us consider the convergents for √2.

{% asset_img 2.png %}

Hence the sequence of the first ten convergents for √2 are:

1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...

What is most surprising is that the important mathematical constant,
*e* = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2*k*,1, ...].

The first ten terms in the sequence of convergents for *e* are:

2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...

The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for *e*.

## Solution

Thanks to [OEIS](https://oeis.org/A113873)......

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;

use num_bigint::BigUint;
use num_traits::FromPrimitive;
use std::mem::replace;

fn main() {
    let mut a0: BigUint = FromPrimitive::from_u64(1).unwrap();
    let mut a1: BigUint = FromPrimitive::from_u64(1).unwrap();
    for i in 0..100 {
        if i % 3 == 0 || i % 3 == 1 {
            let a2 = a0 + &a1;
            a0 = replace(&mut a1, a2);
        } else {
            let n: BigUint = FromPrimitive::from_u64((i / 3 + 1) * 2).unwrap();
            let a2 = n * &a1 + &a0;
            a0 = replace(&mut a1, a2);
        }
    }
    let ans = a1.to_str_radix(10).chars()
                .map(|x| x as i32 - '0' as i32)
                .fold(0, |a, b| a+b);
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### Sum of two lowest positive integers

Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 integers. No floats or empty arrays will be passed.

For example, when an array is passed like `[19, 5, 42, 2, 77]`, the output should be `7`.

`[10, 343445353, 3453445, 3453545353453]` should return `3453455`.

## Solution

```js
function sumTwoSmallestNumbers(numbers) {  
  numbers.sort((a, b) => a-b);
  return numbers[0]+numbers[1];
};

const sumTwoSmallestNumbers = (numbers) => 
  numbers
    .sort((a, b) => a-b)
    .slice(0, 2)
    .reduce((a, b) => a+b);

const sumTwoSmallestNumbers = (numbers) => 
  numbers
    .reduce(
      (a, b) => [...a, b].sort((a, b) => a-b).slice(0, 2), 
      [Number.MAX_SAFE_INTEGER, Number.MAX_SAFE_INTEGER]
    )
    .reduce((a, b) => a+b);
```