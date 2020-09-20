+++
title = "2019-02-27 Daily Challenge"
path = "2019-02-27-daily-challenge"
date = 2019-02-27T00:06:29+00:00
updated = 2020-09-19T20:01:27.632313+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Find The Parity Outlier* in *JavaScript*.
<!-- more -->

# CodeWars

## Problem

### Find The Parity Outlier

You are given an array (which will have a length of at least 3, 
but could be very large) containing integers. The array is either 
entirely comprised of odd integers or entirely comprised of even 
integers except for a single integer `N`. Write a method that takes 
the array as an argument and returns this "outlier" `N`.

## Examples

```py
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
```

## Solution

```js
function findOutlier(integers){
  odd = integers.filter(a => a&1);
  even = integers.filter(a => ~a&1);
  return odd.length===1?odd[0]:even[0];
}

function findOutlier(integers){
  return integers
    .slice(0, 3)
    .filter(a => a&1)
    .length<2?
    integers.find(a => a&1):
    integers.find(a => ~a&1);
}
```