+++
title = "2019-01-27 Daily Challenge"
path = "2019-01-27-daily-challenge"
date = 2019-01-27T00:11:33+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Pandigital multiples* in *Rust* and *K-th Symbol in Grammar* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Pandigital multiples

### Problem 38

Take the number 192 and multiply it by each of 1, 2, and 3:

> 192 × 1 = 192
> 192 × 2 = 384
> 192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

## Solution

Nothing to say.

## Implementation

```rust
fn main() {
    let mut ans = 918273645;
    for i in 1..10000 {
        let mut tmp: String = String::new();
        let mut j = 1;
        while tmp.len() < 9 {
            tmp = format!("{}{}", tmp, i*j);
            j += 1;
        }
        if tmp.len() != 9 {
            continue;
        }
        let tmp_n = tmp.parse::<i32>().unwrap();
        if tmp_n > ans && is_pandigital(&tmp) {
            ans = tmp_n;
            println!("{}, {}", i, tmp);
        }
    }
    println!("Answer is {}", ans);
}

fn is_pandigital(s: &String) -> bool {
    static NUMS: [char; 9] = ['1', '2', '3', '4', '5', '6', '7', '8', '9'];
    for c in &NUMS {
        let mut cnt = 0;
        for i in s.chars() {
            if i == *c {
                cnt += 1;
            }
        }
        if cnt != 1 {
            return false;
        }
    }
    return true;
}

```

# Algorithm

## Problem

### 779. K-th Symbol in Grammar

On the first row, we write a `0`. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

Given row `N` and index `K`, return the `K`-th indexed symbol in row `N`. (The values of `K` are 1-indexed.) (1 indexed).

```
Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
```

**Note:**

1. `N` will be an integer in the range `[1, 30]`.
2. `K` will be an integer in the range `[1, 2^(N-1)]`.

## Solution

It's easy to find that string is self-expanded. What's added after N+1 is replace what N have more than N-1.

For example, row 3 = 0110, add "10" to end of row 2, and "10" is what "1" replaced by.

When we want what's on index $K​$, we just need to know $\lfloor \frac{K}{2}\rfloor​$.

And what's more? We would find that because "0" -> "01", "1" -> "10", 1^1 = 0, 0 ^ 1 = 1.

So you would find that what's important is how many 1s in K's binary expression!

## Implementation

```js
/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var kthGrammar = function(N, K) {
  return bitCount(K-1) & 1;
};

function bitCount (n) {
  n = n - ((n >> 1) & 0x55555555);
  n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
  return ((n + (n >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}

// console.log(kthGrammar(1, 1));
// console.log(kthGrammar(2, 1));
// console.log(kthGrammar(2, 2));
// console.log(kthGrammar(4, 5));
```