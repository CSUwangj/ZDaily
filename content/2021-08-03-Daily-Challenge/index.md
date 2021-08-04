+++
title = "2021-08-03 Daily-Challenge"
path = "2021-08-03-Daily-Challenge"
date = 2021-08-03 18:02:12+08:00
updated = 2021-08-03 18:18:34+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Magical String](https://leetcode.com/problems/magical-string/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3837/) with `cpp`.

<!-- more -->

# Magical String

## Description

A magical string `s` consists of only `'1'` and `'2'` and obeys the following rules:

- The string s is magical because concatenating the number of contiguous occurrences of characters `'1'` and `'2'` generates the string `s` itself.

The first few elements of `s` is `s = "1221121221221121122……"`. If we group the consecutive `1`'s and `2`'s in s, it will be `"1 22 11 2 1 22 1 22 11 2 11 22 ......"` and the occurrences of `1`'s or `2`'s in each group are `"1 2 2 1 1 2 1 2 2 1 2 2 ......"`. You can see that the occurrence sequence is `s` itself.

Given an integer `n`, return the number of `1`'s in the first `n` number in the magical string `s`.

 

**Example 1:**

```
Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "12211" and it contains three 1's, so return 3.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

 

**Constraints:**

- `1 <= n <= 105`

## Solution

``` cpp
int result[100001] = {1};
auto speedup = [](){
  int n = 100000;
  int pos = 2;
  int end = 3;
  bool isTwo = false;
  while(end < n) {
    if(isTwo) {
      end += 2 - result[pos];
    } else {
      result[end++] = true;
      if(!result[pos]) result[end++] = true;
    }
    isTwo = !isTwo;
    pos += 1;
  }
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int magicalString(int n) {
    return accumulate(result, result + n, 0);
  }
};

// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.78 % of cpp submissions (6.6 MB)
```

# August LeetCoding Challenge 3

## Description

**Subsets II**

Given an integer array `nums` that may contain duplicates, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

 

**Example 1:**

```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

 

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int len;
  void solve(
    vector<vector<int>> &answer,
    vector<int> &container,
    vector<int>& nums,
    int begin
  ) {
    if(begin == len) {
      answer.push_back(container);
      return;
    }
    int end = begin + 1;
    while(end < len && nums[end] == nums[end - 1]) end += 1;
    solve(answer, container, nums, end);
    for(int i = begin; i < end; ++i) {
      container.push_back(nums[begin]);
      solve(answer, container, nums, end);
    }
    for(int i = begin; i < end; ++i) {
      container.pop_back();
    }
  }
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    len = nums.size();
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, nums, 0);
    return answer;
  }
};

// Accepted
// 19/19 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 24.23 % of cpp submissions (11.6 MB)
```