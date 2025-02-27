+++
updated = 2025-02-27T21:18:16+08:00
title = "2025-02-27 Daily Challenge"
path = "2025-02-27-Daily-Challenge"
date = 2025-02-27T21:18:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 27

## Description

**Length of Longest Fibonacci Subsequence**

<p>A sequence <code>x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub></code> is <em>Fibonacci-like</em> if:</p>

<ul>
	<li><code>n &gt;= 3</code></li>
	<li><code>x<sub>i</sub> + x<sub>i+1</sub> == x<sub>i+2</sub></code> for all <code>i + 2 &lt;= n</code></li>
</ul>

<p>Given a <b>strictly increasing</b> array <code>arr</code> of positive integers forming a sequence, return <em>the <strong>length</strong> of the longest Fibonacci-like subsequence of</em> <code>arr</code>. If one does not exist, return <code>0</code>.</p>

<p>A <strong>subsequence</strong> is derived from another sequence <code>arr</code> by deleting any number of elements (including none) from <code>arr</code>, without changing the order of the remaining elements. For example, <code>[3, 5, 8]</code> is a subsequence of <code>[3, 4, 5, 6, 7, 8]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,6,7,8]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence that is fibonacci-like: [1,2,3,5,8].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,7,11,12,14,18]
<strong>Output:</strong> 3
<strong>Explanation</strong>:<strong> </strong>The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt; arr[i + 1] &lt;= 10<sup>9</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_set<int> has;
    int len = arr.size();
    int answer = 0;
    for(auto i : arr) has.insert(i);
    for(int i = 2; i < len; ++i) {
      for(int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; --j) {
        int gt = arr[i];
        int lt = arr[j];
        int diff = gt - lt;
        if(has.count(diff)) {
          mp[gt][lt] = mp[lt][diff] + 1;
          answer = max(mp[gt][lt], answer);
        }
      }
    }
    return answer ? answer + 2 : 0;
  }
};
```
