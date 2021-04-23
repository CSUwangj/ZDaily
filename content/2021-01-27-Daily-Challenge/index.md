+++
title = "2021-01-27 Daily-Challenge"
path = "2021-01-27-Daily-Challenge"
date = 2021-01-27 18:00:59+08:00
updated = 2021-01-27 20:07:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Integer to Roman](https://leetcode.com/problems/integer-to-roman/), [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/) with `cpp`.

<!-- more -->

# Water and Jug Problem

## Description

You are given two jugs with capacities *x* and *y* litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly *z* litres using these two jugs.

If *z* liters of water is measurable, you must have *z* liters of water contained within **one or both buckets** by the end.

Operations allowed:

- Fill any of the jugs completely with water.
- Empty any of the jugs.
- Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

**Example 1:** (From the famous [*"Die Hard"* example](https://www.youtube.com/watch?v=BVtQNK_ZUJg))

```
Input: x = 3, y = 5, z = 4
Output: True
```

**Example 2:**

```
Input: x = 2, y = 6, z = 5
Output: False
```

 

**Constraints:**

- $0 \le x \le 10^6$
- $0 \le y \le 10^6$
- $0 \le z \le 10^6$

## Solution

``` cpp
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(gcd(x, y) == 0) return z==0;
        return z <= x+y && z % gcd(x, y) == 0;
    }
};
```

# Integer to Roman

## Description

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
    vector<tuple<int, int, char, char>> helpers = {
        {1000, 100, 'M', 'C'},
        {500, 100, 'D', 'C'},
        {100, 10, 'C', 'X'},
        {50, 10, 'L', 'X'},
        {10, 1, 'X', 'I'},
        {5, 1, 'V', 'I'},
        {1, -1, 'I', ' '}
    };
public:
    string intToRoman(int num) {
        string answer;
        for(auto [larger, smaller, lC, sC] : helpers) {
            while(num >= larger) {
                answer.push_back(lC);
                num -= larger;
            }
            if(num >= larger - smaller) {
                answer.push_back(sC);
                answer.push_back(lC);
                num -= larger - smaller;
            }
        }
        return answer;
    }
};
```

# January LeetCoding Challenge27

## Description

**Concatenation of Consecutive Binary Numbers**

## Description

Given an integer `n`, return *the **decimal value** of the binary string formed by concatenating the binary representations of* `1` *to* `n` *in order, **modulo*** `109 + 7`.

 

**Example 1:**

```
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
```

**Example 2:**

```
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```

**Example 3:**

```
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
```

 

**Constraints:**

- $1 \le n \le 10^5$

## Solution

``` cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        int shift = 1;
        int base = 2;
        long long answer = 0;
        const int MOD = 1e9 + 7;
        for(int i = 1; i <= n; ++i) {
            if(i == base) {
                base *= 2;
                shift += 1;
            }
            answer = (answer << shift) | i;
            answer %= MOD;
        }
        return answer;
    }
};
```
