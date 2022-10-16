+++
title = "2019-02-06 Daily Challenge"
path = "2019-02-06-daily-challenge"
date = 2019-02-06T00:00:48+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Self powers* in *Rust* and *Average of Levels in Binary Tree* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Self powers

### Problem 48

The series, $1^1 + 2^2 + 3^3 + ... + 10^{10} = 10405071317$.

Find the last ten digits of the series, $1^1 + 2^2 + 3^3 + ... + 1000^{1000}$.

## Solution

Modular arithmetic has compatibility with addition\multiplication.

Be careful, result of middle processing will exceed 2^64.

## Implementation

```rust
fn main() {
    let mut ans: u128 = 0;
    const MOD: u128 = 10_000_000_000;
    for i in 1..1001 {
        ans += quick_pow(i, i, MOD);
        ans %= MOD;
    }
    println!("Answer is {}", ans);
}

fn quick_pow(mut b: u128, mut e: u128, m: u128) -> u128 {
    let mut ans = 1;
    while e != 0 {
        if e&1 == 1 {
            ans *= b;
            ans %= m;
        }
        e >>= 1;
        b *= b;
        b %= m;
    }
    return ans;
}
```

# Algorithm

## Problem

### 637. Average of Levels in Binary Tree

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

**Example 1:**

```
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
```



**Note:**

1. The range of node's value is in the range of 32-bit signed integer.

## Solution

Simple BFS/DFS.

I've write a non-FP implementation and an implementation with a little FP :D

## Implementation

non-FP

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function(root) {
  let queue = [];
  let ans = [];
  let cnt = [];
  queue.push([0, root]);
  while (queue.length) {
    let cur = queue.shift();
    if (cur[1] === null) continue;
    if (ans.length <= cur[0]) ans.push(cur[1].val);
    else ans[cur[0]] += cur[1].val;
    if (cnt.length <= cur[0]) cnt.push(1);
    else cnt[cur[0]] += 1;
    queue.push([cur[0]+1, cur[1].left]);
    queue.push([cur[0]+1, cur[1].right]);
  }
  for (const [index, value] of ans.entries()) {
    ans[index] = value/cnt[index];
  }
  return ans;
};
```

A little FP

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function(root) {
  let queue = [];
  let ans = [];
  queue.push([0, root]);
  while (queue.length) {
    let cur = queue.shift();
    if (cur[1] === null) continue;
    if (ans.length < cur[0]) {
      ans.push({cnt : 1, sum : cur[1].val});
    } else {
      ans[cur[0]].cnt += 1;
      ans[cur[0]].sum += cur[1].val;
    }
    queue.push([cur[0]+1, cur[1].left]);
    queue.push([cur[0]+1, cur[1].right]);
  }
  return ans.map(val => val.sum/val.cnt);
};
```