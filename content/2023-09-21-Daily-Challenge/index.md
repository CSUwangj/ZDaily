+++
updated = 2023-09-21T20:11:54+08:00
title = "2023-09-21 Daily Challenge"
path = "2023-09-21-Daily-Challenge"
date = 2023-09-21T20:11:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/median-of-two-sorted-arrays/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 21

## Description

**Median of Two Sorted Arrays**

<p>Given two sorted arrays <code>nums1</code> and <code>nums2</code> of size <code>m</code> and <code>n</code> respectively, return <strong>the median</strong> of the two sorted arrays.</p>

<p>The overall run time complexity should be <code>O(log (m+n))</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,3], nums2 = [2]
<strong>Output:</strong> 2.00000
<strong>Explanation:</strong> merged array = [1,2,3] and median is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2], nums2 = [3,4]
<strong>Output:</strong> 2.50000
<strong>Explanation:</strong> merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums1.length == m</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>0 &lt;= m &lt;= 1000</code></li>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= m + n &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
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
  int len1;
  int len2;
  int low;
  int high;
  int findCount(vector<int> &nums, int high, int num) {
    int low = 0;
    while(low < high) {
      int mid = (low + high + 1) >> 1;
      if(nums[mid] > num) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    return low + (nums[low] <= num);
  }
  double findNthSortedArrays(vector<int>& nums1, vector<int>& nums2, int n) {
    if(nums1.empty()) return nums2[n - 1];
    if(nums2.empty()) return nums1[n - 1];
    int low = this->low;
    int high = this->high;
    while(low < high) {
      int mid = (low + high) >> 1;
      int count = findCount(nums1, len1 - 1, mid) + findCount(nums2, len2 - 1, mid);
      if(count < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    low = min(nums1.size() ? nums1.front() : INT_MAX, nums2.size() ? nums2.front() : INT_MAX);
    high = max(nums1.size() ? nums1.back() : INT_MIN, nums2.size() ? nums2.back() : INT_MIN);
    len1 = nums1.size();
    len2 = nums2.size();
    pair<int, int> target = {(len1 + len2 + 1) / 2, (len1 + len2 + 2) / 2};
    return (findNthSortedArrays(nums1, nums2, target.first) + findNthSortedArrays(nums1, nums2, target.second)) / 2.0;
  }
};

// Accepted
// 2094/2094 cases passed (23 ms)
// Your runtime beats 76.84 % of cpp submissions
// Your memory usage beats 46.95 % of cpp submissions (89.7 MB)
```
