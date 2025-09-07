+++
updated = 2025-09-08T01:48:02+02:00
title = "2025-09-07 Daily Challenge"
path = "2025-09-07-Daily-Challenge"
date = 2025-09-08T01:48:02+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 7

## Description

**Find N Unique Integers Sum up to Zero**

<p>Given an integer <code>n</code>, return <strong>any</strong> array containing <code>n</code> <strong>unique</strong> integers such that they add up to <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> [-7,-1,1,3,4]
<strong>Explanation:</strong> These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [-1,0,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> answer(n);
    for(int i = 0; i * 2 + 1 < n; ++i) {
      answer[i * 2] = i + 1;
      answer[i * 2 + 1] = -i - 1;
    }
    return move(answer);
  }
};

// Accepted
// 42/42 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.89 % of cpp submissions (9.6 MB)
```
