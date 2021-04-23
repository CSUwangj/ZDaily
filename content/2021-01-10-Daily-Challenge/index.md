+++
title = "2021-01-10 Daily-Challenge"
path = "2021-01-10-Daily-Challenge"
date = 2021-01-10 16:25:32+08:00
updated = 2021-01-10 17:34:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3599/) with `cpp`.

<!-- more -->

# LeetCode Review

## Word Ladder

bidirectional BFS

``` cpp
class Solution {
    unordered_set<string> dictionary;
    int len;
    int BBFS(
        unordered_set<string> &sourceSet,
        unordered_set<string> &targetSet,
        int length
    ) {
        unordered_set<string> newSourceSet;
        
        for(auto &s : sourceSet) dictionary.erase(s);
        
        for(auto &s : sourceSet) {
            for(int i = 0; i < len ; ++i) {
                string newWord = s;
                for(char c = 'a'; c <= 'z'; ++c) {
                    newWord[i] = c;
                    if(targetSet.count(newWord)) return length+1;
                    if(dictionary.count(newWord)) newSourceSet.insert(newWord);
                }
            }
        }
        if(!newSourceSet.size()) return 0;
        
        if(newSourceSet.size() < targetSet.size()) return BBFS(newSourceSet, targetSet, length+1);
        return BBFS(targetSet, newSourceSet, length+1);
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        len = endWord.length();
        for(auto &s : wordList) if(s.length() == len) dictionary.insert(s);
        if(!dictionary.count(endWord)) return 0;
        
        unordered_set<string> beginSet;
        beginSet.insert(beginWord);
        unordered_set<string> endSet;
        endSet.insert(endWord);
        
        return BBFS(beginSet, endSet, 1);
    }
};
```

# January LeetCoding Challenge10

## Description

**Create Sorted Array through Instructions**

## Description

Given an integer array `instructions`, you are asked to create a sorted array from the elements in `instructions`. You start with an empty container `nums`. For each element from **left to right** in `instructions`, insert it into `nums`. The **cost** of each insertion is the **minimum** of the following:

- The number of elements currently in `nums` that are **strictly less than** `instructions[i]`.
- The number of elements currently in `nums` that are **strictly greater than** `instructions[i]`.

For example, if inserting element `3` into `nums = [1,2,3,5]`, the **cost** of insertion is `min(2, 1)` (elements `1` and `2` are less than `3`, element `5` is greater than `3`) and `nums` will become `[1,2,3,3,5]`.

Return *the **total cost** to insert all elements from* `instructions` *into* `nums`. Since the answer may be large, return it **modulo** `109 + 7`

 

**Example 1:**

```
Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.
```

**Example 2:**

```
Input: instructions = [1,2,3,6,5,4]
Output: 3
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
```

**Example 3:**

```
Input: instructions = [1,3,3,3,2,4,2,1,2]
Output: 4
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].
Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.
```

 

**Constraints:**

- `1 <= instructions.length <= 105`
- `1 <= instructions[i] <= 105`

## Solution

Binary Indexed Tree

``` cpp
class Solution {
    int BIT[100100] = {0};
    const int SZ = 1e5;
    const int MOD = 1e9 + 7;
    int lowbit(int x) { return x&(-x); };
    
    void add(int x) {
        while(x < SZ) {
            BIT[x] += 1;
            x += lowbit(x);
        }
    }
    
    int sum(int x) {
        int sum = 0;
        while(x) {
            sum += BIT[x];
            x -= lowbit(x);
        }
        return sum;
    }
public:
    int createSortedArray(vector<int>& instructions) {
        int answer = 0;
        int len = instructions.size();
        for(int i = 0; i < len; ++i) {
            int less = sum(instructions[i]-1);
            int cnt = sum(instructions[i]);
            add(instructions[i]);
            answer += min(less, i-cnt);
            answer %= MOD;
        }
        return answer;
    }
};
```
