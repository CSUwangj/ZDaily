+++
updated = 2022-04-06 19:49:00+08:00
title = "2022-04-06 Daily-Challenge"
path = "2022-04-06-Daily-Challenge"
date = 2022-04-06 19:47:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/3sum-with-multiplicity/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 6

## Description

**3Sum With Multiplicity**

Given an integer array `arr`, and an integer `target`, return the number of tuples `i, j, k` such that `i < j < k` and `arr[i] + arr[j] + arr[k] == target`.

As the answer can be very large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
```

**Example 2:**

```
Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
```

 

**Constraints:**

- `3 <= arr.length <= 3000`
- `0 <= arr[i] <= 100`
- `0 <= target <= 300`

## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr int pick(int total, int need) {
  if(total < need) return 0;
  long long answer = 1;
  for(int i = 1; i <= need; ++i) {
    answer *= (total + 1 - i);
    answer /= i;
    answer %= MOD;
  }
  return answer;
}

class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    map<int, int> count;
    for(auto num : arr) count[num] += 1;
    
    long long answer = 0;
    for(auto it = count.begin(); it != count.end(); ++it) {
      for(auto jt = it; jt != count.end(); ++jt) {
        int rest = target - it->first - jt->first;
        if(rest < jt->first || !count.count(rest)) continue;
        if(it->first == jt->first && it->first == rest) {
          answer += pick(it->second, 3);
        } else if(it->first == jt->first) {
          answer += pick(it->second, 2) * count[rest];
        } else if(jt->first == rest) {
          answer += pick(jt->second, 2) * it->second;
        } else {
          answer += it->second * jt->second * count[rest];
        }
        answer %= MOD;
      }
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (12 ms)
// Your runtime beats 92.78 % of cpp submissions
// Your memory usage beats 62.54 % of cpp submissions (10.6 MB)
```
