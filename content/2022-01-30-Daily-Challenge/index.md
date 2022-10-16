+++
title = "2022-01-30 Daily-Challenge"
path = "2022-01-30-Daily-Challenge"
date = 2022-01-30 12:20:00+08:00
updated = 2022-01-30 12:20:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/rotate-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 30

## Description

**Rotate Array**

Given an array, rotate the array to the right by `k` steps, where `k` is non-negative.

 

**Example 1:**

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul> 

**Follow up:**

- Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    if(!k) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

// Accepted
// 38/38 cases passed (39 ms)
// Your runtime beats 45.28 % of cpp submissions
// Your memory usage beats 52.93 % of cpp submissions (25 MB)
```
