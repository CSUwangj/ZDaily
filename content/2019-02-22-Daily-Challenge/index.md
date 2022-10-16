+++
title = "2019-02-22 Daily Challenge"
path = "2019-02-22-daily-challenge"
date = 2019-02-22T18:53:33+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
I've get tired with leetcode, especially meet strange runtime at yesterday. So I jumped into codewors and want to learn some fp and ES6 from Space :D

What I've done today is *Odd period square roots* in *Rust* and *Jaden Casing Strings* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Odd period square roots

### Problem 64

All square roots are periodic when written as continued fractions and can be written in the form:

{% asset_img 1.png %}

For example, let us consider √23:

{% asset_img 2.png %}

If we continue we would get the following expansion:

{% asset_img 3.png %}

The process can be summarised as follows:

{% asset_img 4.png %}

It can be seen that the sequence is repeating. For conciseness, we use the notation √23 = [4;(1,3,1,8)], to indicate that the block (1,3,1,8) repeats indefinitely.

The first ten continued fraction representations of (irrational) square roots are:

√2=[1;(2)], period=1
√3=[1;(1,2)], period=2
√5=[2;(4)], period=1
√6=[2;(2,4)], period=2
√7=[2;(1,1,1,4)], period=4
√8=[2;(1,4)], period=2
√10=[3;(6)], period=1
√11=[3;(3,6)], period=2
√12= [3;(2,6)], period=2
√13=[3;(1,1,1,1,6)], period=5

Exactly four continued fractions, for N ≤ 13, have an odd period.

How many continued fractions for N ≤ 10000 have an odd period?

## Solution

I "borrow" something from wikipedia but don't get it known...

## Implementation

```rust
fn main() {
    let mut ans = 0;
    for i in 1..10001 {
        ans += get_period(i) & 1;
    }
    println!("Answer is {}", ans);
}

fn get_period(n: i32) -> i32 {
    let root = (n as f64).sqrt() as i32;
    if root * root == n {
        return 0;
    }
    let mut extra = root;
    let mut numerator = 0;
    let mut denominator = 1;
    let mut period = 0;
    while extra != 2 * root {
        numerator = denominator * extra - numerator;
        if (n - numerator * numerator) % denominator != 0 && (root + numerator) % denominator != 0 {
            panic!("???");
        }
        denominator = (n - numerator * numerator) / denominator;
        extra = (root + numerator) / denominator;
        period += 1;
    }
    period
}
```

# Codewar

## Problem

### Jaden Casing Strings



- Jaden Smith, the son of Will Smith, is the star of films such as The Karate Kid (2010) and After Earth (2013). Jaden is also known for [some of his philosophy that he delivers via Twitter](https://twitter.com/officialjaden). When writing on Twitter, he is known for almost always capitalizing every word.

  Your task is to convert strings to how they would be written by Jaden Smith. The strings are actual quotes from Jaden Smith, but they are not capitalized in the same way he originally typed them.

  Example:

  ```
  Not Jaden-Cased: "How can mirrors be real if our eyes aren't real"
  Jaden-Cased:     "How Can Mirrors Be Real If Our Eyes Aren't Real"
  ```

  Note that the **Java version** expects a return value of null for an empty string or null

## Solution

```js
String.prototype.toJadenCase = function () {
  return this.split(" ").map(([a, ...i]) => [a.toUpperCase(), ...i].join("")).join(" ");
};
```