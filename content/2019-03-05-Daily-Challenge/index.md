+++
title = "2019-03-05 Daily Challenge"
path = "2019-03-05-daily-challenge"
date = 2019-03-05T00:00:21+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Build a pile of Cubes* in *JavaScript*.
<!-- more -->

# CodeWars

## Problem

### Build a pile of Cubes

Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until the top which will have a volume of 1^3.

You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

The parameter of the function findNb `(find_nb, find-nb, findNb)` will be an integer m and you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m if such a n exists or -1 if there is no such n.

## Examples:

```
findNb(1071225) --> 45
findNb(91716553919377) --> -1
mov rdi, 1071225
call find_nb            ; rax <-- 45

mov rdi, 91716553919377
call find_nb            ; rax <-- -1
```

## Solution

```js
function findNb(m) {
  let cur = 0;
  let sum = 0;
  while (sum < m) {
    cur += 1;
    sum += cur * cur * cur;
  }
  return sum===m?cur:-1;
}

function findNb(m) {
  let n = 0;
  while (m > 0) {
    n += 1;
    m -= n ** 3;
  return m ? -1 : n
}
```