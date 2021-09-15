+++
title = "2021-09-15 Daily-Challenge"
path = "2021-09-15-Daily-Challenge"
date = 2021-09-15 20:33:44+08:00
updated = 2021-09-15 20:54:57+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 15

## Description

**Longest Turbulent Subarray**

Given an integer array `arr`, return *the length of a maximum size turbulent subarray of* `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if and only if:

- For `i <= k < j`:
  - `arr[k] > arr[k + 1]` when `k` is odd, and
  - `arr[k] < arr[k + 1]` when `k` is even.
- Or, for `i <= k < j`:
  - `arr[k] > arr[k + 1]` when `k` is even, and
  - `arr[k] < arr[k + 1]` when `k` is odd.

**Example 1:**

```
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
```

**Example 2:**

```
Input: arr = [4,8,12,16]
Output: 2
```

**Example 3:**

```
Input: arr = [100]
Output: 1
```

 

**Constraints:**

- `1 <= arr.length <= 4 * 10^4`
- `0 <= arr[i] <= 10^9`

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
  int maxTurbulenceSize(vector<int>& arr) {
    int len = arr.size();
    if(len == 1) return 1;
    int count = 1 + (arr[0] != arr[1]);
    int answer = count;
    for(int i = 1; i < len - 1; ++i) {
      if((arr[i + 1] > arr[i] && arr[i] < arr[i - 1]) ||
         (arr[i + 1] < arr[i] && arr[i] > arr[i - 1])) {
        count += 1;
      } else {
        count = 1 + (arr[i] != arr[i + 1]);
      }
      answer = max(answer, count);
    }

    return answer;
  }
};

// Accepted
// 89/89 cases passed (32 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.59 % of cpp submissions (40.1 MB)
```
