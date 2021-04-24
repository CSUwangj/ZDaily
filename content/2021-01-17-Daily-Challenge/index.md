+++
title = "2021-01-17 Daily-Challenge"
path = "2021-01-17-Daily-Challenge"
date = 2021-01-17 16:00:07+08:00
updated = 2021-01-17 20:32:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3607/) with `cpp`.

<!-- more -->

# LeetCode Review

## Kth Largest Element in an Array

handwritting three-way quicksort's partition

``` cpp
class Solution {
    int KthLargest(vector<int>& nums, int begin, int len, int k) {
        if(len <= 1) return nums[begin];
        const int pivot = nums[begin + rand()%len];
        int front = begin, index = begin, back = begin+len;
        while(index < back) {
            if(nums[index] < pivot) {
                swap(nums[index], nums[front]);
                index += 1;
                front += 1;
            } else if(nums[index] > pivot) {
                back -= 1;
                swap(nums[index], nums[back]);
            } else {
                index += 1;
            }
        }
        cout << pivot << ": " << front << ' ' << back << endl;
        for(auto i : nums) cout << i << ' ';
        cout << endl;
        if(front >= k) return KthLargest(nums, begin, front-begin, k);
        else if (back < k) return KthLargest(nums, back, begin+len-back, k);
        return pivot;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return KthLargest(nums, 0, len, len-k+1);
    }
};
```

# January LeetCoding Challenge17

## Description

**Count Sorted Vowel Strings**

Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`*) and are **lexicographically sorted**.*

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.

 

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

**Example 2:**

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

**Example 3:**

```
Input: n = 33
Output: 66045
```

 

**Constraints:**

- `1 <= n <= 50` 

## Solution

simple DP

``` cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < 5; ++j) dp[j] += dp[j-1];
        }
        int answer = 0;
        for(int i = 0; i < 5; ++i) answer += dp[i];
        return answer;
    }
};
```
