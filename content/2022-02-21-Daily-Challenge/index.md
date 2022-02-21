+++
title = "2022-02-21 Daily-Challenge"
path = "2022-02-21-Daily-Challenge"
date = 2022-02-21 08:14:00+08:00
updated = 2022-02-21 08:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/majority-element/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 21

## Description

**Majority Element**

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

 

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

 

**Constraints:**

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int answer = !nums.front();
    int count = 0;
    for(auto n : nums) {
      if(answer == n) {
        count += 1;
      } else {
        if(!count) {
          answer = n;
        } else {
          count -= 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 47/47 cases passed (20 ms)
// Your runtime beats 77.76 % of cpp submissions
// Your memory usage beats 52.27 % of cpp submissions (19.7 MB)
```
