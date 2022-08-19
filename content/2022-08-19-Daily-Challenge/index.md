+++
updated = 2022-08-19 18:14:00+08:00
title = "2022-08-19 Daily-Challenge"
path = "2022-08-19-Daily-Challenge"
date = 2022-08-19 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 19

## Description

**Split Array into Consecutive Subsequences**

​You are given an integer array `nums` that is **sorted in non-decreasing order**.

Determine if it is possible to split `nums` into **one or more subsequences** such that **both** of the following conditions are true:

- Each subsequence is a **consecutive increasing sequence** (i.e. each integer is **exactly one** more than the previous integer).
- All subsequences have a length of `3` **or more**.

Return `true` *if you can split* `nums` *according to the above conditions, or* `false` *otherwise*.

A **subsequence** of an array is a new array that is  formed from the original array by deleting some (can be none) of the  elements without disturbing the relative positions of the remaining  elements. (i.e., `[1,3,5]` is a subsequence of `[1,2,3,4,5]` while `[1,3,2]` is not).

 

**Example 1:**

```
Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
```

**Example 2:**

```
Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5
```

**Example 3:**

```
Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
```

 

**Constraints:**

- `1 <= nums.length <= 104`
- `-1000 <= nums[i] <= 1000`
- `nums` is sorted in **non-decreasing** order.

## Solution

``` cpp
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    map<int, int> not_placed;
    map<int, int> end_with;
    for(auto n : nums) {
      not_placed[n] += 1;
    }

    for(auto n : nums) {
      if(!not_placed[n]) continue;
      not_placed[n] -= 1;
      if(end_with[n - 1]) {
        end_with[n - 1] -= 1;
        end_with[n] += 1;
      } else if(not_placed[n + 1] && not_placed[n + 2]) {
        not_placed[n + 1] -= 1;
        not_placed[n + 2] -= 1;
        end_with[n + 2] += 1;
      } else {
        return false;
      }
    }

    return true;
  }
};

// Accepted
// 186/186 cases passed (180 ms)
// Your runtime beats 43.45 % of cpp submissions
// Your memory usage beats 17.83 % of cpp submissions (59.2 MB)
```
