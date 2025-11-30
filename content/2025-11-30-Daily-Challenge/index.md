+++
updated = 2025-11-30T11:50:19+01:00
title = "2025-11-30 Daily Challenge"
path = "2025-11-30-Daily-Challenge"
date = 2025-11-30T11:50:19+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/make-sum-divisible-by-p/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 30

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
    for(auto &i : nums) i %= p;
    int sum = accumulate(nums.begin(), nums.end(), 0, [=](int a, int b) { 
      return (a + b) % p;
    });
    if(!sum) return 0;
    unordered_map<int, int> prefix{{0, -1}};
    int len = nums.size();
    int invTarget = p - sum;
    int curSum = 0;
    int answer = len;
    for(int i = 0; i < len; ++i) {
      curSum += nums[i];
      curSum %= p;
      if(prefix.count((curSum + invTarget) % p)) {
        answer = min(answer, i - prefix[(curSum + invTarget) % p]);
      }
      prefix[curSum] = i;
    }

    return answer == len ? -1 : answer;
  }
};

// Accepted
// 145/145 cases passed (83 ms)
// Your runtime beats 53.19 % of cpp submissions
// Your memory usage beats 52.86 % of cpp submissions (87.9 MB)
```
