+++
updated = 2023-11-25T22:25:18+08:00
title = "2023-11-25 Daily Challenge"
path = "2023-11-25-Daily-Challenge"
date = 2023-11-25T22:25:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 25

## Description

**Sum of Absolute Differences in a Sorted Array**

<p>You are given an integer array <code>nums</code> sorted in <strong>non-decreasing</strong> order.</p>

<p>Build and return <em>an integer array </em><code>result</code><em> with the same length as </em><code>nums</code><em> such that </em><code>result[i]</code><em> is equal to the <strong>summation of absolute differences</strong> between </em><code>nums[i]</code><em> and all the other elements in the array.</em></p>

<p>In other words, <code>result[i]</code> is equal to <code>sum(|nums[i]-nums[j]|)</code> where <code>0 &lt;= j &lt; nums.length</code> and <code>j != i</code> (<strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,5]
<strong>Output:</strong> [4,3,5]
<strong>Explanation:</strong> Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,6,8,10]
<strong>Output:</strong> [24,15,13,15,21]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums[i + 1] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int back = accumulate(nums.begin(), nums.end(), 0);
    int front = 0; 
    int len = nums.size();
    int count = 0;
    vector<int> answer;
    answer.reserve(len);

    for(auto n : nums) {
      answer.push_back(count * n - front + back - (len - count) * n);
      front += n;
      back -= n;
      count += 1;
    }

    return answer;
  }
};

// Accepted
// 59/59 cases passed (80 ms)
// Your runtime beats 94.05 % of cpp submissions
// Your memory usage beats 66.49 % of cpp submissions (83.6 MB)
```
