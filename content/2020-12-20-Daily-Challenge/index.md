+++
title = "2020-12-20 Daily-Challenge"
path = "2020-12-20-Daily-Challenge"
date = 2020-12-20 17:33:37+08:00
updated = 2020-12-20 18:22:06+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3572/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge20

**Decoded String at Index**

## Description

An encoded string `S` is given. To find and write the *decoded* string to a tape, the encoded string is read **one character at a time** and the following steps are taken:

- If the character read is a letter, that letter is written onto the tape.
- If the character read is a digit (say `d`), the entire current tape is repeatedly written `d-1` more times in total.

Now for some encoded string `S`, and an index `K`, find and return the `K`-th letter (1 indexed) in the decoded string.

**Example 1:**

```
Input: S = "leet2code3", K = 10
Output: "o"
Explanation: 
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
```

**Example 2:**

```
Input: S = "ha22", K = 5
Output: "h"
Explanation: 
The decoded string is "hahahaha".  The 5th letter is "h".
```

**Example 3:**

```
Input: S = "a2345678999999999999999", K = 1
Output: "a"
Explanation: 
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
```

**Constraints:**

- `2 <= S.length <= 100`
- `S` will only contain lowercase letters and digits `2` through `9`.
- `S` starts with a letter.
- `1 <= K <= 10^9`
- It's guaranteed that `K` is less than or equal to the length of the decoded string.
- The decoded string is guaranteed to have less than `2^63` letters.

## Solution

maintain a list mapping length of decoded string to corresponding index, and last character of that index, then we could get the answer.

if length is equal to of multiple of K, answer is last character of that index, if not, then we move forward. when length is larger than K, then it must be a digit, so we use $K\mod length(pos-1)$ to get new K.

``` cpp
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        char prevChar = S[0];
        int len = S.length();
        vector<unsigned long long> cnt(len);
        vector<char> lastChar(len);
        cnt[0] = 1, lastChar[0] = S[0];
        for(int i = 1; i < len; ++i) {
            if(isdigit(S[i])) {
                cnt[i] = cnt[i-1] * (S[i]-'0');
            } else {
                cnt[i] = cnt[i-1] + 1;
                prevChar = S[i];
            }
            lastChar[i] = prevChar;
        }
        if(K >= cnt.back()) K %= cnt.back();
        if(K == 0) return string(1, prevChar);
        while(K) {
            int pos = 0;
            while(pos < len && cnt[pos] < K) ++pos;
            if(cnt[pos] == K || K % cnt[pos-1] == 0) return string(1, lastChar[pos]);
            K %= cnt[pos-1];
        }
        return "";
    }
};
```
