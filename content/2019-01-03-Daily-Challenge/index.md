+++
title = "2019-01-03 Daily Challenge"
path = "2019-01-03-daily-challenge"
date = 2019-01-03T00:04:05+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Longest Collatz sequence* in *Rust* and *Permutation Sequence* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Longest Collatz sequence

Problem 14 

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
```

## Solution

Brute force, and you'll find that every number less than half a million can be get with its double, and therefore in a definitely longer chain.

## Implementation

```rust
fn main() {
    let mut ans = 0;
    let mut cnt = 0;
    for i in 500_000u64..1_000_000u64 {
        let mut tmp = i;
        let mut tcnt = 0;
        while tmp != 1 {
            if tmp%2 == 0 {
                tmp /=2;
            } else {
                tmp = tmp * 3 + 1;
            }
            tcnt += 1;
        }
        if tcnt > cnt {
            ans = i;
            cnt = tcnt;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

```
60. Permutation Sequence

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
```

## Solution

I'm too tired doing my project to explain it...

Sry for delay.

## Implementation

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
  k -= 1;
  let fac = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 369880];
  let used = new Array(n);
  let nums = new Array();
  let ans = "";
  for(let i = 1; i <= n ; ++i){
    nums.push(i);
  }
  let cur = n - 1;
  while(cur >= 0) {
    let index = Math.floor(k/fac[cur]);
    k %= fac[cur];
    for(const [i, v] of nums.entries()){
      if(used[i] === undefined){
        if(index) --index;
        else {ans += v; used[i] = 1; break;}
      }
    }
    --cur;
  }
  return ans;
};

// console.log(getPermutation(3,3));
// console.log(getPermutation(4,9));

```