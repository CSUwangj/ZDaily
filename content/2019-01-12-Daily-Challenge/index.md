+++
title = "2019-01-12 Daily Challenge"
path = "2019-01-12-daily-challenge"
date = 2019-01-12T00:48:32+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Non-abundant sums* in *Rust* and *Word Ladder* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Non-abundant sums

Problem 23 

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
```

## Solution

Nothing to say.

## Implementation

```rust
extern crate primal;

use std::vec::Vec;
use primal::Sieve;

fn main() {
    const SIZE: usize = 28124;
    let mut arr: [bool; SIZE] = [false; SIZE];
    let sieve = Sieve::new(10000);
    let mut abundants :Vec<i32> = Vec::new();
    let mut ans: i64 = 0;
    for i in 1..28123 {
        if sum_of_divisor(i, &sieve) > i {
            abundants.push(i);
        }
    }
    for i in 0..(abundants.len()) {
        for j in i..(abundants.len()){
            if ((abundants[i] + abundants[j]) as usize) < SIZE {
                arr[(abundants[i] + abundants[j]) as usize] = true;
            }
        }
    }
    assert!(arr[24]);
    for i in 0..SIZE {
        if !arr[i] {
            ans += i as i64;
        }
    }
    println!("Answer is {}", ans);
}

fn sum_of_divisor(n: i32, sieve: &Sieve) -> i32 {
    let factors: Vec<(usize, usize)> = match sieve.factor(n as usize) {
        Ok(v) => v,
        Err(_) => Vec::new(),
    };
    let mut ans = 1;
    for factor in factors {
        let mut tmp = 1;
        let mut sum = 1;
        for _ in 0..factor.1 {
            tmp *= factor.0;
            sum += tmp;
        }
        ans *= sum;
    }
    ans as i32 - n
}
```

# Algorithm

## Problem

```
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

## Solution

Of course BFS can handle this, but I want to implement dijkstra in js.

So I really have done a shitty job..... :X

## Implementation

```js
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
  let map = new Map();
  if(wordList.indexOf(beginWord)==-1) wordList.unshift(beginWord);
  let G = new Array(wordList.length);
  for(let i=0; i<wordList.length; ++i){
    map.set(wordList[i], i);
    G[i] = new Array(wordList.length).fill(1e10);
  }
  // console.log(map);
  let OK = (str1, str2) => {
    let cnt = 0;
    for(let i=0; i<str1.length; ++i){
      if(str1.charAt(i) !== str2.charAt(i)) ++cnt;
    }
    return cnt===1;
  };

  let dijkstra = (src, dst) => {
    let d = new Array(wordList.length).fill(1e10);
    d[src] = 0;
    let set = new Set();
    for(let i=0; i<wordList.length; ++i){
      set.add(i);
    }
    while(set.size){
      let mx = 1e11;
      let index;
      for(const v of set){
        if(d[v] < mx){
          mx = d[v];
          index = v;
        }
      }
      set.delete(index);
      for(let i=0; i<wordList.length; ++i){
        if(G[i][index] + d[index]<d[i]){
          d[i] = G[i][index] + d[index];
        }
      }
    }
    return d[dst];
  };
  if(!map.has(beginWord)||!map.has(endWord)) return 0;
  for(let i=0; i<wordList.length; ++i){
    for(let j=i+1; j<wordList.length; ++j){
      if(OK(wordList[i],wordList[j])){
        G[i][j] = G[j][i] = 1;
      }
    }
  }
  // console.log(G);
  // console.log(map.get(beginWord),map.get(endWord));
  let ans = dijkstra(map.get(beginWord), map.get(endWord));
  // console.log(G);
  return ans < 1e9?ans+1:0;
};

// console.log(ladderLength("hit","cog",  ["hot","dot","dog","lot","log","cog"]));
```