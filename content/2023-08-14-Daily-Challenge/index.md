+++
updated = 2023-08-14T12:23:16+08:00
title = "2023-08-14 Daily Challenge"
path = "2023-08-14-Daily-Challenge"
date = 2023-08-14T12:23:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/kth-largest-element-in-an-array/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 14

## Description

**Kth Largest Element in an Array**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>Can you solve it without sorting?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
<strong>Output:</strong> 5
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
<strong>Output:</strong> 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

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

// Accepted
// 40/40 cases passed (72 ms)
// Your runtime beats 96.84 % of cpp submissions
// Your memory usage beats 74.16 % of cpp submissions (45.5 MB)
```
