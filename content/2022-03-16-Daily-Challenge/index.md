+++
updated = 2022-03-16 18:18:00+08:00
title = "2022-03-16 Daily-Challenge"
path = "2022-03-16-Daily-Challenge"
date = 2022-03-16 18:17:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/validate-stack-sequences/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 16

## Description

**Validate Stack Sequences**

Given two integer arrays `pushed` and `popped` each with distinct values, return `true` *if this could have been the result of a sequence of push and pop operations on an initially empty stack, or* `false` *otherwise.*

 

**Example 1:**

```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

**Example 2:**

```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

 

**Constraints:**

- `1 <= pushed.length <= 1000`
- `0 <= pushed[i] <= 1000`
- All the elements of `pushed` are **unique**.
- `popped.length == pushed.length`
- `popped` is a permutation of `pushed`.

## Solution

``` cpp
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> st;
    int pos = 0;
    int len = pushed.size();
    for(int i = 0; i < len; ++i) {
      while(pos < len && (st.empty() || st.back() != popped[i])) {
        st.push_back(pushed[pos]);
        pos += 1;
      }
      if(st.back() != popped[i]) return false;;
      st.pop_back();
    }
    return true;
  }
};

// Accepted
// 151/151 cases passed (4 ms)
// Your runtime beats 97.31 % of cpp submissions
// Your memory usage beats 59.16 % of cpp submissions (15.4 MB)
```
