+++
title = "2021-05-10 Daily-Challenge"
path = "2021-05-10-Daily-Challenge"
date = 2021-05-10 18:00:27+08:00
updated = 2021-05-10 18:48:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Construct K Palindrome Strings](https://leetcode.com/problems/construct-k-palindrome-strings/description/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/) with `cpp`.

<!-- more -->

# Construct K Palindrome Strings

## Description

Given a string `s` and an integer `k`. You should construct `k` non-empty **palindrome** strings using **all the characters** in `s`.

Return ***True*** if you can use all the characters in `s` to construct `k` palindrome strings or ***False*** otherwise.

 

**Example 1:**

```
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
```

**Example 2:**

```
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
```

**Example 3:**

```
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
```

**Example 4:**

```
Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.
```

**Example 5:**

```
Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- All characters in `s` are lower-case English letters.
- `1 <= k <= 10^5`

## Solution

``` cpp
class Solution {
public:
  bool canConstruct(string s, int k) {
    int cnt[26] = {};
    for(auto c : s) cnt[c - 'a'] += 1;
    int mmin = 0;
    for(int i = 0; i < 26; ++i) mmin += cnt[i] & 1;
    mmin = max(mmin, 1);
    return k >= mmin && k <= s.length();
  }
};
```

# May LeetCoding Challenge 10

## Description

**Count Primes**

Count the number of prime numbers less than a non-negative number, `n`.

 

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```
Input: n = 0
Output: 0
```

**Example 3:**

```
Input: n = 1
Output: 0
```

 

**Constraints:**

- `0 <= n <= 5 * 10^6`

## Solution

``` cpp
class Solution {
public:
  int countPrimes(int n) {
    bool isPrime[n + 2];
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
      if(!isPrime[i]) continue;
      for(int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
    return accumulate(isPrime, isPrime + n, 0);
  }
};
```
