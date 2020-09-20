+++
title = "2019-03-11 Daily Challenge"
path = "2019-03-11-daily-challenge"
date = 2019-03-11T14:10:36+00:00
updated = 2020-09-19T20:01:27.637303+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *A Chain adding function* in *JavaScript*.

Currying is awesome!

<!-- more -->

# CodeWars

## Problem

### A Chain adding function

We want to create a function that will add numbers together when called in succession.

```javascript
add(1)(2);
// returns 3
```

We also want to be able to continue to add numbers to our chain.

```javascript
add(1)(2)(3); // 6
add(1)(2)(3)(4); // 10
add(1)(2)(3)(4)(5); // 15
```

and so on.

A single call should return the number passed in.

```javascript
add(1); // 1
```

We should be able to store the returned values and reuse them.

```javascript
var addTwo = add(2);
addTwo; // 2
addTwo + 5; // 7
addTwo(3); // 5
addTwo(3)(5); // 10
```

We can assume any number being passed in will be valid whole number.

## Solution

```js
function add(n){
  const f = (x) => add(x+n);
  f.valueOf = () => n;
  return f;
}
```