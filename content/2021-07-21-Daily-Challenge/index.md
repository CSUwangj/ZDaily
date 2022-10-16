+++
title = "2021-07-21 Daily-Challenge"
path = "2021-07-21-Daily-Challenge"
date = 2021-07-21 15:33:49+08:00
updated = 2021-07-21 22:45:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3821) with `cpp`.

<!-- more -->

# Bulb Switcher

## Description

There are `n` bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the `ith` round, you toggle every `i` bulb. For the `nth` round, you only toggle the last bulb.

Return *the number of bulbs that are on after `n` rounds*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bulb.jpg)

```
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.
```

**Example 2:**

```
Input: n = 0
Output: 0
```

**Example 3:**

```
Input: n = 1
Output: 1
```

 

**Constraints:**

- `0 <= n <= 10^9`

## Solution

only square numbers are on

``` cpp
class Solution {
public:
  int bulbSwitch(int n) {
    return sqrt(n);
  }
};
```

# July LeetCoding Challenge 21

## Description

**Push Dominoes**

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string `dominoes` representing the initial state where:

- `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,
- `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and
- `dominoes[i] = '.'`, if the `ith` domino has not been pushed.

Return *a string representing the final state*.

 

**Example 1:**

```
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
```

**Example 2:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

```
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
```

 

**Constraints:**

- `n == dominoes.length`
- `1 <= n <= 10^5`
- `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  string pushDominoes(string dominoes) {
    int len = dominoes.length();
    bool prevLeft = true;
    int prevPos = -1;
    for(int i = 0; i < len; ++i) {
      if(dominoes[i] == '.') continue;
      if(dominoes[i] == 'L') {
        if(prevLeft) {
          for(int j = prevPos + 1; j < i; ++j) dominoes[j] = 'L';
        } else {
          for(int left = prevPos + 1, right = i - 1; left < right; ++left, --right) {
            dominoes[left] = 'R';
            dominoes[right] = 'L';
          }
        }
        prevLeft = true;
        prevPos = i;
      } else {
        if(!prevLeft) for(int j = prevPos + 1; j < i; j++) dominoes[j] = 'R';
        prevLeft = false;
        prevPos = i;
      }
    }
    if(!prevLeft) {
      for(int i = prevPos + 1; i < len; ++i) dominoes[i] = 'R';
    }
    return dominoes;
  }
};
```
