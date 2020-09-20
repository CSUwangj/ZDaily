+++
title = "2019-03-14 Daily Challenge"
path = "2019-03-14-daily-challenge"
date = 2019-03-14T00:09:22+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Moving Zeros To The End* in *JavaScript*.

<!-- more -->

# CodeWars

## Problem

### Moving Zeros To The End

Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

```javascript
moveZeros([false,1,0,1,2,0,1,3,"a"]) // returns[false,1,1,2,1,3,"a",0,0]
```

## Solution

```js
var moveZeros = function (arr) {
  return arr.filter(a=>a!==0).concat(arr.filter(a=>a===0))
}
```