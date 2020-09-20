+++
title = "2019-02-08 Daily Challenge"
path = "2019-02-08-daily-challenge"
date = 2019-02-08T00:05:41+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Self powers* in *Rust* and *Summary Ranges* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Consecutive prime sum

### Problem 50

The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

## Solution

Brute force.

## Implementation

```rust
extern crate primal;

use primal::Sieve;

fn main() {
    const LIMIT: usize = 1_000_000;
    let sieve: Sieve = Sieve::new(LIMIT);
    let bound = sieve.prime_pi(LIMIT);
    let mut ans = 0;
    let mut cnt = 0;
    for i in 1..bound {
        let mut sum = 0;
        let mut offset = 0;
        if i + cnt > bound {
            break
        }
        while sum < LIMIT {
            if offset > cnt && sieve.is_prime(sum) {
                ans = sum;
                cnt = offset;
            }
            sum += sieve.nth_prime(i + offset);
            offset += 1;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

**Example 1:**

```
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
```

**Example 2:**

```
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
```

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
  if (nums.length === 0) return [];
  let ans = [];
  let begin = nums[0];
  let cur = nums[0];
  for (let i = 1; i < nums.length; ++i) {
    if (nums[i] - cur === 1) cur += 1;
    else {
      if (cur === begin) ans.push(cur+"");
      else ans.push(begin+"->"+cur);
      begin = cur = nums[i];
    }
  }
  if (cur === begin) ans.push(cur+"");
  else ans.push(begin+"->"+cur);
  return ans;
};
```