+++
title = "2019-03-15 Daily Challenge"
path = "2019-03-15-daily-challenge"
date = 2019-03-15T00:10:10+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Pete, the baker* in *JavaScript*.

<!-- more -->

# CodeWars

## Problem

### Pete, the baker

Pete likes to bake some cakes. He has some recipes and ingredients. Unfortunately he is not good in maths. Can you help him to find out, how many cakes he could bake considering his recipes?

  Write a function `cakes()`, which takes the recipe (object) and the available ingredients (also an object) and returns the maximum number of cakes Pete can bake (integer). For simplicity there are no units for the amounts (e.g. 1 lb of flour or 200 g of sugar are simply 1 or 200). Ingredients that are not present in the objects, can be considered as 0.

  Examples:

  ```javascript
  // must return 2
  cakes({flour: 500, sugar: 200, eggs: 1}, {flour: 1200, sugar: 1200, eggs: 5, milk: 200}); 
  // must return 0
  cakes({apples: 3, flour: 300, sugar: 150, milk: 100, oil: 100}, {sugar: 500, flour: 2000, milk: 2000}); 
  ```

## Solution

```js
function cakes(recipe, available) {
  let ans = Object.keys(recipe)
    .reduce(
      (a, b) => Math.min(a, Math.floor(available[b] / recipe[b])),
      Number.MAX_SAFE_INTEGER
    );
  return isNaN(ans) ? 0 : ans;
}

////

function cakes(recipe, available) {
  return Object.keys(recipe)
    .reduce(
      (a, b) => Math.min(a, Math.floor(available[b] / recipe[b]) || 0),
      Infinity
    );
}
```