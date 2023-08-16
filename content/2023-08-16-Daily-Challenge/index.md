+++
updated = 2023-08-16T11:40:18+08:00
title = "2023-08-16 Daily Challenge"
path = "2023-08-16-Daily-Challenge"
date = 2023-08-16T11:40:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/sliding-window-maximum/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 16

## Description

**Sliding Window Maximum**

<p>You are given an array of integers&nbsp;<code>nums</code>, there is a sliding window of size <code>k</code> which is moving from the very left of the array to the very right. You can only see the <code>k</code> numbers in the window. Each time the sliding window moves right by one position.</p>

<p>Return <em>the max sliding window</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,-1,-3,5,3,6,7], k = 3
<strong>Output:</strong> [3,3,5,5,6,7]
<strong>Explanation:</strong> 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> monoQueue;
    for(int i = 0; i < k; ++i) {
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      monoQueue.push_back(nums[i]);
    }
    vector<int> answer{monoQueue.front()};
    for(int i = k; i < nums.size(); ++i) {
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      if(monoQueue.size() && monoQueue.front() == nums[i-k]) monoQueue.pop_front();
      monoQueue.push_back(nums[i]);
      answer.push_back(monoQueue.front());
    }
    return answer;
  }
};

// Accepted
// 51/51 cases passed (199 ms)
// Your runtime beats 91.73 % of cpp submissions
// Your memory usage beats 45.65 % of cpp submissions (134.7 MB)
```
