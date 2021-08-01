+++
title = "2021-01-19 Daily-Challenge"
path = "2021-01-19-Daily-Challenge"
date = 2021-01-19 18:00:59+08:00
updated = 2021-01-19 22:05:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3609/) with `cpp`.

<!-- more -->

# Maximum Number of Non-Overlapping Substrings

## Description

Given a string `s` of lowercase letters, you need to find the maximum number of **non-empty** substrings of `s` that meet the following conditions:

1. The substrings do not overlap, that is for any two substrings `s[i..j]` and `s[k..l]`, either `j < k` or `i > l` is true.
2. A substring that contains a certain character `c` must also contain all occurrences of `c`.

Find *the maximum number of substrings that meet the above conditions*. If there are multiple solutions with the same number of substrings, *return the one with minimum total length.* It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in **any** order.

 

**Example 1:**

```
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
```

**Example 2:**

```
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
```

 

**Constraints:**

- $1 \le  s.length \le 10^5$
- `s` contains only lowercase English letters.

## Solution

greedy...

``` cpp
class Solution {
    vector<int> l = vector<int>(26, INT_MAX);
    vector<int> r = vector<int>(26, INT_MIN);
    int getRight(string &s, int index) {
        int right = r[s[index] - 'a'];
        for(int i = index; i <= right; ++i) {
            if(l[s[i] - 'a'] < index) return -1;
            right = max(right, r[s[i] - 'a']);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int len = s.length();
        for(int i = 0; i < len; ++i) {
            l[s[i] - 'a'] = min(i, l[s[i] - 'a']);
            r[s[i] - 'a'] = i;
        }
        int right = -1;
        vector<string> answer;
        for(int i = 0; i < len; ++i) {
            if(i == l[s[i] - 'a']) {
                int currentRight = getRight(s, i);
                if(currentRight != -1) {
                    if(i > right) answer.push_back(s.substr(i, currentRight-i+1));
                    else answer.back() = s.substr(i, currentRight-i+1);
                    right = currentRight;
                }
            }
        }
        return answer;
    }
};
```

# January LeetCoding Challenge 19

## Description

**Longest Palindromic Substring**

Given a string `s`, return *the longest palindromic substring* in `s`.

 

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"
```

**Example 3:**

```
Input: s = "a"
Output: "a"
```

**Example 4:**

```
Input: s = "ac"
Output: "a"
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consist of only digits and English letters (lower-case and/or upper-case),

## Solution

memorized

``` cpp
class Solution {
    vector<vector<int>> memo;
public:
    string longestPalindrome(string s) {
        int len = s.length();
        memo.resize(len+1, vector<int>(len+1, -1));
        for(int i = 0; i < len; ++i) {
            memo[i][i] = 0;
            memo[i][i+1] = 1;
        }
        int answer = 1;
        int begin = 0;
        for(int i = 2; i <= len; ++i) {
            for(int j = 0; j+i <= len; ++j) {
                if(memo[j+1][j+i-1] != -1 && s[j] == s[j+i-1]) {
                    memo[j][j+i] = memo[j+1][j+i-1] + 2;
                    if(memo[j][j+i] > answer) {
                        answer = i;
                        begin = j;
                    }
                }
            }
        }
        return s.substr(begin, answer);
    }
};
```
