+++
updated = 2022-09-15 18:14:00+08:00
title = "2022-09-15 Daily-Challenge"
path = "2022-09-15-Daily-Challenge"
date = 2022-09-15 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/find-original-array-from-doubled-array/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 15

## Description

**Find Original Array From Doubled Array**

An integer array `original` is transformed into a **doubled** array `changed` by appending **twice the value** of every element in `original`, and then randomly **shuffling** the resulting array.

Given an array `changed`, return `original` *if* `changed` *is a **doubled** array. If* `changed` *is not a **doubled** array, return an empty array. The elements in* `original` *may be returned in **any** order*.

 

**Example 1:**

```
Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
```

**Example 2:**

```
Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
```

**Example 3:**

```
Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
```

 

**Constraints:**

- `1 <= changed.length <= 10^5`
- `0 <= changed[i] <= 10^5`

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
  vector<int> findOriginalArray(vector<int>& changed) {
    if(changed.size() & 1) return {};
    sort(changed.begin(), changed.end());
    int count[100010] = {};
    vector<int> answer;
    for(auto i : changed) {
      if(count[i] == 0) {
        if(i > 50000) return {};
        count[i * 2] -= 1;
      } else {
        count[i] += 1;
        answer.push_back(i / 2);
      }
    }
    for(int i = 0; i < 100001; ++i) {
      if(count[i]) return {};
    }
    return answer;
  }
};

// Accepted
// 178/178 cases passed (245 ms)
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 96.70 % of cpp submissions (117.8 MB)
```
