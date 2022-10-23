+++
updated = 2022-10-23T22:27:30+08:00
title = "2022-10-23 Daily Challenge"
path = "2022-10-23-Daily-Challenge"
date = 2022-10-23T22:27:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/set-mismatch/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 23

## Description

**Set Mismatch**

<p>You have a set of integers <code>s</code>, which originally contains all the numbers from <code>1</code> to <code>n</code>. Unfortunately, due to some error, one of the numbers in <code>s</code> got duplicated to another number in the set, which results in <strong>repetition of one</strong> number and <strong>loss of another</strong> number.</p>

<p>You are given an integer array <code>nums</code> representing the data status of this set after the error.</p>

<p>Find the number that occurs twice and the number that is missing and return <em>them in the form of an array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2,4]
<strong>Output:</strong> [2,3]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int len = nums.size();
    vector<bool> used(len);
    int loss = -1;
    int dup = -1;
    for(auto i : nums) {
      if(!used[i - 1]) used[i - 1] = true;
      else dup = i;
    }
    for(int i = 0; i < len; ++i) {
      if(!used[i]) loss = i + 1;
    }
    return vector<int>{dup, loss};
  }
};

// Accepted
// 49/49 cases passed (81 ms)
// Your runtime beats 49.41 % of cpp submissions
// Your memory usage beats 50.7 % of cpp submissions (21.6 MB)
```
