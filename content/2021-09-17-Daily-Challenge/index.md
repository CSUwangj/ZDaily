+++
title = "2021-09-17 Daily-Challenge"
path = "2021-09-17-Daily-Challenge"
date = 2021-09-17 19:12:13+08:00
updated = 2021-09-17 19:27:15+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3978/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 17

## Description

**Intersection of Two Arrays II**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

 

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

 

**Constraints:**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

 

**Follow up:**

- What if the given array is already sorted? How would you optimize your algorithm?
- What if `nums1`'s size is small compared to `nums2`'s size? Which algorithm is better?
- What if elements of `nums2` are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

## Solution

``` cpp
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> answer;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end() && it2 != nums2.end()) {
      if(*it1 == *it2) {
        answer.push_back(*it1);
        ++it1;
        ++it2;
      } else if(*it1 < *it2) {
        ++it1;
      } else {
        ++it2;
      }
    }

    return answer;
  }
};

// Accepted
// 55/55 cases passed (3 ms)
// Your runtime beats 91.05 % of cpp submissions
// Your memory usage beats 88.6 % of cpp submissions (9.9 MB)
```
