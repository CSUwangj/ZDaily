+++
title = "2021-01-03 Daily-Challenge"
path = "2021-01-03-Daily-Challenge"
date = 2021-01-03 16:24:46+08:00
updated = 2021-01-03 22:10:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3591/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge3

## Description

**Beautiful Arrangement**

## Description

Suppose you have `n` integers from `1` to `n`. We define a beautiful arrangement as an array that is constructed by these `n` numbers successfully if one of the following is true for the `ith` position (`1 <= i <= n`) in this array:

- The number at the `ith` position is divisible by `i`.
- `i` is divisible by the number at the `ith` position.

Given an integer `n`, return *the number of the beautiful arrangements that you can construct*.

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1, 2]:
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
The second beautiful arrangement is [2, 1]:
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

**Constraints:**

- `1 <= n <= 15`

## Solution

simple dfs

``` cpp
class Solution {
    int answer;
    int n;
    vector<bool> used;
    void dfs(int index) {
        if(index == n+1) {
            answer += 1;
            return;
        }
        for(int i = 1; i <= n; ++i) {
            if(!used[i] && (i % index == 0 || index % i == 0)) {
                // cout << i << ' ' << index << endl;
                used[i] = true;
                dfs(index + 1);
                used[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        this->n = n;
        answer = 0;
        used.resize(n+1);
        dfs(1);
        return answer;
    }
};
```
