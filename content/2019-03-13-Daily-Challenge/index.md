+++
title = "2019-03-13 Daily Challenge"
path = "2019-03-13-daily-challenge"
date = 2019-03-13T00:03:32+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Strip Comments* in *JavaScript*.

Regex is awesome!

<!--more-->

# CodeWars

## Problem

### Strip Comments

Complete the solution so that it strips all text that follows any of a set of comment markers passed in. Any whitespace at the end of the line should also be stripped out.

**Example:**

Given an input string of:

```
apples, pears # and bananas
grapes
bananas !apples
```

The output expected would be:

```
apples, pears
grapes
bananas
```

The code would be called like so:

```javascript
var result = solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"])
// result should == "apples, pears\ngrapes\nbananas"
```

## Solution

```js
const escape = (string) => string.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&');

function solution(input, markers) {
  if (input[input.length-1] !== "\n") input += "\n";
  markers.map(m => escape(m)).forEach(m => input = input.replace(RegExp(`\ *${m}.*?\n`), "\n"));
  return input.slice(0,-1);
};

////

function solution(input, markers){
  return input.replace(RegExp("\\s?[" + markers.join("") + "].*(\\n)?", "gi"), "$1");
}

////

function solution(input, markers) {
  return input.split('\n').map(
    line => markers.reduce(
      (line, marker) => line.split(marker)[0].trim(), line
    )
  ).join('\n')
}
```