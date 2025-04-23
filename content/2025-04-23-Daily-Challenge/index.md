+++
updated = 2025-04-23T13:08:06+08:00
title = "2025-04-23 Daily Challenge"
path = "2025-04-23-Daily-Challenge"
date = 2025-04-23T13:08:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-largest-group/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 23

## Description

**Count Largest Group**

<p>You are given an integer <code>n</code>.</p>

<p>Each number from <code>1</code> to <code>n</code> is grouped according to the sum of its digits.</p>

<p>Return <em>the number of groups that have the largest size</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 13
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 groups [1], [2] of size 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countLargestGroup(int n) {
    map<int, int> count;
    for(int i = 1; i <= n; ++i) {
      int sum = 0;
      int current = i;
      while(current) {
        sum += current % 10;
        current /= 10;
      }
      count[sum] += 1;
    }
    int answer = 0;
    int size = 0;
    for(const auto &[_s, c] : count) {
      if(c > size) {
        answer = 0;
        size = c;
      }
      answer += (c == size);
    }
    return answer;
  }
};

// Accepted
// 75/75 cases passed (3 ms)
// Your runtime beats 33.9 % of cpp submissions
// Your memory usage beats 74.92 % of cpp submissions (8 MB)
```
