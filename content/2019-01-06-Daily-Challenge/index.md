+++
title = "2019-01-06 Daily Challenge"
path = "2019-01-06-daily-challenge"
date = 2019-01-06T23:12:35+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Number letter counts* in *Rust* and *Reverse String* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Number letter counts

Problem 17 

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
```

## Solution

Emmmm, carefully simulation.

## Implementation

```rust
fn main() {
    assert!(nlc(342) == 23);
    assert!(nlc(115) == 20);
    assert!(nlc(1)+nlc(2)+nlc(3)+nlc(4)+nlc(5) == 19);
    assert!(nlc(900) == 11);
    let mut ans: i32 = 0;
    for i in 1..1001 {
        ans += nlc(i);
    }
    println!("Answer is {}", ans);
}

// nlc means Number Letter Count
// only apply to positive number and less  than 1e9 + 1
fn nlc(n: i32) -> i32 {
    match n {
        // one, two, six, ten
        1 | 2 | 6 | 10 => return 3,
        // zero, four, five, nine
        0 | 4 | 5 | 9 => return 4,
        // three, seven, eight, forty, fifty, sixty
        3 | 7 | 8 | 40 | 50 | 60 => return 5,
        // eleven, twelve, twenty, thirty, eighty, ninety
        11 | 12 | 20 | 30 | 80 | 90 => return 6,
        // fifteen, sixteen, seventy
        15 | 16 | 70 => return 7,
        // thirteen, fourteen, eighteen, nineteen
        13 | 14 | 18 | 19 => return 8,
        // seventeen
        17 => return 9,
        // one million, one billion
        1_000_000 | 1_000_000_000 => return 10,
        // one thouand
        1000 => return 11,
        // (\d)0 but not 10
        n if n > 20 && n < 100 => return nlc(n-n%10) + nlc(n%10),
        // (\d)00
        // {} hundred
        n if n > 99 && n < 1000 && n % 100 == 0 => return nlc(n/100) + 7,
        // 101..999 but not 100/200..
        // {} hundred and {}
        n if n > 100 && n < 1000 => return nlc(n/100) + 7 + 3 + nlc(n%100),
        // (\d)000
        n if n > 999 && n < 1000000 && n % 1000 == 0 => return nlc(n/1000) + 8,
        // 1001..999999
        // {} thousand {} hundred and {}
        n if n > 1000 && n < 1_000_000 => return nlc(n/1000) + 8 + nlc(n%1000),
        // (\d)000000
        n if n > 999_999 && n < 1_000_000_000 && n % 1_000_000 == 0 => return nlc(n/1_000_000) + 7,
        // 1000001..999999999
        // {} million {} thousand {} hundred and {}
        n if n > 1_000_000 && n < 1_000_000_000 => return nlc(n/1_000_000) + 7 + nlc(n%1_000_000),
        // -1 for error
        _ => return -1,
    }
}
```

# Algorithm

## Problem

```
344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
```

## Solution

Nothing to say

## Implementation

```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
  return s.split("").reverse().join("");
};
```