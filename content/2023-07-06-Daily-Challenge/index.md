+++
updated = 2023-07-06T12:16:40+08:00
title = "2023-07-06 Daily Challenge"
path = "2023-07-06-Daily-Challenge"
date = 2023-07-06T12:16:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/minimum-size-subarray-sum/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 6

## Description

**Minimum Size Subarray Sum**

<p>Given an array of positive integers <code>nums</code> and a positive integer <code>target</code>, return <em>the <strong>minimal length</strong> of a </em><span data-keyword="subarray-nonempty"><em>subarray</em></span><em> whose sum is greater than or equal to</em> <code>target</code>. If there is no such subarray, return <code>0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = 7, nums = [2,3,1,2,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The subarray [4,3] has the minimal length under the problem constraint.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = 4, nums = [1,4,4]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution of which the time complexity is <code>O(n log(n))</code>.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int start = 0;
    int answer = INT_MAX;
    for(int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while(sum >= target) {
        answer = min(answer, i - start + 1);
        sum -= nums[start];
        start += 1;
      }
    }
    return answer == INT_MAX ? 0 : answer;
  }
};

// Accepted
// 20/20 cases passed (28 ms)
// Your runtime beats 99.24 % of cpp submissions
// Your memory usage beats 71.68 % of cpp submissions (28.1 MB)
```
