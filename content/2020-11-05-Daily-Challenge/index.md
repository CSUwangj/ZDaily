+++
title = "2020-11-05 Daily-Challenge"
path = "2020-11-05-Daily-Challenge"
date = 2020-11-05 00:19:21+08:00
updated = 2020-11-05 20:16:32+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Bulls and Cows* on [leetcode](https://leetcode.com/problems/bulls-and-cows/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3520/) with `cpp`.

<!-- more -->

# Bulls and Cows

## Description

You are playing the **[Bulls and Cows](https://en.wikipedia.org/wiki/Bulls_and_Cows)** game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

- The number of "bulls", which are digits in the guess that are in the correct position.
- The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number `secret` and your friend's guess `guess`, return *the hint for your friend's guess*.

The hint should be formatted as `"xAyB"`, where `x` is the number of bulls and `y` is the number of cows. Note that both `secret` and `guess` may contain duplicate digits.

 **Example 1:**

```
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
```

**Example 2:**

```
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
```

**Example 3:**

```
Input: secret = "1", guess = "0"
Output: "0A0B"
```

**Example 4:**

```
Input: secret = "1", guess = "1"
Output: "1A0B"
```

**Constraints:**

- `1 <= secret.length, guess.length <= 1000`
- `secret.length == guess.length`
- `secret` and `guess` consist of digits only.

## Solution

nothing to say

``` cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        map<char, int> sMap, gMap;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) bulls += 1;
            else {
                sMap[secret[i]] += 1;
                gMap[guess[i]] += 1;
            }
        }
        for(auto &p : sMap) {
            if(gMap.count(p.first)) {
                cows += min(gMap[p.first], p.second);
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

# November LeetCoding Challenge5

**Minimum Cost to Move Chips to The Same Position**

## Description

We have `n` chips, where the position of the `ith` chip is `position[i]`.

We need to move all the chips to **the same position**. In one step, we can change the position of the `ith` chip from `position[i]` to:

- `position[i] + 2` or `position[i] - 2` with `cost = 0`.
- `position[i] + 1` or `position[i] - 1` with `cost = 1`.

Return *the minimum cost* needed to move all the chips to the same position.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/15/chips_e1.jpg)

```
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/15/chip_e2.jpg)

```
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at poistion 3 to position 2. Each move has cost = 1. The total cost = 2.
```

**Example 3:**

```
Input: position = [1,1000000000]
Output: 1
```

**Constraints:**

- `1 <= position.length <= 100`
- `1 <= position[i] <= 10^9`

## Solution

parity

``` cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt[2] = {0, 0};
        for(auto i : position) {
            cnt[i&1] += 1;
        }
        return min(cnt[0], cnt[1]);
    }
};
```
