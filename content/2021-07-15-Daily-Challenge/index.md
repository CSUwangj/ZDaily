+++
title = "2021-07-15 Daily-Challenge"
path = "2021-07-15-Daily-Challenge"
date = 2021-07-15 23:49:50+08:00
updated = 2021-07-15 18:24:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3815/) with `cpp`.

<!-- more -->

# Combination Sum II

## Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

 

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

 

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Solution

``` cpp
class Solution {
  int len;
  void dfs(
    vector<vector<int>> &answer,
    vector<int> &cur,
    vector<int> &candidates,
    int rest,
    int index
  ) {
    // cout << rest << ' ' << index << endl;
    if(!rest) {
      answer.push_back(cur);
      return;
    }
    if(index == len) return;
    for(int i = index; i < len; ++i) {
      if(candidates[i] <= rest) {
        cur.push_back(candidates[i]);
        dfs(answer, cur, candidates, rest - candidates[i], i + 1);
        cur.pop_back();
      }
    }
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    len = candidates.size();
    sort(candidates.rbegin(), candidates.rend());
    vector<vector<int>> answer;
    vector<int> tmp;
    dfs(answer, tmp, candidates, target, 0);
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};

// Accepted
// 174/174 cases passed (532 ms)
// Your runtime beats 16.38 % of cpp submissions
// Your memory usage beats 34.76 % of cpp submissions (11.6 MB)
```

# July LeetCoding Challenge 15

## Description

**Valid Triangle Number**

Given an integer array `nums`, return *the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle*.

 

**Example 1:**

```
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Example 2:**

```
Input: nums = [4,2,3,4]
Output: 4
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

## Solution

``` cpp
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int answer = 0;
    for(int i = 0; i < len - 2; i++) {
      for(int j = i + 1; j < len - 1; j++) {
        int l = nums[j] - nums[i];
        int h = nums[i] + nums[j];
        int low = upper_bound(nums.begin() + j + 1, nums.end(), l);
        int high = lower_bound(nums.begin() + j + 1, nums.end(), h);
        high -= 1;
        answer += high >= low ? high - low + 1 : 0；
      }
    }

    return answer;
  }
};


// 233 / 233 test cases passed.
// Status: Accepted
// Runtime: 968 ms
// Memory Usage: 12.9 MB
```
