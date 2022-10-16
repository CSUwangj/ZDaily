+++
title = "2019-02-14 Daily Challenge"
path = "2019-02-14-daily-challenge"
date = 2019-02-14T00:12:13+00:00
updated = 2020-09-19T20:01:27.629322+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Powerful digit sum* in *Rust* and *Restore IP Addresses* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Powerful digit sum

### Problem 56

A googol ($10^{100}$) is a massive number: one followed by one-hundred zeros; 
$100^{100}$ is almost unimaginably large: one followed by two-hundred zeros. 
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, $a^b$, where *a, b* < 100, what is the maximum digital sum?

## Solution

Nothing to say.

## Implementation

```rust
extern crate num_bigint;
extern crate num_traits;

use num_bigint::{BigUint};
use num_traits::{FromPrimitive};

fn main() {
    let mut ans = 0;
    for i in 1..101 {
        let base: BigUint = FromPrimitive::from_usize(i).unwrap();
        let mut tmp: BigUint = FromPrimitive::from_usize(i).unwrap();
        for _j in 0..100 {
            let sum = tmp.to_str_radix(10).chars()
                .fold(0, |a, b| a+b as usize - '0' as usize);
            ans = if ans < sum { sum } else { ans };
            tmp = tmp * &base;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

**Example:**

```
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```

## Solution

Simple DFS.

## Implementation

```js
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
  let ans = [];
  let arr = [];
  const isValid = (s) => {
    return (+s < 256) && (+s+"" === s);
  };
  const dfs = (index, cursor) => {
    // console.log(index, cursor, arr);
    if (index === 4 || cursor >= s.length) {
      if (cursor === s.length && index === 4) ans.push(arr.join("."));
      return;
    }
    for (let i = 1; i < 4; ++i) {
      if (cursor+i <= s.length && isValid(s.substr(cursor, i))) {
        arr[index] = s.substr(cursor, i);
        dfs(index+1, cursor+i);
      }
    }
  };
  dfs(0, 0);
  return ans;
};
```