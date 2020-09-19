+++
title = "2019-03-04 Daily Challenge"
path = "2019-03-04-daily-challenge"
date = 2019-03-04T00:22:20+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Array.diff* in *JavaScript*.
<!--more-->

# CodeWars

## Problem

### Array.diff

Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.

It should remove all values from list `a`, which are present in list `b`.

```javascript
array_diff([1,2],[1]) == [2]
```

If a value is present in `b`, all of its occurrences must be removed from the other:

```javascript
array_diff([1,2,2,2,3],[2]) == [1,3]
```

## Solution

```js
function array_diff(a, b) {
  return a.filter(e => !b.includes(e));
}

function array_diff(a, b) {
  b = new Set(b)
  return a.filter(v => !b.has(v))
}
```