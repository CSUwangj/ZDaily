+++
title = "2019-02-10 Daily Challenge"
path = "2019-02-10-daily-challenge"
date = 2019-02-10T00:03:53+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Permuted multiples* in *Rust* and *Find Minimum in Rotated Sorted Array II* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Permuted multiples

### Problem 52

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, *x*, such that 2*x*, 3*x*, 4*x*, 5*x*, and 6*x*, contain the same digits.

## Solution

I've tried to find some graceful solution which need no stack-based array to determine if two numbers are permutation of each other, and get nothing.

So just brute force.

## Implementation

```rust
fn main() {
    let mut down_bound = 100;
    let mut up_bound = 1000/6 + 1;
    let mut found: bool = false;
    let mut ans = 0;
    while !found {
        for i in down_bound..up_bound {
            let mut is_ok = true;
            for j in 2..7 {
                if !is_permutation(i, i*j) {
                    is_ok = false;
                    break;
                }
            }
            if is_ok {
                ans = i;
                found = true;
            }
        }
        down_bound *= 10;
        up_bound = down_bound*10/6 + 1;
    }
    println!("Answer is {}", ans);
}

fn is_permutation(mut u: usize, mut v: usize) -> bool {
    let mut a1: [usize; 10] = [0; 10];
    let mut a2: [usize; 10] = [0; 10];
    while u > 0 {
        a1[u%10] += 1;
        a2[v%10] += 1;
        u /= 10;
        v /= 10;
    }
    for i in 0..10 {
        if a1[i] != a2[i] {
            return false;
        }
    }
    true
}
```

# Algorithm

## Problem

### 154. Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

The array may contain duplicates.

**Example 1:**

```
Input: [1,3,5]
Output: 1
```

**Example 2:**

```
Input: [2,2,2,0,1]
Output: 0
```

**Note:**

- This is a follow up problem to [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/).
- Would allow duplicates affect the run-time complexity? How and why?

## Solution

I guess worst case of time complexity of algorithms will be $O(N)$, because we can't use binary partition to deal with duplicates.

## Implementation

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
  if (nums[0] < nums[nums.length-1]) return nums[0];
  for (const val of nums) {
    if (val < nums[0]) return val;
  }
  return nums[0];
};
```