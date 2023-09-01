+++
updated = 2023-09-01T10:23:33+08:00
title = "2023-09-01 Daily Challenge"
path = "2023-09-01-Daily-Challenge"
date = 2023-09-01T10:23:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/counting-bits/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 1

## Description

**Counting Bits**

<p>Given an integer <code>n</code>, return <em>an array </em><code>ans</code><em> of length </em><code>n + 1</code><em> such that for each </em><code>i</code><em> </em>(<code>0 &lt;= i &lt;= n</code>)<em>, </em><code>ans[i]</code><em> is the <strong>number of </strong></em><code>1</code><em><strong>&#39;s</strong> in the binary representation of </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> [0,1,1]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> [0,1,1,2,1,2]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>It is very easy to come up with a solution with a runtime of <code>O(n log n)</code>. Can you do it in linear time <code>O(n)</code> and possibly in a single pass?</li>
	<li>Can you do it without using any built-in function (i.e., like <code>__builtin_popcount</code> in C++)?</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int pop_count(int x) {
  const int m1  = 0X55555555;
  const int m2  = 0X33333333;
  const int m4  = 0X0F0F0F0F;
  const int m8  = 0X00FF00FF;
  const int m16 = 0X0000FFFF;
  x = (x &  m1) + ((x >>  1) &  m1);
  x = (x &  m2) + ((x >>  2) &  m2);
  x = (x &  m4) + ((x >>  4) &  m4);
  x = (x &  m8) + ((x >>  8) &  m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> answer(n + 1);
    for(int i = 1; i <= n; ++i) {
      answer[i] = pop_count(i);
    }
    return move(answer);
  }
};

// Accepted
// 15/15 cases passed (6 ms)
// Your runtime beats 56.68 % of cpp submissions
// Your memory usage beats 51.17 % of cpp submissions (8 MB)
```
