+++
title = "2019-02-05 Daily Challenge"
path = "2019-02-05-daily-challenge"
date = 2019-02-05T00:03:23+00:00
updated = 2020-09-19T20:01:27.628325+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
Happy new year!~

What I've done today is *Distinct primes factors* in *Rust* and *Longest Univalue Path* in *JavaScript*.

<!--more-->

# Math

## Problem

### Distinct primes factors

### Problem 47

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

## Solution

Nothing to say.

## Implementation

```rust
extern crate primal;

use primal::Sieve;

fn main() {
    let sieve: Sieve = Sieve::new(10000);
    let mut found = false;
    let mut cur: usize = 2;
    let mut ans: usize = 0;
    while !found {
        while sieve.factor(cur).unwrap().len() != 4 {
            cur += 1;
        }
        let mut tmp = true;
        for _i in 0..3 {
            cur += 1;
            if sieve.factor(cur).unwrap().len() != 4 {
                tmp = false;
                break;
            }
        }
        if tmp == true {
            ans = cur - 3;
            found = true;
        }
        cur += 1;
    } 
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 687. Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

**Note:** The length of path between two nodes is represented by the number of edges between them.

**Example 1:**

Input:

```
              5
             / \
            4   5
           / \   \
          1   1   5
```



Output:

```
2
```



**Example 2:**

Input:

```
              1
             / \
            4   5
           / \   \
          4   4   5
```



Output:

```
2
```



**Note:** The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

## Solution

It's easy to come up with recursive this idea.

And with more deep thinking you might find that, if we want to construct a longer path with subnode's subtree, we can just pick one subtree, and we need to maintain answer at processing.

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
 * @param {TreeNode} root
 * @return {number}
 */
var longestUnivaluePath = function(root) {
  let ans = 0;
  const findPath = (root) => {
    if (root === null) return 0;
    let left = findPath(root.left);
    let right = findPath(root.right);
    let arrowLeft = 0;
    let arrowRight = 0;
    if (root.left !== null && root.left.val === root.val) {
      arrowLeft = left + 1;
    }
    if (root.right !== null && root.right.val === root.val) {
      arrowRight = right + 1;
    }
    ans = Math.max(ans, arrowLeft + arrowRight);
    return Math.max(arrowRight, arrowLeft);
  };
  findPath(root);
  return ans;
};
```