+++
title = "2021-12-21 Daily-Challenge"
path = "2021-12-21-Daily-Challenge"
date = 2021-12-21 18:26:00+08:00
updated = 2021-12-21 18:27:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/power-of-two/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 21

## Description

**Power of Two**

Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that <code>x</code> such that <code>n == 2<sup>x</sup></code>.

 

**Example 1:**

```
Input: n = 1
Output: true
Explanation: 20 = 1
```

**Example 2:**

```
Input: n = 16
Output: true
Explanation: 24 = 16
```

**Example 3:**

```
Input: n = 3
Output: false
```

 

**Constraints:**

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul> 

**Follow up:** Could you solve it without loops/recursion?

## Solution

``` cpp
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n - 1));
  }
};

// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.12 % of cpp submissions (5.9 MB)
```
