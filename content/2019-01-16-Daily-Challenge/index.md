+++
title = "2019-01-16 Daily Challenge"
path = "2019-01-16-daily-challenge"
date = 2019-01-16T00:07:53+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Quadratic primes* in *Rust* and *Longest Absolute File Path* in *JavaScript*.

<!--more-->

# Math

## Problem

```
Quadratic primes

Problem 27 

Euler discovered the remarkable quadratic formula:

n……2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,41^2+41+41 is clearly divisible by 41.

The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2+an+b, where |a|<1000 and |b|≤1000

where |n| is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
```

## Solution

Because n start from zero, so b must be a prime.

Because maximum number of primes for consecutive values must be greater than one, so when n equals one, the expression will be a prime, which means $1 + a + b$ is prime, when $b$ equals two, $a$ must be even, otherwise $a$ must be odd. But I don't want to do it.

## Implementation

```rust
extern crate primal;

use primal::Sieve;

fn main() {
    let sieve = Sieve::new(2_000_000);
    let mut ansa = 0;
    let mut ansb = 0;
    let mut ansc = 0;
    let count = sieve.prime_pi(1000) + 1usize;
    for i in -999i32..1000 {
        for j in 1..count {
            let mut tmpc = 1;
            loop {
                let tmp = tmpc * tmpc + i * tmpc + (sieve.nth_prime(j) as i32);
                if tmp < 0 {
                    break;
                }
                if !sieve.is_prime(tmp as usize) {
                    break;
                }
                tmpc += 1;
            }
            if tmpc > ansc {
                ansa = i;
                ansb = sieve.nth_prime(j);
                ansc = tmpc;
            }
        }
    }
    println!("Answer is {}, {}, {}", ansa, ansb, ansc);
}
```

# Alogorithm

```
388. Longest Absolute File Path


Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
```

## Solution

This problem looks like real world problem happens on Windows.

Solution is quite clear so I don't want to explain it.

The point is that when you come cross one file, you can know its ancestor directories's length.

## Implementation

```js
/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
  let sumArr = [];
  let ans = 0;
  const countTab = (str) => {
    for(let i = 0; i < str.length; ++i){
      if(str[i] !== "\t") return i;
    }
  };
  for(const str of input.split('\n')) {
    if(str.includes(".")){
      let pos = countTab(str);
      ans = Math.max(ans, pos?str.length - pos + sumArr[pos - 1]:str.length);
    }else{
      let pos = countTab(str);
      sumArr[pos] = pos?sumArr[pos - 1] + str.length - pos + 1:str.length+1;
    }
  }
  return ans;
};

// console.log(lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
// console.log(lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"));
// console.log(lengthLongestPath("asdf.asdf"));

```