+++
title = "2019-02-13 Daily Challenge"
path = "2019-02-13-daily-challenge"
date = 2019-02-13T00:11:30+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Poker hands* in *Rust* and *Minimum Moves to Equal Array Elements* in *JavaScript*.

<!--more-->

# Math

## Problem

### Lychrel numbers

### Problem 55

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.

## Solution

Nothing to say.

## Implementation

```rust
fn main() {
    let mut ans = 0;
    for i in 10..10_000 {
        let mut tmp = i128::from(i);
        tmp += reverse(tmp);
        let mut cnt = 1;
        while cnt < 50 && !is_palindrome(tmp) {
            cnt += 1;
            // println!("{}, {}, {}", i, tmp, reverse(tmp));
            tmp += reverse(tmp);
        }
        if cnt == 50 {
            println!("{}", i);
            ans += 1;
        }
    }
    println!("Answer is {}", ans);
}

fn is_palindrome(n: i128) -> bool {
    let s = n.to_string();
    // println!("{}",s);
    let s = s.as_bytes();
    for i in 0..(s.len()/2) {
        if s[i] != s[s.len()-1-i] {
            return false;
        }
    }
    true
}

fn reverse(mut n: i128) -> i128 {
    let mut ans = 0;
    while n!= 0 {
        ans *= 10;
        ans += n%10;
        n /= 10;
    }
    ans
}
```

# Algorithm

## Problem

### 81. Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
- Would this affect the run-time complexity? How and why?

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
  for (let i = 0; i < nums.length; ++i) {
    if (nums[i] === target) return true;
  }
  return false;
};
```