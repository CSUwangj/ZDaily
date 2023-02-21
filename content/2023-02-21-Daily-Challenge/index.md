+++
updated = 2023-02-21T13:46:47+08:00
title = "2023-02-21 Daily Challenge"
path = "2023-02-21-Daily-Challenge"
date = 2023-02-21T13:46:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/single-element-in-a-sorted-array/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 21

## Description

**Single Element in a Sorted Array**

<p>You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.</p>

<p>Return <em>the single element that appears only once</em>.</p>

<p>Your solution must run in <code>O(log n)</code> time and <code>O(1)</code> space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
<strong>Output:</strong> 10
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
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
  int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while(low < high - 1) {
      int mid = (low + high) >> 1;
      mid ^= (mid & 1);
      if(nums[mid] == nums[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[high];
  }
};

// Accepted
// 15/15 cases passed (25 ms)
// Your runtime beats 82.58 % of cpp submissions
// Your memory usage beats 16.37 % of cpp submissions (22.4 MB)
```
