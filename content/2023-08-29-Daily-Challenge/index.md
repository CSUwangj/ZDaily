+++
updated = 2023-08-29T10:43:52+08:00
title = "2023-08-29 Daily Challenge"
path = "2023-08-29-Daily-Challenge"
date = 2023-08-29T10:43:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/minimum-penalty-for-a-shop/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 29

## Description

**Minimum Penalty for a Shop**

<p>You are given the customer visit log of a shop represented by a <strong>0-indexed</strong> string <code>customers</code> consisting only of characters <code>&#39;N&#39;</code> and <code>&#39;Y&#39;</code>:</p>

<ul>
	<li>if the <code>i<sup>th</sup></code> character is <code>&#39;Y&#39;</code>, it means that customers come at the <code>i<sup>th</sup></code> hour</li>
	<li>whereas <code>&#39;N&#39;</code> indicates that no customers come at the <code>i<sup>th</sup></code> hour.</li>
</ul>

<p>If the shop closes at the <code>j<sup>th</sup></code> hour (<code>0 &lt;= j &lt;= n</code>), the <strong>penalty</strong> is calculated as follows:</p>

<ul>
	<li>For every hour when the shop is open and no customers come, the penalty increases by <code>1</code>.</li>
	<li>For every hour when the shop is closed and customers come, the penalty increases by <code>1</code>.</li>
</ul>

<p>Return<em> the <strong>earliest</strong> hour at which the shop must be closed to incur a <strong>minimum</strong> penalty.</em></p>

<p><strong>Note</strong> that if a shop closes at the <code>j<sup>th</sup></code> hour, it means the shop is closed at the hour <code>j</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> customers = &quot;YYNY&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- Closing the shop at the 0<sup>th</sup> hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1<sup>st</sup> hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2<sup>nd</sup> hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3<sup>rd</sup> hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4<sup>th</sup> hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2<sup>nd</sup> or 4<sup>th</sup> hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> customers = &quot;NNNNN&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> It is best to close the shop at the 0<sup>th</sup> hour as no customers arrive.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> customers = &quot;YYYY&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> It is best to close the shop at the 4<sup>th</sup> hour as customers arrive at each hour.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= customers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>customers</code> consists only of characters <code>&#39;Y&#39;</code> and <code>&#39;N&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int bestClosingTime(string customers) {
    int Y = 0;
    for(auto c : customers) {
      Y += 'Y' == c;
    }

    int answer = 0;
    int result = Y;
    int currentY = 0;
    int currentN = 0;
    for(int i = 0; i < customers.length(); ++i) {
      currentY += customers[i] == 'Y';
      currentN += customers[i] == 'N';
      if(result > (Y - currentY) + currentN) {
        result = Y - currentY + currentN;
        answer = i + 1;
      }
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (11 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 86.38 % of cpp submissions (10.6 MB)
```
