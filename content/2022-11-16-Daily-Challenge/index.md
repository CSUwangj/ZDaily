+++
updated = 2022-11-16T12:39:43+08:00
title = "2022-11-16 Daily Challenge"
path = "2022-11-16-Daily-Challenge"
date = 2022-11-16T12:39:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/guess-number-higher-or-lower/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 16

## Description

**Guess Number Higher or Lower**

<p>We are playing the Guess Game. The game is as follows:</p>

<p>I pick a number from <code>1</code> to <code>n</code>. You have to guess which number I picked.</p>

<p>Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.</p>

<p>You call a pre-defined API <code>int guess(int num)</code>, which returns three possible results:</p>

<ul>
	<li><code>-1</code>: Your guess is higher than the number I picked (i.e. <code>num &gt; pick</code>).</li>
	<li><code>1</code>: Your guess is lower than the number I picked (i.e. <code>num &lt; pick</code>).</li>
	<li><code>0</code>: your guess is equal to the number I picked (i.e. <code>num == pick</code>).</li>
</ul>

<p>Return <em>the number that I picked</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10, pick = 6
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, pick = 1
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 2, pick = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= pick &lt;= n</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int guessNumber(int n) {
    int begin = 1, end = n;
    while(begin < end) {
      int mid = begin + (end - begin) / 2;
      int res = guess(mid);
      if(res != 1) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};

// Accepted
// 25/25 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.31 % of cpp submissions (5.9 MB)
```
