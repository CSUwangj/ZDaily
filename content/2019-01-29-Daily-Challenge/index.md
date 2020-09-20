+++
title = "2019-01-29 Daily Challenge"
path = "2019-01-29-daily-challenge"
date = 2019-01-29T12:26:03+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Champernowne's constant* in *Rust* and *~~Sudoku Solver~~Is Subsequence* in *JavaScript*.

I need more practice to write my own Dancing Link is JS.

<!-- more -->

# Math

## Problem

### Champernowne's constant

### Problem 40

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If *d**n* represents the *n*th digit of the fractional part, find the value of the following expression.

*d*1 × *d*10 × *d*100 × *d*1000 × *d*10000 × *d*100000 × *d*1000000

## Solution

Nothing to say.

## Implementation

```rust
fn main() {
    let mut ans = 1;
    for i in 0..7 {
        ans *= getdigit(10i32.pow(i));
    }
    println!("Answer is {}", ans);
}

fn getdigit(n: i32) -> i32 {
    let mut cur: i32 = 0;
    let mut s: i32 = 0;
    let mut index = 0;
    while s < n {
        cur = s;
        index += 1;
        s += 9*10i32.pow(index as u32 - 1) * (index as i32);
    }
    let h = n - cur - 1;
    let t = 10i32.pow(index-1) + h / (index as i32);
    let p = (h % (index as i32)) as usize;
    let ans = t.to_string().as_bytes()[p];
    let ans = ans as char;
    let ans = ans.to_digit(10).unwrap();
    ans as i32
}
```

# Algorithm

## Problem

### 392. Is Subsequence

Medium

Given a string **s** and a string **t**, check if **s** is subsequence of **t**.

You may assume that there is only lower case English letters in both **s** and **t**. **t** is potentially a very long (length ~= 500,000) string, and **s** is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ace"` is a subsequence of `"abcde"`while `"aec"` is not).

**Example 1:**
**s** = `"abc"`, **t** = `"ahbgdc"`

Return `true`.

**Example 2:**
**s** = `"axc"`, **t** = `"ahbgdc"`

Return `false`.

**Follow up:**
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

**Credits:**
Special thanks to [@pbrother](https://leetcode.com/pbrother/) for adding this problem and creating all test cases.

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
  let cur = 0;
  for (let i = 0; i < t.length && cur < s.length; ++i) {
    if (t.charAt(i) === s.charAt(cur)) ++cur;
  }
  return cur === s.length;
};

// console.log(isSubsequence("abc","ahbgdc"));
// console.log(isSubsequence("axc","ahbgdc"));
```