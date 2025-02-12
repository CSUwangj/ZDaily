+++
updated = 2025-02-12T21:36:50+08:00
title = "2025-02-12 Daily Challenge"
path = "2025-02-12-Daily-Challenge"
date = 2025-02-12T21:36:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 12

## Description

**Max Sum of a Pair With Equal Sum of Digits**

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> consisting of <strong>positive</strong> integers. You can choose two indices <code>i</code> and <code>j</code>, such that <code>i != j</code>, and the sum of digits of the number <code>nums[i]</code> is equal to that of <code>nums[j]</code>.</p>

<p>Return <em>the <strong>maximum</strong> value of </em><code>nums[i] + nums[j]</code><em> that you can obtain over all possible indices </em><code>i</code><em> and </em><code>j</code><em> that satisfy the conditions.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [18,43,36,13,7]
<strong>Output:</strong> 54
<strong>Explanation:</strong> The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,12,19,14]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no two numbers that satisfy the conditions, so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumSum(vector<int>& nums) {
    map<int, multiset<int>> sumToNum;
    int answer = -1;
    for(auto n : nums) {
      int c = n;
      int s = 0;
      while(c) {
        s += c % 10;
        c /= 10;
      }
      sumToNum[s].insert(n);
    }
    for(auto [_s, nums] : sumToNum) {
      if(nums.size() < 2) continue;
      auto it = nums.rbegin();
      int result = *it;
      ++it;
      result += *it;
      answer = max(answer, result);
    }
    return answer;
  }
};

// Accepted
// 83/83 cases passed (334 ms)
// Your runtime beats 5.25 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (148.4 MB)
```
