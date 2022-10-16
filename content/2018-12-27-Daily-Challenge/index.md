+++
title = "2018-12-27 Daily Challenge"
path = "2018-12-27-daily-challenge"
date = 2018-12-27T09:14:07+00:00
updated = 2020-09-19T20:01:27.625333+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *10001st prime* in *Rust* and *Binary Tree Preorder Traversal* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
10001st prime

Problem 7 

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
```

## Solution

It's easy to think about use sieve of Eratosthenes to compute prime, whose time complexity is $O(nloglogn)$, or Euler sieve, whose time complexity is $O(n)$.

I'll do it with extern crate. ;)

## Implementation

```rust
extern crate primal;

fn main() {
    let p = primal::Primes::all().nth(10001 - 1).unwrap();
    println!("The 10001st prime is {}", p);
}
```

# Algorithm

## Problem

```
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
```

## Solution

;p

## Implementation

```javascript
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
var preorderTraversal = (root) => {
  if(root == null) return [];
  let ans = [root.val]
  ans = ans.concat(preorderTraversal(root.left));
  ans = ans.concat(preorderTraversal(root.right));
  return ans;
};

var preorderTraversal = (root) => {
  if(root == null) return [];
  let ans = [root.val];
  let s = [];
  s.push(root.right);
  s.push(root.left);
  while(s.length){
    let tmp = s.pop();
    if(tmp === null) continue;
    ans.push(tmp.val);
    s.push(tmp.right);
    s.push(tmp.left);
  }
  return ans;
};
```

![wwwww](1545880199212.png)