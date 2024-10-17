+++
updated = 2024-10-17T08:11:26+08:00
title = "2024-10-17 Daily Challenge"
path = "2024-10-17-Daily-Challenge"
date = 2024-10-17T08:11:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-swap/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 17

## Description

**Maximum Swap**

<p>You are given an integer <code>num</code>. You can swap two digits at most once to get the maximum valued number.</p>

<p>Return <em>the maximum valued number you can get</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 2736
<strong>Output:</strong> 7236
<strong>Explanation:</strong> Swap the number 2 and the number 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 9973
<strong>Output:</strong> 9973
<strong>Explanation:</strong> No swap.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumSwap(int num) {
    using pci = pair<char, int>;
    priority_queue<pci> pq;
    string n = to_string(num);
    pair<int, int> targetSwap = {-1, -1};
    for(int i = n.length() - 1; i >= 0; --i) {
      if(pq.size() && pq.top().first > n[i]) {
        targetSwap = {i, pq.top().second};
      }
      pq.push({n[i], i});
    }
    if(targetSwap.first != -1) {
      swap(n[targetSwap.first], n[targetSwap.second]);
    }
    return stoi(n);
  }
};
```
