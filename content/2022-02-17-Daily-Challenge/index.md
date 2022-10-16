+++
title = "2022-02-17 Daily-Challenge"
path = "2022-02-17-Daily-Challenge"
date = 2022-02-17 11:35:00+08:00
updated = 2022-02-17 11:40:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/combination-sum/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 17

## Description

**Combination Sum**

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of* `candidates` *where the chosen numbers sum to* `target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
Input: candidates = [2], target = 1
Output: []
```

 

**Constraints:**

- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 200`
- All elements of `candidates` are **distinct**.
- `1 <= target <= 500`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    vector<int> &candidates,
    int index,
    int rest
  ) {
    if(!rest) {
      answer.push_back(tmp);
      return;
    }
    if(index == candidates.size()) return;
    int curSize = tmp.size();
    while(rest >= 0) {
      solve(answer, tmp, candidates, index + 1, rest);
      rest -= candidates[index];
      tmp.push_back(candidates[index]);
    }
    while(curSize < tmp.size()) tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, candidates, 0, target);
    return answer;
  }
};

// Accepted
// 170/170 cases passed (6 ms)
// Your runtime beats 80.84 % of cpp submissions
// Your memory usage beats 46.83 % of cpp submissions (11.2 MB)
```
