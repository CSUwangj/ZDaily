+++
title = "2022-02-13 Daily-Challenge"
path = "2022-02-13-Daily-Challenge"
date = 2022-02-13 12:55:00+08:00
updated = 2022-02-13 12:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/subsets/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 13

## Description

**Subsets**

Given an integer array `nums` of **unique** elements, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

 

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size();
    int sz = (1 << len);
    vector<vector<int>> answer;
    for(int i = 0; i < sz; ++i) {
      vector<int> st;
      for(int b = 0; b < len; ++b) {
        if(i & (1 << b)) st.push_back(nums[b]);
      }
      answer.emplace_back(move(st));
    }
    return answer;
  }
};

// Accepted
// 10/10 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.44 % of cpp submissions (7.1 MB)
```
