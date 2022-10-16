+++
title = "2019-01-07 Daily Challenge"
path = "2019-01-07-daily-challenge"
date = 2019-01-07T00:06:14+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Maximum path sum I* in *Rust* and *Valid Parenthesis String* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Maximum path sum I

Problem 18 

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
```

## Solution

DP or recursive method is capable of doing this.

## Implementation

```rust
use std::cmp::max;

fn main() {
    let nums = [[75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0],
[99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0],
[41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0],
[41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0],
[53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0],
[70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0],
[91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0],
[63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0],
[4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23]];
    let mut mx = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]];
    mx[0][0] = nums[0][0];
    for i in 1..15 {
        for j in 0..i+1 {
            if j == 0 {
                mx[i][j] = mx[i-1][j] + nums[i][j];
            }else if i == j {
                mx[i][j] = mx[i-1][j-1] + nums[i][j];
            }else{
                mx[i][j] = max(mx[i-1][j], mx[i-1][j-1]) + nums[i][j];
            }
            // print!("{} ", mx[i][j]);
        }
        // println!("");
    }
    let mut ans = 0;
    for i in 0..15 {
        ans = max(ans, mx[14][i]);
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

```
678. Valid Parenthesis String

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
```

## Solution

Simulating a stack is capable for none \* parenthesis pairing.

Invalid parenthesis is '(' doesn't have a corresponding ')' or right more '*', and versa versa.

Second way is to maintain the smallest and largest possible number of open left brackets after processing the current character in the string.

Solution page also illustrate a DP approach but with $O(N^3)$ time complexity and $O(N^2)$ space complexity, so I don't want to implement it.

## Implementation

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
  let stack = [];
  let star = [];
  let len = s.length;
  for(let i = 0; i < len; ++i){
    if(s.charAt(i) === "("){
      stack.push(i);
    }else if(s.charAt(i) === ")"){
      if(stack.length){
        stack.pop();
      }else if(star.length){
        star.pop();
      }else{
        return false;
      }
    }else{
      star.push(i);
    }
  }
  while(stack.length){
    if(star.length && star[star.length-1] > stack[stack.length-1]){
      stack.pop();
      star.pop();
    }else{
      break;
    }
  }
  return stack.length==0;
};
```

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
  let l = 0;
  let h = 0;
  let len = s.length;
  for(let i = 0; i < len; ++i){
    if(s.charAt(i)=="("){
      l += 1;
      h += 1;
    }else if(s.charAt(i)==")"){
      l -= 1;
      h -= 1;
    }else{
      l -= 1;
      h += 1;
    }
    if(h < 0){
      break;
    }
    l = Math.max(lo, 0);
  }
  return l == 0;
};
```