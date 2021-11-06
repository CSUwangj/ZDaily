+++
title = "2021-11-06 Daily-Challenge"
path = "2021-11-06-Daily-Challenge"
date = 2021-11-06 22:00:00+08:00
updated = 2021-11-06 22:28:02+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/arranging-coins/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 6

## Description

**Single Number III**

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

**Example 1:**

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
```

**Example 2:**

```
Input: nums = [-1,0]
Output: [-1,0]
```

**Example 3:**

```
Input: nums = [0,1]
Output: [1,0]
```


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Each integer in <code>nums</code> will appear twice, only two integers will appear once.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int lowbit = 0;
    for(auto n : nums) lowbit ^= n;
    
    if(lowbit == INT_MIN) lowbit = 1;
    else lowbit &= -lowbit;
    vector<int> answer{0, 0};
    for(auto n : nums) {
      if(n & lowbit) {
        answer[0] ^= n;
      } else {
        answer[1] ^= n;
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (8 ms)
// Your runtime beats 85.25 % of cpp submissions
// Your memory usage beats 42.4 % of cpp submissions (10.1 MB)
```
