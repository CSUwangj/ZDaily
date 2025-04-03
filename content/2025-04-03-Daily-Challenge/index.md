+++
updated = 2025-04-03T12:22:04+08:00
title = "2025-04-03 Daily Challenge"
path = "2025-04-03-Daily-Challenge"
date = 2025-04-03T12:22:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 3

## Description

**Maximum Value of an Ordered Triplet II**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>Return <em><strong>the maximum value over all triplets of indices</strong></em> <code>(i, j, k)</code> <em>such that</em> <code>i &lt; j &lt; k</code><em>. </em>If all such triplets have a negative value, return <code>0</code>.</p>

<p>The <strong>value of a triplet of indices</strong> <code>(i, j, k)</code> is equal to <code>(nums[i] - nums[j]) * nums[k]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,6,1,2,7]
<strong>Output:</strong> 77
<strong>Explanation:</strong> The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,4,19]
<strong>Output:</strong> 133
<strong>Explanation:</strong> The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using rmap = map<int, int, greater<>>;
public:
  long long maximumTripletValue(vector<int>& nums) {
    long long answer = 0;
    rmap i;
    rmap k;
    i[nums[0]] += 1;
    for(int i = 1; i < nums.size(); ++i) {
      k[nums[i]] += 1;
    }
    for(int j = 1; j < nums.size() - 1; ++j) {
      k[nums[j]] -= 1;
      if(!k[nums[j]]) k.erase(nums[j]);
      answer = max(answer, (i.begin()->first - nums[j]) * 1LL * k.begin()->first);
      i[nums[j]] += 1;
    }
    return answer;
  }
};

// Accepted
// 599/599 cases passed (691 ms)
// Your runtime beats 5.86 % of cpp submissions
// Your memory usage beats 5.28 % of cpp submissions (186.2 MB)
```
