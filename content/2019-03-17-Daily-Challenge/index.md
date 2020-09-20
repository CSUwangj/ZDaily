+++
title = "2019-03-17 Daily Challenge"
path = "2019-03-17-daily-challenge"
date = 2019-03-17T00:00:48+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Counting Change Combinations* in *JavaScript*.

DP sucks.

<!-- more -->

# CodeWars

## Problem

### Counting Change Combinations


Write a function that counts how many different ways you can make change for an amount of money, given an array of coin denominations. For example, there are 3 ways to give change for 4 if you have coins with denomination 1 and 2:

```
1+1+1+1, 1+1+2, 2+2.
```

The order of coins does not matter:

```
1+1+2 == 2+1+1
```

Also, assume that you have an infinite amount of coins.

Your function should take an amount to change and an array of unique denominations for the coins:

```javascript
  countChange(4, [1,2]) // => 3
  countChange(10, [5,2,3]) // => 4
  countChange(11, [5,7]) //  => 0
```

## Solution

```js
var countChange = function (money, coins) {
  let dp = new Array(money + 1).fill(0);
  dp[0] = 1;
  for (let coin of coins) {
    for (let i = 0; i <= money - coin; ++i) {
      if (dp[i]) dp[i + coin] += dp[i];
    }
  }
  return dp[money];
}

////

const countChange = (money, coins) => money === 0 ? 1 : coins.filter(e => e <= money).reduce((s, _, i, coins) => s + countChange(money - coins[i], coins.slice(i)), 0);

////

let countChange = (money, coins) => {
  let [coin, ...rest] = coins;
  if (!coin) return 0;
  if (money < 0) return 0;
  if (money === 0) return 1;
  return countChange(money - coin, coins) +
    countChange(money, rest);
}
```