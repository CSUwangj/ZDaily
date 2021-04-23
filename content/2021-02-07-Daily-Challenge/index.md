+++
title = "2021-02-07 Daily-Challenge"
path = "2021-02-07-Daily-Challenge"
date = 2021-02-07 18:00:22+08:00
updated = 2021-02-07 18:53:02+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3631/) with `cpp`.

BTW, I participated in Weekly Contest 227, but only get two problems done. If I stick with it for more 30 minutes, maybe I could have done it(I go to lunch at 11:30).

<!-- more -->

# February LeetCoding Challenge7

## Description

**Shortest Distance to a Character**

## Description

Given a string `s` and a character `c` that occurs in `s`, return *an array of integers `answer` where* `answer.length == s.length` *and* `answer[i]` *is the shortest distance from* `s[i]` *to the character* `c` *in* `s`.

 

**Example 1:**

```
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
```

**Example 2:**

```
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
```

 

**Constraints:**

- $1 \le s.length \le 10^4$
- `s[i]` and `c` are lowercase English letters.
- `c` occurs at least once in `s`.

## Solution

``` cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cPos;
        int len = s.length();
        vector<int> answer(len);
        for(int i = 0; i < len; ++i) {
            if(s[i] == c) cPos.push_back(i);
        }
        cPos.push_back(20020);
        int pos = 0;
        for(int i = 0; i < len; ++i) {
            int result0 = abs(i - cPos[pos]);
            int result1 = abs(i - cPos[pos+1]);
            if(result1 <= result0) {
                pos += 1;
                answer[i] = result1;
            } else {
                answer[i] = result0;
            }
        }
        return move(answer);
    }
};
```

# Weekly Contest 227

## 1752. Check if Array Is Sorted and Rotated

Given an array `nums`, return `true` *if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)*. Otherwise, return `false`.

There may be **duplicates** in the original array.

**Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `A[i] == B[(i+x) % A.length]`, where `%` is the modulo operation.

 

**Example 1:**

```
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
```

**Example 2:**

```
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
```

**Example 4:**

```
Input: nums = [1,1,1]
Output: true
Explanation: [1,1,1] is the original sorted array.
You can rotate any number of positions to make nums.
```

**Example 5:**

```
Input: nums = [2,1]
Output: true
Explanation: [1,2] is the original sorted array.
You can rotate the array by x = 5 positions to begin on the element of value 2: [2,1].
```

 

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

### Solution

``` cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int r = 0;
        int cur = nums.front();
        for(auto n : nums) {
            if(cur > n) r += 1;
            cur = n;
        }
        return r == 0 || (r == 1 && nums.front() >= nums.back());
    }
};
```

## 1753. Maximum Score From Removing Stones

You are playing a solitaire game with **three piles** of stones of sizes `a`, `b`, and `c` respectively. Each turn you choose two **different non-empty** piles, take one stone from each, and add `1` point to your score. The game stops when there are **fewer than two non-empty** piles (meaning there are no more available moves).

Given three integers `a`, `b`, and `c`, return *the* ***maximum\*** ***score** you can get.*

 

**Example 1:**

```
Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.
```

**Example 2:**

```
Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.
```

**Example 3:**

```
Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.
```

 

**Constraints:**

- $1 \le a, b, c \le 10^5$

### Solution

think of a solution run with $O(1)$ will make rank larger, so.

``` cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> tmp{a, b, c};
        sort(tmp.begin(), tmp.end());
        int answer = 0;
        while(tmp[1] > 0) {
            tmp[1] -= 1;
            tmp[2] -= 1;
            answer += 1;
            sort(tmp.begin(), tmp.end());
        }
        return answer;
    }
};
```

## 1754. Largest Merge Of Two Strings

You are given two strings `word1` and `word2`. You want to construct a string `merge` in the following way: while either `word1` or `word2` are non-empty, choose **one** of the following options:


  - If `word1` is non-empty, append the **first** character in `word1` to `merge` and delete it from `word1`.

      - For example, if `word1 = "abc" `and `merge = "dv"`, then after choosing this operation, `word1 = "bc"` and `merge = "dva"`.
- If `word2` is non-empty, append the **first** character in `word2` to `merge` and delete it from `word2`.

    - For example, if `word2 = "abc" `and `merge = ""`, then after choosing this operation, `word2 = "bc"` and `merge = "a"`.

Return *the lexicographically **largest*** `merge` *you can construct*.

A string `a` is lexicographically larger than a string `b` (of the same length) if in the first position where `a` and `b` differ, `a` has a character strictly larger than the corresponding character in `b`. For example, `"abcd"` is lexicographically larger than `"abcc"` because the first position they differ is at the fourth character, and `d` is greater than `c`.

 

**Example 1:**

```
Input: word1 = "cabaa", word2 = "bcaaa"
Output: "cbcabaaaaa"
Explanation: One way to get the lexicographically largest merge is:
- Take from word1: merge = "c", word1 = "abaa", word2 = "bcaaa"
- Take from word2: merge = "cb", word1 = "abaa", word2 = "caaa"
- Take from word2: merge = "cbc", word1 = "abaa", word2 = "aaa"
- Take from word1: merge = "cbca", word1 = "baa", word2 = "aaa"
- Take from word1: merge = "cbcab", word1 = "aa", word2 = "aaa"
- Append the remaining 5 a's from word1 and word2 at the end of merge.
```

**Example 2:**

```
Input: word1 = "abcabc", word2 = "abdcaba"
Output: "abdcabcabcaba"
```

 

**Constraints:**

- `1 <= word1.length, word2.length <= 3000`
- `word1` and `word2` consist only of lowercase English letters.

### Solution

``` cpp
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int len2 = word2.length(), pos2 = 0;
        int len1 = word1.length(), pos1 = 0;
        string answer;
        while(pos1 < len1 && pos2 < len2) {
            if(word1.substr(pos1) < word2.substr(pos2)) {
                answer.push_back(word2[pos2++]);
            } else {
                answer.push_back(word1[pos1++]);
            }
        }
        while(pos1 < len1) answer.push_back(word1[pos1++]);
        while(pos2 < len2) answer.push_back(word2[pos2++]);
        return answer;
    }
};
```

## 1755. Closest Subsequence Sum

You are given an integer array `nums` and an integer `goal`.

You want to choose a subsequence of `nums` such that the sum of its elements is the closest possible to `goal`. That is, if the sum of the subsequence's elements is `sum`, then you want to **minimize the absolute difference** `abs(sum - goal)`.

Return *the **minimum** possible value of* `abs(sum - goal)`.

Note that a subsequence of an array is an array formed by removing some elements **(possibly all or none)** of the original array.

 

**Example 1:**

```
Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.
```

**Example 2:**

```
Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
```

**Example 3:**

```
Input: nums = [1,2,3], goal = -7
Output: 7
```

 

**Constraints:**

- `1 <= nums.length <= 40`
- $-10^7 \le nums[i] \le 10^7$
- $-10^9 \le goal \le 10^9$

### Solution

enumeration with binary search

``` cpp
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int answer = INT_MAX / 2;
        int len = nums.size();
        int l = len / 2;
        int r = len - l;
        vector<int> vl;
        for(int i = 0; answer && i < (1<<l); ++i) {
            int s = 0;
            for(int j = 0; (1 << j) <= i; ++j) {
                if(i&(1<<j)) s += nums[j];
            }
            answer = min(answer, abs(goal-s));
            vl.push_back(s);
        }
        sort(vl.begin(), vl.end());
        auto it = unique(vl.begin(), vl.end());
        int lenl = it - vl.begin();
        vl.resize(lenl);        
        
        for(int i = 0; answer && i < (1<<r); ++i) {
            int s = 0;
            for(int j = 0; (1 << j) <= i; ++j) {
                if(i&(1<<j)) s += nums[l+j];
            }
            answer = min(answer, abs(goal-s));
            int diff = goal - s;
            int pos = lower_bound(vl.begin(), vl.end(), diff) - vl.begin();
            for(int j = max(0, pos-1); j < min(pos+2, lenl); ++j) {
                answer = min(answer, abs(vl[j] + s - goal));
            }
        }
        
        return answer;
    }
};
```