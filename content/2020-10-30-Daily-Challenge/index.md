+++
title = "2020-10-30 Daily-Challenge"
path = "2020-10-30-Daily-Challenge"
date = 2020-10-30 00:04:07+08:00
updated = 2020-10-30 20:33:37+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Find the Closest Palindrome* on [leetcode](https://leetcode.com/problems/find-the-closest-palindrome/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3513/) with `cpp`.

<!-- more -->

# Find the Closest Palindrome

## Description

Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

**Example 1:**

```
Input: "123"
Output: "121"
```

**Note:**

1. The input **n** is a positive integer represented by string, whose length will not exceed 18.
2. If there is a tie, return the smaller one as answer.

## Solution

very ugly solution...

first I cut the number into two parts and take the first part(which is not less than second part), make it a palindrome number, minus one and make result a palindrome number, add one and make result a palindrome number.

I think this solution is kind of ugly because code looks terrible...

``` cpp
class Solution {
  long long makePalindrom(long long n, bool odd) {
    long long tmp = n;
    if(odd) tmp /= 10;
    while(tmp) {
      n *= 10;
      n += tmp % 10;
      tmp /= 10;
    }
    return n;
  }
public:
  string nearestPalindromic(string n) {
    if(n == "10" || n == "11") return "9";
    int len = n.length();
    long long n_half = stoll(string(n.begin(), n.begin()+(len+1)/2));
    bool odd_length = len&1;
    long long middle = makePalindrom(n_half, odd_length);
    long long n_num = stoll(n);
    long long min_difference = LONG_LONG_MAX;
    vector<long long> candidates;
    long long less_num = makePalindrom(n_half-1, odd_length);
    if(less_num && LONG_LONG_MAX/10 > less_num && less_num * 10 < n_num) less_num = less_num*10+9;
    candidates.push_back(less_num);
    min_difference = min(min_difference, n_num-less_num);
    if(middle != n_num) {
      candidates.push_back(middle);
      min_difference = min(min_difference, abs(middle - n_num));
    }
    long long more_num = makePalindrom(n_half+1, odd_length);
    if(LONG_LONG_MAX/10 > n_num && n_num * 10 < more_num) more_num = more_num/10+1;
    candidates.push_back(more_num);
    min_difference = min(min_difference, more_num-n_num);
    for(auto candidate : candidates) {
      if(abs(candidate - n_num) == min_difference) return to_string(candidate);
    }
    return "WTF";
  }
};
```

# October LeetCoding Challenge30

## Description

**Number of Longest Increasing Subsequence**

## Description

Given an integer array `nums`, return *the number of longest increasing subsequences.*

**Example 1:**

```
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
```

**Example 2:**

```
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
```

**Constraints:**

- `0 <= nums.length <= 2000`
- `-106 <= nums[i] <= 106`

## Solution

haven't find a way to solve this problem in O(nlogn) time complexity.

``` cpp
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> dp(nums.size(), 1), ways(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j]) {
          if(dp[j]+1 > dp[i]) {
            dp[i] = dp[j]+1;
            ways[i] = ways[j];
          } else if(dp[j]+1 == dp[i]) {
            ways[i] += ways[j];
          }
        }
      }
    }
    int LISLength = *max_element(dp.begin(), dp.end()), ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(dp[i] == LISLength) ans += ways[i];
    }
    return ans;
  }
};
```
