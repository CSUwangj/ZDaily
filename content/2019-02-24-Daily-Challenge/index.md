+++
title = "2019-02-24 Daily Challenge"
path = "2019-02-24-daily-challenge"
date = 2019-02-24T16:17:32+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Diophantine equation* in *Rust* and *Printer Errors* in *JavaScript*.

BTW, I found math became more and more difficult, far more than I've expected. I decided to learn some practical course before returning to math.

So there will be only CodeWars after today~

<!-- more -->

# Math

## Problem

### Diophantine equation

### Problem 66

Consider quadratic Diophantine equations of the form:

*x*2 – D*y*2 = 1

For example, when D=13, the minimal solution in *x* is 6492 – 13×1802 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in *x* for D = {2, 3, 5, 6, 7}, we obtain the following:

$3^2 – 2×2^2 = 1$
$2^2 – 3×1^2 = 1$
$9^2 – 5×4^2 = 1$
$5^2 – 6×2^2 = 1$
$8^2 – 7×3^2 = 1$

Hence, by considering minimal solutions in *x* for D ≤ 7, the largest *x* is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of *x* for which the largest value of *x* is obtained.

## Solution

Thanks to

- [How to find a fundamental solution to Pell's equation? - Mathematics Stack Exchange](https://math.stackexchange.com/questions/1045127/how-to-find-a-fundamental-solution-to-pells-equation)
- [Pell's equation - Wikipedia](https://en.wikipedia.org/wiki/Pell%27s_equation#Solutions)
- [Methods of computing square roots](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion)

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;
extern crate num_integer;

use num_bigint::BigInt;
use num_traits::{Zero, One, FromPrimitive};
use num_integer::Roots;
use std::vec::Vec;
use std::mem::{replace, swap};

fn main() {
    let mut ans: BigInt = Zero::zero();
    let mut index = 0;
    for i in 1u64..1001 {
        let tmp = pell_equation(i);
        if tmp > ans {
            replace(&mut ans, tmp);
            index = i;
        }
    }
    println!("Answer is {}", index);
}


fn pell_equation(d: u64) -> BigInt {
    let root = d.sqrt();
    if root * root == d {
        return Zero::zero();
    }
    let dd: BigInt = FromPrimitive::from_u64(d).unwrap();
    let mut extra = root;
    let mut extras: Vec<u64> = vec![];
    let mut numerator = 0;
    let mut denominator = 1;
    loop {
        extras.push(extra);
        numerator = denominator * extra - numerator;
        if (d - numerator * numerator) % denominator != 0 && (root + numerator) % denominator != 0 {
            panic!("???");
        }
        denominator = (d - numerator * numerator) / denominator;
        extra = (root + numerator) / denominator;
        let mut denominator: BigInt = Zero::zero();
        let mut numerator: BigInt = One::one();
        // println!("{:?}", extras);
        for i in (0..extras.len()).rev() {
            let mul: BigInt = FromPrimitive::from_u64(extras[i]).unwrap();
            denominator = mul * &numerator + &denominator;
            swap(&mut numerator, &mut denominator);
        }
        // println!("{}/{}", numerator.to_str_radix(10), denominator.to_str_radix(10));
        let tmp = &numerator * &numerator - &dd * &denominator * &denominator;
        if tmp == One::one() {
            println!("{}, {}, {}",d, numerator, denominator);
            return numerator;
        }
    }
}
```

# CodeWars

## Problem

### Printer Errors

In a factory a printer prints labels for boxes. For one kind of boxes the printer has to use colors which, for the sake of simplicity, are named with letters from `a to m`.

The colors used by the printer are recorded in a control string. For example a "good" control string would be `aaabbbbhaijjjm` meaning that the printer used three times color a, four times color b, one time color h then one time color a...

Sometimes there are problems: lack of colors, technical malfunction and a "bad" control string is produced e.g. `aaaxbbbbyyhwawiwjjjwwm` with letters not from `a to m`.

You have to write a function `printer_error` which given a string will output the error rate of the printer as a **string** representing a rational whose numerator is the number of errors and the denominator the length of the control string. Don't reduce this fraction to a simpler expression.

The string has a length greater or equal to one and contains only letters from `a`to `z`.

\#Examples:

```
s="aaabbbbhaijjjm"
error_printer(s) => "0/14"

s="aaaxbbbbyyhwawiwjjjwwm"
error_printer(s) => "8/22"
```
## Solution

```js
function printerError(s) {
  return `${[...s].map(a=>a.charCodeAt(0)>109).reduce((a, b)=>a+b)}/${s.length}`;
}

function printerError(s) {
  return `${[...s].filter(a=>a.charCodeAt(0)>109).length}/${s.length}`;
}

function printerError(s) {
  return `${s.replace(/[a-m]/gi, "").length}/${s.length}`;
}
```