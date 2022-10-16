+++
title = "2021-12-20 Daily-Challenge"
path = "2021-12-20-Daily-Challenge"
date = 2021-12-20 18:20:00+08:00
updated = 2021-12-20 18:37:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/minimum-absolute-difference/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 20

## Description

**Minimum Absolute Difference**

Given an array of **distinct** integers `arr`, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair `[a, b]` follows

- `a, b` are from `arr`
- `a < b`
- `b - a` equals to the minimum absolute difference of any two elements in `arr`

 

**Example 1:**

```
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
```

**Example 2:**

```
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
```

**Example 3:**

```
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
```

 

**Constraints:**

- `2 <= arr.length <= 10^5`
- `-10^6 <= arr[i] <= 10^6`

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
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int minDiff = INT_MAX;
    for(int i = 1; i < len; ++i) {
      minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }

    vector<vector<int>> answer;
    for(int i = 1; i < len; ++i) {
      if(arr[i] - arr[i - 1] == minDiff) {
        answer.push_back({arr[i - 1], arr[i]});
      }
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (36 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.65 % of cpp submissions (32.2 MB)
```
