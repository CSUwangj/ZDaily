+++
updated = 2022-05-06 18:58:00+08:00
title = "2022-05-06 Daily-Challenge"
path = "2022-05-06-Daily-Challenge"
date = 2022-05-06 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 6

## Description

**Remove All Adjacent Duplicates in String II**

You are given a string `s` and an integer `k`, a `k` **duplicate removal** consists of choosing `k` adjacent and equal letters from `s` and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` **duplicate removals** on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

**Example 1:**

```
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
```

**Example 2:**

```
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
```

**Example 3:**

```
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `2 <= k <= 10^4`
- `s` only contains lower case English letters.

## Solution

``` cpp
class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st;
    for(auto c : s) {
      if(st.empty() || st.back().first != c) {
        st.push_back(make_pair(c, 1));
      } else {
        st.back().second += 1;
        if(st.back().second == k) st.pop_back();
      }
    }
    string answer;
    for(auto [c, cnt] : st) {
      for(int i = 0; i < cnt; ++i) answer.push_back(c);
    }
    return answer;
  }
};

// Accepted
// 20/20 cases passed (25 ms)
// Your runtime beats 68.41 % of cpp submissions
// Your memory usage beats 54.02 % of cpp submissions (10.6 MB)
```
