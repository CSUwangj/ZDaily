+++
title = "2019-02-12 Daily Challenge"
path = "2019-02-12-daily-challenge"
date = 2019-02-12T19:39:03+00:00
updated = 2020-09-19T20:01:27.631316+00:00
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

### Poker hands

### Problem 54

In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

- **High Card**: Highest value card.
- **One Pair**: Two cards of the same value.
- **Two Pairs**: Two different pairs.
- **Three of a Kind**: Three cards of the same value.
- **Straight**: All cards are consecutive values.
- **Flush**: All cards of the same suit.
- **Full House**: Three of a kind and a pair.
- **Four of a Kind**: Four cards of the same value.
- **Straight Flush**: All cards are consecutive values of same suit.
- **Royal Flush**: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

| **Hand**       | **Player 1**                                          | **Player 2**                                           | **Winner** |
| ------------ | --------------------------------------------------- | --------------------------------------------------- | ---------- |
| **1**          | 5H 5C 6S 7S KD Pair of Fives                          | 2C 3S 8S 8D TD Pair of Eights                    |       Player 2   |
| **2**          | 5D 8C 9S JS AC Highest card Ace                       | 2C 5C 7D 8S QH Highest card Queen                |       Player 1   |
| **3**          | 2D 9C AS AH AC Three Aces                             | 3D 6D 7D TD QD Flush with Diamonds               |       Player 2   |
| **4**          | 4D 6S 9H QH QC Pair of Queens Highest card Nine       | 3D 6D 7H QD QS Pair of Queens Highest card Seven |       Player 1   |
| **5**          | 2H 2D 4C 4D 4S Full House With Three Fours            | 3C 3D 3S 9S 9D Full House with Three Threes      |       Player 1   |

The file, [poker.txt](https://projecteuler.net/project/resources/p054_poker.txt), contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?

## Solution

Big simulation......

There must be more graceful implementation, but I'm so poor at Rust...

## Implementation

```rust
use std::io;

fn main() {
    let reader = io::stdin();
    let mut line = String::new();
    let mut card1: [(i32, i32); 5] = [(0, 0); 5];
    let mut card2: [(i32, i32); 5] = [(0, 0); 5];
    let mut rank1: [i32; 6] = [0; 6];
    let mut rank2: [i32; 6] = [0; 6];
    let mut ans = 0;
    // let mut cnt = 0;
    loop {
        match reader.read_line(&mut line) {
            Ok(l) => {
                if l == 0 {
                    break;
                } else {
                    ();
                }
            }
            Err(_) => break,
        }
        let mut iter = line.split_whitespace();
        for i in 0..5 {
            card1[i] = get_card(&iter.next().unwrap());
        }
        for i in 0..5 {
            card2[i] = get_card(&iter.next().unwrap());
        }
        // print!("{}", line);
        // println!("{:?}", card1);
        // println!("{:?}", card2);
        get_rank(&mut rank1, &card1);
        get_rank(&mut rank2, &card2);
        // println!("{:?}", rank1);
        // println!("{:?}", rank2);
        if compare_rank(&rank1, &rank2) {
            // println!("Test {}: Player 1", cnt);
            ans += 1;
        } else {
            // println!("Test {}: Player 2", cnt);
        }
        // cnt += 1;
        // println!("{}", ans);
        line.clear();
    }
    println!("Answer is {}", ans);
}

fn get_card(s: &str) -> (i32, i32) {
    let mut s = s.chars();
    let number = get_number(s.next().unwrap());
    let suit = get_suit(s.next().unwrap());
    (number, suit)
}

fn get_number(c: char) -> i32 {
    match c {
        '2' => return 2,
        '3' => return 3,
        '4' => return 4,
        '5' => return 5,
        '6' => return 6,
        '7' => return 7,
        '8' => return 8,
        '9' => return 9,
        'T' => return 10,
        'J' => return 11,
        'Q' => return 12,
        'K' => return 13,
        'A' => return 14,
        _ => panic!("Unknown value {:?}", c),
    }
}

fn get_suit(c: char) -> i32 {
    match c {
        'S' => return 0,
        'D' => return 1,
        'C' => return 2,
        'H' => return 3,
        _ => panic!("Unknown value {:?}", c),
    }
}

fn get_rank(rank: &mut [i32; 6], card: &[(i32, i32); 5]) {
    let mut suits: [i32; 4] = [0; 4];
    let mut numbers: [i32; 15] = [0; 15];
    for (number, suit) in card.iter() {
        suits[*suit as usize] += 1;
        numbers[*number as usize] += 1;
    }
    if suits[0] == 5 || suits[1] == 5 || suits[2] == 5 || suits[3] == 5 {
        let mut is_ok = true;
        for i in 10..15 {
            is_ok = numbers[i] == 1;
        }
        if is_ok {
            rank[0] = 10;
            return;
        }
        is_ok = true;
        for i in 2..10 {
            if numbers[i] == 1 {
                for j in 1..5 {
                    is_ok = is_ok && numbers[i + j] == 1;
                }
            }
        }
        let mut cnt = 1;
        for i in (2..10).rev() {
            if numbers[i] == 1 {
                rank[cnt] = i as i32;
                cnt += 1;
            }
        }
        rank[0] = if is_ok { 9 } else { 6 };
        return;
    }
    for i in 2..15 {
        if numbers[i] == 4 {
            rank[0] = 8;
            rank[1] = i as i32;
            return;
        }
    }
    for i in 2..15 {
        if numbers[i] == 3 {
            let mut is_ok = false;
            for j in 2..15 {
                if numbers[j] == 2 {
                    is_ok = true;
                }
            }
            rank[0] = if is_ok { 7 } else { 4 };
            rank[1] = i as i32;
            return;
        }
    }
    for i in 2..15 {
        if numbers[i] == 2 {
            for j in i + 1..15 {
                if numbers[j] == 2 {
                    rank[1] = j as i32;
                    rank[2] = i as i32;
                    rank[0] = 3;
                    for k in 2..15 {
                        if numbers[k] == 1 {
                            rank[3] = k as i32;
                        }
                    }
                    return;
                }
            }
            let mut cnt = 2;
            for j in (2..15).rev() {
                if numbers[j] == 1 {
                    rank[cnt] = j as i32;
                    cnt += 1;
                }
            }
            rank[0] = 2;
            rank[1] = i as i32;
            return;
        }
    }
    let mut is_ok = true;
    for i in 2..10 {
        if numbers[i] == 1 {
            for j in 1..5 {
                is_ok = is_ok && numbers[i + j] == 1;
            }
            if is_ok {
                break;
            }
        }
    }
    rank[0] = if is_ok { 5 } else { 1 };
    let mut cnt = 1;
    for i in (2..15).rev() {
        if numbers[i] == 1 {
            rank[cnt] = i as i32;
            cnt += 1;
        }
    }
}


fn compare_rank(rank1: &[i32; 6], rank2: &[i32; 6]) -> bool {
    if rank1[0] != rank2[0] {
        return rank1[0] > rank2[0];
    }
    match rank1[0] {
        9 | 8 | 7 | 5 | 4 => return rank1[1] > rank2[1],
        _ => (),
    }
    if rank1[0] == 6 || rank1[0] == 1 {
        let mut cnt = 1;
        while cnt < 6 && rank1[cnt] == rank2[cnt] {
            cnt += 1;
        }
        return if cnt == 6 { false } else { rank1[cnt] > rank2[cnt]};
    }
    if rank1[0] == 3 {
        let mut cnt = 1;
        while cnt < 4 && rank1[cnt] == rank2[cnt] {
            cnt += 1;
        }
        return if cnt == 4 { false } else { rank1[cnt] > rank2[cnt]};
    }
    if rank1[0] == 2 {
        let mut cnt = 1;
        while cnt < 5 && rank1[cnt] == rank2[cnt] {
            cnt += 1;
        }
        return if cnt == 5 { false } else { rank1[cnt] > rank2[cnt]};
    }
    false
}
```

# Algorithm

## Problem

### 453. Minimum Moves to Equal Array Elements

Given a **non-empty** integer array of size *n*, find the minimum number of moves required to make all array elements equal, where a move is incrementing *n* - 1 elements by 1.

**Example:**

```
Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```

## Solution

Increment other n-1 element means decrement one element.

## Implementation

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
  let min = number.MAX_SAFE_INTEGER;
  let sum = 0;
  for (const num of nums) {
    min = min<num?min:num;
    sum += num;
  }
  return sum-min*nums.length;
};
```