+++
updated = 2023-10-26T12:37:58+08:00
title = "2023-10-26 Daily Challenge"
path = "2023-10-26-Daily-Challenge"
date = 2023-10-26T12:37:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/binary-trees-with-factors/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 26

## Description

**Binary Trees With Factors**

<p>Given an array of unique integers, <code>arr</code>, where each integer <code>arr[i]</code> is strictly greater than <code>1</code>.</p>

<p>We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node&#39;s value should be equal to the product of the values of its children.</p>

<p>Return <em>the number of binary trees we can make</em>. The answer may be too large so return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [4, 2, 2]</code></pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,4,5,10]
<strong>Output:</strong> 7
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]</code>.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>2 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li>All the values of <code>arr</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<int> count(len, 1);
    for(int i = 1; i < len; ++i) {
      for(int j = 0; arr[i] / arr[j] >= arr[j]; ++j) {
        if(arr[i] % arr[j]) continue;
        int pos = lower_bound(arr.begin(), arr.end(), arr[i] / arr[j]) - arr.begin();
        if(arr[i] / arr[j] != arr[pos]) continue;
        count[i] += (2LL - (arr[j] == arr[pos])) * count[j] * count[pos] % MOD;
        count[i] %= MOD;
      }
    }
    
    int answer = accumulate(count.begin(), count.end(), 0, [](int prev, int cur) {
      return (prev + cur) % MOD;
    });
    return answer;
  }
};

// Accepted
// 48/48 cases passed (28 ms)
// Your runtime beats 91.73 % of cpp submissions
// Your memory usage beats 92.91 % of cpp submissions (8.7 MB)
```
