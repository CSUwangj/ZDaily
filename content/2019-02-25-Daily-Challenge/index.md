+++
title = "2019-02-25 Daily Challenge"
path = "2019-02-25-daily-challenge"
date = 2019-02-25T00:35:16+00:00
updated = 2020-09-19T20:01:27.632313+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Find the divisors!* in *JavaScript*.

<!-- more -->

# CodeWars

## Problem

### Find the divisors!

Create a function named `divisors`/`Divisors` that takes an integer `n > 1` and returns an array with all of the integer's divisors(except for 1 and the number itself), from smallest to largest. If the number is prime return the string '(integer) is prime' (`null` in C#) (use `Either String a` in Haskell and `Result<Vec<u32>, String>` in Rust).

#### Example:

```javascript
divisors(12); // should return [2,3,4,6]
divisors(25); // should return [5]
divisors(13); // should return "13 is prime"
```

## Solution

```js
function divisors(integer) {
  s = Array.apply(null, {length: Math.ceil((integer+1)/2)}).map(Number.call, Number).slice(2).filter(x => integer % x===0);
  return s.length?s:`${integer} is prime`;
};
```