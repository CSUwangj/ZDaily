+++
title = "2021-02-16 Daily-Challenge"
path = "2021-02-16-Daily-Challenge"
date = 2021-02-16 18:00:09+08:00
updated = 2021-02-16 18:11:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3642/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge16

**Letter Case Permutation**

## Description

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return *a list of all possible strings we could create*. You can return the output in **any order**.

 

**Example 1:**

```
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
```

**Example 2:**

```
Input: S = "3z4"
Output: ["3z4","3Z4"]
```

**Example 3:**

```
Input: S = "12345"
Output: ["12345"]
```

**Example 4:**

```
Input: S = "0"
Output: ["0"]
```

 

**Constraints:**

- `S` will be a string with length between `1` and `12`.
- `S` will consist only of letters or digits.

## Solution

``` cpp
class Solution {
    int len;
    void dfs(vector<string> &answer, string &S, int pos) {
        if(pos == len) {
            answer.push_back(S);
            return;
        }
        if(!isalpha(S[pos])) {
            dfs(answer, S, pos + 1);
            return;
        }
        S[pos] = tolower(S[pos]);
        dfs(answer, S, pos + 1);
        S[pos] = toupper(S[pos]);
        dfs(answer, S, pos + 1);
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> answer;
        len = S.length();
        dfs(answer, S, 0);
        
        return move(answer);
    }
};
```