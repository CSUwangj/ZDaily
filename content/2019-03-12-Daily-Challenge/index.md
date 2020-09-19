+++
title = "2019-03-12 Daily Challenge"
path = "2019-03-12-daily-challenge"
date = 2019-03-12T00:14:59+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Range Extraction* in *JavaScript*.

<!--more-->

# CodeWars

## Problem

### Range Extraction

A format for expressing an ordered list of integers is to use a comma separated list of either

- individual integers
- or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example ("12, 13, 15-17")

Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

**Example:**

```javascript
solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]);
// returns "-6,-3-1,3-5,7-11,14,15,17-20"
```

## Solution

```js
function solution(list) {
  let ans = "";
  if (!list.length) return ans;
  let cur = list[0];
  let begin = list[0];
  for (let i = 1; i < list.length; ++i) {
    if (list[i] === cur + 1) {
      cur += 1;
    } else {
      if (cur - begin > 1) {
        ans += `${begin}-${cur},`;
      } else {
        ans += begin === cur ? `${begin},` : `${begin},${cur},`;
      }
      begin = cur = list[i];
    }
  }
  if (cur - begin > 1) {
    ans += `${begin}-${cur},`;
  } else {
    ans += begin === cur ? `${begin},` : `${begin},${cur},`;
  }
  return ans.slice(0, ans.length - 1);
}

function solution(list) {
  for (let i = 0; i < list.length; ++i) {
    let index = i;
    while (list[index] - list[index+1] === -1) index += 1;
    if (index !== 0 && index - i > 1) list.splice(i, index-i+1, list[i]+"-"+list[index]);
  }
  return list.join();
}

const solution = l =>
  l.map((cur, i, arr) => (cur - 1 === arr[i - 1] && cur + 1 === arr[i + 1] ? "-" : cur))
   .map((cur, i, arr) => (cur !== arr[i + 1] ? cur : "@"))
   .filter(e => e !== "@")
   .join(",")
   .replace(/(,-,)/g, "-");
```