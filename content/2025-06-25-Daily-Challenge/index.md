+++
updated = 2025-06-26T02:40:30+08:00
title = "2025-06-25 Daily Challenge"
path = "2025-06-25-Daily-Challenge"
date = 2025-06-26T02:40:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 25

## Description

**Kth Smallest Product of Two Sorted Arrays**

Given two <strong>sorted 0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> as well as an integer <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> (<strong>1-based</strong>) smallest product of </em><code>nums1[i] * nums2[j]</code><em> where </em><code>0 &lt;= i &lt; nums1.length</code><em> and </em><code>0 &lt;= j &lt; nums2.length</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,5], nums2 = [3,4], k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2<sup>nd</sup> smallest product is 8.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
<strong>Output:</strong> 0
<strong>Explanation:</strong> The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6<sup>th</sup> smallest product is 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
<strong>Output:</strong> -6
<strong>Explanation:</strong> The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3<sup>rd</sup> smallest product is -6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums1.length * nums2.length</code></li>
	<li><code>nums1</code> and <code>nums2</code> are sorted.</li>
</ul>


## Solution

``` cpp
class Solution {
  long long countLE(const vector<int>& nums1, const vector<int>& nums2, long long target) {
    long long result = 0;
    int len2 = nums2.size();
    for(auto n1 : nums1) {
      if(!n1) {
        if(target >= 0) result += len2;
        continue;
      }
      int low = 0;
      int high = len2 - 1;
      while(low <= high) {
        int mid = (low + high) / 2;
        if((n1 > 0 && 1LL * n1 * nums2[mid] <= target) ||
           (n1 < 0 && 1LL * n1 * nums2[mid] > target)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      result += n1 < 0 ? len2 - low : low;
    }
    return result;
  }
public:
  long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    long long mmin = min({1LL * nums1.front() * nums2.back(), 1LL * nums1.back() * nums2.front(), 1LL * nums1.front() * nums2.front(), 1LL * nums2.back() * nums2.back()});
    long long mmax = max({1LL * nums1.front() * nums2.back(), 1LL * nums1.back() * nums2.front(), 1LL * nums1.front() * nums2.front(), 1LL * nums2.back() * nums2.back()});

    // cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
    while(mmin < mmax) {
      long long mmid = (mmin + mmax - (mmax <= 0)) / 2;
      // cout << mmin << ' ' << mmax << ' ' << mmid << ' ' << countLE(nums1, nums2, mmid) << endl;
      if(countLE(nums1, nums2, mmid) < k) {
        mmin = mmid + 1;
      } else {
        mmax = mmid;
      }
    }
    return mmin;
  }
};

// Accepted
// 112/112 cases passed (541 ms)
// Your runtime beats 71.3 % of cpp submissions
// Your memory usage beats 41.69 % of cpp submissions (98.1 MB)
```
