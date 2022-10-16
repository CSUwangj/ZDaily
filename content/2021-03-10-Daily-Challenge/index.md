+++
title = "2021-03-10 Daily-Challenge"
path = "2021-03-10-Daily-Challenge"
date = 2021-03-10 18:03:31+08:00
updated = 2021-03-10 18:17:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3667/) with `cpp`.

<!-- more -->

# Guess Number Higher or Lower

## Description

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns 3 possible results:

- `-1`: The number I picked is lower than your guess (i.e. `pick < num`).
- `1`: The number I picked is higher than your guess (i.e. `pick > num`).
- `0`: The number I picked is equal to your guess (i.e. `pick == num`).

Return *the number that I picked*.

 

**Example 1:**

```
Input: n = 10, pick = 6
Output: 6
```

**Example 2:**

```
Input: n = 1, pick = 1
Output: 1
```

**Example 3:**

```
Input: n = 2, pick = 1
Output: 1
```

**Example 4:**

```
Input: n = 2, pick = 2
Output: 2
```

 

**Constraints:**

- `1 <= n <= 231 - 1`
- `1 <= pick <= n`

## Solution

``` cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int begin = 1, end = n;
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            int res = guess(mid);
            if(res != 1) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};
```

# March LeetCoding Challenge 10

## Description

**Integer to Roman**

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

 

**Example 1:**

```
Input: num = 3
Output: "III"
```

**Example 2:**

```
Input: num = 4
Output: "IV"
```

**Example 3:**

```
Input: num = 9
Output: "IX"
```

**Example 4:**

```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```

**Example 5:**

```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

 

**Constraints:**

- `1 <= num <= 3999`

## Solution

``` cpp
class Solution {
    vector<pair<int, int>> p = {
        {1000, 100},
        {500, 100},
        {100, 10},
        {50, 10},
        {10, 1},
        {5, 1},
        {1, 0}
    };
    unordered_map<int, char> mp = {
        {1000, 'M'},
        {500, 'D'},
        {100, 'C'},
        {50, 'L'},
        {10, 'X'},
        {5, 'V'},
        {1, 'I'}
    };
public:
    string intToRoman(int num) {
        string answer;
        for(auto [larger, less] : p) {
            while(num >= larger) {
                num -= larger;
                answer.push_back(mp[larger]);
            }
            if(num >= larger - less) {
                num -= larger - less;
                answer.push_back(mp[less]);
                answer.push_back(mp[larger]);
            }
        }
        return move(answer);
    }
};
```
