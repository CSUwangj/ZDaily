+++
title = "2018-12-29 Daily Challenge"
path = "2018-12-29-daily-challenge"
date = 2018-12-29T09:27:37+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Special Pythagorean triplet* in *Rust* and *Dota2 Senate* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Special Pythagorean triplet

Problem 9 

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
```

## Solution

Brute force is still enough.

And I implicated the solution in the overview, but I need some time to digest it.

## Implementation

```rust
fn main() {
    let mut a: (i32, i32, i32);
    a = pythagorean_triplet_brute(1000);
    println!("a = {}\nb = {}\nc = {}\nAnswer is {}",a.0,a.1,a.2,a.0*a.1*a.2);
    a = pythagorean_triplet(1000);
    println!("a = {}\nb = {}\nc = {}\nAnswer is {}",a.0,a.1,a.2,a.0*a.1*a.2);
}

fn pythagorean_triplet_brute(n: i32) -> (i32, i32, i32) {
    let mut a = 0;
    let mut b = 0;
    let mut c = 0;
    for i in 1..(n/3)+1 {
        for j in 1..(n-i)/2 {
            let k = n - i - j;
            if !(i<j&&j<k) {
                continue;
            }
            if i*i + j*j == k*k {
                c = k;
                b = j;
                a = i;
            }
        }
    }
    (a, b, c)
}

// Only return first Pythagorean triplet
fn pythagorean_triplet(s: i32) -> (i32, i32, i32) {
    let s2: i32 = s /2;
    let mut sm: i32;
    let mut k: i32;
    let mut tmp: f64 = (s2 as f64) / 2f64;
    let d: i32;
    let n: i32;
    tmp = tmp.sqrt().ceil();
    let mlimit: i32 = tmp as i32;
    for m in 2..mlimit {
        if s2 % m == 0 {
            sm = s2 / m;
            while sm % 2 == 0 {
                sm /= 2;
            }
            if m % 2 == 1 {
                k = m + 2;
            }else {
                k = m + 1;
            }
            while k < 2*m && k <= sm {
                if sm % k == 0 && gcd(k, m) == 1 {
                    d = s2 / (k*m);
                    n = k-m;
                    return (d*(m*m-n*n),2*d*m*n,d*(m*m+n*n));
                }
                k += 2;
            }
        }
    }
    (0, 0, 0)
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    let mut tmp: i32;
    while b!= 0 {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    a
}
```

# Algorithm

## Problem

```
649. Dota2 Senate

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: 
A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: 
If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision about the change in the game.
Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

Example 1:
Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights any more since his right has been banned. 
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:
Input: "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in the round 1. 
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
Note:
The length of the given string will in the range [1, 10,000].
```

## Solution

I came up a Greedy method which said that when it comes to an unbanned senator, its best choice is ban the opponent which near him most but behind it. If no opponent is behind it, then the best choice is ban the front unbanned opponent.

## Implementation

```javascript
/**
 * @param {string} senate
 * @return {string}
 */
var predictPartyVictory = (senate) => {
  let q = [];
  let banQ = 0;
  let banR = 0;
  for(const s of senate){
    q.push(s);
  }
  let last_round_len;
  do {
    last_round_len = q.length;
    for(let i = 0; i < last_round_len; ++i){
      const tmp = q.shift();
      if(tmp === "R"){
        if(banR) --banR;
        else{
          ++banQ;
          q.push(tmp);
        }
      }else{
        if(banQ) --banQ;
        else{
          ++banR;
          q.push(tmp);
        }
      }
    }
  }while(q.length != last_round_len);
  return (q[0]==="R")?"Radiant":"Dire";
};
```