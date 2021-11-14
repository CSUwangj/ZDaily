+++
title = "2021-11-13 Daily-Challenge"
path = "2021-11-13-Daily-Challenge"
date = 2021-11-13 14:16:44+08:00
updated = 2021-11-13 14:59:33+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/remove-linked-list-elements/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 13

## Description

**Remove Linked List Elements**

Given an array of integers `temperatures` represents the daily temperatures, return *an array* `answer` *such that* `answer[i]` *is the number of days you have to wait after the* `ith` *day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

 

**Example 1:**

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Example 2:**

```
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

**Example 3:**

```
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

 

**Constraints:**

- `1 <= temperatures.length <= 105`
- `30 <= temperatures[i] <= 100`

## Solution

crab leetcode extension...

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> monoStack;
    int len = temperatures.size();
    vector<int> answer(len);
    for(int i = len - 1; i >= 0; --i) {
      while(monoStack.size() && temperatures[monoStack.back()] <= temperatures[i]) {
        monoStack.pop_back();
      }
      if(monoStack.size()) answer[i] = monoStack.back() - i;
      monoStack.push_back(i);
    }
    return answer;
  }
};

// Runtime: 96 ms, faster than 99.78% of C++ online submissions for Daily Temperatures.
// Memory Usage: 85 MB, less than 95.98% of C++ online submissions for Daily Temperatures.
```
