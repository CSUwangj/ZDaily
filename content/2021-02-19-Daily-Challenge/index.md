+++
title = "2021-02-19 Daily-Challenge"
path = "2021-02-19-Daily-Challenge"
date = 2021-02-19 17:20:53+08:00
updated = 2021-02-19 17:26:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3645/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge19

## Description

**Minimum Remove to Make Valid Parentheses**

## Description

Given a string s of `'('` , `')'` and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

 

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Example 4:**

```
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is one of `'('` , `')'` and lowercase English letters`.`

## Solution

``` cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        
        vector<int> st;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ')') {
                if(st.size()) st.pop_back();
                else s[i] = 0;
            } else if(s[i] == '(') st.push_back(i);
        }
        while(st.size()) {
            s[st.back()] = 0;
            st.pop_back();
        }
        
        string answer;
        for(auto c : s) if(c) answer.push_back(c);
        return answer;
    }
};
```