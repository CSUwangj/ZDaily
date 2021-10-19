+++
title = "2021-10-19 Daily-Challenge"
path = "2021-10-19-Daily-Challenge"
date = 2021-10-19 19:40:13+08:00
updated = 2021-10-19 19:46:27+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/next-greater-element-i/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 19

## Description

**Next Greater Element I**

The **next greater element** of some element `x` in an array is the **first greater** element that is **to the right** of `x` in the same array.

You are given two **distinct 0-indexed** integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return *an array* `ans` *of length* `nums1.length` *such that* `ans[i]` *is the **next greater element** as described above.*

 

**Example 1:**

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
```

**Example 2:**

```
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
```

 

**Constraints:**

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 104`
- All integers in `nums1` and `nums2` are **unique**.
- All the integers of `nums1` also appear in `nums2`.

 

**Follow up:** Could you find an `O(nums1.length + nums2.length)` solution?

## Solution

``` cpp
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    vector<int> monoStack;
    for(auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
      while(monoStack.size() && monoStack.back() <= *it) monoStack.pop_back();
      nextGreater[*it] = monoStack.size() ? monoStack.back() : -1;
      monoStack.push_back(*it);
    }
    vector<int> answer(nums1.size());
    for(int i = 0; i < nums1.size(); ++i) {
      answer[i] = nextGreater[nums1[i]];
    }
    return answer;
  }
};

// Accepted
// 15/15 cases passed (10 ms)
// Your runtime beats 33.18 % of cpp submissions
// Your memory usage beats 58.15 % of cpp submissions (8.8 MB)
```
