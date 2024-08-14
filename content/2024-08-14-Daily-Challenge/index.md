+++
updated = 2024-08-14T13:32:37+08:00
title = "2024-08-14 Daily Challenge"
path = "2024-08-14-Daily-Challenge"
date = 2024-08-14T13:32:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 14

## Description

**Find K-th Smallest Pair Distance**

<p>The <strong>distance of a pair</strong> of integers <code>a</code> and <code>b</code> is defined as the absolute difference between <code>a</code> and <code>b</code>.</p>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>smallest <strong>distance among all the pairs</strong></em> <code>nums[i]</code> <em>and</em> <code>nums[j]</code> <em>where</em> <code>0 &lt;= i &lt; j &lt; nums.length</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,1], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Here are all the pairs:
(1,3) -&gt; 2
(1,1) -&gt; 0
(3,1) -&gt; 2
Then the 1<sup>st</sup> smallest distance pair is (1,1), and its distance is 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1], k = 2
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,6,1], k = 3
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n * (n - 1) / 2</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int countPairs(int x, vector<int> &nums) {
    int len = nums.size();
    int count = 0;
    for(int l = 0, r = 1; r < len; ++r) {
      while(r > l && nums[r] - nums[l] > x) {
        l += 1;
      }
      count += r - l;
    }
    return count;

  }
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int high = nums.back();
    int low = 0;
    while(low < high) {
      int mid = (low + high) / 2;
      if(countPairs(mid, nums) < k) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
```
