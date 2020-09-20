+++
title = "2019-02-01 Daily Challenge"
path = "2019-02-01-daily-challenge"
date = 2019-02-01T14:59:13+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Sub-string divisibility* in *Rust* and *Numbers With Same Consecutive Differences* in *JavaScript*.

I also spent a few hours at Vidar Team's HGAME2019, and go through Crypto and Web Challenge.

Misc is boring, RE is boring too, PWN is interesting, but DotA2 is more interesting ;D

<!-- more -->

# Math

## Problem

### Sub-string divisibility

### Problem 43

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let *d*1 be the 1st digit, *d*2 be the 2nd digit, and so on. In this way, we note the following:

- *d*2*d*3*d*4=406 is divisible by 2
- *d*3*d*4*d*5=063 is divisible by 3
- *d*4*d*5*d*6=635 is divisible by 5
- *d*5*d*6*d*7=357 is divisible by 7
- *d*6*d*7*d*8=572 is divisible by 11
- *d*7*d*8*d*9=728 is divisible by 13
- *d*8*d*9*d*10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

## Solution

Nothing to say.

## Implementation

```rust
use permutohedron::heap_recursive;

fn main() {
    let mut data: [i64; 10] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    let primes: [i64; 7] = [2, 3, 5, 7, 11, 13, 17];
    let mut ans: i64 = 0;
    let mut permutations = Vec::new();
    heap_recursive(&mut data, |permutation| {
        permutations.push(permutation.to_vec())
    });
    for permutation in permutations {
        let mut is_ok = true;
        for i in 1..8 {
            if num(permutation[i], permutation[i+1], permutation[i+2]) % primes[i-1] != 0{
                is_ok = false;
            }
        }
        if is_ok {
            ans += numm(&permutation);
        }
    }
    println!("Answer is {}", ans);
}

fn num(i: i64, j: i64, k: i64) -> i64 {
    return 100*i+10*j+k;
}

fn numm(vec: &Vec<i64>) -> i64 {
    let mut ans = 0;
    for i in vec {
        ans *= 10;
        ans += i;
    }
    return ans;
}
```

# Algorithm

## Problem

### 967. Numbers With Same Consecutive Differences

Return all **non-negative** integers of length `N` such that the absolute difference between every two consecutive digits is `K`.

Note that **every** number in the answer **must not** have leading zeros **except** for the number `0` itself. For example, `01` has one leading zero and is invalid, but `0` is valid.

You may return the answer in any order.

**Example 1:**

```
Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
```

**Example 2:**

```
Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
```

**Note:**

1. `1 <= N <= 9`
2. `0 <= K <= 9`

## Solution

Simple BFS.

I write two implementation and they don't come up with enough difference on performance.

## Implementation

```js
/**
 * @param {number} N
 * @param {number} K
 * @return {number[]}
 */
var numsSameConsecDiff = function(N, K) {
  let ans = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  if (N === 1) {
    ans.push(0);
    return ans;
  }
  let cnt = 1;
  while (cnt < N) {
    cnt += 1;
    let sz = ans.length;
    while (sz) {
     sz -= 1;
     let cur = ans.shift();
     if (cur%10 - K >= 0) ans.push(cur*10 + cur%10 - K);
     if (K !== 0 && cur%10 + K <= 9) ans.push(cur*10 + cur%10 + K);
    }
  }
  return ans;
};

// console.log(numsSameConsecDiff(2,1));
// console.log(numsSameConsecDiff(3,7));
```



```js
/**
 * @param {number} N
 * @param {number} K
 * @return {number[]}
 */
var numsSameConsecDiff = function(N, K) {
  let ans = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  if (N === 1) {
    ans.push(0);
    return ans;
  }
  let cnt = 1;
  while (cnt < N) {
    cnt += 1;
    let sz = ans.length;
    while (sz) {
     sz -= 1;
     let cur = ans.shift();
     if (cur%10 - K >= 0) ans.push(cur*10 + cur%10 - K);
     if (K !== 0 && cur%10 + K <= 9) ans.push(cur*10 + cur%10 + K);
    }
  }
  return ans;
};

console.log(numsSameConsecDiff(2,1));
console.log(numsSameConsecDiff(3,7));

/**
 * @param {number} N
 * @param {number} K
 * @return {number[]}
 */
var numsSameConsecDiff = function(N, K) {
  let ans = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  if (N === 1) {
    ans.push(0);
    return ans;
  }
  if (K === 0) {
    for (let i = 0; i < 9; ++i) {
      let cur = "" + ans.shift();
      ans.push(+(cur.repeat(N)));
    }
    return ans;
  }
  let cnt = 1;
  while (cnt < N) {
    cnt += 1;
    let sz = ans.length;
    while (sz) {
      sz -= 1;
      let cur = ans.shift();
      if (cur%10 - K >= 0) ans.push(cur*10 + cur%10 - K);
      if (cur%10 + K <= 9) ans.push(cur*10 + cur%10 + K);
    }
  }
  return ans;
};
```