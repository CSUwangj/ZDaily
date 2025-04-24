+++
updated = 2025-04-24T13:08:06+08:00
title = "2025-04-24 Daily Challenge"
path = "2025-04-24-Daily-Challenge"
date = 2025-04-24T13:08:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-largest-group/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 24

## Description

**Count Complete Subarrays in an Array**

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>We call a subarray of an array <strong>complete</strong> if the following condition is satisfied:</p>

<ul>
	<li>The number of <strong>distinct</strong> elements in the subarray is equal to the number of distinct elements in the whole array.</li>
</ul>

<p>Return <em>the number of <strong>complete</strong> subarrays</em>.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,5,5,5]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countCompleteSubarrays(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    int target = st.size();
    map<int, int> count;
    int begin = 0;
    int answer = 0;
    for(int end = 0; end < nums.size(); ++end) {
      count[nums[end]] += 1;
      while(count.size() == target) {
        answer += nums.size() - end;
        count[nums[begin]] -= 1;
        if(!count[nums[begin]]) count.erase(nums[begin]);
        begin += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 1074/1074 cases passed (27 ms)
// Your runtime beats 38.05 % of cpp submissions
// Your memory usage beats 45.93 % of cpp submissions (42 MB)
```
