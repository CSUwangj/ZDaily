+++
updated = 2024-10-30T08:35:38+08:00
title = "2024-10-30 Daily Challenge"
path = "2024-10-30-Daily-Challenge"
date = 2024-10-30T08:35:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 30

## Description

**Minimum Number of Removals to Make Mountain Array**

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some index <code>i</code> (<strong>0-indexed</strong>) with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given an integer array <code>nums</code>​​​, return <em>the <strong>minimum</strong> number of elements to remove to make </em><code>nums<em>​​​</em></code><em> </em><em>a <strong>mountain array</strong>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array itself is a mountain array so we do not need to remove any elements.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,1,5,6,2,3,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that you can make a mountain array out of <code>nums</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minimumMountainRemovals(vector<int>& nums) {
    int len = nums.size();
    vector<int> upDP(len, 1);
    vector<int> downDP(len, 0);

    int maxMountainLen = 0;
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j]) {
          upDP[i] = max(upDP[i], upDP[j] + 1);
        } else if(nums[i] < nums[j]) {
          if(upDP[j] > 1) downDP[i] = max(downDP[i], upDP[j] + 1);
          if(downDP[j] > 1) downDP[i] = max(downDP[i], downDP[j] + 1);
        }
      }
      maxMountainLen = max(maxMountainLen, downDP[i]);
    }
    return len - maxMountainLen;
  }
};
```
