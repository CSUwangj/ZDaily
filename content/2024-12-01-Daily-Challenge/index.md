+++
updated = 2024-12-01T13:00:58+08:00
title = "2024-12-01 Daily Challenge"
path = "2024-12-01-Daily-Challenge"
date = 2024-12-01T13:00:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/check-if-n-and-its-double-exist/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 1

## Description

**Check If N and Its Double Exist**

Given an array `arr` of integers, check if there exist two indices `i` and `j` such that :

- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`

 

**Example 1:**

```
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
```

**Example 2:**

```
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
```

 

**Constraints:**

- `2 <= arr.length <= 500`
- `-103 <= arr[i] <= 103`

## Solution

``` cpp
class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    map<int, int> st;
    for(auto i : arr) {
      st[i] += 1;;
    }
    for(auto i : arr) {
      if(i && st.count(i * 2)) return true;
      if(!i && st[i] > 1)return true;
    }
    return false;
  }
};
```
