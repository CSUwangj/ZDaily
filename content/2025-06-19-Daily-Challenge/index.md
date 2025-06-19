+++
updated = 2025-06-20T02:59:20+08:00
title = "2025-06-19 Daily Challenge"
path = "2025-06-19-Daily-Challenge"
date = 2025-06-20T02:59:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 19

## Description

**Partition Array Such That Maximum Difference Is K**

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You may partition <code>nums</code> into one or more <strong>subsequences</strong> such that each element in <code>nums</code> appears in <strong>exactly</strong> one of the subsequences.</p>

<p>Return <em>the <strong>minimum </strong>number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is <strong>at most</strong> </em><code>k</code><em>.</em></p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,6,1,2,5], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,4,5], k = 0
<strong>Output:</strong> 3
<strong>Explanation:</strong>
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    map<int, int> count;
    for(auto n : nums) {
      count[n] += 1;
    }
    auto it = count.begin();
    int answer = 0;
    while(it != count.end()) {
      answer += 1;
      it = count.upper_bound(it->first + k);
    }
    return answer;
  }
};

// Accepted
// 92/92 cases passed (236 ms)
// Your runtime beats 5.15 % of cpp submissions
// Your memory usage beats 5.15 % of cpp submissions (125.7 MB)
```
