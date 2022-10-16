+++
title = "2022-02-09 Daily-Challenge"
path = "2022-02-09-Daily-Challenge"
date = 2022-02-09 19:44:00+08:00
updated = 2022-02-09 19:45:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/k-diff-pairs-in-an-array/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 9

## Description

**K-diff Pairs in an Array**

Given an array of integers `nums` and an integer `k`, return *the number of **unique** k-diff pairs in the array*.

A **k-diff** pair is an integer pair `(nums[i], nums[j])`, where the following are true:

- `0 <= i < j < nums.length`
- `|nums[i] - nums[j]| == k`

**Notice** that `|val|` denotes the absolute value of `val`.

 

**Example 1:**

```
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

**Example 3:**

```
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for(auto i : nums) {
      cnt[i] += 1;
    }

    int answer = 0;
    for(auto [i, c] : cnt) {
      if(k) answer += cnt.count(i + k);
      else answer += c > 1;
    }
    return answer;
  }
};

// Accepted
// 60/60 cases passed (11 ms)Vubmissions
// Your memory usage beats 68.98 % of cpp submissions (13.1 MB)
```
