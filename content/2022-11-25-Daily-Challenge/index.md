+++
updated = 2022-11-25T14:07:21+08:00
title = "2022-11-25 Daily Challenge"
path = "2022-11-25-Daily-Challenge"
date = 2022-11-25T14:07:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/sum-of-subarray-minimums/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 25

## Description

**Sum of Subarray Minimums**

<p>Given an array of integers arr, find the sum of <code>min(b)</code>, where <code>b</code> ranges over every (contiguous) subarray of <code>arr</code>. Since the answer may be large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [3,1,2,4]
<strong>Output:</strong> 17
<strong>Explanation:</strong> 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [11,81,94,43,3]
<strong>Output:</strong> 444
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


## Solution

seems a problems can be solved with monotonic stack

``` cpp
class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    int len = arr.size();
    if(len == 1) return arr[0];
    vector<int> left(len), right(len);
    vector<pair<int, int>> monoStack;
    vector<pair<int, int>> momoStack;
    for(int i = 0; i < len; ++i) {
      left[i] = i + 1;
      right[i] = len - i;
    }
    for(int i = 0; i < len; ++i) {
      while(monoStack.size() && monoStack.back().first >= arr[i]) {
        monoStack.pop_back();
      }
      left[i] = monoStack.size() ? i - monoStack.back().second : i + 1;
      monoStack.push_back({arr[i], i});

      while(momoStack.size() && momoStack.back().first >= arr[i]) {
        auto pos = momoStack.back().second;
        momoStack.pop_back();
        right[pos] = i - pos;
      }
      momoStack.push_back({arr[i], i});
    }
    long long answer = 0;
    constexpr int MOD = 1e9 + 7;
    for(int i = 0; i < len; ++i) {
      answer += 1LL * right[i] * left[i] * arr[i];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 87/87 cases passed (100 ms)
// Your runtime beats 95.32 % of cpp submissions
// Your memory usage beats 13.34 % of cpp submissions (44.2 MB)
```
