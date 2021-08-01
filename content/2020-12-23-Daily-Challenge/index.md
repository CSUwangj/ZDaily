+++
title = "2020-12-23 Daily-Challenge"
path = "2020-12-23-Daily-Challenge"
date = 2020-12-23 18:00:42+08:00
updated = 2020-12-23 18:19:47+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Unique Substrings in Wraparound String](https://leetcode.com/problems/unique-substrings-in-wraparound-string/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3578/) with `cpp`.

<!-- more -->

# Unique Substrings in Wraparound String

## Description

Consider the string `s` to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so `s` will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string `p`. Your job is to find out how many unique non-empty substrings of `p` are present in `s`. In particular, your input is the string `p` and you need to output the number of different non-empty substrings of `p` in the string `s`.

**Note:** `p` consists of only lowercase English letters and the size of p might be over 10000.

**Example 1:**

```
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
```

**Example 2:**

```
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
```

**Example 3:**

```
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
```

## Solution

when we have a contiguous substring like `abc`, consider substring end with `c`, we have `c`, `bc`, `abc`. so we can find that if length of longest substring end with some character $x$ is $n$, then amount of eligible substrings end with $x$ will be $n$. so we just need to find longest substring of every character.

first, we can easily determine length of longest substring which ends with specified char in `p` by remember last character and length of it. then we can get length of at most 26 substrings. then we maintain a array which records the length of longest substring end with every letter, by update this array when iterator through string, we'll get the answer.

``` cpp
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int length[26] = {0};
        int pos = 0, len = p.length();
        int currentLength = 0;
        int lastChar = -1;
        while(pos < len) {
            int currentChar = p[pos]-'a';
            int prevChar = (currentChar - 1 + 26) % 26;
            if(lastChar != prevChar) {
                currentLength = 0;
            }
            currentLength += 1;
            length[currentChar] = max(length[currentChar], currentLength);
            for(int i = 1; i < min(26, currentLength); ++i) {
                int c = (currentChar - 1 + 26) % 26;
                length[c] = max(length[c], currentLength-i);
            }
            lastChar = currentChar;
            pos += 1;
        }
        int answer = 0;
        for(int i = 0; i < 26; ++i) {
            answer += length[i];
        }
        return answer;
    }
};
```

and we can break it when we update the array when we find a bigger value.

``` cpp
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int length[26] = {0};
        int pos = 0, len = p.length();
        int currentLength = 0;
        int lastChar = -1;
        while(pos < len) {
            int currentChar = p[pos]-'a';
            int prevChar = (currentChar - 1 + 26) % 26;
            if(lastChar != prevChar) {
                currentLength = 0;
            }
            currentLength += 1;
            if(length[currentChar] < currentLength) {
                length[currentChar] = currentLength;
                for(int i = 1; i < min(26, currentLength); ++i) {
                    int c = (currentChar - 1 + 26) % 26;
                    if(length[c] >= currentLength-i) break;
                    length[c] = max(length[c], currentLength-i);
                }
            }
            lastChar = currentChar;
            pos += 1;
        }
        int answer = 0;
        for(int i = 0; i < 26; ++i) {
            answer += length[i];
        }
        return answer;
    }
};
```

# December LeetCoding Challenge 23

## Description

**Next Greater Element III**

Given a positive integer `n`, find *the smallest integer which has exactly the same digits existing in the integer* `n` *and is greater in value than* `n`. If no such positive integer exists, return `-1`.

**Note** that the returned integer should fit in **32-bit integer**, if there is a valid answer but it does not fit in **32-bit integer**, return `-1`.

**Example 1:**

```
Input: n = 12
Output: 21
```

**Example 2:**

```
Input: n = 21
Output: -1
```

**Constraints:**

- $1 \le n \le 2^{31} - 1$

## Solution

nothing to say

``` cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string answer = to_string(n);
        int ans;
        if(next_permutation(answer.begin(), answer.end())) {
            if(stoll(answer) > INT_MAX) {
                ans = -1;
            } else {
                ans = stoi(answer);
            }
        } else {
            ans = -1;
        }
        return ans;
    }
};
```