+++
title = "2019-03-06 Daily Challenge"
path = "2019-03-06-daily-challenge"
date = 2019-03-06T00:38:14+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

What I've done today is *Weight for weight* in *JavaScript*.

Although solution is clever, I still think that this problem is so dumb. Bad details, bad description towards input and output, and bad input.

<!--more-->

# CodeWars

## Problem

### Weight for weight

My friend John and I are members of the "Fat to Fit Club (FFC)". John is 
worried because each month a list with the weights of members is published 
and each month he is the last on the list which means he is the heaviest.

I am the one who establishes the list so I told him: "Don't worry any more, 
I will modify the order of the list". It was decided to attribute a "weight" 
to numbers. The weight of a number will be from now on the sum of its digits.

For example `99` will have "weight" `18`, `100` will have "weight" `1` so in 
the list `100` will come before `99`. Given a string with the weights of FFC 
members in normal order can you give this string ordered by "weights" of these numbers?

#### Example:

```
"56 65 74 100 99 68 86 180 90"` ordered by numbers weights becomes: `"100 180 90 56 65 74 68 86 99"
```

When two numbers have the same "weight", let us class them as if they were 
strings and not numbers: `100` is before `180` because its "weight" (1) is 
less than the one of `180` (9) and `180` is before `90` since, having the 
same "weight" (9), it comes before as a *string*.

All numbers in the list are positive numbers and the list can be empty.

#### Notes

- it may happen that the input string have leading, trailing whitespaces and more than a unique whitespace between two consecutive numbers
- Don't modify the input
- For C: The result is freed.

## Solution

```js
function orderWeight(strng) {
  return strng.match(/[^ ]+/gi)
    .map(Number)
    .map(a => a.toString())
    .sort((a, b) => {
      return a.split("").map(e => +e).reduce((a, b) => a + b) - b.split("").map(e => +e).reduce((a, b) => a + b) ?
        a.split("").map(e => +e).reduce((a, b) => a + b) - b.split("").map(e => +e).reduce((a, b) => a + b) :
        (a < b ? -1 : (a > b ? 1 : 0));
    }).join(" ")
}

function orderWeight(strng) {
  const digitsum = (num) => num.split("").map(e => +e).reduce((a, b) => a + b);
  if (strng.search(/[^ ]+/) === -1) return "";
  return strng.match(/[^ ]+/gi)
    .map(Number)
    .map(a => a.toString())
    .sort((a, b) => {
      return digitsum(a)-digitsum(b) ?
        digitsum(a)-digitsum(b) :
        (a < b ? -1 : (a > b ? 1 : 0));
    }).join(" ")
}

function orderWeight(strng) {
  const digitsum = (num) => num.split("").map(e => +e).reduce((a, b) => a + b);
  if (strng.search(/[^ ]+/) === -1) return "";
  return strng.match(/[^ ]+/gi)
    .map(Number)
    .map(a => a.toString())
    .sort((a, b) => {
      return digitsum(a)-digitsum(b) ?
        digitsum(a)-digitsum(b) :
        a.localeCompare(b);
    }).join(" ")
}

function orderWeight(strng) {
  return strng
    .split(" ")
    .map(function(v) {  
      return {
        val: v,
        key: v.split("").reduce(function(prev, curr) {
          return parseInt(prev) + parseInt(curr);
        }, 0)
      };
    })
    .sort(function(a, b) {
      return a.key == b.key 
        ? a.val.localeCompare(b.val)
        : (a.key - b.key);
    })
    .map(function(v) {
      return v.val;
    })
    .join(" ");
}
```