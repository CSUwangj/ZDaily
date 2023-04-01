+++
updated = 2023-04-01T08:43:01+08:00
title = "2023-04-01 Daily Challenge"
path = "2023-04-01-Daily-Challenge"
date = 2023-04-01T08:43:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/binary-search/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 1

## Description

**Binary Search**

<p>Given an array of integers <code>nums</code> which is sorted in ascending order, and an integer <code>target</code>, write a function to search <code>target</code> in <code>nums</code>. If <code>target</code> exists, then return its index. Otherwise, return <code>-1</code>.</p>

<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,0,3,5,9,12], target = 9
<strong>Output:</strong> 4
<strong>Explanation:</strong> 9 exists in nums and its index is 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,0,3,5,9,12], target = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> 2 does not exist in nums so return -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt; nums[i], target &lt; 10<sup>4</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is sorted in ascending order.</li>
</ul>


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
  int search(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] >= target) {
        end = mid;
      } else {
        begin = mid+1;
      }
    }
    return nums[begin]==target?begin:-1;
  }
};

// Accepted
// 47/47 cases passed (28 ms)
// Your runtime beats 98.7 % of cpp submissions
// Your memory usage beats 13.43 % of cpp submissions (27.7 MB)
```
