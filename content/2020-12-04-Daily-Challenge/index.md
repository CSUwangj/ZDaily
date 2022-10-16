+++
title = "2020-12-04 Daily-Challenge"
path = "2020-12-04-Daily-Challenge"
date = 2020-12-04 18:01:30+08:00
updated = 2020-12-04 19:34:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Equal Rational Numbers](https://leetcode.com/problems/equal-rational-numbers) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3554/) with `cpp`.

<!-- more -->

# Equal Rational Numbers

## Description

Given two strings `S` and `T`, each of which represents a non-negative rational number, return **True** if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.

In general a rational number can be represented using up to three parts: an *integer part*, a *non-repeating part,* and a *repeating part*. The number will be represented in one of the following three ways:

- `<IntegerPart>` (e.g. 0, 12, 123)
- `<IntegerPart><.><NonRepeatingPart>` (e.g. 0.5, 1., 2.12, 2.0001)
- `<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>` (e.g. 0.1(6), 0.9(9), 0.00(1212))

The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:

1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)

Both 0.1(6) or 0.1666(6) or 0.166(66) are correct representations of 1 / 6.

**Example 1:**

```
Input: S = "0.(52)", T = "0.5(25)"
Output: true
Explanation:
Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
```

**Example 2:**

```
Input: S = "0.1666(6)", T = "0.166(66)"
Output: true
```

**Example 3:**

```
Input: S = "0.9(9)", T = "1."
Output: true
Explanation: 
"0.9(9)" represents 0.999999999... repeated forever, which equals 1.  [See this link for an explanation.]
"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".
```

**Note:**

1. Each part consists only of digits.
2. The `<IntegerPart>` will not begin with 2 or more zeros. (There is no other restriction on the digits of each part.)
3. `1 <= <IntegerPart>.length <= 4`
4. `0 <= <NonRepeatingPart>.length <= 4`
5. `1 <= <RepeatingPart>.length <= 4`

## Solution

if we have a unambiguous form to represent a number, then we can compare them directly.

``` cpp
class Solution {
    int gcd(int a, int b) { return b ? gcd(b, a%b) : a;}
    tuple<string,string,string> parse(string r) {
        string integerPart, nonRepeatingPart, repeatingPart;
        int pos = 0;
        int len = r.length();
        while(pos < len && isdigit(r[pos])) {
            integerPart += r[pos];
            pos += 1;
        }
        if(pos == len) {
            // unify to max decimal part length
            return make_tuple(integerPart, "0000", "0");
        }
        // '.'
        pos += 1;
        while(pos < len && isdigit(r[pos])) {
            nonRepeatingPart += r[pos];
            pos += 1;
        }
        if(pos == len) {
            return make_tuple(integerPart, nonRepeatingPart, "0");
        }
        // '('
        pos += 1;
        bool all9 = true, all0 = true;
        while(pos < len && isdigit(r[pos])) {
            if(r[pos] != '9') all9 = false;
            if(r[pos] != '0') all0 = false;
            repeatingPart += r[pos];
            pos += 1;
        }
        if(all9) {
            int carry = 1;
            for(auto it = nonRepeatingPart.rbegin(); carry && it != nonRepeatingPart.rend(); ++it) {
                if(*it != '9') {
                    carry = 0;
                    *it += 1;
                } else {
                    *it = '0';
                }
            }
            for(auto it = integerPart.rbegin(); carry && it != integerPart.rend(); ++it) {
                if(*it != '9') {
                    carry = 0;
                    *it += 1;
                } else {
                    *it = '0';
                }
            }
            if(carry) integerPart = "1" + integerPart;
        }
        if(all9 || all0) return make_tuple(integerPart, nonRepeatingPart, "0");
        return make_tuple(integerPart, nonRepeatingPart, repeatingPart);
    }
public:
    bool isRationalEqual(string S, string T) {
        auto [si, sn, sr] = parse(S);
        auto [ti, tn, tr] = parse(T);
        cout << si << '.' << sn << '(' << sr << ')' << endl;
        cout << ti << '.' << tn << '(' << tr << ')' << endl;
        int srl = sr.length(), trl = tr.length();
        if(si != ti) return false;
        if(sn.length() < tn.length()) {
            if(srl == 1) {
                while(sn.length() < tn.length()) sn += sr;
            } else {
                while(sn.length() < tn.length()) {
                    sn += sr[0];
                    sr = sr.substr(1) + sr[0];
                }
            }
        }
        if(tn.length() < sn.length()) {
            if(trl == 1) {
                while(tn.length() < sn.length()) tn += tr;
            } else {
                while(tn.length() < sn.length()) {
                    tn += tr[0];
                    tr = tr.substr(1) + tr[0];
                }
            }
        }
        int lcm = srl * trl / gcd(srl, trl);
        if(srl < lcm) {
            string newSr = "";
            while(newSr.length() != lcm) newSr += sr;
            sr = newSr;
        }
        if(trl < lcm) {
            string newTr = "";
            while(newTr.length() != lcm) newTr += tr;
            tr = newTr;
        }
        cout << si << '.' << sn << '(' << sr << ')' << endl;
        cout << ti << '.' << tn << '(' << tr << ')' << endl;
        return (sn == tn && sr == tr);
    }
};
```

# December LeetCoding Challenge 4

## Description

**The kth Factor of n**

Given two positive integers `n` and `k`.

A factor of an integer `n` is defined as an integer `i` where `n % i == 0`.

Consider a list of all factors of `n` sorted in **ascending order**, return *the* `kth` *factor* in this list or return **-1** if `n` has less than `k` factors.

**Example 1:**

```
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
```

**Example 2:**

```
Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
```

**Example 3:**

```
Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
```

**Example 4:**

```
Input: n = 1, k = 1
Output: 1
Explanation: Factors list is [1], the 1st factor is 1.
```

**Example 5:**

```
Input: n = 1000, k = 3
Output: 4
Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
```

**Constraints:**

- `1 <= k <= n <= 1000`

## Solution

nothing to say

``` cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            if(n % i) continue;
            if(++cur == k) return i;
        }
        return -1;
    }
};
```