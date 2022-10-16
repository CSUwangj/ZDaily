+++
title = "2019-01-15 Daily Challenge"
path = "2019-01-15-daily-challenge"
date = 2019-01-15T00:52:50+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Reciprocal cycles* in *Rust* and *Open the Lock* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Reciprocal cycles

Problem 26 

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
```

## Solution

I use a very simple way to simulate it, check the code for more detail.

## Implementation

```rust
use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();
    let mut ans = 0;
    let mut ansi = 7;
    for i in 1..1000 {
        map.clear();
        let mut res = 1;
        let mut cnt = 0;
        loop {
            // println!("{}, {}, {}",res, i, res % i);
            res = res % i;
            if res == 0 {
                // println!("WTF");
                break;
            }
            if map.contains_key(&res) {
                let tmp: i32 = cnt - *map.get(&res).unwrap();
                // println!("{}, {}, {}",res,i,tmp);
                if tmp > ans {
                    ans = tmp;
                    ansi = i;
                }
                break;
            }
            map.insert(res, cnt);
            res *= 10;
            cnt += 1;
        }
    }
    println!("Answer is {}, recurring cycle is {}-digit.", ansi, ans);
}

```

# Algorithm

```
752. Open the Lock

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.
```

## Solution

BFS is capable for it, but better way is two-end bfs.

By the way, this code is just like shit, I'm going rewrite it later!

---

Done!

## Implementation

```js
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target){
  if(deadends.includes(target) || deadends.includes("0000")) return -1;
  let set = new Set();
  let srcMap = new Map();
  for (const s of deadends){
    set.add(s);
  }
  let srcQueue = [];
  let tmp;
  srcQueue.push(["0000",0]);
  srcMap.set("0000",0);
  while(srcQueue.length){
    // console.log(srcQueue,dstQueue);
    let cur = srcQueue.shift();
    if(cur[0]==target) return cur[1];
    tmp = (+cur[0][0] + 1)%10 + cur[0].slice(1);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0][0] + (+cur[0][1] + 1)%10 +cur[0].slice(2);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0].slice(0, 2) + (+cur[0][2] + 1)%10 + cur[0][3];
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0].slice(0, 3) + (+cur[0][3] + 1)%10;
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = (+cur[0][0] -1 + 10)%10 + cur[0].slice(1);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0][0] + (+cur[0][1] -1 + 10)%10 +cur[0].slice(2);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0].slice(0, 2) + (+cur[0][2] -1 + 10)%10 + cur[0][3];
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0].slice(0, 3) + (+cur[0][3] -1 + 10)%10;
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
  }
  return -1;
};

```

Rewrite it!

---

```js
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target){
  if(deadends.includes(target) || deadends.includes("0000")) return -1;
  let set = new Set();
  let srcMap = new Map();
  for (const s of deadends){
    set.add(s);
  }
  let srcQueue = [];
  srcQueue.push(["0000",0]);
  srcMap.set("0000",0);
  let check = (cur, i) => {
    // console.log(set);
    let tmp = cur[0].slice(0,i) + (+cur[0][i] + 1)%10 + cur[0].slice(i+1);
    // console.log(tmp);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
    tmp = cur[0].slice(0,i) + (+cur[0][i] -1 + 10)%10 + cur[0].slice(i+1);
    // console.log(tmp);
    if(!set.has(tmp) && !srcMap.has(tmp)){
      srcMap.set(tmp, cur[1] + 1);
      srcQueue.push([tmp, cur[1] + 1]);
    }
  };
  while(srcQueue.length){
    // console.log(srcQueue);
    let cur = srcQueue.shift();
    if(cur[0] === target) return cur[1];
    for(let i = 0; i < 4; ++i){
      check(cur, i);
    }
  }
  return -1;
};

// console.log(openLock(["0201","0101","0102","1212","2002"],"0202"));
// console.log(openLock(["8888"],"0009"));
// console.log(openLock(["8887","8889","8878","8898","8788","8988","7888","9888"],"8888"));
```