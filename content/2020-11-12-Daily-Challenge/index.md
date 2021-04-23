+++
title = "2020-11-12 Daily-Challenge"
path = "2020-11-12-Daily-Challenge"
date = 2020-11-12 09:44:45+08:00
updated = 2020-11-12 20:14:58+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Student Attendance Record I* on [leetcode](https://leetcode.com/problems/student-attendance-record-i/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3528/) with `cpp`.

<!-- more -->

# Student Attendance Record I

## Description

You are given a string representing an attendance record for a student. The record only contains the following three characters:

1. **'A'** : Absent.
2. **'L'** : Late.
3. **'P'** : Present.

A student could be rewarded if his attendance record doesn't contain **more than one 'A' (absent)** or **more than two continuous 'L' (late)**.

You need to return whether the student could be rewarded according to his attendance record.

**Example 1:**

```
Input: "PPALLP"
Output: True
```

**Example 2:**

```
Input: "PPALLL"
Output: False
```

## Solution

nothing to say

``` cpp
class Solution {
public:
    bool checkRecord(string s) {
        int aCnt = 0, continousLCnt = 0;
        for(auto c : s) {
            if(c == 'L') {
                continousLCnt += 1;
                if(continousLCnt > 2) return false;
                continue;
            }
            continousLCnt = 0;
            if(c == 'A') {
                aCnt += 1;
                if(aCnt > 1) return false;
            }
        }
        return true;
    }
};
```

# November LeetCoding Challenge12

## Description

**Permutations II**

## Description

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Constraints:**

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

## Solution

nothing to say

``` cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        do{
            answer.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return answer;
    }
};
```
