+++
updated = 2023-09-10T14:10:02+08:00
title = "2023-09-10 Daily Challenge"
path = "2023-09-10-Daily-Challenge"
date = 2023-09-10T14:10:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 10

## Description

**Count All Valid Pickup and Delivery Options**

<p>Given <code>n</code> orders, each order consist in pickup and delivery services.&nbsp;</p>

<p>Count all valid pickup/delivery possible sequences such that delivery(i) is always after of&nbsp;pickup(i).&nbsp;</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 90
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr auto table = []{
  array<int, 501> answer{0, 1};
  for(int i = 2; i <= 500; ++i) {
    answer[i] = 1LL * answer[i - 1] * i * (i * 2 - 1) % MOD;
  }
  return answer;
}();
class Solution {
public:
  int countOrders(int n) {
    return table[n];
  }
};

// Accepted
// 36/36 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.45 % of cpp submissions (6 MB)
```
