+++
updated = 2024-08-19T14:58:32+08:00
title = "2024-08-19 Daily Challenge"
path = "2024-08-19-Daily-Challenge"
date = 2024-08-19T14:58:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/2-keys-keyboard/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 19

## Description

**2 Keys Keyboard**

<p>There is only one character <code>&#39;A&#39;</code> on the screen of a notepad. You can perform one of two operations on this notepad for each step:</p>

<ul>
	<li>Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).</li>
	<li>Paste: You can paste the characters which are copied last time.</li>
</ul>

<p>Given an integer <code>n</code>, return <em>the minimum number of operations to get the character</em> <code>&#39;A&#39;</code> <em>exactly</em> <code>n</code> <em>times on the screen</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Initially, we have one character &#39;A&#39;.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get &#39;AA&#39;.
In step 3, we use Paste operation to get &#39;AAA&#39;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 0
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
  int minSteps(int n) {
    int ans = 0;
    for(int i = 2; i*i <= n; ++i) {
      if(n % i != 0) continue;
      while(n % i == 0) {
        n /= i;
        ans += i;
      }
    }
    if(n != 1) ans += n;
    return ans;
  }
};
```
