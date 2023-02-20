+++
updated = 2023-02-20T13:43:43+08:00
title = "2023-02-20 Daily Challenge"
path = "2023-02-20-Daily-Challenge"
date = 2023-02-20T13:43:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/search-insert-position/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 20

## Description

**Search Insert Position**

<p>Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.</p>

<p>You must&nbsp;write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,6], target = 5
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,6], target = 2
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,6], target = 7
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> contains <strong>distinct</strong> values sorted in <strong>ascending</strong> order.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
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
  int searchInsert(vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    nums.push_back(INT_MAX);
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};

// Accepted
// 64/64 cases passed (3 ms)
// Your runtime beats 84.06 % of cpp submissions
// Your memory usage beats 72.14 % of cpp submissions (9.7 MB)
```
