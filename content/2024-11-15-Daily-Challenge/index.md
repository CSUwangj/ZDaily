+++
updated = 2024-11-15T12:53:18+08:00
title = "2024-11-15 Daily Challenge"
path = "2024-11-15-Daily-Challenge"
date = 2024-11-15T12:53:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 15

## Description

**Shortest Subarray to be Removed to Make Array Sorted**

<p>Given an integer array <code>arr</code>, remove a subarray (can be empty) from <code>arr</code> such that the remaining elements in <code>arr</code> are <strong>non-decreasing</strong>.</p>

<p>Return <em>the length of the shortest subarray to remove</em>.</p>

<p>A <strong>subarray</strong> is a contiguous subsequence of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,10,4,2,3,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [5,4,3,2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array is already non-decreasing. We do not need to remove any elements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int len = arr.size();

    int left = 0;
    while(left + 1 < len && arr[left] <= arr[left + 1]) left += 1;
    if(left == len - 1) return 0;

    int right = len - 1;
    while(right > left && arr[right - 1] <= arr[right]) right -= 1;

    int answer = min(len - left - 1, right);
    for(int i = 0, j = right; i <= left && j < len;) {
      if(arr[i] <= arr[j]) {
        answer = min(answer, j - i - 1);
        i += 1;
      } else {
        j += 1;
      }
    }
    return answer;
  }
};
```
