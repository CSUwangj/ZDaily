+++
title = "2018-12-26 Daily Challenge"
path = "2018-12-26-daily-challenge"
date = 2018-12-26T10:09:24+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Sum square difference* in *Rust* and *Split Array into Consecutive Subsequences* in *JavaScript*.

<!--more-->

# Math

## Problem

```
Sum square difference

Problem 6 

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
```

## Solution

Brute force is enough for such a small range.

But if I want to solve it more elegantly, there is one formula show up during my high school life.

$1^2+2^2+3^2+...+n^2=\frac{n(n+1)(2n+1)}{6}$

So the answer will be $\frac{n^4}{4}+\frac{n^3}{6}-\frac{n^2}{4}-\frac{n}{6}$

## Implementation

```rust
fn main() {
    println!("Answer is {}", solve_brute(100));
    println!("Answer is {}", solve_formula(100));
}

fn solve_brute(n: i32) -> i64 {
    let ans: i64;
    let mut tmp: i64 = 0;
    for i in 1..n+1 {
        tmp += i as i64;
    }
    ans = tmp * tmp;
    tmp = 0;
    for i in 1..n+1 {
        tmp += (i * i) as i64;
    }
    ans - tmp
}

fn solve_formula(n: i32) -> i64 {
    let tmp: f64 = n as f64;
    (tmp.powf(4.0)/4.0 + tmp.powf(3.0)/6.0 - tmp.powf(2.0) / 4.0 - tmp/6.0) as i64
}
```

# Algorithm

## Problem

```
659. Split Array into Consecutive Subsequences

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
```

## Solution

Call a *chain* a sequence of 3 or more consecutive numbers.

Considering numbers `x` from left to right, if `x` can be added to a current chain, it's at least as good to add `x` to that chain first, rather than to start a new chain.

So we just need to see if current x can be add to a chain or can be first of a new chain.

## Implementation

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isPossible = (nums) => {
  let map = new Map();
  let need = new Map();

  for(const i of nums){
    if(!map.has(i)) map.set(i, 1);
    else map.set(i, map.get(i)+1);
  }

  // console.log(map);
  // console.log(need);

  for(const i of nums){
    if(map.get(i) == 0) continue;
    else if(need.has(i)&&need.get(i) > 0){
      need.set(i, need.get(i)-1);
      need.set(i+1, need.has(i+1)?need.get(i+1)+1:1);
    }else if(map.has(i+1)&&map.get(i+1)>0&&map.has(i+2)&&map.get(i+2)>0){
      map.set(i+1, map.get(i+1)-1);
      map.set(i+2, map.get(i+2)-1);
      need.set(i+3, need.has(i+3)?need.get(i+3)+1:1);
    }else return false;
    map.set(i, map.get(i)-1);
  }

  return true;
};

// console.log(isPossible([1,2,3,3,4,5]));
// console.log(isPossible([1,2,3,3,4,4,5,5]));
// console.log(isPossible([1,2,3,4,4,5]));
```