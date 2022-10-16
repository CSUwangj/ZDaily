+++
title = "2019-02-20 Daily Challenge"
path = "2019-02-20-daily-challenge"
date = 2019-02-20T00:02:07+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Cubic permutations* in *Rust* and *Lemonade Change* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Cubic permutations

### Problem 62

The cube, 41063625 ($345^3$), can be permuted to produce two other 
cubes: 56623104 ($384^3$) and 66430125 ($405^3$). In fact, 41063625 
is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

## Solution

I used a simple function to mapping number to another number to determine if they are of same digits.

## Implementation

```rust
use std::collections::HashMap;

fn main() {
    let mut map: HashMap<u64, usize> = HashMap::new();
    let mut first_num: HashMap<u64, u64> = HashMap::new();
    let mut found = false;
    let mut ans = 0;
    let mut cur = 1;
    while !found {
        let cube = cur * cur * cur;
        let tmp = special_f(cube);
        let it = map.entry(tmp).or_insert(0);
        *it += 1;
        match map.get(&tmp) {
            Some(n) => {
                if *n == 1 {
                    first_num.insert(tmp, cube);
                }
                if *n == 5 {
                    found = true;
                    ans = *first_num.get(&tmp).unwrap();
                }
            }
            None => (),
        }
        cur += 1;
    }
    println!("Answer is {}", ans);
}

fn special_f(mut n: u64) -> u64 {
    let mut arr: [u64; 10] = [0; 10];
    while n > 0 {
        let tmp = (n % 10) as usize;
        arr[tmp] += 1;
        n /= 10;
    }
    let mut tmp = 0;
    for i in 1..10 {
        while arr[i] > 0 {
            tmp *= 10;
            tmp += i;
            arr[i] -= 1;
        }
    }
    while arr[0] > 0 {
        tmp *= 10;
        arr[0] -= 1;
    }
    tmp as u64
}
```

# Algorithm

## Problem

### 860. Lemonade Change

At a lemonade stand, each lemonade costs `$5`. 

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by `bills`).

Each customer will only buy one lemonade and pay with either a `$5`, `$10`, or `$20` bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return `true` if and only if you can provide every customer with correct change.

 

**Example 1:**

```
Input: [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
```

**Example 2:**

```
Input: [5,5,10]
Output: true
```

**Example 3:**

```
Input: [10,10]
Output: false
```

**Example 4:**

```
Input: [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can't give change of $15 back because we only have two $10 bills.
Since not every customer received correct change, the answer is false.
```

 

**Note:**

- `0 <= bills.length <= 10000`
- `bills[i]` will be either `5`, `10`, or `20`.

## Solution

Nothing to say.

## Implementation

```js
/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
  let five = 0;
  let ten = 0;
  for (const bill of bills) {
    if (bill === 5) {
      five += 1;
    } else if (bill === 10) {
      if (five === 0) return false;
      five -= 1;
      ten += 1;
    } else {
      if (ten === 0) {
        if (five < 3) return false;
        five -= 3;
      } else {
        if (five === 0) return false;
        five -= 1;
        ten -= 1;
      }
    }
  }
  return true;
};
```