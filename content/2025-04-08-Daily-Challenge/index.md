+++
updated = 2025-04-08T23:58:16+08:00
title = "2025-04-08 Daily Challenge"
path = "2025-04-08-Daily-Challenge"
date = 2025-04-08T23:58:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 8

## Description

**Minimum Number of Operations to Make Elements in Array Distinct**

<p>You are given an integer array <code>nums</code>. You need to ensure that the elements in the array are <strong>distinct</strong>. To achieve this, you can perform the following operation any number of times:</p>

<ul>
	<li>Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.</li>
</ul>

<p><strong>Note</strong> that an empty array is considered to have distinct elements. Return the <strong>minimum</strong> number of operations needed to make the elements in the array distinct.<!-- notionvc: 210ee4f2-90af-4cdf-8dbc-96d1fa8f67c7 --></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,2,3,3,5,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>In the first operation, the first 3 elements are removed, resulting in the array <code>[4, 2, 3, 3, 5, 7]</code>.</li>
	<li>In the second operation, the next 3 elements are removed, resulting in the array <code>[3, 5, 7]</code>, which has distinct elements.</li>
</ul>

<p>Therefore, the answer is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,5,6,4,4]</span></p>

<p><strong>Output:</strong> 2</p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>In the first operation, the first 3 elements are removed, resulting in the array <code>[4, 4]</code>.</li>
	<li>In the second operation, all remaining elements are removed, resulting in an empty array.</li>
</ul>

<p>Therefore, the answer is 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [6,7,8,9]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The array already contains distinct elements. Therefore, the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    map<int, int> count;
    int dup = 0;
    for(auto n : nums) {
      dup += (count[n] == 1);
      count[n] += 1;
    }

    int answer = 0;
    int pos = 0;
    int len = nums.size();
    while(dup) {
      answer += 1;
      for(int i = 0; pos + i < len && i < 3; ++i) {
        count[nums[pos + i]] -= 1;
        dup -= (count[nums[pos + i]] == 1);
      }
      pos += 3;
    }
    return answer;
  }
};

// Accepted
// 781/781 cases passed (9 ms)
// Your runtime beats 25.43 % of cpp submissions
// Your memory usage beats 35.5 % of cpp submissions (28.4 MB)
```
