+++
title = "2021-11-05 Daily-Challenge"
path = "2021-11-05-Daily-Challenge"
date = 2021-11-05 22:00:00+08:00
updated = 2021-11-05 22:02:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/arranging-coins/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 5

## Description

**Arranging Coins**

You have `n` coins and you want to build a staircase with these coins. The staircase consists of `k` rows where the `ith` row has exactly `i` coins. The last row of the staircase **may be** incomplete.

Given the integer `n`, return *the number of **complete rows** of the staircase you will build*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins1-grid.jpg)

```
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins2-grid.jpg)

<code><pre>
<strong>Input:</strong> n = 8
<strong>Output:</strong> 3
<strong>Explanation:</strong> Because the 4<sup>th</sup> row is incomplete, we return 3.
</pre></code>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int arrangeCoins(int n) {
    long long begin = 0, end = n;
    while(begin < end) {
      long long mid = (begin + end) / 2;
      long long need = (mid + 1LL) * mid / 2;
      if(need < n) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(begin * (begin + 1) / 2 > n) begin -= 1;
    return begin;
  }
};

// Accepted
// 1335/1335 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.1 % of cpp submissions (5.8 MB)
```
