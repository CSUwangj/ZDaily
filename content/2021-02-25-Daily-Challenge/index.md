+++
title = "2021-02-25 Daily-Challenge"
path = "2021-02-25-Daily-Challenge"
date = 2021-02-25 18:32:36+08:00
updated = 2021-02-25 18:47:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3651/) with `cpp`.

<!-- more -->

# Smallest Subsequence of Distinct Characters

## Description

Return the lexicographically smallest subsequence of `s` that contains all the distinct characters of `s` exactly once.

**Note:** This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/

 

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of lowercase English letters.

## Solution

greedily pick character, if it's ok to remove last character of answer(when there is still same character after this turn), then remove the last character that is larger than current character.

``` cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        vector<bool> used(26);
        for(auto c : s) cnt[c - 'a'] += 1;
        string answer;
        
        for(auto c : s) {
            if(used[c - 'a']) {
                cnt[c - 'a'] -= 1;
                continue;
            }
            while(answer.length() && answer.back() > c && cnt[answer.back() - 'a']) {
                used[answer.back() - 'a'] = false;
                answer.pop_back();
            }
            answer.push_back(c);
            used[c - 'a'] = true;
            cnt[c - 'a'] -= 1;
        }
        return answer;
    }
};
```

# February LeetCoding Challenge 25

## Description

**Shortest Unsorted Continuous Subarray**

Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return *the shortest such subarray and output its length*.

 

**Example 1:**

```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
```

**Example 3:**

```
Input: nums = [1]
Output: 0
```

 

**Constraints:**

- $1 \le nums.length \le 10^4$
- $-10^5 \le nums[i] \le 10^5$

 

**Follow up:** Can you solve it in `O(n)` time complexity?

## Solution

best algorithm, but code is not good enough

``` cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int wrongLess = -1;
        for(int i = 1; i < len; ++i) {
            if(nums[i] < nums[i - 1]) {
                wrongLess = i - 1;
                break;
            }
        }
        if(wrongLess == -1) return 0;
        int wrongGreater = -1;
        for(int i = len - 2; i >= 0; --i) {
            if(nums[i] > nums[i + 1]) {
                wrongGreater = i + 1;
                break;
            }
        }
        int minPos = wrongLess;
        int maxPos = wrongGreater;
        for(int i = min(wrongLess, wrongGreater); i <= max(wrongLess, wrongGreater); ++i) {
            if(nums[i] < nums[minPos]) minPos = i;
            if(nums[i] > nums[maxPos]) maxPos = i;
        }
        int begin = 0;
        while(nums[begin] <= nums[minPos]) begin += 1;
        int end = len - 1;
        while(nums[end] >= nums[maxPos]) end -= 1;
        return end - begin + 1;
    }
};
```
