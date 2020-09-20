+++
title = "2019-01-13 Daily Challenge"
path = "2019-01-13-daily-challenge"
date = 2019-01-13T00:02:16+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Lexicographic permutations* in *Rust* and *Unique Binary Search Trees II* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Lexicographic permutations

Problem 24 

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
```

## Solution

I've done it with javascript in [2019-01-03 Daily Challenge](https://csuwangj.github.io/2019-01-03-Daily-Challenge/), so what I need to do is just translate it into Rust.

## Implementation

```rust
use std::vec::Vec;

fn main() {
    for i in nth_permutation(3, 3) {
        println!("{}", i);
    }
    println!("");
    for i in nth_permutation(4, 9) {
        print!("{}", i);
    }
    println!("");
    for i in nth_permutation(10, 1_000_000) {
        print!("{}", i);
    }
}

fn nth_permutation(n: i32, mut k: i64) -> Vec<i32> {
    k -= 1;
    let mut fac: Vec<i64> = [1].to_vec();
    let mut ans: Vec<i32> = Vec::new();
    let mut used: Vec<bool> = [false].to_vec();
    for i in 1i64..(n as i64) {
        let tmp = fac[i as usize - 1]*i;
        fac.push(tmp);
        used.push(false);
    }
    let mut cur = n-1;
    while cur >= 0 {
        let mut index = k/fac[cur as usize];
        k %= fac[cur as usize];
        for i in 0..used.len() {
            if !used[i] {
                if index > 0 {
                    index -= 1;
                }else{
                    ans.push(i as i32);
                    used[i] = true;
                    break;
                }
            }
        }
        cur -= 1;
    }
    return ans;
}
```

# Algorithm

## Problem

```
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

## Solution

Because it is BST, so when we determine one root, we will known what's on its left and what's on right. So we could do it recursively.

Because recursive process will go through many repeated tree nodes(like recursive fibonacci function), so we could memorize it.

## Implementation

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
  if(n===0) return [];
  const map = new Map();
  return generateTreess(1,n+1,map);
};

/**
 * Interval is left-closed right-opened
 * @param {number} l
 * @param {number} r
 * @param {Map} map
 * @return {TreeNode[]}
 */
function generateTreess(l,r,map){
  if(l===r) return [null];
  if(map.has(l)&&map.get(l).has(r)){
    return map.get(l).get(r);
  }
  let trees = [];
  for(let i = l; i < r; ++i){
    const left = generateTreess(l,i,map);
    const right = generateTreess(i+1,r,map);
    for(let j = 0; j < left.length; ++j){
      for(let k = 0; k < right.length; ++k){
        const node = new TreeNode(i);
        node.left = left[i];
        node.right = right[k];
        trees.push(node);
      }
    }
  }
  if(!map.has(l)){
    map.set(l,new Map());
  }
  map.get(l).set(r,trees);
  return trees;
}
```