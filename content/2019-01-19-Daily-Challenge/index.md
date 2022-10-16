+++
title = "2019-01-19 Daily Challenge"
path = "2019-01-19-daily-challenge"
date = 2019-01-19T01:04:34+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Digit fifth powers* in *Rust* and *Valid Square* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Digit fifth powers

### Problem 30

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

$1634 = 1^4 + 6^4 + 3^4 + 4^4$
$8208 = 8^4 + 2^4 + 0^4 + 8^4$
$9474 = 9^4 + 4^4 + 7^4 + 4^4$

As $1 = 1^4$ is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

## Solution

All you need is a DFS.

Because $9^5<10^5$,$7\times 9^5<10^6$, so upper bound of DFS is 6.

## Implementation

```rust
use std::vec::Vec;

fn main() {
    let mut ans: Vec<i32> = Vec::new();
    dfs(0, 5, 0, 0, &mut ans);
    ans.sort();
    ans.dedup();
    let mut ans_sum = 0;
    for num in &ans {
        println!("{}", num);
        ans_sum += num;       
    }
    println!("Answer is {}", ans_sum);
}


fn dfs(c: i32, n: i32, num: i32, sum: i32, ans: &mut Vec<i32>){
    if sum == num && sum > 1 {
        ans.push(num);
    }
    if c > n {
        return;
    }
    for i in 0i32..10i32 {
        dfs(c+1, n, num*10 + i, sum + i.pow(n as u32), ans);
    }
}
```

# Algorithm

## Problem

### 593. Valid Square

Medium

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

**Example:**

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
```



Note:

1. All the input integers are in the range [-10000, 10000].
2. A valid square has four equal sides with positive length and four equal angles (90-degree angles).
3. Input points have no order.

## Solution

Here's how I solve it:

1. There is three line when you fixed one point, and pick up shorter two.
2. Check if these two line are of same length and don't equal zero.
3. Check if these two line are perpendicular.

## Implementation

```js
/**
 * @param {number[]} p1
 * @param {number[]} p2
 * @param {number[]} p3
 * @param {number[]} p4
 * @return {boolean}
 */
var validSquare = function(p1, p2, p3, p4) {
  const dis = (p1, p2) => {
    return Math.sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
  };
  const cmp = (a, b) => {
    return a-b >1e-6;
  };
  if(cmp(dis(p1,p2), dis(p1,p3))) [p2, p4] = [p4, p2];
  else if(cmp(dis(p1,p3), dis(p1, p2))) [p3, p4] = [p4, p3];
  return !cmp(dis(p1,p2),dis(p1,p3)) && !cmp(dis(p1,p3),dis(p1,p2)) && cmp(dis(p1,p2),0)&&
         (Math.abs(p1[0]-p2[0]) === Math.abs(p3[0]-p4[0])) &&
         (Math.abs(p1[1]-p2[1]) === Math.abs(p3[1]-p4[1])) &&
         (Math.abs(p1[0]-p3[0]) === Math.abs(p2[0]-p4[0])) &&
         (Math.abs(p1[1]-p3[1]) === Math.abs(p2[1]-p4[1])) &&
         ((p1[0]-p2[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p2[1]) === 0);
};

// console.log(validSquare(p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]));
// console.log(validSquare([0,0], [5,0], [5,4], [0,4]));
```