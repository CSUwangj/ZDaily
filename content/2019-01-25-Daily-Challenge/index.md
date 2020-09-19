+++
title = "2019-01-25 Daily Challenge"
path = "2019-01-25-daily-challenge"
date = 2019-01-25T00:02:42+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Double-base palindromes* in *Rust* and *Find Mode in Binary Search Tree* in *JavaScript*.

<!--more-->

# Math

## Problem

### Double-base palindromes

### Problem 36

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

## Solution

In fact I've done something similar before, at [2018-12-25 Daily Challenge](https://csuwangj.github.io/2018-12-25-Daily-Challenge/).

There is quick way to find palindromes, but rewrite it in rust is a suffer.

So I use brute force, which makes me happier :D

## Implementation

```rust
fn main() {
    const LIMIT: usize = 1_000_000;
    let mut ans: usize = 0;
    for i in 1..LIMIT {
        if double_base_palindrome(i) {
            println!("{}, {}", i, format!("{:b}", i));
            ans += i;
        }
    }
    println!("Answer is {}", ans);
}

fn double_base_palindrome(n: usize) -> bool {
    let s = n.to_string();
    // println!("{}",s);
    let s = s.as_bytes();
    for i in 0..(s.len()/2) {
        if s[i] != s[s.len()-1-i] {
            return false;
        }
    }
    let s = format!("{:b}", n);
    // println!("{}",s);
    let s = s.as_bytes();
    for i in 0..(s.len()/2) {
        if s[i] != s[s.len()-1-i] {
            return false;
        }
    }
    true
}
```

# Algorithm

## Problem

### 501. Find Mode in Binary Search Tree

Given a binary search tree (BST) with duplicates, find all the [mode(s)](https://en.wikipedia.org/wiki/Mode_(statistics)) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
- The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
- Both the left and right subtrees must also be binary search trees.

 

For example:
Given BST `[1,null,2,2]`,

```
   1
    \
     2
    /
   2
```

 

return `[2]`.

**Note:** If a tree has more than one mode, you can return them in any order.

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

## Solution

First I solve it by using a set, then rewrite it with another approach with less space usage.

Because problem is easy, so I don't want to explain my solution, check the code~:D

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
 * @return {number[]}
 */
var findMode = function(root) {
  let map = new Map();
  let ans = [];
  const travel = (root) => {
    if (!root) return;
    if (map.has(root.val)) map.set(root.val, map.get(root.val) + 1);
    else map.set(root.val, 1);
    travel(root.left);
    travel(root.right);
  };
  travel(root);
  let mx = 0;
  for (const [_key, value] of map.entries()) {
    mx = mx < value? value: mx;
  }
  for (const [key, value] of map.entries()) {
    if (value === mx) ans.push(key);
  }
  return ans;
};
```

```js
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function(root) {
  let ans = [];
  let cnt = 0;
  let mxcnt = 0;
  let cur = null;
  const inorder_travel = (root) => {
    if (!root) return;
    inorder_travel(root.left);
    handle_val(root.val);
    inorder_travel(root.right);
  };
  const handle_val = (val) => {
    if (val !== cur) {
      cur = val;
      cnt = 1;
    } else {
      cnt += 1;
    }
    if (cnt > mxcnt) {
      ans.splice(0, ans.length);
      ans.push(val);
      mxcnt = cnt;
    } else if (cnt === mxcnt) {
      ans.push(val);
    }
  };
  inorder_travel(root);
  return ans;
};
```