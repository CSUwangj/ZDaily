+++
title = "2019-01-23 Daily Challenge"
path = "2019-01-23-daily-challenge"
date = 2019-01-23T00:46:06+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Digit factorials* in *Rust* and *Search a 2D Matrix II* in *JavaScript*.

<!--more-->

# Math

## Problem

### Digit factorials

### Problem 34

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

## Solution

Simple DFS is capabel for this problem.

Because 9!*7 < 9e7, so number limit will be 6.

## Implementation

```rust
use std::vec::Vec;

fn main() {
    let mut ans: Vec<i64> = Vec::new();
    dfs(0, 6, 0, 0, &mut ans);
    ans.sort();
    ans.dedup();
    let mut ans_sum = 0;
    for num in &ans {
        println!("{}", num);
        ans_sum += num;       
    }
    println!("Answer is {}", ans_sum);
}


fn dfs(c: i64, n: i64, num: i64, sum: i64, ans: &mut Vec<i64>){
    if sum == num && sum > 2 {
        ans.push(num);
    }
    if c > n {
        return;
    }
    for i in 0i64..10i64 {
        if num == 0 && i == 0 {
            continue;
        } else {
            dfs(c+1, n, num*10 + i, sum + factorial(i), ans);
        }
    }
}

fn factorial(i: i64) -> i64 {
    let mut tmp = 1;
    for j in 1..(i+1) {
        tmp *= j;
    }
    tmp
}
```

# Algorithm

## Problem

### 240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an *m* x *n* matrix. This matrix has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

**Example:**

Consider the following matrix:

```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

Given target = `5`, return `true`.

Given target = `20`, return `false`.

## Solution

Simple simulation.
## Implementation
```js
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
  if(!matrix.length || !matrix[0].length || target < matrix[0][0]) return false;
  let row = 0;
  let col = matrix[0].length - 1;
  let m = matrix.length;
  while (row < m && col >= 0) {
    if (target === matrix[row][col]) return true;
    else if (target < matrix[row][col]) --col;
    else ++row;
  }
  return false;
};
```