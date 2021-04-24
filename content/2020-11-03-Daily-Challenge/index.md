+++
title = "2020-11-03 Daily-Challenge"
path = "2020-11-03-Daily-Challenge"
date = 2020-11-03 00:33:17+08:00
updated = 2020-11-03 19:39:29+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Next Greater Element I* on [leetcode](https://leetcode.com/problems/next-greater-element-i/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3518/) with `cpp`.

<!-- more -->

# Next Greater Element I

## Description

You are given two arrays **(without duplicates)** `nums1` and `nums2` where `nums1`’s elements are subset of `nums2`. Find all the next greater numbers for `nums1`'s elements in the corresponding places of `nums2`.

The Next Greater Number of a number **x** in `nums1` is the first greater number to its right in `nums2`. If it does not exist, output -1 for this number.

**Example 1:**

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
```

**Example 2:**

```
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
```

**Note:**

1. All elements in `nums1` and `nums2` are unique.
2. The length of both `nums1` and `nums2` would not exceed 1000.

## Solution

monotonic stack

``` cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> pos;
        for(int i = 0; i < nums2.size(); ++i) {
            pos[nums2[i]] = i;
        }
        stack<int, vector<int>> monoStack;
        vector<int> nextGreaterElement(nums2.size());
        for(int i = nums2.size()-1; i >= 0; --i) {
            while(monoStack.size() && monoStack.top() <= nums2[i]) {
                monoStack.pop();
            }
            nextGreaterElement[i] = monoStack.empty() ? -1 : monoStack.top();
            monoStack.push(nums2[i]);
        }
        vector<int> ans;
        for(auto e : nums1) {
            ans.push_back(nextGreaterElement[pos[e]]);
        }
        return ans;
    }
};
```

# November LeetCoding Challenge3

## Description

**Consecutive Characters**

Given a string `s`, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return *the power* of the string.

**Example 1:**

```
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
```

**Example 2:**

```
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
```

**Example 3:**

```
Input: s = "triplepillooooow"
Output: 5
```

**Example 4:**

```
Input: s = "hooraaaaaaaaaaay"
Output: 11
```

**Example 5:**

```
Input: s = "tourist"
Output: 1
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` contains only lowercase English letters.

## Solution

nothing to say

``` cpp
class Solution {
public:
    int maxPower(string s) {
        int ans = 0, cnt = 0;
        char cur = '?';
        for(auto c : s) {
            if(c != cur) {
                ans = max(cnt, ans);
                cur = c;
                cnt = 1;
            } else {
                cnt += 1;
            }
        }
        ans = max(cnt, ans);
        return ans;
    }
};
```
