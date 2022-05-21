+++
updated = 2022-05-21 18:14:00+08:00
title = "2022-05-21 Daily-Challenge"
path = "2022-05-21-Daily-Challenge"
date = 2022-05-21 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/coin-change/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 21

## Description

**Coin Change**

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the fewest number of coins that you need to make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

 

**Example 1:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```
Input: coins = [1], amount = 0
Output: 0
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= coins.length &lt;= 12</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= amount &lt;= 10<sup>4</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount+1);
    dp[0] = 0;
    for(auto coin : coins){
      for(int i = coin; i <= amount; ++i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
    return dp.back() > amount ? -1 : dp.back();
  }
};

// Accepted
// 188/188 cases passed (108 ms)
// Your runtime beats 58.8 % of cpp submissions
// Your memory usage beats 68.59 % of cpp submissions (14.3 MB)
```
