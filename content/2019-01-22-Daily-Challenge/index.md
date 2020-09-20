+++
title = "2019-01-22 Daily Challenge"
path = "2019-01-22-daily-challenge"
date = 2019-01-22T00:03:31+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Digit cancelling fractions* in *Rust* and *Repeated String Match* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Digit cancelling fractions

### Problem 33

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

## Solution

Brute force.

## Implementation

```rust
fn main() {
    let mut numerator = 1;
    let mut denominator = 1;
    for i in 1..9 {
        for j in i+1..10 {
            for k in 1..10 {
                if (i*10 + k)*j == (k*10 + j)*i {
                    println!("{}/{} = {}/{}",i*10+k,k*10+j,i,j);
                    numerator *= i;
                    denominator *= j;
                }
            }
        }
    }
    println!("Answer is {}", denominator/gcd(denominator, numerator));
}

fn gcd(a: usize, b: usize) -> usize {
    return if b == 0 { a } else { gcd(b, a%b) }
}
```

# Algorithm

## Problem

### 686. Repeated String Match

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

**Note:**
The length of `A` and `B` will be between 1 and 10000.

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {string} A
 * @param {string} B
 * @return {number}
 */
var repeatedStringMatch = function(A, B) {
  let nstr = A;
  while(nstr.length < B.length) nstr += A;
  return nstr.indexOf(B) !== -1 ? Math.ceil(B.length/A.length):((nstr+A).indexOf(B) === -1? -1:Math.ceil(B.length/A.length)+1);
};

// console.log(repeatedStringMatch("abcd","cdabcdab"));
```