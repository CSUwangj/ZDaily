+++
title = "2019-01-08 Daily Challenge"
path = "2019-01-08-daily-challenge"
date = 2019-01-08T00:31:26+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Counting Sundays* in *Rust* and *N-Queens II* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Counting Sundays

Problem 19 

You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
```

## Solution

Simple simulation.

## Implementation

```rust
fn main() {
    assert!(is_leap_year(2016));
    assert!(is_leap_year(1997) == false);
    let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut day = 2;
    let mut ans = 0;
    for year in 1901..2001{
        for month in 0..12 {
            if day == 0 {
                ans += 1;
            }
            if month == 1 {
                day = if is_leap_year(year) { (day + 29) % 7 } else { (day + 28) % 7 };
            } else {
                day = (day + days[month]) % 7;
            }
        } 
    }
    println!("Answer is {}", ans);
}

fn is_leap_year(n: i32) -> bool {
    n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)
}
```

# Algorithm

## Problem

```
52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

![img](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

## Solution

Simple DFS.

## Implementation

```js
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
  let row = new Array(n);
  let ans = 0;
  let dfs = (r) => {
    if(r == n){
      ans++;
      return;
    }
    for(let i = 0 ; i < n; ++ i){
      if(check(r, i)){
        row[r] = i;
        dfs(r + 1);
      }
    }
  };
  let check = (r, col) => {
    for(let i = 0; i < r; ++i){
      if(row[i] == col || Math.abs(row[i] - col) == Math.abs(r - i)){
        return false;
      }
    }
    return true;
  };
  dfs(0);
  return ans;
};
```