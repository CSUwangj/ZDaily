+++
title = "2018-12-25 Daily Challenge"
path = "2018-12-25-daily-challenge"
date = 2018-12-25T21:04:34+00:00
updated = 2020-09-19T20:01:27.624335+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Smallest multiple* in *Rust* and *Remove Duplicates from Sorted Array* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Smallest multiple

Problem 5 

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
```

## Solution

On the one hand I can compute the LCM with Euclidean Algorithm, one the other hand I can compute the contribution of each prime, and then, get the right answer.

## Implementation

```Rust
extern crate primal;

use primal::Primes;

fn main() {
    let mut ans = lcm(1,2);
    for i in 3..21 {
        ans = lcm(ans, i);
    }
    println!("Answer is {}", ans);
    
    ans = 1;
    let twenty: f64 = 20f64;
    let mut tmp: u64;
    for p in Primes::all().take(20) {
        if p > 19 {
            break;
        }
        let q = twenty.log(p as f64) as u32;
        tmp = p as u64;
        ans *= tmp.pow(q);
    }
    println!("Answer is {}", ans);
}

fn lcm(a: u64, b: u64) -> u64 {
    a/ gcd(a, b) * b
}

fn gcd(mut a: u64, mut b: u64) -> u64 {
    let mut tmp: u64;
    while b!= 0 {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    a
}
```

# Algorithm

## Problem

```
866. Prime Palindrome

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101
 

Note:

1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.
```

## Solution

First, according to the math problem I've done yesterday, every even-lengthed palindrome number is a multiple of eleven. So we can just skip them.

To check if a number is a prime, there is a lot of ways to do it. I once want use Miller-Rabin, but find it is so difficult to implicate it in JavaScript.

## Implementation

```javascript
/**
 * @param {number} N
 * @return {number}
 */
let primePalindrome = function(N) {
  let cur = N;
  if (N < 12){
    while(!isPrime(cur)) ++cur;
    return cur;
  }
  while(!isPal(cur)) cur++;
  while (true){
    if(isPrime(cur)) return cur;
    cur = nextPal(cur);
  }
};

let isPal = (n) =>{
  return ("" + n) == ("" + n).split("").reverse().join("");
};

let nextPal = (n) => {
  let s = ("" + n);
  let len = s.length;
  if(len % 2 == 0){
    return "1"+ "0".repeat(len-1) + "1";
  }else{
    let half = Math.ceil(len / 2);
    let left = s.slice(0, half);
    let plus1 = (+left + 1) + "";
    return +(plus1 + plus1.slice(0, plus1.length - 1).split("").reverse().join(""));
  }
};

let isPrime = (n) => {
  if(n%2 == 0) return n==2;
  for(let i=3; i*i<=n; i+=2){
    if(n%i===0) return false;
  }
  return n!=1;
};

// console.log(primePalindrome(1));
// console.log(primePalindrome(2));
// console.log(primePalindrome(3));
// console.log(primePalindrome(6));
// console.log(primePalindrome(8));
// console.log(primePalindrome(13));
// console.log(primePalindrome(11));
// console.log(primePalindrome(1234));
```