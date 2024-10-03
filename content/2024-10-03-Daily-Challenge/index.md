+++
updated = 2024-10-03T08:11:52+08:00
title = "2024-10-03 Daily Challenge"
path = "2024-10-03-Daily-Challenge"
date = 2024-10-03T08:11:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/make-sum-divisible-by-p/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 3

## Description

**Make Sum Divisible by P**

<p>Given an array of positive integers <code>nums</code>, remove the <strong>smallest</strong> subarray (possibly <strong>empty</strong>) such that the <strong>sum</strong> of the remaining elements is divisible by <code>p</code>. It is <strong>not</strong> allowed to remove the whole array.</p>

<p>Return <em>the length of the smallest subarray that you need to remove, or </em><code>-1</code><em> if it&#39;s impossible</em>.</p>

<p>A <strong>subarray</strong> is defined as a contiguous block of elements in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,4,2], p = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,3,5,2], p = 9
<strong>Output:</strong> 2
<strong>Explanation:</strong> We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], p = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= p &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int target = 0;
    for(auto n : nums) {
      target += n;
      target %= p;
    }
    if(!target) return 0;
    map<int, int> pos;
    pos[0] = -1;
    int sum = 0;
    int answer = nums.size();
    for(int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sum %= p;
      int targetSum = (sum - target + p) % p;
      if(pos.count(targetSum)) {
        answer = min(answer, i - pos[targetSum]);
      }
      pos[sum] = i;
    }
    return answer == nums.size() ? -1 : answer;
  }
};
```
