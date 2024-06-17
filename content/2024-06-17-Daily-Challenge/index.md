+++
updated = 2024-06-17T15:07:58+08:00
title = "2024-06-17 Daily Challenge"
path = "2024-06-17-Daily-Challenge"
date = 2024-06-17T15:07:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/sum-of-square-numbers/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 17

## Description

**Sum of Square Numbers**

<p>Given a non-negative integer <code>c</code>, decide whether there&#39;re two integers <code>a</code> and <code>b</code> such that <code>a<sup>2</sup> + b<sup>2</sup> = c</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> c = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> 1 * 1 + 2 * 2 = 5
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> c = 3
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool judgeSquareSum(int c) {
    for(int i = 2; i * i <= c; ++i) {
      if(c % i == 0) {
        int count = 0;
        while(c % i == 0) {
          count += 1;
          c /= i;
        }
        if(i % 4 == 3 && (count & 1)) {
          return false;
        }
      }
    }
    return c % 4 != 3;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 54.21 % of cpp submissions
// Your memory usage beats 10.72 % of cpp submissions (6.4 MB)
```
