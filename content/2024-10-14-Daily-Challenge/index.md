+++
updated = 2024-10-14T08:07:13+08:00
title = "2024-10-14 Daily Challenge"
path = "2024-10-14-Daily-Challenge"
date = 2024-10-14T08:07:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximal-score-after-applying-k-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 14

## Description

**Maximal Score After Applying K Operations**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>. You have a <strong>starting score</strong> of <code>0</code>.</p>

<p>In one <strong>operation</strong>:</p>

<ol>
	<li>choose an index <code>i</code> such that <code>0 &lt;= i &lt; nums.length</code>,</li>
	<li>increase your <strong>score</strong> by <code>nums[i]</code>, and</li>
	<li>replace <code>nums[i]</code> with <code>ceil(nums[i] / 3)</code>.</li>
</ol>

<p>Return <em>the maximum possible <strong>score</strong> you can attain after applying <strong>exactly</strong></em> <code>k</code> <em>operations</em>.</p>

<p>The ceiling function <code>ceil(val)</code> is the least integer greater than or equal to <code>val</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,10,10,10,10], k = 5
<strong>Output:</strong> 50
<strong>Explanation:</strong> Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,3,3], k = 3
<strong>Output:</strong> 17
<strong>Explanation: </strong>You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,<strong><u>4</u></strong>,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,<strong><u>2</u></strong>,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,<u><strong>1</strong></u>,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(auto n : nums) {
      pq.push(n);
    }
    long long answer = 0;
    while(k--) {
      auto n = pq.top();
      pq.pop();
      answer += n;
      pq.push(ceil(n / 3.0));
    }
    return answer;
  }
};
```
