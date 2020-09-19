+++
title = "2019-02-11 Daily Challenge"
path = "2019-02-11-daily-challenge"
date = 2019-02-11T00:01:32+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Combinatoric selections* in *Rust* and *Search in Rotated Sorted Array* in *JavaScript*.

<!--more-->

# Math

## Problem

### Combinatoric selections

### Problem 53

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, $C^5_3​$ = 10.

In general,
$C^n_r=\frac{n!}{r!(n-r)!},where r ≤ n, n! = n×(n−1)×...×3×2×1, and\ 0! = 1​$

It is not until n = 23, that a value exceeds one-million: $C^{23}_{10}$ = 1144066.

How many, not necessarily distinct, values of  $C^n_r$, for 1 ≤ n ≤ 100, are greater than one-million?

## Solution

By definition you could find that $C^n_r=C^n_{(n-r)}$, and more, $C_r^n\ meet\ its\ maximum\ when\ r=n/2$.

## Implementation

```rust
fn main() {
    let mut ans = 0;
    for i in 2..101 {
        let mut tmp = 1;
        for j in 1..i/2 {
            tmp *= i-j+1;
            tmp /= j;
            if tmp > 1_000_000 {
                println!("C({}, {})", i, j);
                ans += i-j-j+1;
                break;
            }
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

## Solution

All you need to do is use what we done at the day before yesterday to find pivot, and add it into normal binary search.

## Implementation

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let begin = 0;
    let end = nums.length - 1;
    let mid;
    while (nums[begin] > nums[end]) {
      mid = Math.floor((begin + end) / 2);
      if (nums[mid] >= nums[begin]) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    let pivot = begin;
    begin = 0;
    end = nums.length;
    // console.log(begin, end);
    while (begin < end) {
      mid = (Math.floor((begin + end) / 2));
      if (nums[(mid+pivot)%nums.length] < target) begin = mid + 1;
      else end = mid;
    }
    return nums[(begin+pivot)%nums.length]===target?(begin+pivot)%nums.length:-1;
  };
```